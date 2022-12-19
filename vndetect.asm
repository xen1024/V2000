/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

       public NumeralDetect
       $DEFFN NumeralDetect(2,0,0,0,0,0,0,0)
       RSEG CODE
$vdef.inc
#define x5EH $LOCBD NumeralDetect
#define x5FH $LOCBD NumeralDetect+1
#define SelectBank 0
#define TempArray12 stack_begin+(4-stack_begin&3)&3
#define Comparator LineData
#define MinQuality 2*0x10
;------------------------------------------------------------
;Show Indikator
;------------------------------------------------------------
DelayA16MHzB:
         mov A,DeviderTo2ms
         cjne A,#1,NoNextA
          inc NRazr
          jb VideoBit9,No9RazrN0
           mov NRazr,#0
           jmp No9RazrN0a
No9RazrN0: nop
           nop
           nop
No9RazrN0a:
          mov C,VideoBit9
          mov A,NRazrB
          rlc A
          mov NRazrB,A
          mov VideoBit9,C
          anl P4,#LOW(~Bit9IndHW)
          jnb VideoBit9,No9RazrN1
           orl P4,#Bit9IndHW
           jmp No9RazrN1a
No9RazrN1: nop
           nop
           nop
No9RazrN1a:
         nop
         jmp DelayA16MHzA
NoNextA:
         NOP
         MUL AB
         MUL AB
         MUL AB
         MUL AB
         MUL AB
         jmp DelayA16MHzA

IndikatorShow:
         djnz DeviderTo2ms,DelayA16MHzB
          mov DeviderTo2ms,#6
          push    DPL
          push    DPH

          mov     DPTR,#HighVideoAddress<<8
          clr A
          movx    @DPTR,A
          mov DPH,#HighP4Address
          mov A,P4
          movx @DPTR,A

          mov     A,NRazr
          rl      A
          add     A,#VideoBuffer+1-2
          mov     R0,A
          add     A,#(SelectRazr-$-5)<<1-(VideoBuffer+1-2)
          rr      A
          movc    A,@A+PC
          mov     DPL,A
          mov     DPH,#7fh
          mov     A,@R0
          movx    @DPTR,A
          pop     DPH
          pop     DPL
          nop
          nop
          NOP
          ret

SelectRazr: db 0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F,0xFF

;            NOP
DelayA16MHz:;mov A,#2
            ;djnz ACC,$
            NOP                        ;1
;            NOP                        ;2
;            NOP                        ;3
            movc A,@A+PC
            NOP                        ;4
DelayA16MHzA:
            NOP                        ;5
            NOP                        ;6
            NOP                        ;7
;            MUL AB
;            NOP                        ;8
;            NOP                        ;9
;            NOP                        ;10
;            NOP                        ;11
            MUL AB
;            NOP                        ;12
;            NOP                        ;13
;            NOP                        ;14
;            NOP                        ;15
            MUL AB
            ret
;------------------------------------------------------------
test_1:
        mov F0,C
        call IndikatorShow

        mov C,F0
        MOV   A,R7                      ;
        RLC   A                         ;
        MOV   C,Comparator              ;38ms - 10MHz
        RLC   A                         ;
        MOV   R7,A                      ;

        call DelayA16MHz

        DJNZ  R3,Lable_1
         MOV   R3,#09H
         NOP
Lable_4:
        CJNE  R5,#10H,Lable_2
         MOV   R2,#0FFH
         MOV   R4,#22H
         NOP
Lable_3:
         MUL   AB
         MUL   AB
         MUL   AB
         NOP
        SJMP  start_opr
Lable_2:
        movc A,@A+PC
        SJMP  Lable_3
Lable_1:
        SJMP  Lable_4
;----------------...И начали мы разгребать процедеру ОПРЕДЕЛЕНИЯ...------
NumeralDetect:
         CLR   EA                   ;Запрет всех прерываний

;        inc DeviderTo2ms

;         orl P4,#Bit9IndHW
;         mov DPH,#HighP4Address
;         mov A,P4
;         movx @DPTR,A

         setb Comparator

         CLR   A                    ;A=0
