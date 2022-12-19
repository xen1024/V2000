/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

;---------------------------------------------------------------;
;                                                               ;
;                       CSTARTUP.S03                            ;
;                                                               ;
; This module contains the entire code executed before the C    ;
; "main" function is called.  The code can be tailored to suit  ;
; special hardware needs.  The code is designed to run on any   ;
; processor based on the 8051 architecture.                     ;
;                                                               ;
; Version: 5.20 [IMAF 960603]                                   ;
;
; Revision control system
;       $Revision: 1.16 $
;
;---------------------------------------------------------------;
    NAME    CSTARTUP
    PUBLIC  init_C
    $DEFFN  init_C(0400H,0,0,0,0,0,0,0)

$defmodel.inc                           ; Defines memory model

    EXTERN  ?C_EXIT                 ; Where to go when program is done
    EXTERN  _R                      ; Register bank (0, 8, 16 or 24)
    EXTERN  main                    ; First C function usually
    $DEFFN    main(32768,0,0,0)
    EXTERN    __low_level_init        ; Setup low level things
    $DEFFN    __low_level_init(0,0,0,0)
    EXTERN  exit
    $DEFFN    exit(0,0,0,0)
    IF    banked_mode
    EXTERN    ?X_CALL_L18
        ENDIF

    RSEG    B_UDATA
    RSEG    B_CDATA
    RSEG    B_IDATA
    RSEG    D_UDATA
    RSEG    D_CDATA
    RSEG    D_IDATA
    RSEG    I_UDATA
    RSEG    I_CDATA
    RSEG    I_IDATA
    RSEG    P_UDATA
    RSEG    P_CDATA
    RSEG    P_IDATA
lcall_mode=0
    IF      lcall_mode
    RSEG    X_UDATA
    RSEG    X_CDATA
    RSEG    X_IDATA
    RSEG    ECSTR
    RSEG    CCSTR
    ENDIF

;---------------------------------------------------------------;
; The C stack segment. Should be mapped into internal data RAM  ;
;---------------------------------------------------------------;
; The C stack is used for LCALL's and temporary storage for     ;
; code generator help-routines (math etc).  The stack will be   ;
; located after all other internal RAM variables if the stan-   ;
; dard linking procedure is followed.  Note that C interrupt    ;
; routines can double stack size demands.                       ;
;---------------------------------------------------------------;

    RSEG    CSTACK
stack_begin:
    DS      30                      ; Increase if needed

    COMMON  INTVEC                  ; Should be at location zero

;---------------------------------------------------------------;
; C interrupt routines with defined [vectors] will reserve      ;
; space in this area.  So will handlers written in assembler if ;
; they follow the recommended format.                           ;
;---------------------------------------------------------------;

startup:
    IF      lcall_mode
    LJMP    init_C
    ELSE
    AJMP    init_C
    ENDIF


    RSEG    RCODE                   ; Should be loaded after INTVEC
init_C:
    MOV     SP,#stack_begin - 1     ; From low to high addresses
    MOV     DPTR,#SFB (P_IDATA)      ; Initialize high byte of PDATA.
    MOV     P2,DPH                  ;

;----------------------------------------------------------------------
; Call __low_level_init to perform initialization before initializing
; segments and calling main. If the function returns 0 no segment
; initialization should take place.
;
; Link with your own version of __low_level_init to override the
; default action: to do nothing but return 1.
;----------------------------------------------------------------------

    IF    banked_mode
    MOV    A,#$BYTE3 __low_level_init
    MOV    DPTR,# LWRD(__low_level_init)
    LCALL    ?X_CALL_L18        ; main()
    ELSE
    IF    lcall_mode
    LCALL    __low_level_init
    ELSE
    ACALL    __low_level_init
    ENDIF
    ENDIF

        MOV     A,R4
        ORL     A,R5
        JZ      skip_init


;---------------------------------------------------------------;
;             C variable initialization section                 ;
;             =================================                 ;
;                                                               ;
; If there is no demand that global/static C variables should   ;
; have a defined value at startup (required by ANSI), the       ;
; following section can be removed to conserve code memory      ;
; size.   Note that this part calls functions in the end of     ;
; this file, that also can be removed if initialized values are ;
; not needed.                                                   ;
;                                                               ;
; Systems controlled by a watch-dog may require additional      ;
; code insertions as the initialization can take several        ;
; milliseconds (if there are many variables) to complete.       ;
; These parts are marked with    *** WDG ***                    ;
;---------------------------------------------------------------;

;===============================================================;
; Zero out sections containing variables without explicit       ;
; initializers like in:                                         ;
;                                                               ;
;       int i;                                                  ;
;       xdata double d[10];                                     ;
;===============================================================;
    mov R0,#stack_begin-2
AgainClearData:
      mov @R0,#0
     djnz R0,AgainClearData
