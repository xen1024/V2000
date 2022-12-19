/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

; IAR V3.11A
;#define DEBUG_FLASH

    Name FlashWork
    RSEG CODE
    public LoadByteFromAdrInRam,SaveByteFromAdrInRam
    public LoadByteFromAdrInRamC,SaveByteFromAdrInRamC
    $DEFFN LoadByteFromAdrInRamC(0,0,0,0,0,0,0,0)
    $DEFFN SaveByteFromAdrInRamC(0,0,0,0,0,0,0,0)
    $DEFFN InitFlash(0,0,0,0,0,0,0,0)
    public StopSendFlash
    $DEFFN StopSendFlash(0,0,0,0,0,0,0,0)

    public  InitFlash,PushC1
#define __Flash
#define FastFlash
$vdef.inc

#define PushR0 ByteFlash
#define CxSendA CxSendFlash

#ifdef DEBUG_FLASH
SDA     equ P3.0
SCL     equ P3.0
#endif

;ByteWrite equ 22h
;ByteWrite1 equ 33h
;------­¨ζ¨ «¨§ ζ¨ο δ«νθ¨
;In:
;Out: C
;     0 Ok
;     1 Error init flash
InitFlash:
         setb SDA                            ;Data=1
         mov A,#1+9*2
AgainInitFlash:
          setb SCL                           ;Clock=1
          jb SDA,NextInitOn                  ;If (Data=1) ResetOk
          clr SCL
         djnz ACC,AgainInitFlash
         setb C
         ret
NextInitOn:
         clr SCL
         ;=========

         setb Flash24C16
         clr StopEveryWrite
         clr OldOperation
         call StopSendFl
         clr C
         ret


;      ;clr StopEveryWrite
;
;         mov A,#ByteWrite
;         mov DPTR,#1ebah
;         call SaveByteFromAdrInRam
;         mov A,#ByteWrite1
;         inc DPTR
;         call SaveByteFromAdrInRam
;         mov DPTR,#1ebah
;         call LoadByteFromAdrInRam
;         mov B,A
;         inc DPTR
;         call LoadByteFromAdrInRam
;
;          setb Led0
;          cjne A,#ByteWrite1,KKKKKKK3
;           clr Led0
;
;           mov A,B
;           setb Led0
;           cjne A,#ByteWrite,KKKKKKK3
;            clr Led0
;KKKKKKK3:
;
;         mov A,#ByteWrite1
;         mov DPTR,#622h
;         call SaveByteFromAdrInRam
;         mov DPTR,#622h
;         call LoadByteFromAdrInRam
;
;         setb Led0
;         cjne A,#ByteWrite1,KKA
;          clr Led0
;KKA:
;         sjmp $
;
;
;         mov A,#10100000b
;         call SendFlashByte
;         mov A,#001H
;         call SendFlashByte
;         mov A,#010H
;         call SendFlashByte
;         mov A,#ByteWrite
;         call SendFlashByte
;         mov A,#ByteWrite1
;         call SendFlashByte
;
;          clr SDA
;          setb SCL
;          setb SDA                           ;        StopDataFlash
;          clr SCL
;
;         mov R0,#0
;         mov B,#4
;TTTT:
;           djnz R0,$
;          djnz B,TTTT
;
;         setb SDA
;         setb SCL
;         clr SDA                             ;Start Data
;         clr SCL
;
;
;
;
;         mov A,#10100000b
;         call SendFlashByte
;         mov A,#001H
;         call SendFlashByte
;         mov A,#010H
;         call SendFlashByte
;         setb SDA                      ;        Start
;         setb SCL
;         clr SDA
;         clr SCL
;         mov A,#10100001b
;         call SendFlashByte
;         call GetFlashByte
;
;               clr SDA
;               setb SCL
;               clr SCL
;
;         setb Led0
;         cjne A,#ByteWrite,KKKKKKK1
;          clr Led0
;
;          call GetFlashByte
;               setb SDA
;               setb SCL
;               clr SCL
;          setb Led0
;          cjne A,#ByteWrite1,KKKKKKK1
;           clr Led0
;KKKKKKK1:
;          clr SDA
;          setb SCL
;          setb SDA
;          clr C
;          sjmp $
;         ret

#ifndef FastFlash
SendFlashByte:
               mov LoopFlashA,#8
AgainSendFlashByte:
                rlc A
                mov SDA,C
                setb SCL
                clr SCL
               djnz LoopFlashA,AgainSendFlashByte

               setb SDA
               setb SCL
               mov C,SDA
               clr SCL
               ret