;         clr TR0
;         clr TR1
         MOV   R5,#21H              ;R5=#21h
         MOV   R3,#09H              ;R3=#09h
         MOV   R7,A                 ;R7=0
         MOV   R2,A                 ;R2=0
         MOV   DPTR,#Freq_TBL       ;таблица частот
         MOV   R4,#16H              ;R4=#16h

start_opr:
         MOV   A,R7                 ;A=R7
         XRL   A,R2                 ;A=R7 xor R2
         MOV   R6,A                 ;R6=A=R7 xor R2
         MOV   R1,#TempArray12;40H              ;R1=#40h
Again_1:
           NOP
Again_2:
           MOV   C,Comparator         ;C=P3.3          38.39.38.39us - 10MHz
           MOV   A,R7                 ;A=R7
           RLC   A                    ;A=C<A<C
           MOV   R7,A                 ;R7=A=C<A<C
           call DelayA16MHz

           MOV   A,R4                 ;A=R4 16h/22h+
           ADD   A,#09H               ;A=A+9=R4+9 C=0
           MOVC  A,@A+PC              ;A=[A+PC]=[R4+PC+9]
           XRL   A,R6                 ;A=A xor R6=[R4+PC+9] xor R6
           RRC   A                    ;A=0>A>C X1=RCR (R7 xor R2 xor [TBLA+(R4-16h)]);Proc_326:
           MOVC  A,@A+DPTR            ;A=[A+DPTR]=[X1+CHASTOT_TBL] = [ADR1]
           ADDC  A,@R1                ;A=A+@R1+C=[ADR1]+@R1+C
           MOV   @R1,A                ;@R1=A=[ADR1]+@R1+C 40h+
           INC   R1                   ;R1++
           INC   R4                   ;R4++
           MOV   A,R4                 ;A=R4 16h/22h+
           MOVC  A,@A+PC              ;A=[A+PC]=[R4+PC]=[TBLA+(R4-16h)]=[ADR2]
           XRL   A,R6                 ;A=A xor R6=[ADR2] xor R6
           CLR   C                    ;C=0
           RRC   A                    ;A=0>A>C
           MOVC  A,@A+DPTR            ;A=[A+CHASTOT_TBL]
           ADDC  A,@R1                ;A=A+@R1+C
           MOV   @R1,A                ;@R1=A=[rcr([ADR2] xor R2 xor R7)+CHASTOT_TBL]+@R1+C
           INC   R1                   ;R1++
           INC   R4                   ;R4++
           MOV   A,R1                 ;A=R1

;           clr C                      ;5 !!!
;           subb  A,#TempArray12       ;6 !!!

          JB    ACC.1,Again_1         ;R1.1=1:Again_1
         CJNE  R1,#TempArray12+12,Again_2 ;R1<<4ch:Again_2 (40<<=R1<<=4c)
         ;4CH,Again_2
         MOV   C,Comparator;P3.3               ;C=P3.3               ;38us
         DJNZ  R5,test_1            ;R5--;R5=0:test1
         LJMP  Lable_1536
TBLA:

      db      000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
      db      0FFh,0FFh,0FFh,0FEh,0FFh,0F8h,0FFh,0F0h,0FFh,0F0h,0FEh,0E0h
      db      0FFh,080h,0FCh,000h,0E0h,000h,080h,003h,000h,00Fh,001h,01Fh
      db      0C0h,000h,000h,007h,001h,07Fh,01Fh,0FFh,07Fh,0F8h,0FCh,0C0h
      db      000h,01Fh,00Fh,0FFh,0FFh,0F8h,0F8h,000h,080h,007h,003h,03Fh
      db      00Fh,0FFh,0FFh,0E0h,0C0h,000h,001h,03Fh,03Fh,0FCh,0F8h,080h
      db      0FFh,0F8h,0C0h,000h,003h,0FFh,0FFh,0F0h,0C0h,001h,007h,07Fh
      db      0FCh,000h,000h,07Fh,0FFh,0F0h,080h,003h,01Fh,0FEh,0F0h,080h
      db      000h,000h,0FFh,0FFh,0C0h,000h,01Fh,0FFh,0E0h,000h,00Fh,0FFh
      db      000h,0FFh,0FEh,000h,007h,0FFh,0F8h,000h,00Fh,0FFh,0E0h,001h
      db      07Fh,0FFh,000h,003h,0FFh,0E0h,003h,07Fh,0F0h,000h,01Fh,0FEh
      db      0FFh,0C0h,007h,0FFh,080h,001h,0FFh,0E0h,007h,07Fh,0C0h,003h
      db      0E0h,000h,0FFh,0F0h,007h,0FFh,000h,007h,0FCh,080h,03Fh,0FCh
      db      000h,00Fh,0E0h,000h,0FFh,0E0h,03Fh,0FEh,003h,03Fh,0C0h,007h
      db      007h,0FFh,000h,03Fh,000h,003h,0F0h,000h,0FEh,0C0h,07Fh,0F8h
      db      0FFh,0FEh,07Fh,0FFh,00Fh,0FFh,003h,07Fh,001h,01Fh,080h,00Fh
      db      0FFh,000h,0FFh,080h,0FFh,0C0h,0FFh,0E0h,0FFh,0E0h,0FFh,0F0h