;    MOV     R0,#SFE(I_UDATA)
;    SJMP    CLEAR_IDATA_2
;CLEAR_IDATA:
;    MOV     @R0,#0
;    DEC     R0
;CLEAR_IDATA_2:
;    CJNE    R0,#SFB(I_UDATA),CLEAR_IDATA
;
;    MOV     R0,#SFE(D_UDATA)
;    SJMP    CLEAR_DDATA_2
;CLEAR_DDATA:
;    MOV     @R0,#0
;    DEC     R0
;CLEAR_DDATA_2:
;    CJNE    R0,#SFB(D_UDATA),CLEAR_DDATA
;
;    MOV     R0,#SFE(B_UDATA)
;    SJMP    CLEAR_BDATA_2
;CLEAR_BDATA:
;    MOV     @R0,#0
;    DEC     R0
;CLEAR_BDATA_2:
;    CJNE    R0,#SFB(B_UDATA),CLEAR_BDATA

    IF      lcall_mode
    MOV     DPTR,#SFE (X_UDATA)             ; XDATA
    MOV     R6,DPH
    MOV     R7,DPL
    MOV     DPTR,#SFB (X_UDATA)
NEXT_X_UDATA:
    LCALL   COMP_R67_DPTR
    JZ      INIT_P_UDATA
    CLR     A
    MOVX    @DPTR,A
    INC     DPTR
    SJMP    NEXT_X_UDATA

INIT_P_UDATA:
    MOV     DPTR,#SFB (P_UDATA)
    MOV     R0,DPL
    MOV     DPTR,#SFE (P_UDATA)
    MOV     R1,DPL
NEXT_P_UDATA:
    MOV     A,R0
    CLR     C
    SUBB    A,R1
    JNC     INIT_VARS
    MOV     @R0,#0
    INC     R0
    SJMP    NEXT_P_UDATA
    ENDIF

;===============================================================;
; Copy initializers into the proper memory segments for decla-  ;
; rations like:                                                 ;
;                                                               ;
;       int i = 7;                                              ;
;       idata char *cp = "STRING";                              ;
;===============================================================;

INIT_VARS:
    MOV     DPTR,#BDATA_TABLE               ; BDATA
    IF      lcall_mode
    LCALL   DI_INIT
    ELSE
    ACALL   DI_INIT
    ENDIF
    MOV     DPTR,#DATA_TABLE                ; DATA
    IF      lcall_mode
    LCALL   DI_INIT
    ELSE
    ACALL   DI_INIT
    ENDIF
    MOV     DPTR,#IDATA_TABLE               ; IDATA
    IF      lcall_mode
    LCALL   DI_INIT
    ELSE
    ACALL   DI_INIT
    ENDIF
    MOV     DPTR,#PDATA_TABLE               ; PDATA
    IF      lcall_mode
    LCALL   X_INIT
    ENDIF
    IF      lcall_mode
    MOV     DPTR,#XDATA_TABLE               ; XDATA
    LCALL   X_INIT
    MOV     DPTR,#YDATA_TABLE               ; For the -y compiler option
    LCALL   X_INIT
    ENDIF

skip_init:

;---------------------------------------------------------------;
;          C variable initialization section end                ;
;---------------------------------------------------------------;

;---------------------------------------------------------------;
; Activate the (at link-time) selected register bank.           ;
;---------------------------------------------------------------;

    MOV     PSW,#_R

;---------------------------------------------------------------;
; If hardware must be initiated from assembly or if interrupts  ;
; should be on when reaching main, this is the place to insert  ;
; such code.                                                    ;
;---------------------------------------------------------------;

    IF      banked_mode

    MOV     A,#$BYTE3 main
    MOV     DPTR,#LWRD(main)
    LCALL   ?X_CALL_L18             ; main()

    ELSE

    IF      lcall_mode
    LCALL   main                    ; main()
    ELSE
    ACALL   main                    ; main()
    ENDIF
    ENDIF

;---------------------------------------------------------------;
; Now when we are ready with our C program (usually 8051 C      ;
; programs are continuous) we must perform a system-dependent   ;
; action.  In this simple case we just stop.                    ;
;---------------------------------------------------------------;
; DO NOT CHANGE NEXT LINE OF CSTARTUP IF YOU WANT TO RUN YOUR   ;
; SOFTWARE WITH THE AID OF THE C-SPY HLL DEBUGGER.  IT CAN      ;
; THOUGH BE REMOVED IF YOUR PROGRAM IS CONTINUOUS (NO EXIT).    ;
; If it is removed the EXTERN ?C_EXIT line should also be re-   ;
; moved to avoid linking of the "exit" module                   ;
;---------------------------------------------------------------;
    IF      lcall_mode
    LJMP    exit
    ELSE
    AJMP    exit
    ENDIF

;---------------------------------------------------------------;
; Last part of the C variable initializer code.                 ;
;---------------------------------------------------------------;
    IF      lcall_mode
