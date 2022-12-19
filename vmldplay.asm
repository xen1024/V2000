/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

        name Melody
        rseg CODE
        public TestMelody
        $DEFFN TestMelody(0,0,0,0,0,0,0,0)
        public NextNotePlay
        $DEFFN NextNotePlay(0,0,0,0,0,0,0,0)
        public StartMelodyA
        $DEFFN StartMelodyA(0,0,0,0,0,0,0,0)
        public VolumeUp
        $DEFFN VolumeUp(0,0,0,0,0,0,0,0)
$vdef.inc

#define RB0R1 0x1
;Melody play
TestMelody:
        mov ParamLL,#0
        call StartMelodyA
        ret
;----------------------------------------------------------------
;StartMelody
;----------------------------------------------------------------
StartMelodyA:
        call StopPlay
        mov A,ParamLH
        inc A
        jz NoSetNewVolume
         dec A
         rl A
         rl A
         anl A,#0xFC
         mov XrlByte,A
NoSetNewVolume:
        setb MeandrPlay
        setb MelodyPlay

        mov A,ParamLL
        jnz NoRandomMelody
         mov A,TL0
         add A,TL1
         add A,TL2
         mov B,#MaxMelodyPlay
         div AB
         mov A,B
         inc A
NoRandomMelody:
        dec A
        mov     DPTR,#MelodyTbl         ;MelodyTable
        rl      A
        lcall   X39EC                   ;GETDPTR(A)
        mov     R1,#0xFF
        setb    F2E_7


NextCurrMelodyPlay:
        mov StepTone1,DPH
        mov StepTone1+1,DPL
        lcall   X39EB                   ;GETDPTR(0)
        clr     A
        movc    A,@A+DPTR
        mov     ParamLH,A
        clr     MF0

NextNotePlayA:
;        mov A,DPL
;        cjne A,#Low(ZZZZ),$+3
;        mov A,DPH
;        subb A,#High(ZZZZ)
;        jnc $
        inc     DPTR
        mov     A,#1
        movc    A,@A+DPTR
        mov     R0,A
        clr     A
        movc    A,@A+DPTR
        mov     ParamLL,A
        jnb     MF0,X0C83
         inc     ParamHL
         mov     A,ParamHL
         dec     A
         jz      X0C75
         dec     A
         jz      X0C67
         dec     A
         jz      X0C5B
          mov     ParamHL,#0          ;A=(ParamLL>>2)
          mov     A,ParamLL
          anl     A,#0FCH
          rr      A
          rr      A
          sjmp    X0C79

X0C5B:  mov     A,ParamLL             ;A=(R4>>4)|((R0&3)<<4)
        swap    A
        anl     A,#0FH
        mov     R2,A
        mov     A,R0
        swap    A
        anl     A,#30H
        orl     A,R2
        sjmp    X0C79

X0C67:  mov     A,ParamLL             ;A=(R4>>6)|((R0&0xF)<<2)
        rl      A
        rl      A
        anl     A,#3
        mov     R2,A
        mov     A,R0
        rl      A
        rl      A
        anl     A,#3CH
        orl     A,R2
        sjmp    X0C79
;
X0C75:  lcall   DecDPTR           ;DECDPTR
        mov     A,ParamLL
X0C79:  jnz     X0C83
         clr     MF0
         inc     DPTR
         movc    A,@A+DPTR
         jnz     X0C83
          inc     DPTR
          movc    A,@A+DPTR
X0C83:  cjne    A,#0FFH,X0CB4
         mov     R1,#0FFH
         ljmp    EndCurrMelodyPlay
X0CB4:  mov     ParamLL,A
        cjne    A,#3DH,X0CBC
         setb    F2E_7
         jmp    NextNotePlayA
X0CBC:  cjne    A,#3EH,X0CC3
         clr     F2E_7
         sjmp    NextNotePlayA
X0CC3:  cjne    A,#3FH,X0CCD
         setb    MF0
         mov     ParamHL,#0
         ljmp    X0D5E
X0CCD:  mov     R0,DPH
        mov     R2,DPL
        anl     A,#3FH
        cjne    A,#3CH,X0CF2
         clr TR1
         setb F0
         mov     R1,#0FFH
         sjmp    PausePlayN ;X0D2F
X0CF2:  mov     B,#0CH
        div     AB
        inc     A
        xch     A,B
        anl     A,#0FH
        cjne    A,RB0R1,X0D00
         sjmp    X0D2F
