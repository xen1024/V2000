/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

         NAME   Timers
         PUBLIC InitTimers
         $DEFFN InitTimers(0,0,0,0,0,0,0,0)

         public SecondOut,KeyPresent,NowKey,LongPressKey,FirstKeyt,\
         EndPressKey,NiceMigDown,DetectingTone,XrlByte,StepTone1,\
         XTone1Lo,XTone1Hi,LinePresent,EndReciveNumeral,RecivedNumeral,\
         ImpulseNumeral,LBell,LBellMin,LBellMax,RepeatLBell,\
         TimeOut1sA,TimeOut4msA,Timer1sA,Timer4msA,Timer4msB,\
         TimeOut4msB,P4,EndTime_snd,StartBell,EndBell,OldBell,\
         DeviderTo2ms,NRazr,NRazrB,VideoBit9,BankPlay,StepTone2,\
         TReload,EndWavPlay,TCXsnd,PauseAfterSayWav,P4IN,MeandrPlay,\
         MelodyPlay,TimerModePIC,t2ms,BankB0,OldLine
         ;,DATABitToPIC
         public Key,OutByte,EndKvantDecode,StartPlay16
         public SoundToLine
         public SndOnKey
         $DEFFN SndOnKey(0,0,0,0,0,0,0,0),SayPhrase ;,SayKey
         public BeepStop
         $DEFFN BeepStop(0,0,0,0,0,0,0,0)
         public BeepStart
         $DEFFN BeepStart(0,0,0,0,0,0,0,0)
         public RequestStart,LineSoundStop
         $DEFFN RequestStart(0,0,0,0,0,0,0,1)
         $DEFFN LineSoundStop(0,0,0,0,0,0,0,0)
         public StartT1_8,StopPlay
         $DEFFN StopPlay(0,0,0,0,0,0,0,0)
         public TestVoice
         $DEFFN TestVoice(0,0,0,0,0,0,0,0)
         public PlaySampleNext
         $DEFFN PlaySampleNext(0,0,0,0,0,0,0,0)
         public StartPlayWav
         $DEFFN StartPlayWav(0,0,0,0,0,0,0,0)
         public SetTimer1msA
         $DEFFN SetTimer1msA(0,0,0,0,0,0,0,0)
         public LineSoundOn,LineSoundOff
         $DEFFN LineSoundOn(0,0,0,0,0,0,0,0)
         $DEFFN LineSoundOff(0,0,0,0,0,0,0,0)
         public BeepLineStart
         $DEFFN BeepLineStart(0,0,0,0,0,0,0,0)
;         public BellPlay
;         $DEFFN BellPlay(0,0,0,0,0,0,0,0)
         public LoadByteBankCDPTR

#define __Timers
$vdef.inc

#ifdef DEBUG
         public Devider250
#endif
          COMMON INTVEC
StartVec:
          ORG    StartVec + 0Bh;Timer 0
          jmp   Timer0a        ;0B

          ORG    StartVec + 1Bh;Timer 1
#ifdef DEBUG_KeyEmulation
 clr TR0
 clr TR1
#endif
          jb DetectingTone,TimerToneDetect
          jb TwoTonesPlay,TwoTonesOuta
          jb WavPlay,TimerVoice
          jb MeandrPlay,MeandrOuta
          jmp   Timer1a        ;1b

          ORG    StartVec + 2Bh
;          clr TR2
          mov T2CON,#0
          jb TimerModePIC, WorkWithPIC
          reti

WorkWithPIC:
             jb DATABitToPIC,SetBitToPIC
              clr DATAbusPIC
              reti
SetBitToPIC:  setb DATAbusPIC
              reti


MeandrOuta: jmp MeandrOut
TwoTonesOuta: jmp TwoTonesOut

#define xLineData8 XTone1Hi
TimerToneDetect:
        mov PushC1,C
        mov C,LineData
        xch A,xLineData8
        rlc A
        jnc NoEndKvantDecode
         mov OutByte,A
         setb EndKvantDecode
         mov A,#0x01
NoEndKvantDecode:
        xch A,xLineData8
;        jc TimerToneDecodea
        mov C,PushC1
        reti
;TimerToneDecodea: jmp TimerToneDecode

;------------------------------------------------------------
;Bank switch functions !!!!!!
          ORG    StartVec + OffsetBankFunctions
ResetBank0:
           clr BankB0
           jmp 0
;------------------------------------------------------------
LoadByteBankCDPTR:  clr A
LoadByteBankCDPTRA: clr EA
                    mov BankB0,C
                    movc A,@A+DPTR
                    inc DPTR
                    clr BankB0
                    setb EA
                    ret
;------------------------------------------------------------
TimerVoice:
                jnb BankPlay,NoPlayingBank1
                 setb BankB0
NoPlayingBank1: push PSW
                push    B                   ;
                xch     A,SamplePosLo       ;
                xch     A,DPL               ;
                xch     A,SamplePosHi       ;
                xch     A,DPH               ;
                xch     A,OutByte           ;
                anl     P4,#3               ;
                orl     A,P4                ;
                mov     P4,A                ;
                movx    @R0,A               ;hP4=OutA|(P4&3);
                clr     A                   ;
                movc    A,@A+DPTR           ;
                mov     B,A                 ;XADR=XMEM[ADDR];
                mov     A,XTone1Lo          ;if (R1!=0)
                jz      X065d               ;
                 add     A,#FastShl1-$-3-1  ;{
                 movc    A,@A+PC            ; XADR=XADRt=High(X6c4[R1]*XMEM[ADDR+1])
                 mov     StepTone2,A        ;        |Low(X6c4[R1]*XMEM[ADDR]);
                 mul     AB                 ;
                 mov     StepTone2+1,A      ;
                 mov     A,#1               ;
                 movc    A,@A+DPTR          ;
                 mov     B,StepTone2        ;
                 mul     AB                 ;
                 mov     A,StepTone2+1      ;}