#endif
#ifdef FastFlash
SendFlashByte:
              rlc A
              mov SDA,C
              setb SCL
              clr SCL
              rlc A
              mov SDA,C
              setb SCL
              clr SCL
              rlc A
              mov SDA,C
              setb SCL
              clr SCL
              rlc A
              mov SDA,C
              setb SCL
              clr SCL
              rlc A
              mov SDA,C
              setb SCL
              clr SCL
              rlc A
              mov SDA,C
              setb SCL
              clr SCL
              rlc A
              mov SDA,C
              setb SCL
              clr SCL
              rlc A
              mov SDA,C
              setb SCL
              clr SCL

              setb SDA
              setb SCL
              mov C,SDA
              clr SCL
              ret
#endif

#ifndef FastFlash
GetFlashByte:
               mov LoopFlashA,#8
AgainGetFlashByte:
                setb  SDA
                setb SCL
                mov C,SDA
                rlc A
                clr SCL
               djnz LoopFlashA,AgainGetFlashByte
               ret
#endif
#ifdef FastFlash
GetFlashByte:
              setb  SDA
              setb SCL
              mov C,SDA
              clr SCL
              rlc A
              setb SCL
              mov C,SDA
              clr SCL
              rlc A
              setb SCL
              mov C,SDA
              clr SCL
              rlc A
              setb SCL
              mov C,SDA
              clr SCL
              rlc A
              setb SCL
              mov C,SDA
              clr SCL
              rlc A
              setb SCL
              mov C,SDA
              clr SCL
              rlc A
              setb SCL
              mov C,SDA
              clr SCL
              rlc A
              setb SCL
              mov C,SDA
              clr SCL
              rlc A
              ret
#endif

SaveByteFromAdrInRamC:
                      mov DPL,ParamLL
                      mov DPH,ParamLH
                      mov A,ParamHL
                      jmp SaveByteFromAdrInRam
LoadByteFromAdrInRamC:
                      mov DPL,ParamLL
                      mov DPH,ParamLH
                      call LoadByteFromAdrInRam
                      mov ParamLL,A
                      ret
LoadByteFromAdrInRam:
                      mov ByteFlash,A
                      mov A,DPH
                      inc A
                      jnz OkLoadByteFromAdrInRam
                       mov PushR0,R0
                       mov R0,DPL
                       mov A,@R0
                       mov R0,PushR0
                       ret
OkLoadByteFromAdrInRam:
#ifdef DEBUG_FLASH
 mov A,ByteFlash
 movx A,@DPTR
 ret
#endif
                      setb Operation
                      sjmp FlashRW


SaveByteFromAdrInRam:
                      mov ByteFlash,A
                      mov A,DPH
                      inc A
                      jnz OkSaveByteFromAdrInRam
                       mov A,ByteFlash
                       mov PushR0,R0
                       mov R0,DPL
                       mov @R0,A
                       mov R0,PushR0
                       ret
OkSaveByteFromAdrInRam:
#ifdef DEBUG_FLASH
 mov A,ByteFlash
 movx @DPTR,A
 ret
#endif
                      clr Operation
                      sjmp FlashRW

; Operation = 0 W
;             1 R
WDH equ 10100000b
RDH equ 10100001b
FlashRW:  mov PushC1,C
          clr A
          mov C,Operation
;          jc LLLLLLLL
          rlc A
          mov C,OldOperation
          subb A,#0
          jz OperationEqual
;LLLLLLLL:
            jnb OldOperation,NoStopRead        ;Operation!=OldOperation
             jb AlreadyStoppedSend,NoStopRead
                                               ;If NoStopped
              setb SDA                         ;OldOperation==Read
              setb SCL                         ;StopRead d x1100
              clr SCL                          ;         c 00110
NoStopRead:
            sjmp SendAdrA
OperationEqual:
           jb Operation,NoApplyReadFL
            mov A,DPL
            xrl A,OldFlashAdL
            anl A,#0xF0
            jb Flash24C16,NoPage32Bytes
             anl A,#0xE0
NoPage32Bytes:
            add A,DPH
            clr C
            subb A,OldFlashAdH
            jnz SendAdrA
NoApplyReadFL:
           setb C
           mov A,DPL
           subb A,OldFlashAdL
           mov OldFlashAdL,A
           mov A,DPH
           subb A,OldFlashAdH
           orl A,OldFlashAdL