X0D00:  mov     R1,A
        rl      A
        mov     DPTR,#MTBL2 ;0937DH
        lcall   X39EC
AgainShrD:
         mov     A,DPH
         clr     C
         rrc     A
         mov     DPH,A
         mov     A,DPL
         rrc     A
         mov     DPL,A
        djnz    B,AgainShrD
        cpl     A
        mov     TReload+1,A
        mov     A,DPH
        cpl     A
        mov     TReload,A                 ;ParamHL7=~(ROM[937D+A]>>B)

X0D2F:  clr F0
PausePlayN:
        mov     DPL,R2
        mov     DPH,R0
        mov     A,ParamLL
        jnb     MF0,X0D48
         mov     A,ParamHH
X0D48:  anl     A,#0C0H
        mov     ParamHH,A
        rl      A
        rl      A                        ;A=(A>>6)+1; //(1..5)
        inc     A
;        mov     R0,A
        mov B,A
        mov A,ParamLH
        rl A
        swap A
        anl A,#0x1F
        add A,ParamLH
        mul AB
        xch A,B
        rrc A
        anl A,#0x7F
        xch A,B
        rrc A                            ;temp<<

        clr EndTime_snd
        inc B
        mov TCXsnd+1,B
        inc A
        mov TCXsnd,A
        jb F0,PausePlayingNote
         jb TR1,PausePlayingNote
          anl P4,#0x03
          call StartPlay16
PausePlayingNote:
;        jnb EndTime_snd,$


;uint MelodyAddress
;uint MelodyPosition
;uchar R1,R6
;bit MF0,
;Idle Enter
        mov StepTone2,DPH
        mov StepTone2+1,DPL
        mov XTone1Lo,R1
        mov XTone1Hi,ParamHL
        mov OutByte,ParamHH
        mov R0,#NPhrase
        mov @R0,ParamLHd
        clr C
        ret

;----------------------------------------------------------------
;Idle Leave
NextNotePlay:
        mov DPH,StepTone2
        mov DPL,StepTone2+1
        mov R1,XTone1Lo
        mov ParamHL,XTone1Hi
        mov ParamHH,OutByte
        mov R0,#NPhrase
        mov ParamLHd,@R0

        jnb     F2E_7,X0D60
X0D5E:   mov     R1,#0FFH
X0D60:  jmp    NextNotePlayA

EndCurrMelodyPlay:
        mov DPH,StepTone1
        mov DPL,StepTone1+1
        inc     DPTR
        inc     DPTR
        clr     A
        movc    A,@A+DPTR
        cjne A,#0xFF,NoCMelodyAddressFFFF
         mov     A,#1
         movc    A,@A+DPTR
         cjne A,#0xFF,NoCMelodyAddressFFFF
          call StopPlay                     ;Exit
          setb C
          ret
NoCMelodyAddressFFFF:
        jmp    NextCurrMelodyPlay         ;NextMelodyPlay

;out: dptr=ROM[DPTR]
;out: dptr=ROM[DPTR+A]
X39EB:  clr     A
X39EC:  push B
        mov B,A
        movc A,@A+DPTR
        xch A,B
        inc A
        movc A,@A+DPTR
        mov DPL,A
        mov DPH,B
        pop B
        ret
;----------------------------------------------------------------------
;bit VolumeUp(void);
;----------------------------------------------------------------------
VolumeUp:mov A,XrlByte
         cjne A,#MaxVolume<<2,$+3
         jnc NoVolumeUp
          add A,#1<<2
          mov ParamLL,A
AgainWait0SquareA:
          setb EA
AgainWait0Square:
           mov A,P4
           anl A,#0xFC
           jnb TR1,NextVolumUp
          jnz AgainWait0Square
          clr EA
          mov A,P4
          anl A,#0xFC
          jnz AgainWait0SquareA
NextVolumUp:
          mov XrlByte,ParamLL
          anl P4,#0x3
          setb EA
          setb C
          ret
NoVolumeUp:
          clr C
          ret


MTBL2:
 db 0x35,0x83,0x32,0x82,0x2F,0xAC,0x2C,0xFF,0x2A,0x79,0x28,0x17,0x25,0xD7,0x23,0xB7
 db 0x21,0xB6,0x1F,0xD1,0x1E,0x08,0x1C,0x59,0xC0,0xD0,0xC5,0x17,0x53,0x29,0x03,0x45