X065d:          clr BankB0
                orl     A,B                 ;
                mov     StepTone2,DPL       ;
                mov     StepTone2+1,DPH     ;
                mov     DPTR,#SoundUnPackTbl ;
                movc    A,@A+DPTR           ;;//X6c4[XMEM[ADDR]] or X6c4[XADRt]
                mov     DPL,StepTone2       ;
                mov     DPH,StepTone2+1     ;
                mov     B,A                 ;
                anl     A,#7                ;
                inc     A                   ;
                add     A,XTone1Lo          ;R1=X6c4[XADR]&7+R1+1;
                jnb     ACC.3,X0677         ;if (R1&8)
                 anl     A,#7               ;{ R1&=7;                 // R1=00000xxx;
                 inc     DPTR               ;  ADDR++;
X0677:          mov     XTone1Lo,A          ;}
                mov     A,B                 ;
                swap    A                   ;
                anl     A,#0fh              ;A=X6c4[XADR]>>4;     //A=0..7..0xA
                jnb     ACC.3,X0689         ;                     //A=0..7,FF,FE,FD
                                            ;                      +0..7/-1..-3
                 clr     ACC.3              ;if (A&8) A~=A&7;     //A=11111xxx;
                 cpl     A                  ;
X0689:          add     A,XrlByte           ;A=x3eh=x3eh+A;      //
                mov     XrlByte,A           ;
                swap    A                   ;
                rr      A                   ;
                xch     A,OutByte           ;OutA=A.43210765;     //OutA=xXXXXXxx=xxxxxx000
                xch     A,DPH               ;
                xch     A,SamplePosHi       ;
                xch     A,DPL               ;
                xch     A,SamplePosLo       ;
                djnz    WawLenLo,X0680      ;if (LEN--) tr0=fAlse; //end loop
                 djnz    WawLenHi,X0680     ;
                  clr     TR1               ;}
                  setb    EndWavPlay
X0680:                                      ;
                pop     B                   ;while(tr0);
                pop PSW
                reti
FastShl1: db 0x02,0x04,0x08,0x10,0x20,0x40,0x80
;------------------------------------------------------------


         RSEG CODE(0)
; Timer of time
; Parametrs:
;  T = 1ms
;  Freq = 1/T = 1.0kHz
; Variables:
;  Devider5,Devider200
; In-Timer Functions:
;  1) Timer 5ms A
;    T             5ms
;    type  TCX     char
;    max           1275ms(255*5ms)
;    stop          while(--TCX>0)
;    Flags         no set
;  1) Timer 1s A
;    T             1s
;    type TCX      char
;    max           255s/4:15
;    stop          while(--TCX>0)
;    Flags         no set
;  2) Timer 1s X
;    T             1s
;    type TCX      bit
;    stop          while(--TCX>0)
;    Flags         SecondOut
;  3) VideoRefresh
;    Freq [25Hz;100Hz]
;    Freq=TimerFreq/NumbRazr/Devider
;    Freq=1000/9/5=22.2Hz
;    INT           while(--TCX>0)
;  5) Keyboard
;    FreqRepeat=1;2..10;

Timer0a:
#ifdef DEBUG_KeyEmulation
 clr TR0
 clr TR1
#endif
          mov TH0,#HIGH(T0_1ms)
          mov TL0,#LOW(T0_1ms)
          push PSW
          push ACC
          push _R+0
          push DPH
          push DPL
          dec DeviderTo2ms
          mov A,DeviderTo2ms
          xrl A,CurrLightLevel
          jnz NoLightDown
           mov DPTR,#HighVideoAddress<<8
           movx @DPTR,A
NoLightDown:
          mov A,DeviderTo2ms
          jz ?5msOut
          jmp No5msOut