;      jmp SendAdrA
           jnz SendAdrA
           mov A,CxSendFlash
           jb ACC.4,SendAdrA              ;5->4
           sjmp NoSendAdrA
SendAdrA:
                                          ;Address!=OldAddress+1|CxSend=32)
;            mov CxSendFlash,#0
            jbc AlreadyStoppedSend,SkipStopA
             clr SDA                          ;If NoStopped
             setb SCL                         ;StopSend
             setb SDA
             clr SCL
SkipStopA:
            mov CxSendA,#0

AgainSetA:
             setb SDA
             setb SCL                         ;StartSend
             clr SDA
             clr SCL

             mov A,#WDH
             jnb Flash24C16,NoUseShortAddressW
              rr A
              orl A,DPH
              rl A
NoUseShortAddressW:
             call SendFlashByte
             jnc OkSetA
            djnz CxSendA,AgainSetA
OkSetA:
            mov CxSendFlash,#0

            jb Flash24C16,NoUseLongAddress
             mov A,DPH
             call SendFlashByte
NoUseLongAddress:
            mov A,DPL
            call SendFlashByte

            jnb Operation,NoSetStartRD
             setb SDA                         ;Operation=R
             setb SCL                         ;StartSend
             clr SDA
             clr SCL
             mov A,#RDH
             jnb Flash24C16,NoUseShortAddressR
              rr A
              orl A,DPH
              rl A
NoUseShortAddressR:
             call SendFlashByte
NoSetStartRD:
            sjmp BeginWR
NoSendAdrA:
            jnb OldOperation,NoNextRead
              clr SDA                          ;OldOperation==Read
              setb SCL                         ;NextRead
              clr SCL
NoNextRead:
BeginWR:

           mov OldFlashAdL,DPL
           mov OldFlashAdH,DPH
           inc CxSendFlash
           mov C,Operation
           mov OldOperation,C
           jnc NoReadNow
             call GetFlashByte
             mov ByteFlash,A
             sjmp EndOperFlash
NoReadNow:
             mov A,ByteFlash
             call SendFlashByte
EndOperFlash:
           mov A,CxSendFlash                      ;
           jb ACC.4,StopSendB                     ;5->4!!!
           jb Operation,NoStopSendB               ;
           jb StopEveryWrite,StopSendB            ;
           sjmp NoStopSendB                       ;
StopSendFlash:
StopSendB:
            setb AlreadyStoppedSend          ;if (CxSendFlash=0x20|StopEveryWrite&Oper=W)
            mov CxSendFlash,#0x10
            clr SDA
            setb SCL                         ;StopSend
            setb SDA
            clr SCL
NoStopSendB:
           mov A,ByteFlash
           mov C,PushC1
           ret

StopSendFl:
         setb StopEveryWrite                   ;Write 1
         sjmp StopSendB
;         setb AlreadyStoppedSend
;         setb StopEveryWrite                   ;Write 1
;         ;clr StopEveryWrite                   ;Write 32
;         mov CxSendFlash,#32
;         clr SDA
;         setb SCL                              ;StopSend
;         setb SDA
;         clr SCL


; DPTR=Address
; A=Data
;
; Operation = 0 W
;             1 R
;
;if (Operation!=OldOperation)
;    {
;     if (OldOperation==R) StopRead;
;     CxSend=0;
;     StopBit;
;     SendAddressA;
;    }
;else
;    {
;     if (Address!=OldAddress+1|CxSend=32)
;      {
;       CxSend=0;
;       StopBit;
;       SendAddressA;
;      }
;     else
;      if (OldOperation==R) NextRead;
;    }
;   CxSend++;
;   OldOperation=Operation;
;   OldAddress=Address;
;   if (Operation=W)
;     WriteByte;
;   else
;     ReadByte;
;
;   if (CxSend=32)
;     {
;      StopBit;
;     }
; exit:SCL=0
;
;
        RSEG    D_UDATA
OldFlashAdL:        DS 1
OldFlashAdH:        DS 1
CxSendFlash:        DS 1
#ifndef FastFlash
LoopFlashA:         DS 1
#endif
ByteFlash:          DS 1
;CxSendA:            DS 1
;PushR0:             DS 1
        RSEG    BITVARS
Operation:          DS 1
OldOperation:       DS 1
AlreadyStoppedSend: DS 1
StopEveryWrite:     DS 1
PushC1:             DS 1
Flash24C16:         DS 1
 END