Lable_1536:
;        MOV   R5,#01H
;        LCALL Proc_339

;        setb TR0
        MOV   R0,#06H
        LCALL Proc_340
        ADD   A,#(TBLB-LABELA1-1-1);#26H
LABELA1:
        MOVC  A,@A+PC
        MOV   ParamLL,A

        MOV   A,R5                  ;Качество
        JNB   ACC.4,Lable_1551
         MOV   A,#0FH
Lable_1551:

        SWAP  A
        ANL   A,#0F0H
        add A,#-MinQuality
        jc OkCifraGood
         mov ParamLL,#0Fh
OkCifraGood:

        SETB  EA               ;!!!!!!!!


;        call CorrTime
;        setb TR1
;extern DPbuffA
;        mov DPH,DPbuffA
;        mov DPL,DPbuffA+1
;;        call LoadByteFromAdrInRam
;;        mov R7,A
;        call SaveByteFromAdrInRam
;        inc DPTR
;        mov A,Nbmp
;        orl A,#30h
;        call SaveByteFromAdrInRam
;        inc DPTR
;        mov DPbuffA,DPH
;        mov DPbuffA+1,DPL
        RET                                  ;*
TBLB: DB 0Ah,01,02,04,07,0Ah,01,0Ah,03,05,08,0Ah,02,03,0Ah,06    ;A-тиш.
      DB 09,0Bh,04,05,06,0Ah,00,0Ch,07,08,09,00,0Ah,0Ah,0Ah,0Ah  ;B-начало
      DB 0Bh,0Ch,0Ah,0Ah                                         ;C-повтор


Freq_TBL:    db 00,01,01,02 ,01,02,02,03 ,01,02,02,03 ,02,03,03,04
             db 01,02,02,03 ,02,03,03,04 ,02,03,03,04 ,03,04,04,05
             db 01,02,02,03 ,02,03,03,04 ,02,03,03,04 ,03,04,04,05
             db 02,03,03,04 ,03,04,04,05 ,03,04,04,05 ,04,05,05,06

             db 01,02,02,03 ,02,03,03,04 ,02,03,03,04 ,03,04,04,05
             db 02,03,03,04 ,03,04,04,05 ,03,04,04,05 ,04,05,05,06
             db 02,03,03,04 ,03,04,04,05 ,03,04,04,05 ,04,05,05,06
             db 03,04,04,05 ,04,05,05,06 ,04,05,05,06 ,05,06,06,07
             ; 0000-0 ; 1000-1  0 1 1 2        x   x+1 x+1 x+2
             ; 0001-1 ; 1001-2  1 2 2 3 x      x+1 x+2 x+2 x+3
             ; 0010-1 ; 1010-2  1 2 2 3
             ; 0011-2 ; 1011-3  2 3 3 4
             ; 0100-1 ; 1100-2
             ; 0101-2 ; 1101-3
             ; 0110-2 ; 1110-3
             ; 0111-3 ; 1111-4
;----------------------------Разгребание частот-----------------------------
Proc_340:
        CLR   A                 ;A=0
        MOV   R4,A              ;R4=0
        MOV   x5EH,A             ;5eh=0
        MOV   x5FH,A             ;5fh=0