?5msOut:   mov DeviderTo2ms,#9
;*****VideoRefresh {
           inc NRazr
           jb VideoBit9,No9RazrN0
            mov NRazr,#0
No9RazrN0:
           mov C,VideoBit9
           mov A,NRazrB
           rlc A
           mov NRazrB,A
           mov VideoBit9,C
           anl P4,#LOW(~Bit9IndHW)
           jnb VideoBit9,No9RazrN1
            orl P4,#Bit9IndHW
No9RazrN1:
           mov DPH,#HighP4Address
           clr EA                       ;disable interrupts
           mov A,P4
           movx @DPTR,A
           setb EA                      ;enable interrupts

           mov DPH,#HighVideoAddress
           mov A,NRazr
           rl A
           add A,#VideoBuffer
           mov R0,A

           mov A,@R0
           anl A,#0x0F
           mov CurrLightLevel,A

           mov A,@R0
           anl A,#0x30
           cjne A,#MigType1,NoMigType1
            mov A,Devider250
            jnb ACC.7,SetMigLightLevelA
             jmp NoMigType
NoMigType1:
           cjne A,#MigType2,NoMigType2
            mov A,Devider250
            add A,#0x2a
            jnb ACC.6,SetMigLightLevel
             jmp NoMigType
SetMigLightLevelA:
           rr A
           jb NoSecNiceMig,MinLight
SetMigLightLevel:
           rr A
           rr A
           jb ACC.3,NoInvertLight
            cpl A
NoInvertLight:
           anl A,#7
           add A,CurrLightLevel  ;0..7 light high..low
           subb A,NiceMigDown
           jc MinLight
            mov CurrLightLevel,A
            jmp NoMigType
MinLight:   clr A
            jmp OutChar
NoMigType2:
NoMigType:
           mov A,#8
           clr C
           subb A,CurrLightLevel
           mov CurrLightLevel,A
           inc R0
           mov A,@R0
OutChar:   mov DPL,NRazrB
           movx @DPTR,A

;-----VideoRefresh }
;-----Keyboard {
           movx A,@R0
           cpl A
           mov P4IN,A
           anl A,#0xF0
           jz NoKeyPressedNow
            orl A,NRazr
            mov Key,A
NoKeyPressedNow:

           mov A,NRazr              ;if (NRazr==0)
           jnz NoEndScanKey         ;
            mov A,KeyCx1            ;{if (KeyCx1==0&&!KeyPresent)
            jnz NoKeyCxZero         ;
            jb KeyPresent,ExitKeyboard
             mov A,Key              ; {if (Key!=0)
             jz NoKeyPressed        ;
               mov A,Key            ;   { if (NowKey!=Key)
               xrl A,NowKey         ;
               jz NowKeyEQKey       ;
                mov A,NowKey        ;
                jnz EndKeyPressedNow ;
                jb EndPressKey,ExitKeyboard
                 mov RepeatKey,#0    ;     {   RepeatKey=0;
                 mov KeyCx1,#PauseAntiSpark;   KeyCx1=PauseAntiSpark;
                 mov KeyCx2,#StartPause0;      KeyCx2=StartPause0;
                 mov KeySpeed,#StartKeySpeed;  KeySpeed=StartKeySpeed;
                 setb FirstKeyt      ;         FirstKeyt=1
                 clr LongPressKey    ;         LongPressKey=0;
                 jmp NoNowKeyEQKey   ;     }
NowKeyEQKey:                        ;     else
                mov A,KeyCx2        ;       if (KeyCx2!=0)
                jz NoWaitBeforeKey  ;
                 dec KeyCx2         ;         KeyCx2--;
                 jmp ExitKeyboard   ;       else
NoWaitBeforeKey:                    ;
                 mov A,KeySpeed     ;       {  KeyCx2=KeySpeed;
                 mov KeyCx2,A       ;
                 xrl A,#MinKeySpeed ;          if (KeySpeed!=MinKeySpeed)
                 jz MinSpeedIsSet   ;
                  %subC KeySpeed,DecreaseSpeed;  KeySpeed-=DecreaseSpeed
MinSpeedIsSet:
                 mov A,RepeatKey    ;         if (RepeatKey!=0xFF)
                 inc A              ;
                 jz MaxRepeatKeyIsSet;
                  mov RepeatKey,A   ;           RepeatKey++;
                  xrl A,#LongRepeatKey;         if (RepeatKey==LongRepeatKey)
                  jnz NoRepeatEQLongRepeatKey;
                   setb LongPressKey;              LongPressKey=1;
MaxRepeatKeyIsSet:                  ;
NoRepeatEQLongRepeatKey:            ;       }
NoNowKeyEQKey:   setb KeyPresent    ;     KeyPresent=1;
                 mov NowKey,Key     ;     NowKey=Key;
                 jmp ExitKeyboard   ;   }
NoKeyPressed:                       ;  else
               mov A,NowKey         ;   if (OldKey!=0)
               jz ExitKeyboard      ;
EndKeyPressedNow:
                setb EndPressKey    ;   { EndPressKey=1;
                mov KeyCx2,#0       ;     KeyCx2=0;
                mov NowKey,#0       ;     NowKey=0;
                jmp ExitKeyboard    ;   }
NoKeyCxZero:                        ; }
           dec KeyCx1               ; else KeyCx1--;
ExitKeyboard:                       ;
           mov Key,#0               ;Key=0;
NoEndScanKey:

;-----Keyboard }
DefaultTimeOutLineDetect = 50
DefaultTimeImpulseDetect = 50
PauseTimeImpulse = 125
DefaultBellTimeDetect = 50
StartNumberBell = 3
#define TimeImpulseDetect TimeOutLineDetect
;-----LineOper {
;             setb Line
                jnb LinePresent,NoTestLinePresent
;########## Line Off Detect
                 jb Line,LineNowPresentA
                  clr OldLine
                  djnz TimeOutLineDetect,NextTestLinePresent
                   clr LinePresent
                   mov TimeImpulseDetect,#PauseTimeImpulse
                   mov ImpulseNumeral,#0
                   jmp ExitTestLine
LineNowPresentA:  setb OldLine
                  mov TimeOutLineDetect,#DefaultTimeOutLineDetect
NextTestLinePresent:
;########## Bell Detect
                 jnb Bell,NoBellNow
                  setb OldBell
                  jmp NoChangedBell
NoBellNow:
                  jnb OldBell,NoChangedBell
                   clr OldBell

                   mov A,LBell
                   clr C
                   subb A,LBellMin
                   jc NoLBellInLimit
;                    mov A,LBell
;                    subb A,LBellMax
;                    jnc NoLBellInLimit

                     mov A,RepeatLBell
                     inc A
                     jz NoLBellInLimit
                      mov RepeatLBell,A
                      xrl A,#StartNumberBell
                      jnz LBellInLimit
                       setb StartBell
                       jmp LBellInLimit
NoLBellInLimit:
                  mov A,RepeatLBell
                  jz LBellInLimit
                   mov RepeatLBell,#0
                   setb EndBell
LBellInLimit:
                  mov LBell,#0
NoChangedBell:
                  inc LBell
                  mov A,LBell
                  xrl A,LBellMax
                  jz NoLBellInLimit

                 jmp ExitTestLine
;########## Impulse Detect
NoTestLinePresent:
                 jb Line,LineNowPresentB
                  jnb OldLine,NoLineChanged
                   clr OldLine
                   mov TimeImpulseDetect,#DefaultTimeImpulseDetect
                   inc ImpulseNumeral
                   mov A,ImpulseNumeral
                   cjne A,#11,NoLineChanged
                    dec ImpulseNumeral
                    jmp NoLineChanged
LineNowPresentB:  jb OldLine,NoLineChanged
                   setb OldLine
                   mov TimeImpulseDetect,#PauseTimeImpulse
NoLineChanged:

;##########
ExitTestLine:
;              }