COMP_R67_DPTR:
;===========================;
;       *** WDG ***         ;
;                           ;
; ACC, B, R0-R3 may be used ;
;===========================;
    MOV     A,R7
    XRL     A,DPL
    JNZ     NOT_EQUAL
    MOV     A,R6
    XRL     A,DPH
NOT_EQUAL:
    RET
    ENDIF

DI_INIT:
    CLR     A
    MOVC    A,@A+DPTR
    MOV     R0,A
    MOV     A,#1
    MOVC    A,@A+DPTR
    MOV     R1,A
    MOV     A,#2
    MOVC    A,@A+DPTR
    MOV     R6,A
    MOV     A,#3
    MOVC    A,@A+DPTR
    MOV     DPL,A
    MOV     DPH,R6
MORE_DI_COPY:
;===========================;
;       *** WDG ***         ;
;                           ;
; ACC, B, R2-R6 may be used ;
;===========================;
    MOV     A,R0
    XRL     A,R1
    JNZ     $+3
    RET
    CLR     A
    MOVC    A,@A+DPTR
    MOV     @R0,A
    INC     DPTR
    INC     R0
    SJMP    MORE_DI_COPY

    IF      lcall_mode
X_INIT:
    CLR     A
    MOVC    A,@A+DPTR
    MOV     R4,A
    MOV     A,#1
    MOVC    A,@A+DPTR
    MOV     R5,A
    MOV     A,#2
    MOVC    A,@A+DPTR
    MOV     R6,A
    MOV     A,#3
    MOVC    A,@A+DPTR
    MOV     R7,A
    MOV     A,#4
    MOVC    A,@A+DPTR
    MOV     R0,A
    MOV     A,#5
    MOVC    A,@A+DPTR
    MOV     DPL,A
    MOV     DPH,R0
MORE_X_COPY:
    LCALL   COMP_R67_DPTR
    JNZ     $+3
    RET
    CLR     A
    MOVC    A,@A+DPTR
    INC     DPTR
    MOV     R0,DPH
    MOV     R1,DPL
    MOV     DPH,R4
    MOV     DPL,R5
    MOVX    @DPTR,A
    INC     DPTR
    MOV     R4,DPH
    MOV     R5,DPL
    MOV     DPH,R0
    MOV     DPL,R1
    SJMP    MORE_X_COPY
    ENDIF

BDATA_TABLE:
    DB      SFB (B_IDATA)
    DB      SFE (B_IDATA)
    DW      SFB (B_CDATA)
DATA_TABLE:
    DB      SFB (D_IDATA)
    DB      SFE (D_IDATA)
    DW      SFB (D_CDATA)
IDATA_TABLE:
    DB      SFB (I_IDATA)
    DB      SFE (I_IDATA)
    DW      SFB (I_CDATA)
PDATA_TABLE:
    DW      SFB (P_IDATA)
    DW      SFE (P_CDATA)
    DW      SFB (P_CDATA)

    IF      lcall_mode
XDATA_TABLE:
    DW      SFB (X_IDATA)
    DW      SFE (X_CDATA)
    DW      SFB (X_CDATA)
YDATA_TABLE:
    DW      SFB (ECSTR)
    DW      SFE (CCSTR)
    DW      SFB (CCSTR)
    ENDIF

    ENDMOD  startup

;---------------------------------------------------------------;
; Function/module: exit (int code)                              ;
;                                                               ;
; When C-SPY is used this code will automatically be replaced   ;
; by a 'debug' version of exit().                               ;
;---------------------------------------------------------------;
    MODULE  exit

    PUBLIC  exit
    $DEFFN  exit(0,0,0,0,0,0,0,0)
    PUBLIC  ?C_EXIT

    RSEG    RCODE

?C_EXIT:
exit:
;---------------------------------------------------------------;
; The next line could be replaced by user defined code.         ;
;---------------------------------------------------------------;
    SJMP    $               ; Forever...

    ENDMOD

;----------------------------------------------------------------------
;
; The only action of this default version of __low_level_init is to
; return 1. By doing so it signals that normal initialization of data
; segments should be done.
;
; A customized version of __low_level_init may be created in order to
; perform initialization before initializing segments and calling main
; and/or to skip initialization of data segments under certain
; circumstances.
; For further details see sample file lowinit.c
;
;----------------------------------------------------------------------


    MODULE    lowinit
    PUBLIC    __low_level_init
    $DEFFN    __low_level_init(0,0,0,0,32768,0,0,0)
    RSEG    CODE

__low_level_init:
    MOV    R4,#1                ; By returning 1 this function
    MOV    R5,#0            ; indicates that the normal
                    ; initialization should take place

    IF    banked_mode

    EXTERN    ?X_RET_L18
    LJMP    ?X_RET_L18

    ELSE

    RET

    ENDIF

    END