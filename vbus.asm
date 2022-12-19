/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

   NAME BusPIC
   public PICwork
   $DEFFN PICwork(0,0,0,0,3,0,0,0)
   public InitClock
   $DEFFN InitClock(0,0,0,0,0,0,0,0)
$vdef.inc
;#define _ClockEmulation
;#define _DEBUG

        RSEG    CODE

#define NoEndSetTimePIC TR2

;--------------------------------------------------------------------------------
;bit InitClock(void);
;--------------------------------------------------------------------------------
InitClock: clr TimerModePIC
           setb DATABitToPIC
           setb DATAbusPIC
           ret
;--------------------------------------------------------------------------------
; PIC WORK
;bit PICwork(uchar,uchar *Buffer);
;in: uchar ParamLL - command
;out: C-1 error
;     C-0 Data sent
;--------------------------------------------------------------------------------
#define Command $PRMBD PICwork
#define Buffer  $PRMBD PICwork+1
#define xSP     $PRMBD PICwork+2
;#define NoEndSetTimePIC $PRMBB PICwork
#define InitTimeOut $PRMBD PICwork+3

#define MaxSendDataPIC 6
PICwork:
#ifdef _ClockEmulation
        ret
#endif
               call GoPICwork
               jnc NoError
                mov ParamLL,#errClock
                jmp PrintError
NoError:
               ret
GoPICwork:
; GET BUFFER
               call StopPlay
               mov T2CON,#0
               mov T2MOD,#0xFC                  ;Set T2

               mov Command,ParamLL
               mov Buffer,ParamLH

               mov A,SP
               inc A
               mov xSP,A
;               mov R7,A
               add A,#MaxSendDataPIC
               mov SP,A

               mov InitTimeOut,#LoopReinitBeforeError

               setb TimerModePIC
ReInitPIC:
               setb ET0
; mov R0,#VideoBuffer+1
; mov @R0,InitTimeOut
               djnz InitTimeOut,NoTimeOutOver
                setb C
                jmp ExitOperPICErr
NoTimeOutOver:

;     1) Set 0 to data, wait 5.5ms
               mov A,#CalltoPIC
               call SetTX2toDataPICa

               setb DATABitToPIC
               clr DATAbusPIC
               jb NoEndSetTimePIC, $

               clr ET0
;     2) wait 1ms for 0
               mov A,#Wait1ms
               call SetTX2toDataPICa
;        if (timeout) ReInit
AgainWaitEndModeA:
                jnb NoEndSetTimePIC, ReInitPIC
#ifndef _DEBUG
               jb DATAbusPIC, AgainWaitEndModeA
#endif
               setb ET0

;     3) wait 6.5ms for 1
               mov A,#WaitCallFromPIC
               call SetTX2toDataPICa
;        if (timeout) ReInit
AgainWaitEndModeB:
                jnb NoEndSetTimePIC, ReInitPIC
               jnb DATAbusPIC, AgainWaitEndModeB
; Command send...
;              R7=COMMAND
               mov R1,xSP
               mov @R1, Command
               mov R2, #1
               call SendBytePIC
;               jmp ExitOperPIC

               mov A,Command
               call GetLenghtC
;               mov A,#2
               mov R2, A
               mov R4, A

               mov A,Command
               cjne A,#2,$+3
               jnc SendComandsPIC

                call GetBytePIC
                mov R2, _R+4
                call GetTestCheckSumm
                jc ReInitPIC
                mov A,Command
                jnz GetDatePIC
GetTimePIC:
;                 mov Hours,@R0
;                 inc R0
;                 mov Minutes,@R0
;                 inc R0
;                 mov Seconds,@R0
                 mov ParamLL,#3
GetDataTimePIC:  call CopyToBuffer
                 jmp ExitOperPIC
GetDatePIC:
                 mov ParamLL,#4
                 jmp GetDataTimePIC
;                 mov Day,@R0
;                 inc R0
;                 mov Month,@R0
;                 inc R0
;                 mov Year,@R0
;                 inc R0
;                 mov DayOfWeek,@R0
;                 jmp ExitOperPIC
SendComandsPIC:

SetTimePIC:
                 cjne A,#clcmdSetTime,SetDatePIC
;                  mov @R0,Hours
;                  inc R0
;                  mov @R0,Minutes
;                  inc R0
;                  mov @R0,Seconds
SetDataTimePic:
                  mov ParamLL,#3
                  call CopyFromBuffer
                  jmp SendDataPIC
SetDatePIC:
                 cjne A,#clcmdSetDate,SetPowerDownModePIC
                  jmp SetDataTimePic
;                  mov @R0,Day
;                  inc R0
;                  mov @R0,Month
;                  inc R0
;                  mov @R0,Year
;                  jmp SendDataPIC
SetPowerDownModePIC:
ClearPowerDownModePIC:
;                 mov @R0,TL0
SendDataPIC:
                 call GetTestCheckSumm
                 call SendBytePIC
                 jmp ExitOperPIC
ExitOperPIC:
               clr C
ExitOperPICErr:
               dec xSP
               mov SP,xSP
               clr TimerModePIC

               setb ET0
               ret

; In: R2=Nbytes
; Out: @R2+Buff=checksumm if (o@R7+Buff==checksumm) C=0 else C=1
GetTestCheckSumm: mov A,R2
                  dec A
                  mov R4,A
                  mov R3,#0
                  mov A,xSP
                  add A,R4
                  mov R0,A
AgainCalcCheckSum:
                   dec R0
                   mov A,@R0
                   add A,R3
                   xrl A,R4
                   mov R3,A
                  djnz R4, AgainCalcCheckSum
                  xrl A,#0AAh
                  mov R3,A

                  mov A,xSP
                  add A,R2
                  mov R0,A
                  dec R0

                  mov A,R3
                  xrl A,@R0
                  add A,#0FFh  ;C=R3^@R0-1

                  mov A,R3
                  mov @R0,A
                  mov R0,xSP;_R+1
                  ret