;*****TimeOper

           jbc t2ms,No1sOut
            setb t2ms
;*****Timer 4ms {
            mov A,Timer4msA
            jz NoOutTimer4msA
             djnz Timer4msA,NoOutTimer4msA
              setb TimeOut4msA
NoOutTimer4msA:
            mov A,Timer4msB
            jz NoOutTimer4msB
             djnz Timer4msB,NoOutTimer4msB
              setb TimeOut4msB
NoOutTimer4msB:
;-----Timer 4ms }

                jb LinePresent,NoTimeOutLineDetect
                 djnz TimeImpulseDetect,NoTimeOutLineDetect
                  jnb OldLine,NoNowLineIsPresent
                   setb LinePresent
                   mov TimeOutLineDetect,#DefaultTimeOutLineDetect
                   jmp NoTimeOutLineDetect
NoNowLineIsPresent:mov A,ImpulseNumeral
                   jz NoNumeralRecived
                    jb PipeUp,NoNumeralRecived
                     setb EndReciveNumeral
                     cjne A,#10,NoNumeralIsZero
                      clr A
NoNumeralIsZero:     mov RecivedNumeral,A
NoNumeralRecived:  mov ImpulseNumeral,#0
                   mov TimeImpulseDetect,#DefaultTimeImpulseDetect
NoTimeOutLineDetect:
;--------Sound off timer
            jb EndTime_snd,NoEndTimeSnd
             djnz TCXsnd,NoEndTimeSnd
              djnz TCXsnd+1,NoEndTimeSnd
               setb EndTime_snd
               jb MelodyPlay,NoEndTimeSnd
               clr TR1
               jnb SpeakerOn,NoSpeakerOnSA
                %setbit Amplifer,AmpliferOn
                %setbit Sound,SetSoundOff
                jmp NoEndTimeSnd
NoSpeakerOnSA:
               jnb Snd,_NoEndTimeSnd
                %setbit Amplifer,AmpliferOn
                %setbit Sound,SetSoundOn
                jmp NoEndTimeSnd
_NoEndTimeSnd:  %setbit Amplifer,AmpliferOff
NoEndTimeSnd:

            djnz Devider250,No1sOut
             mov Devider250,#251;250
;*****Timer 1s X {
             setb SecondOut
;-----Timer 1s X }
;*****Timer 1s A {
            mov A,Timer1sA
            jz NoOutTimerA
             djnz Timer1sA,NoOutTimerA
              setb TimeOut1sA
NoOutTimerA:
;-----Timer 1s A }

No1sOut:
No5msOut:
          pop DPL
          pop DPH
          pop _R+0
          pop ACC
          pop PSW
          reti
Timer1a:
          mov TH1,TReload
          mov TL1,TReload+1
          djnz TCXsnd+1,NoTimeOutTimer1a
           djnz TCXsnd,NoTimeOutTimer1a
            clr TR1
;            jnb WavPlaying,NoTimePausing
            setb EndWavPlay
;NoTimePausing:
NoTimeOutTimer1a:
          reti
;-----------------------------------------------------------
;Meandr Play
;-----------------------------------------------------------
MeandrOut:
        mov     TH1,TReload
        mov     TL1,TReload+1
        xch     A,P4
        xrl     A,XrlByte
        movx    @R0,A
        xch     A,P4
        reti
;-----------------------------------------------------------
;2 tones play
;-----------------------------------------------------------
#define XTone2Lo TReload+1
#define XTone2Hi TReload
TwoTonesOut:
        push    PSW
        xch     A,OutByte
        anl     A,#0fch
        anl     P4,#3
        orl     A,P4
        movx    @r0,A
        mov     P4,A

        mov     A,XTone1Lo
        add     A,StepTone1
        mov     XTone1Lo,A
        mov     A,XTone1Hi
        addc    A,StepTone1+1
        mov     XTone1Hi,A
        jbc     ACC.7,InvertTone1
         add     A,#HalfSin-$-3
         movc    A,@A+PC
NextTone1:
        mov     XrlByte,A
        mov     A,XTone2Lo
        add     A,StepTone2
        mov     XTone2Lo,A
        mov     A,XTone2Hi
        addc    A,StepTone2+1
        mov     XTone2Hi,A
        jbc     ACC.7,InvertTone2
         add     A,#HalfSin-$-3
         movc    A,@A+PC