; db 0x29,0xF5,0x29,0xF2,0xE5,0x10,0x25,0x4C,0xF5,0x10,0xE5,0x11,0x35,0x4D,0xF5,0x11
; db 0x10,0xE7,0x27,0x24,0x2B,0x83,0xF5,0x14,0xE5,0x12,0x25,0x4E,0xF5,0x12,0xE5,0x13

$mldydata.asm
 dw MelodyError
 dw MelodyHourBeep

 dw MelodyBell0
 dw MelodyBell1
 dw MelodyBell2
 dw MelodyBell3
 dw MelodyBell4
 dw MelodyBell5
 dw MelodyBell6
 dw MelodyBell7
 dw MelodyBell8
 dw MelodyBell9

 dw MelodyRemoteAccessKey
 dw MelodyLogo

MelodyError:
 dw SampleError
 dw -1
MelodyHourBeep:
 dw SampleHourBeep
 dw -1

MelodyBell0:
 dw SampleBell0
 dw SampleBell0
 dw SampleBell0
 dw SampleBell0
 dw SampleBell0
 dw -1
MelodyBell1:
 dw SampleBell1
 dw SampleBell1
 dw SampleBell1
 dw SampleBell1
 dw SampleBell1
 dw -1
MelodyBell2:
 dw SampleBell2
 dw SampleBell2
 dw SampleBell2
 dw SampleBell2
 dw SampleBell2
 dw -1
MelodyBell3:
 dw SampleBell3
 dw SampleBell3
 dw -1
MelodyBell4:
 dw SampleBell4
 dw -1
MelodyBell5:
 dw SampleBell5
 dw SampleBell5
 dw -1
MelodyBell6:
 dw SampleBell6
 dw SampleBell6
 dw SampleBell6
 dw -1
MelodyBell7:
 dw SampleBell7
 dw SampleBell7a
 dw SampleBell7
 dw -1
MelodyBell8:
 dw SampleBell8
 dw SampleBell8
 dw SampleBell8
 dw -1
MelodyBell9:
 dw SampleBell9
 dw SampleBell9
 dw SampleBell9
 dw -1

MelodyRemoteAccessKey:
 dw SampleRemoteAccessKey
 dw -1

MelodyLogo:
 dw Sample69
 dw Sample70
 dw Sample71
 dw -1
; dw Sample69
; dw Sample72
; dw Sample71
; dw Sample73


#define ENote1 20
#define ENote2 17
#define ETempo 18
SampleError:
 db ETempo,0x40|ENote1,0x3c,0x40|ENote1,0x3c,0x40|ENote1,0x3c,0xC0|ENote2,0xFF
SampleHourBeep:
 db 0x11,0x19,0x3C,0x1C,0x3C,0x1F,0x3C|0xC0,0x3C|0xC0,0xFF

SampleBell0:
 db 18,0x14,0x1A,0x14,0x1A,0x14,0x1A,0xFF

SampleBell1:
 db 10,0x20,0x28,0x20,0x28,0x20,0x28,0xFF

SampleBell2:
 db 10,0x40|0x28,0x30,0x40|0x28,0x30,0x40|0x28,0x30,0xFF

SampleBell3:
 db 30,0x29,0x3C,0x2C,0x3C,0x2F,\
    0x3C,0x2c,0x3c,0x29,0xFC,0xFC,0xFC,0xFC,0xFF

#define S4F1 0x39
#define S4F2 0x34
SampleBell4:
 db 50,0x80|S4F1,0x80|S4F2,0xC0|S4F1,0xFF

SampleBell5:
 db 30,0x80|48,0x80|44,0x80|41,0xFC,0xFC,0xFC,0xFF

SampleBell6:
 db 20,0x30,0x35,0x30,0x35,0x30,0x35,0x30,0x35,0xFC,0xFC,0xFC,0xFC,0xFF

SampleBell7:
 db 80,0x3A,0x3A-4,0xFF
SampleBell7a:
; db 80,0x3A-6,0xBC,0xFF
 db 80,0x3A-8,0xBC,0xFF

SampleBell8:
 db 20,0x30,0x38|0x40,0x30,0x38|0x40,0x30,0x38|0x40,0xFC,0xFF

SampleBell9:
 db 30,0x20,0x21,0x22,0x1D,0xFF

SampleRemoteAccessKey:
; db 0x11,0x1F,0x3C,0x22,0x3C,0x25,0xFF
 db 0x30,0x1B|0xC0,0xFF

  RSEG BITVARS
;F2E_7: DS 1
MF0:   DS 1
        end