;------------------------------------------------------------------------------------------------
;Return len of data
;in: a - data
;out: A - len
;------------------------------------------------------------------------------------------------
GetLenghtC:
       add A,#LenghtC-$-3
       movc A,@A+PC
       ret
LenghtC db GetTimeLen,GetDateLen,SetTimeLen,SetDateLen,SetPowerDownModeLen,ClearPowerDownModeLen
;================================================================
;GET/SEND byte to PIC
; R2-n byte to use
; //R0-buffer ???R0=sp;sp+=R2;???
GetBytePIC:  clr F0
             sjmp GSBytePIC
SendBytePIC: setb F0
GSBytePIC:
             mov R0,xSP
NextGetSendByte:
              mov _R+5,@R0
              inc R5
              clr ET0
;     a) wait 20ms for 0
              mov A,#StartBitWait
              call SetTX2toDataPICa
;        if (timeout) ReInit
AgainWaitEndModeC:
               jnb NoEndSetTimePIC, ReInitPICa
#ifndef _DEBUG
              jb DATAbusPIC, AgainWaitEndModeC
#endif
; Wait First Bit
              jnb F0, GettingBytePIC
               mov A,R5
               rlc A
               mov R5,A
               mov DATABitToPIC, C
               mov A,#FirstBitSendWait
               call SetTX2toDataPICa
               setb ET0
               jb NoEndSetTimePIC,$
               mov A,R5
               rlc A
               mov R5,A
               mov DATABitToPIC, C
               mov A,#SecondBitSendWait
               call SetTX2toDataPIC

;     b) wait X.XXXus get/send bit while(Nbit++<8)
               mov R6,#7
AgainSendBytePIC:
                jb NoEndSetTimePIC,$
                mov A,R5
                rlc A
                mov R5,A
                mov DATABitToPIC, C
                mov A,#NextBitWait
                call SetTX2toDataPIC
               djnz R6,AgainSendBytePIC
               mov A,#StopBitSendWait
               jmp SendingBytePIC

;-----------------
GettingBytePIC:
                mov A,#FirstBitGetWait
                call SetTX2toDataPICa
                mov R6,#8

AgainGetBytePIC:
                jb NoEndSetTimePIC,$
                mov C,DATAbusPIC
                setb ET0
                mov A,R5
                rlc A
                mov R5,A
                mov A,#NextBitWait
                call SetTX2toDataPIC
               djnz R6,AgainGetBytePIC
               mov A,#StopBitGetWait
               dec R5
               mov @R0,_R+5
SendingBytePIC:
               setb DATABitToPIC
               call SetTX2toDataPICa
               jb NoEndSetTimePIC,$
               jnb DATAbusPIC, ReInitPICa
               inc R0
              djnz R2,NextGetSendByte
              mov R0,xSP;_R+1
              ret
ReInitPICa:  pop ACC
             pop ACC
             jmp ReInitPIC
SetTX2toDataPICa:
                clr TR2
                mov B,A
                clr A
                mov TH2,A
                mov TL2,A
                mov A,B
SetTX2toDataPIC:
                clr TR2
                rl A
                mov B,A
                add A,#TableWaitTime-$-3
                movc A,@A+PC
                xch A,B
                add A,#TableWaitTime-$-3+1
                movc A,@A+PC
                add A,TL2
                mov TL2,A
                mov A,B
                addc A,TH2
                mov TH2, A
;                mov NoEndSetTimePIC,C
;                mov T2CON,#0x04
                jc TOverflow
                 setb TR2
                 ret
TOverflow:
                setb TF2
                ret

CopyFromBuffer:  mov R1,_R+0
                 mov R0,Buffer
                 jmp AgainCopyToBuffer
CopyToBuffer:    mov R1,Buffer
AgainCopyToBuffer:
                  mov A,@R0
                  mov @R1,A
                  inc R0
                  inc R1
                 djnz ParamLL,AgainCopyToBuffer
                 ret


TableWaitTime:
;   CallPIC CallFromPIC Wait1ms StartBitWait NextBitWait
;    5.5ms   6.5ms       1ms     20ms         1.1ms
  dw 0xE359, 0xDE24,     0xFAC9, 0x97D4,      0xFA44 ; F0=16MHz
;  dw 0EE18h, 0EAD7h,     0FCBEh, 0BEE5h,      0FC6Bh ; F0=10MHz

;  SecondBitSendWait StopBitGetWait StopBitSendWait FirstBitSendWait
;    0.370ms           1.1ms+0.860ms  2.080ms         0.250
  dw 0xFE11,           0xF5C9,        0xF529,         0xFEB3 ; F0=10MHz
;  dw 0FECBh,           0F99Eh,        0F93Ah,         0FF30h ; F0=10MHz

; FirstBitGetWait
;    0.730ms
  dw 0xFC31    ; F0=10MHz
;  dw 0FD9Fh    ; F0=10MHz

;TX=$10000-F*t/12
;f = Freq
;t = time
;TX=THTL
;ALG: Init
;     1) Set 1 to data, wait 5.5ms
;     2) wait 1ms for 0
;        if (timeout) ReInit
;     3) wait 6.5ms for 1
;        if (timeout) ReInit
;     4) PIC READY!
;        SendByte(command)
;        GetByte()/SendByte() packet
;Get/SendByte
;     a) wait 20ms for 0
;        if (timeout) ReInit
;     b) wait X.XXXus get/send bit while(Nbit++<8)
;        if (timeout) ReInit
;     c) wait 1ms for 1
;        if (timeout) ReInit

 END