NextTone2:
        add     a,XrlByte
        xch     a,OutByte
        pop     PSW
        reti

InvertTone2:
        add     A,#HalfSin-$-3
        movc    A,@A+PC
        xrl     A,#7fh
        sjmp    NextTone2

InvertTone1:
        add     A,#HalfSin-$-3
        movc    A,@A+PC
        xrl     A,#7fh
        sjmp    NextTone1

HalfSin:
 db 0x40,0x41,0x43,0x44,0x46,0x47,0x49,0x4A,0x4C,0x4D,0x4F,0x50,0x52,0x53,0x55,0x56
 db 0x58,0x59,0x5B,0x5C,0x5D,0x5F,0x60,0x61,0x63,0x64,0x65,0x67,0x68,0x69,0x6A,0x6B
 db 0x6C,0x6D,0x6F,0x70,0x71,0x72,0x73,0x73,0x74,0x75,0x76,0x77,0x78,0x78,0x79,0x7A
 db 0x7A,0x7B,0x7B,0x7C,0x7C,0x7D,0x7D,0x7D,0x7E,0x7E,0x7E,0x7F,0x7F,0x7F,0x7F,0x7F
 db 0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7E,0x7E,0x7E,0x7D,0x7D,0x7D,0x7C,0x7C,0x7B,0x7B
 db 0x7A,0x7A,0x79,0x78,0x78,0x77,0x76,0x75,0x74,0x73,0x73,0x72,0x71,0x70,0x6F,0x6D
 db 0x6C,0x6B,0x6A,0x69,0x68,0x67,0x65,0x64,0x63,0x61,0x60,0x5F,0x5D,0x5C,0x5B,0x59
 db 0x58,0x56,0x55,0x53,0x52,0x50,0x4F,0x4D,0x4C,0x4A,0x49,0x47,0x46,0x44,0x43,0x41

;-----------------------------------------------------------
;Init Timers
;Out: T0 on  16bit I_on P_low
;     T1 off 8bit  I_on P_high
;     T2 off       I_on P_low
;-----------------------------------------------------------
InitTimers:
            clr A
            mov TMOD,A
            mov NRazr,A
            mov Key,A
            mov NowKey,A
            clr VideoBit9
            clr NoSecNiceMig
            mov NRazrB,#0xFF
            mov DeviderTo2ms,#5
            mov Devider250,#250
            mov NiceMigDown,#MaxLight
            clr EndPressKey
            clr KeyPresent
            clr Snd

            clr LinePresent
            mov TimeImpulseDetect,#PauseTimeImpulse

            mov TH0,#HIGH(T0_1ms)
            mov TL0,#LOW(T0_1ms)
            mov T2CON,#0
            mov IP,#11101000b
            mov TMOD,#21h
            mov TCON,#10h
            mov IE,#11101010b
;            mov TH0,#0xFF
;            mov TL0,#0xFF
            ret


;-----------------------------------------------------------
StopPlay:jnb Snd,NoSoundOnNow
          %setbit Amplifer,AmpliferOn
          %setbit Sound,SetSoundOn
          jmp NextStopPlay
NoSoundOnNow:
          %setbit Amplifer,AmpliferOff
NextStopPlay:
         jnb SpeakerOn,NoSpeakerOnS
          %setbit Amplifer,AmpliferOn
          %setbit Sound,SetSoundOff
NoSpeakerOnS:
StopT1:  clr TR1
         jnb MeandrPlay,NoMeandrPlayed
          mov A,XrlByte
          cjne A,#P4KZ|P4MaxLevelSnd,NoMeandrPlayed
           anl P4,#Low(~P4KZ)
           mov A,P4
           movx @R0,A
NoMeandrPlayed:
         clr MeandrPlay
         clr TwoTonesPlay
         clr DetectingTone
         clr WavPlay
;         clr WavPlaying
         clr EndWavPlay
         clr MelodyPlay
         ret
StartPlay16:
          call SetSoundPlay
StartT1_16P:
          mov P2,#HighP4Address
StartT1_16:
          mov TL1,#0xFF
          mov TH1,#0xFF
          mov TMOD,#11h
          setb TR1
          ret

StartPlay8:
          call SetSoundPlay
StartT1_8P:
          mov P2,#HighP4Address
StartT1_8:
          mov TL1,#0xFF
          mov TMOD,#21h
          setb TR1
          ret
SetSoundPlay:%setbit Sound,SetSoundOff
             jnb SoundToLine,NoPlayingSoundToLine
              %setbit Amplifer,AmpliferOff
              ret
NoPlayingSoundToLine:
              %setbit Amplifer,AmpliferOn
              ret
;-----------------------------------------------------------
;Init to play meandr
;-----------------------------------------------------------
InitToMeandr:
             mov A,ParamHL
             rl A
             rl A
             anl A,#0xFC
             mov XrlByte,A
             mov A,ParamLL
             cpl A
             mov TReload+1,A
             mov A,ParamLH
             cpl A
             mov TReload,A
             anl P4,#0x03
             setb MeandrPlay
             ret
;-----------------------------------------------------------
;Init to 2 tones play
;-----------------------------------------------------------
InitTo2TonesPlay:
              clr A
              mov XTone1Lo,A
              mov XTone1Hi,A
              mov XTone2Lo,A
              mov XTone2Hi,A
              mov TH1,#Tone_f0
              setb TwoTonesPlay
              ret