Lable_1635:                           ;@R1=A[K]B[K]
        MOV   R2,#02H           ;R2=2
Lable_1629:
          DEC   R1                ;R1--
          MOV   R3,B              ;R3=B
          XCH   A,@R1             ;A><@R1
          JBC   ACC.7,Lable_1628  ;A.7=1:C=1,Label_1628
            XRL   A,#7FH            ;A=A xor 01111111
            INC   A                 ;A++
Lable_1628:
          MOV   B,A               ;B=A
          MUL   AB                ;A^2
        DJNZ  R2,Lable_1629     ;R2--,R2=0:Label_1629
        ADD   A,@R1             ;A=A+@R1
        MOV   @R1,#00H          ;@R1=0
        INC   R1                ;R1++
        MOV   @R1,#00H          ;@R1=0
        DEC   R1                ;R1--
        XCH   A,R3              ;A><R3
        ADDC  A,B               ;A=A+B+C
        MOV   R2,A              ;R2=A  (R2R3)=F_x[i]=@R1^2+(@R1+1)^2
        CJNE  A,x5FH,Lable_1630  ;A=5Fh:Label_1630
          MOV   A,R3              ;A=R3
          CJNE  A,x5EH,Lable_1630  ;A=5Eh:Label_1630
Lable_1630:
        JC    Lable_1631        ;C=1:Label_1631
          MOV   A,R2              ;A=R2
          XCH   A,x5FH             ;A><5Fh
          MOV   R5,A              ;R5=A
          MOV   A,R3              ;A=R3
          XCH   A,x5EH             ;A><5Eh
          MOV   R4,A              ;R4=A
          MOV   A,R0              ;A=R0
          XCH   A,R6              ;A><R6
          SJMP  Lable_1632        ;Label_1632
Lable_1631:
        MOV   A,R2              ;A=R2
        CJNE  A,SelectBank+5,Lable_1633  ;A=R5h:Label_1633;R5
          MOV   A,R3              ;A=R3
          CJNE  A,SelectBank+4,Lable_1633  ;A=R4h:Label_1633 ;R4
Lable_1633:
        JC    Lable_1634        ;C=1:Label_1634
        MOV   R5,SelectBank+2;12H            ;R5=R2
        MOV   R4,SelectBank+3;13H            ;R4=R3
        MOV   A,R0              ;A=R0
Lable_1632:
        MOV   R7,A              ;R7=A
Lable_1634:
        DJNZ  R0,Lable_1635     ;R0--,R0=0:Label_1635
; R6=f1 R7=f2
        DEC   R6                ;R6--
        MOV   A,R6              ;A=R6
        MOV   R0,A              ;R0=A
        RL    A                 ;A*2
        MOV   R6,A              ;R6=A
        RL    A                 ;A*2
        ADD   A,R6              ;A=A+R6
        ADD   A,R7              ;A=A+R7  ;A=R7+(R6-1)*2+(R6-1)*4
        RET
; Исп. регстры:            r w
;                Rx.       x x
;--------------------------      50-59     x -
;                5e,5f     x x
;                40-4c
;TempArray12 0..11 12

                            ; R4=16
;MOV   A,R4                 ;
;ADD   A,#09H               ;
;MOVC  A,@A+PC              ;
;XRL   A,R6                 ;
;RRC   A                    ;
;MOVC  A,@A+DPTR            ;
;ADDC  A,@R1                ;
;MOV   @R1,A                ;
;INC   R1                   ;
;INC   R4                   ;
;MOV   A,R4                 ;
;MOVC  A,@A+PC              ;
;XRL   A,R6                 ;
;CLR   C                    ;
;RRC   A                    ; A<80
;MOVC  A,@A+DPTR            ;
;ADDC  A,@R1                ;
;MOV   @R1,A                ;
;INC   R1           ;22 2e 3a 46 52 5e 6a 76 82 8e 9a a6 b2 be ca d6 e2
                    ;2e 3a 46 52 5e 6a 76 82 8e 9a a6 b2 be ca d6 e2
;INC   R4                   ;16h+12h=38
;MOV   A,R1                 ;22h+10h=2c

 END