;-----------------------------------------------------------
;Init to beeper play
;-----------------------------------------------------------
InitToBeeperPlay:
              mov A,ParamLL
              dec A
              cjne A,#3*3+1+1,NoPristonTone
               inc A
NoPristonTone:jnz No0Tone
               mov A,#3*3+1+1
No0Tone:
              dec A
              mov B,#3
              div AB
              rl A

              mov ParamLL,A
              add A,#FreqTableY-$-3
              movc A,@A+PC
              mov StepTone1+1,A
              mov A,ParamLL
              add A,#FreqTableY-$-3+1
              movc A,@A+PC
              mov StepTone1,A

              mov A,B
              rl A
              add A,#FreqTableX-$-3
              movc A,@A+PC
              mov StepTone2+1,A
              mov A,B
              rl A
              add A,#FreqTableX-$-3+1
              movc A,@A+PC
              mov StepTone2,A
              jmp InitTo2TonesPlay
;              ret
FreqTableX: dw xf0,xf1,xf2
FreqTableY: dw yf0,yf1,yf2,yf3

;-----------------------------------------------------------
BeepStart: setb EndTime_snd
           setb DontPlaySounds
           call LineSoundOn
           call StopPlay
           call InitToBeeperPlay
           call StartPlay8
           jb AutoDial,NoOnSnd
            %setbit Amplifer,AmpliferOn
NoOnSnd:   ret
;-----------------------------------------------------------
BeepStop: clr DontPlaySounds
          call StopPlay
          call LineSoundOff
          ret
;-----------------------------------------------------------
;Generate sound on key
;-----------------------------------------------------------
BeepOnKey:
        clr PlayExitSound
        %setbit Sound,SetSoundOff
        call StopPlay
        mov TCXsnd,#Low(LenBeepKey)+1
        mov TCXsnd+1,#High(LenBeepKey)+1
        clr EndTime_snd
        push ParamLLd
        mov ParamLL,#oTypeKeyBeep
        call LoadValueN
        mov A,ParamLL
        pop ParamLLd
        jz  NoPlayKeyMode
        cjne A,#tkb1tone,NoPlayKeyMode1
         mov ParamLL,#MaxPlayKey-1
         inc A
NoPlayKeyMode1:
        cjne A,#tkb2tone,NoPlayKeyMode2
         mov A,ParamLL
         mov B,#StepSquareFreq
         mul AB
         mov DPTR,#StartSquareFreq
         call AddDPTR_BA
         mov ParamLL,DPL
         mov ParamLH,DPH
         mov ParamHL,#0x3F

         call InitToMeandr
         call StartPlay16
         ret
NoPlayKeyMode2:
        cjne A,#tkbBeeper,NoPlayKeyMode3
         call InitToBeeperPlay
         call StartPlay8
         ret
NoPlayKeyMode3:

        mov ParamLH,#eNone
        mov ParamHH,A
        mov A,Event
;ExitSound
        setb PlayExitSound
        cjne A,#eNone,NoPlayExitSound
         clr PlayExitSound
NoPlayExitSound:
;SubmitSound
        cjne A,#eSubmitMode,NoSubmitSound0
SubmitSound:
         mov ParamLL,#phrS2
         jmp XXXSayPhrase
NoSubmitSound0:
        cjne A,#eResetAll,NoSubmitSound1
         jmp SubmitSound
NoSubmitSound1:
        cjne A,#eReset,NoSubmitSound2
         jmp SubmitSound
NoSubmitSound2:
        cjne A,#eClearBook,NoSubmitSound3
         jmp SubmitSound
NoSubmitSound3:
        cjne A,#eDeleteNumber,NoSubmitSound4
         jmp SubmitSound
NoSubmitSound4:
        cjne A,#eSubmitClearPropAllNumber,NoSubmitSound5
         jmp SubmitSound
NoSubmitSound5:


        mov A,ParamHH

        cjne A,#tkbWav0,NoPlayKeyMode4
         mov ParamLL,#phrS0
XXXSayPhrase:
         call SayPhrase
         clr PauseAfterSayWav
         ret
NoPlayKeyMode4:
        cjne A,#tkbWav1,NoPlayKeyMode5
PlayKeyMode5:
         mov ParamLL,#phrS1
         jmp XXXSayPhrase
NoPlayKeyMode5:
        cjne A,#tkbSayKeys,NoPlayKeyMode6
;         mov R0,#WavData
;         mov @R0,ParamLLd
;         dec @R0
         setb SayNumeralAfterBeep
         mov ParamLL,#phrS1
         jmp PlayKeyMode5
NoPlayKeyMode6:
NoPlayKeyMode:
        ret
;------------------------------------------------------------
;Play sound on key present
;In: ParamLL - Key
;------------------------------------------------------------
SndOnKey:
        jb DontPlaySounds,NoPlayNowOnKeyPressed
        jnb PlayOnKeyEvent,NoPlayNowOnKeyPressed
         mov A,ParamLL
         cjne A,#kfExtendedKey,$+3
         jc NoExtendedKey
          add A,#-kfExtendedKey
NoExtendedKey:
         cjne A,#MaxPlayKey+1,$+3
         jc NoMaxKeyPlay
          mov C,ACC.0
          mov A,#MaxPlayKey-1
          addc A,#0
NoMaxKeyPlay:
         mov ParamLL,A
         call BeepOnKey
NoPlayNowOnKeyPressed:
        ret

;------------------------------------------------------------
#define ListeningLine $LOCBB RequestStart
RequestStart:
             push ParamLLd
             call StopPlay
             call LineSoundOn
             setb EndTime_snd
             mov A,ParamLL
             anl A,#1
             jnz RequestIsSine
              mov ParamLL,#Low(TXSquare500Hz)     ;Square
              mov ParamLH,#High(TXSquare500Hz)
              mov ParamHL,#0
              call InitToMeandr
              mov XrlByte,#P4KZ|P4MaxLevelSnd
              call StartPlay16
              jmp RequestIsSquare
RequestIsSine:
              call InitTo2TonesPlay               ;Sine
              mov ParamLL,#Low(RequestStep500Hz)
              mov ParamLH,#High(RequestStep500Hz)
              mov StepTone1,ParamLL
              mov StepTone2,ParamLL
              mov StepTone1+1,ParamLH
              mov StepTone2+1,ParamLH
              mov TH1,#TXSine500Hz
              call StartPlay8
RequestIsSquare:
             pop ParamLLd
             mov A,ParamLL
             jnb ACC.1,NoChangeRequestForm
              cpl ACC.0
NoChangeRequestForm:
             mov ParamLL,A
             jnb ListeningLine,NoLineListening
              %setbit Amplifer,AmpliferOn
NoLineListening:
             ret
;------------------------------------------------------------
LineSoundStop: call LineSoundOff
               call StopT1
               ret
;------------------------------------------------------------
LineSoundOn: %setbit SndToLine,SndToLineOn
             setb SoundToLine
             ret
;------------------------------------------------------------
LineSoundOff: %setbit SndToLine,SndToLineOff
              clr SoundToLine
              ret
;------------------------------------------------------------
;void BeepLineStart(void);
;Beep out to line in beep emulation
;------------------------------------------------------------
BeepLineStart:setb EndTime_snd
              call StopPlay
              mov ParamLL,#oBeepLineFreq
              call LoadValueN
              mov A,ParamLL
              rr A
              rr A
              anl A,#0xE0
              add A,#Low(BeepLineFreq)
              mov ParamHL,A
              mov A,ParamLL
              rr A
              rr A
              anl A,#0x1f
              addc A,#High(BeepLineFreq)
              mov ParamHH,A
              call InitTo2TonesPlay
              mov StepTone1,ParamHL
              mov StepTone2,ParamHL
              mov StepTone1+1,ParamHH
              mov StepTone2+1,ParamHH
              mov TH1,#TXSine500Hz
              call StartPlay8
              ret
;------------------------------------------------------------
;;#define ToneBellPlay1 0x1000
;;#define ToneBellPlay2 0x1000
;BellPlay:call StopPlay
;;         call InitTo2TonesPlay
;;         mov StepTone1,#Low(ToneBellPlay1)
;;         mov StepTone2,#Low(ToneBellPlay2)
;;         mov StepTone1+1,#High(ToneBellPlay1)
;;         mov StepTone2+1,#High(ToneBellPlay2)
;;         mov TH1,#TXSine500Hz
;;         call StartPlay8
;         clr EndTime_snd
;         mov TCXsnd,#Low(LenBeepKey+100)+1
;         mov TCXsnd+1,#High(LenBeepKey+100)+1
;         mov ParamLL,#Low(StartSquareFreq+200)
;         mov ParamLH,#High(StartSquareFreq+200)
;         mov ParamHL,#0x3F
;
;         call InitToMeandr
;         call StartPlay16
;         ret
;------------------------------------------------------------
TestVoice:
;           call StopPlay
;
;           mov R0,#VideoBuffer+1
;           mov @R0,#0
;AAATestVoice:
;
;           mov R0,#VideoBuffer+1
;           mov A,@R0
;
;           clr C
;           rlc A
;           mov B,#0
;           mov B.0,C
;           mov DPTR,#SoundsTable
;           call AddDPTR_BA
;           call GetDPTR_BA
;           mov DPL,A
;           mov DPH,B
;
;           clr A
;           movc A,@A+DPTR
;           inc DPTR
;           mov C,ACC.0
;           mov BankPlay,C
;           call GetDPTR_BA
;           mov DPL,A
;           mov DPH,B
;
;           mov OutByte,#0x80
;           mov XrlByte,#0x0F
;           mov XTone1Lo,#0
;
;           mov C,BankPlay
;           call LoadByteBankCDPTR
;           inc A
;           mov TReload,A
;           mov C,BankPlay
;           call LoadByteBankCDPTR
;           inc A
;           mov TReload+1,A
;
;           mov StepTone1+1,DPL
;           mov StepTone1,DPH
;           mov P2,#HighP4Address
;
;           mov R0,#VideoBuffer+3
;           mov @R0,TReload
;           inc R0
;           inc R0
;           mov @R0,TReload+1
;           inc R0
;           inc R0
;           clr A
;           mov C,BankPlay
;           mov ACC.7,C
;           mov @R0,A
;           inc R0
;           inc R0
;           mov @R0,StepTone1
;           inc R0
;           inc R0
;           mov @R0,StepTone1+1
;
;           setb WavPlay
;           mov TH1,#TXwav
;           setb EndTime_snd
;           call StartPlay8
;
;           jb TR1,$
;
;           mov R0,#VideoBuffer+1
;           inc @R0
;           cjne @R0,#65,NNNNNNNN
;            ret
;NNNNNNNN:
;           jmp AAATestVoice
           ret
;------------------------------------------------------------
StartPlayWav:   call StopPlay
                mov A,ParamLL
                clr C
                rlc A
                mov B,#0
                mov B.0,C
                mov DPTR,#SoundsTable
                call AddDPTR_BA
                call GetDPTR_BA
                mov PosDataSoundLo,A
                mov PosDataSoundHi,B

;                setb WavPlaying
                call PlaySampleNext
                ret

;------------------------------------------------------------
PlaySampleNext:
                mov ParamLL,#oSpeedOfVoice
                call LoadValueN
                mov A,ParamLL
                mov B,#7
                mul AB
                add A,#TXwav
                mov TH1,A

                clr EndWavPlay
                mov DPL,PosDataSoundLo
                mov DPH,PosDataSoundHi
                setb EndTime_snd
; mov DPTR,#0x8D97-2-3
                clr A
                movc A,@A+DPTR
                cjne A,#dtsndEndSound,NoEndSoundPlaying
                 mov A,#Low(LenPauseAfterSayWav)
                 mov B,#High(LenPauseAfterSayWav)
                 jbc PauseAfterSayWav,PauseWPlaying
;                 inc DPTR
                 setb C
                 jmp ExitPlaySampleNext
NoEndSoundPlaying:
                inc DPTR
                cjne A,#dtsndPauseB,NoPauseBPlaying
                 clr A
                 mov B,A
                 movc A,@A+DPTR
                 inc DPTR
PauseWPlaying:   call StartTimer1msA
                 jmp ExitPlaySampleNext
NoPauseBPlaying:
                cjne A,#dtsndPauseW,NoPauseWPlaying
                 call GetDPTR_BA
                 jmp PauseWPlaying
NoPauseWPlaying:
                 mov C,ACC.0
                 mov BankPlay,C
                 call GetDPTR_BA          ;GetSampleAddress
                 call XchDP_VA
                 mov DPL,A
                 mov DPH,B

                 mov OutByte,#0x80
                 mov XrlByte,#0x0F
                 mov XTone1Lo,#0

                 mov C,BankPlay           ;GetSampleLen
                 call LoadByteBankCDPTR
                 inc A
                 mov WawLenHi,A
                 mov C,BankPlay
                 call LoadByteBankCDPTR
                 inc A
                 mov WawLenLo,A
                 mov SamplePosLo,DPL
                 mov SamplePosHi,DPH

                 setb WavPlay
;                 mov TH1,#TXwav
                 call StartPlay8
                 call XchDP_VA
                 clr C

ExitPlaySampleNext:
                 mov PosDataSoundLo,DPL
                 mov PosDataSoundHi,DPH
                 ret

;------------------------------------------------------------
SetTimer1msA:    mov A,ParamLL
                 mov B,ParamLH
StartTimer1msA:  call StopT1
                 inc A
                 mov TCXsnd+1,A
                 inc B
                 mov TCXsnd,B
                 mov TReload+1,#Low(TX1ms)
                 mov TReload,#High(TX1ms)
                 call StartT1_16
                 clr EndWavPlay
                 ret
;------------------------------------------------------------

        RSEG D_UDATA
DeviderTo2ms:   DS 1
Devider250:     DS 1
Timer1sA:       DS 1
Timer4msA:      DS 1
Timer4msB:      DS 1
NRazrB:         DS 1
NRazr:          DS 1
P4:             DS 1
CurrLightLevel: DS 1
NiceMigDown:    DS 1

Key:            DS 1
KeyCx1:         DS 1
KeyCx2:         DS 1
KeySpeed:       DS 1
RepeatKey:      DS 1
NowKey:         DS 1

                     ;M 2T DT W       MP
TCXsnd:         DS 2 ;+ -  -  -        +
OutByte:        DS 1 ;+ +     +
XrlByte:        DS 1 ;+ +     +        +
TReload:        DS 2 ;-       +        +
StepTone1:      DS 2 ;-       +        +
StepTone2:      DS 2 ;-       +        +
XTone1Lo:       DS 1 ;-       +        +
XTone1Hi:       DS 1 ;-       -        +

TimeOutLineDetect: DS 1
ImpulseNumeral:    DS 1
RecivedNumeral:    DS 1

LBell:         DS 1
LBellMin:      DS 1
LBellMax:      DS 1
RepeatLBell:   DS 1
        RSEG BITVARS
SecondOut:    DS 1
VideoBit9:    DS 1
t2ms:         DS 1
NoSecNiceMig: DS 1
FirstKeyt:    DS 1
EndPressKey:  DS 1
LongPressKey: DS 1
KeyPresent:   DS 1

DetectingTone: DS 1
TwoTonesPlay:  DS 1
WavPlay:       DS 1
MeandrPlay:    DS 1
EndTime_snd:   DS 1

EndKvantDecode: DS 1

LinePresent: DS 1
OldLine:     DS 1
EndReciveNumeral: DS 1

OldBell:   DS 1
StartBell: DS 1
EndBell:   DS 1

TimeOut1sA:  DS 1
TimeOut4msA: DS 1
TimeOut4msB: DS 1
BankPlay: DS 1          ;Wav
EndWavPlay: DS 1
;WavPlaying: DS 1
PauseAfterSayWav: DS 1  ;Wav
SoundToLine: DS 1
MelodyPlay: DS 1

;DATABitToPIC: DS 1
TimerModePIC: DS 1
        RSEG BYTESEG
P4IN:   DS 1
 END