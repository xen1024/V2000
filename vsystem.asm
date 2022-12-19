/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

          NAME   System
          RSEG    CODE
          public ViewDataBufferRom
          $DEFFN ViewDataBufferRom(7,0,0,2,0,0,0,0)
          public ConvertKey
          $DEFFN ConvertKey(0,0,0,0,0,0,0,0)
          public GetEventOnFKey
          $DEFFN GetEventOnFKey(4,0,0,1,0,0,0,0)
          public InitSystem
          $DEFFN InitSystem(0,0,0,0,0,0,0,0)
          public StartLoadOpt
          $DEFFN StartLoadOpt(0,0,0,0,0,0,0,0);,LoadValueN
          public GetVideoDataOnEFunc
          $DEFFN GetVideoDataOnEFunc(0,0,0,0,0,0,0,0)
          public GetKeyMapOn
          $DEFFN GetKeyMapOn(0,0,0,0,0,0,0,0)
          public EventOfModeKey
          $DEFFN EventOfModeKey(0,0,0,0,0,0,0,0),GetEventOnFKey
          public SetCharInEditBuff
          $DEFFN SetCharInEditBuff(0,0,0,0,0,0,0,0)
          public DeleteCharInEditBuff
          $DEFFN DeleteCharInEditBuff(0,0,0,0,0,0,0,0)
          public TestSpecOpt
          $DEFFN TestSpecOpt(0,0,0,0,0,0,0,0)
          public TestEnableOpt
          $DEFFN TestEnableOpt(0,0,0,0,0,0,0,0)
          public DaySetOnKey
          $DEFFN DaySetOnKey(0,0,0,0,0,0,0,0)
          public GetMainModeVFuncData
          $DEFFN GetMainModeVFuncData(0,0,0,0,0,0,0,0)
          public SetNumberBuff,SetNumberBuffA
          $DEFFN SetNumberBuff(0,0,0,0,0,0,0,0)
          $DEFFN SetNumberBuffA(0,0,0,0,0,0,0,0)
          public GetPauseRolNumber
          $DEFFN GetPauseRolNumber(0,0,0,0,0,0,0,0)
          public GetNumberBuff
          $DEFFN GetNumberBuff(0,0,0,0,0,0,0,0)
          public StartImpulse
          $DEFFN StartImpulse(0,0,0,0,0,0,0,0)
          public StopImpulse
          $DEFFN StopImpulse(0,0,0,0,0,0,0,0)
          public InvertImpulse
          $DEFFN InvertImpulse(0,0,0,0,0,0,0,0)
          public LoadCallParam
          $DEFFN LoadCallParam(0,0,0,0,0,0,0,0)
          public GetEventOnBeepMap
          $DEFFN GetEventOnBeepMap(0,0,0,0,0,0,0,0)
          public CallEvent
          $DEFFN CallEvent(0,0,0,0,0,0,0,0)
          public RetEvent
          $DEFFN RetEvent(0,0,0,0,0,0,0,0)
          public EventCallPosition
          $DEFFN EventCallPosition(0,0,0,0,0,0,0,0)
          public SaveDefaultNumber
          $DEFFN SaveDefaultNumber(0,0,0,0,0,0,0,0)
          public SaveDefaultNumberA
          $DEFFN SaveDefaultNumberA(0,0,0,0,0,0,0,0)
          public LoadDefaultNumber
          $DEFFN LoadDefaultNumber(0,0,0,0,0,0,0,0)
          public GetNumeralDefaultBuff
          $DEFFN GetNumeralDefaultBuff(0,0,0,0,0,0,0,0)
          public LineUp,LineDown,PipeOn,PipeOff,PipeOnOff
          $DEFFN LineUp(0,0,0,0,0,0,0,0)
          $DEFFN LineDown(0,0,0,0,0,0,0,0)
          $DEFFN PipeOn(0,0,0,0,0,0,0,0)
          $DEFFN PipeOff(0,0,0,0,0,0,0,0)
          $DEFFN PipeOnOff(0,0,0,0,0,0,0,0)
          public SoundOn,SoundOff
          $DEFFN SoundOn(0,0,0,0,0,0,0,0)
          $DEFFN SoundOff(0,0,0,0,0,0,0,0)
          public Convert10msTo4ms
          $DEFFN Convert10msTo4ms(0,0,0,0,0,0,0,0)
          public ParallelTest
          $DEFFN ParallelTest(0,0,0,0,0,0,0,0)
          public GetLenPackOfLenNumberMinLen
          $DEFFN GetLenPackOfLenNumberMinLen(0,0,0,0,0,0,0,0)
          public ShowBusy
          $DEFFN ShowBusy(0,0,0,0,0,0,0,0),ViewDataBufferRom
          public DeviceReset
          $DEFFN DeviceReset(0,0,0,0,0,0,0,0)
          public SetDefaultLenNumberBuff,SetDefaultNumeralBuff
          public ResetDefaultNumberBuff
          $DEFFN ResetDefaultNumberBuff(0,0,0,0,0,0,0,0)
          $DEFFN SetDefaultLenNumberBuff(0,0,0,0,0,0,0,0)
          $DEFFN SetDefaultNumeralBuff(0,0,0,0,0,0,0,0)
          public XchgNumbBuffers
          $DEFFN XchgNumbBuffers(0,0,0,0,0,0,0,0)
          public BitSetOnKey
          $DEFFN BitSetOnKey(0,0,0,0,0,0,0,0)
          public TestNight
          $DEFFN TestNight(0,0,0,0,0,0,0,0)
          public SetSpeakerOn
          $DEFFN SetSpeakerOn(0,0,0,0,0,0,0,0)
          public SetSpeakerOff
          $DEFFN SetSpeakerOff(0,0,0,0,0,0,0,0)
          public SetSpeakerOnOff
          $DEFFN SetSpeakerOnOff(0,0,0,0,0,0,0,0)
          public SetSpeakerOnA
          $DEFFN SetSpeakerOnA(0,0,0,0,0,0,0,0)
          public PrintError
          $DEFFN PrintError(0,0,0,0,0,0,0,0)
          public TestROM
          $DEFFN TestROM(0,0,0,0,0,0,0,0)
          public ShowPowerDown
          $DEFFN ShowPowerDown(0,0,0,0,0,0,0,0)

          public VideoAdrLo,VideoAdrHi,FirstKey,PlayOnKeyEvent,\
          EndPressKeyNow,LongKeyEvent,EventKeyUp,RomRam01
#define __System
$vdef.inc
$vdata.asm
;-------------------Print to VBuffer-------------------------
;Print data to video buffer
;in: ParamLL - Number of video source
;out: none
;use: A,B,Rx,Local[2]
;------------------------------------------------------------
#define VPos              $LOCBD ViewDataBufferRom
#define TypeMig           $LOCBD ViewDataBufferRom+1
#define StartLevelStackSV $LOCBD ViewDataBufferRom+2
#define CurrentValue      $LOCBD ViewDataBufferRom+3
#define ViewSelectedValue $LOCBD ViewDataBufferRom+4
#define SelectedMigType   $LOCBD ViewDataBufferRom+5
#define SkipChars         $LOCBD ViewDataBufferRom+6
#define ValueSelected     $LOCBB ViewDataBufferRom
#define ViewSerialPaste   $LOCBB ViewDataBufferRom+1
ViewDataBufferRom:
                mov A,ParamLL
                mov DPTR,#StartVideoRom
                call LoadDPTRFromDPTRA
                call XchDP_VA
;                clr RomRam01A
RealStartDataBufferRam:
;---------------------Start-------------------
                clr A
                mov CurrentValue,A
                mov CallProcView,A
                mov TypeMig,A
                mov VPos,A
                mov StartLevelStackSV,A
                mov SkipChars,A
                mov ViewSelectedValue,#0xFF
                mov SelectedMigType,#MigType2
                clr ValueSelected
                clr ViewSerialPaste

SetInitViewDataBuffer:
;------------------Loop View----------------
NextViewDataBuffer:
                clr RomRam01
                call LoadByteFromVideoAdr
;____________________________________________________________________________
; None
                cjne A,#vdNone,NextFunctionView_vdNone
                 jmp NextViewDataBuffer
NextFunctionView_vdNone:
;____________________________________________________________________________
;Function Call
                cjne A,#vdCall,NextFunctionView_Call
                  call LoadDPTRFromVideoAdr
                  call PushProcView
?NextFunctionView_Call:
                  call XchDP_VA
                  clr A
NextFunctionView_Call:
;____________________________________________________________________________
;Function Jump
                cjne A,#vdJump,NextFunctionView_Jump
                  call LoadDPTRFromVideoAdr
                  sjmp ?NextFunctionView_Call
NextFunctionView_Jump:
;____________________________________________________________________________
;Function Call[cv]
                cjne A,#vdCallcv,NextFunctionView_Callcv
                  call LoadDPTRFromVideoAdr
                  call PushProcView
                  mov StartLevelStackSV,CallProcView
                  call GetCVValue
?NextFunctionView_Callcv:
                  call GetDPTRFromA
                  call XchDP_VA
                  clr A
NextFunctionView_Callcv:
;____________________________________________________________________________
;Function Jump[cv]
                cjne A,#vdJumpcv,NextFunctionView_Jumpcv
                  call LoadDPTRFromVideoAdr
                  call GetCVValue
                  jnb ValueSelected,?NextFunctionView_Callcv
                  mov StartLevelStackSV,#0xFF
                  sjmp ?NextFunctionView_Callcv
NextFunctionView_Jumpcv:
;____________________________________________________________________________
;Function Change TypeMig
                cjne A,#vdChangeTM,NextFunctionView_ChangeTM
                  call LoadByteFromVideoAdr
                  mov TypeMig,A
                  clr A
NextFunctionView_ChangeTM:
;____________________________________________________________________________
;Function ViewOneCharNewTypeMig
                cjne A,#vdVwChTM,NextFunctionView_VCNewTM
                  call LoadByteFromVideoAdr
                  xch A,TypeMig
                  mov ParamLL,A
                  call LoadByteFromVideoAdr
                  dec A
?NextFunctionView_VCNewTM:
                  call ViewByte
                  mov TypeMig,ParamLL
                  clr A
NextFunctionView_VCNewTM:
;____________________________________________________________________________
;Function ViewHalfDeccv
                cjne A,#vdViewHalfDeccv,NextFunctionView_ViewHalfDeccv
                 call GetCVValue
                 call ViewHalfByte
                 clr A
NextFunctionView_ViewHalfDeccv:

;____________________________________________________________________________
;Function ViewDeccv
;In: uchar ViewByte=Value[CurrentValue]
                cjne A,#vdViewDeccv,NextFunctionView_ViewDeccv
                 call GetCVValue
?NextFunctionView_ViewDeccv:
                 call HexToDec
                 xch A,B
                 jz NoView100ByteDecA
                   push B
                   call ViewHalfByte
                   pop B
NoView100ByteDecA:
                 xch A,B
                 call View2HalfBytes
                 clr A
NextFunctionView_ViewDeccv:
;____________________________________________________________________________
;Function View3Deccv
;In: uchar ViewByte=Value[CurrentValue]
                cjne A,#vdView3Deccv,NextFunctionView_View3Deccv
                 call GetCVValue
                 call HexToDec
                 push A
                 mov A,B
                 call ViewHexHalfByte
                 pop A
                 call View2HalfBytes
                 clr A
NextFunctionView_View3Deccv:
;____________________________________________________________________________
;Function ViewDecMemI start
                cjne A,#vdViewDecMemI,NextFunctionView_ViewDecMemI
                 call LoadByteFromVideoAdr
                 mov R0,A
                 call LoadByteFromVideoAdr
                 add A,@R0
                 jmp ?NextFunctionView_ViewDeccv
NextFunctionView_ViewDecMemI:
;____________________________________________________________________________
;Function ViewHoursDecMemI start
                cjne A,#vdViewHoursDecMemI,NextFunctionView_vdViewHoursDecMemI
                 call LoadByteFromVideoAdr
                 mov R0,A
                 mov A,@R0
                 jnb HoursModeView,??NextFunctionView_vdViewHoursDecMemI
                  cjne A,#11,$+3
                  jc ?NextFunctionView_vdViewHoursDecMemI
                   add A,#-12
?NextFunctionView_vdViewHoursDecMemI:
                  jnz ??NextFunctionView_vdViewHoursDecMemI
                   mov A,#12
??NextFunctionView_vdViewHoursDecMemI:
                 jmp ?NextFunctionView_ViewDeccv
NextFunctionView_vdViewHoursDecMemI:
;____________________________________________________________________________
;Function ViewHexcv
;In: uchar ViewByte=Value[CurrentValue]
                cjne A,#vdViewHexcv,NextFunctionView_ViewHexcv
??NextFunctionView_ViewHexcv:
                 call GetCVValue
?NextFunctionView_ViewHexcv:
                 call ViewHexByte
                 clr A
NextFunctionView_ViewHexcv:
;____________________________________________________________________________
;Function ViewHexMemI
                cjne A,#vdViewHexMemI,NextFunctionView_ViewHexMemI
                 call LoadByteFromVideoAdr
                 mov R0,A
                 mov A,@R0
                 jmp ?NextFunctionView_ViewHexcv
NextFunctionView_ViewHexMemI:
;____________________________________________________________________________
;Function ViewHexStringMemX
;In: uint addr=(uint)Value[CurrentValue]
                cjne A,#vdViewHexStringMemX,NextFunctionView_ViewHexStringMemX
                 call GetCVValue
                 mov DPL,A
                 call GetCVValue
                 mov DPH,A
                 call LoadByteFromVideoAdr
                 mov ParamLL,A
                 call ViewXString
                 clr A
NextFunctionView_ViewHexStringMemX:
;____________________________________________________________________________
;Function View3HexMemI
                cjne A,#vdView3HexMemI,NextFunctionView_View3HexMemI
                 call GetCVValueW
                 push A
                 mov A,B
                 call ViewHexHalfByte
                 pop A
                 call ViewHexByte
                 clr A
NextFunctionView_View3HexMemI:
;____________________________________________________________________________
;Function DecCV
                cjne A,#vdDecCV,NextFunctionView_vdDecCV
                 dec CurrentValue
                 clr A
NextFunctionView_vdDecCV:
;____________________________________________________________________________
;Function vdTXTCharcv
;uchar ViewByte=Value[CurrentValue]
                cjne A,#vdTXTCharcv,NextFunctionView_vdTXTCharcv
;                 call LoadByteFromVideoAdr
                 call GetCVValue
                 call ViewByte
                 clr A
NextFunctionView_vdTXTCharcv:
;____________________________________________________________________________
;Function ViewLine16
                cjne A,#vdViewLinecv,NextFunctionView_vdViewLine
                 call GetCVValue
                 call ViewLine16
                 clr A
NextFunctionView_vdViewLine:
;____________________________________________________________________________
;Function AppendPixel
                cjne A,#vdPixel,NextFunctionView_vdPixel
                 mov A,VPos
                 rl A
                 add A,#VideoBuffer-1
                 mov R0,A
                 mov A,@R0
                 orl A,#cpixel
                 mov @R0,A
                 clr A
NextFunctionView_vdPixel:
;____________________________________________________________________________
;Function ViewDays
                cjne A,#vdViewDayscv,NextFunctionView_vdViewDayscv
                 call GetCVValue
                 mov ParamLL,A
                 mov ParamHL,#0
                 mov ParamLH,#7
                 mov ParamHH,#0
                 call ViewBits
                 clr A
NextFunctionView_vdViewDayscv:
;____________________________________________________________________________
;Function View Number
                cjne A,#vdViewNumber,NextFunctionView_vdViewNumber
                 mov ParamLL,#NoMig
                 call ViewNumber
                 clr A
NextFunctionView_vdViewNumber:
;____________________________________________________________________________
;Function View Number Mig
                cjne A,#vdViewNumberMig,NextFunctionView_vdViewNumberMig
                 mov ParamLL,#MigType2
                 call ViewNumber
                 clr A
NextFunctionView_vdViewNumberMig:
;____________________________________________________________________________
;Function View Number Type
                cjne A,#vdViewNumberType,NextFunctionView_vdViewNumberType
                 mov A,#zo-1
                 jb TypeNumber,NoNumberInShow
                  mov A,#zHio-1
NoNumberInShow:  call ViewByte
                 clr A
NextFunctionView_vdViewNumberType:
;____________________________________________________________________________
;Function Change TypeMig on HangUp
                cjne A,#vdHangUpTM,NextFunctionView_vdHangUpTM
                 clr A
                 jnb HangUp,NextFunctionView_vdHangUpTM
                  mov TypeMig,#MigType2
NextFunctionView_vdHangUpTM:
;____________________________________________________________________________
;Function Set TypeMig without putchar
                cjne A,#vdSetTM,NextFunctionView_vdSetTM
                 mov A,VPos
                 rl A
                 add A,#VideoBuffer
                 mov R0,A
                 call LoadByteFromVideoAdr
                 anl A,#0xF0
                 orl A,LightLevel
                 mov @R0,A
                 inc VPos
                 clr A
NextFunctionView_vdSetTM:
;____________________________________________________________________________
;Function ViewHalfDecMemI start
                cjne A,#vdViewHalfDecMemI,NextFunctionView_vdViewHalfDecMemI
                 call LoadByteFromVideoAdr
                 mov R0,A
                 call LoadByteFromVideoAdr
                 add A,@R0
                 call ViewHalfByte
                 clr A
NextFunctionView_vdViewHalfDecMemI:
;____________________________________________________________________________
;Function Change Selected TypeMig
                cjne A,#vdChangeSMT,NextFunctionView_vdChangeSMT
                 call LoadByteFromVideoAdr
                 mov SelectedMigType,A
                 clr A
NextFunctionView_vdChangeSMT:
;____________________________________________________________________________
;Function Show Password symbols
                cjne A,#vdShowPWDcv,NextFunctionView_vdShowPWDcv
                 call LoadByteFromVideoAdr
                 mov ParamLL,A
                 call ShowPasswordSym
                 clr A
NextFunctionView_vdShowPWDcv:
;____________________________________________________________________________
;Function Show Filter symbols
                cjne A,#vdShowFiltercv,NextFunctionView_vdShowFiltercv
                 call LoadByteFromVideoAdr
                 mov ParamLH,A
                 call GetCVValue
                 mov ParamLL,A
                 mov ParamHL,#0
                 mov ParamHH,#zo-1
                 call ViewBits
                 clr A
NextFunctionView_vdShowFiltercv:
;____________________________________________________________________________
;Function Change Selected TypeMig on TodaySee
                cjne A,#vdTodaySeeSTM,NextFunctionView_vdTodaySeeTM
                 clr A
                 mov SelectedMigType,#NoMig
                 jnb TodaySee,NextFunctionView_vdTodaySeeTM
                  mov SelectedMigType,#MigType1
NextFunctionView_vdTodaySeeTM:
;____________________________________________________________________________
;Function Call[SpeakerOn]
                cjne A,#vdCallSpeaker,NextFunctionView_vdCallSpeaker
                  call LoadDPTRFromVideoAdr
                  call PushProcView
                  mov StartLevelStackSV,CallProcView
                  clr A
                  mov C,SpeakerOn
                  rlc A
                  jmp ?NextFunctionView_Callcv
NextFunctionView_vdCallSpeaker:
;____________________________________________________________________________
;                cjne A,#vdIncPosView,NextFunctionView_vdIncPosView
;                 inc VPos
;                 clr A
;NextFunctionView_vdIncPosView:
;____________________________________________________________________________
                 cjne A,#vdViewDec5cv,NextFunctionView_vdViewDec5cv
                  call GetCVValue
                  push A
                  call GetCVValueA
                  pop B
                  call HexTo5DecWord
                  push A
                  push B
                  mov A,ParamLL
                  call ViewHalfByte
                  pop A
                  call View2HalfBytes
                  pop A
                  call View2HalfBytes
                  clr A
NextFunctionView_vdViewDec5cv:
;____________________________________________________________________________
;Function VieoOffsetData
                 cjne A,#vdViewOffsetDatacv,NextFunctionView_vdViewOffsetDatacv
                  call GetCVValue
                  mov SkipChars,A
                  jnb ACC.7,NoMnsOffset
                   mov SkipChars,#0
                   cpl A
                   inc A
                   mov ParamLL,A
AgainSkip:          mov A,#zSP-1
                    call ViewByte
                   djnz ParamLL,AgainSkip
NoMnsOffset:
                  clr A
NextFunctionView_vdViewOffsetDatacv:
;____________________________________________________________________________
;Function Exit
                cjne A,#vdExit,NextFunctionView_Exit
                 mov A,StartLevelStackSV
                 xrl A,CallProcView
                 jnz NoEndViewValueStack
                  mov StartLevelStackSV,A
                  clr ValueSelected
NoEndViewValueStack:
                 mov A,CallProcView
                 jnz NoRetMainFunc
                  mov A,VPos
                  rl A
                  add A,#VideoBuffer
                  mov R0,A
AgainClearingVideoBuff:
                  cjne R0,#VideoBuffer+MaxRazr<<1,$+3
                  jnc VideoBuffViewed
                   mov @R0,#0
                   inc R0
                   jmp AgainClearingVideoBuff
VideoBuffViewed:
                  ret
NoRetMainFunc:
                 dec CallProcView
                 pop VideoAdrLo
                 pop VideoAdrHi
                 clr A
NextFunctionView_Exit:
               jz NoClearAViewIt
                dec A
                call ViewByte
NoClearAViewIt:
               mov A,StartLevelStackSV
               jnz NoClearValueSelected
                clr ValueSelected
                jnb ViewSerialPaste,NoClearValueSelected
                 clr ViewSerialPaste
                 call ViewEditMode
NoClearValueSelected:
               jmp NextViewDataBuffer
;************************************************************
;------------------------------------------------------------
;Show Password
;in: ParamLL - number of password chars
;------------------------------------------------------------
ShowPasswordSym: call GetCVValue
                 mov ParamLH,#0
AgainShowPasswordSym:
                  cjne ParamLH,#2,NoNextByteLoadPwdShow
                   call GetCVValueA
                   mov ParamLH,#0
NoNextByteLoadPwdShow:
                  mov A,#zo-1
                  call ViewByte
                  inc ParamLH
                 djnz ParamLL,AgainShowPasswordSym
                 ret
;------------------------------------------------------------
;in: ParamLL - MigTypeNumber
;------------------------------------------------------------
ViewNumber:mov ParamXL,ParamLLd
           mov ParamLH,OffsetNumberView
           mov ParamHL,#7
AgainViewNumber:
;            cjne ParamXL,#0,NoSetMigTypeNumber
;           mov TypeMig,ParamXL
;NoSetMigTypeNumber:
;            mov TypeMig,#NoMig
            mov TypeMig,ParamXL

            mov ParamLL,#0xFF
            mov A,LenNumber
            setb C
            subb A,ParamLH
            jc NoViewCurrNumeral
             mov ParamLL,ParamLHd
             call GetNumberBuff
             jnb ShowSearch,NoShowNumberA
              mov A,LenShowA
              setb C
              subb A,ParamLH
              jnc NoShowNumberA
               mov TypeMig,#MigType2
NoShowNumberA:
NoViewCurrNumeral:

            jnb EditCallBuff,NoThisNumeralCallNow
            jnb CallSelect,NoThisNumeralCallNow
             mov A,ParamLH
             xrl A,PosCall
             jnz NoThisNumeralCallNow
              mov TypeMig,#MigType2
NoThisNumeralCallNow:
            mov A,ParamLL
            add A,#NumberViewChars-$-3+1
            movc A,@A+PC
            dec A
            call ViewByte
            inc ParamLH
           djnz ParamHL,AgainViewNumber
           ret
NumberViewChars:
 db zSP,z0,z1,z2,z3,z4,z5,z6,z7,z8,z9,zMNS,zP,zt,zPr,z_,zo
;------------------------------------------------------------
ViewBits:
AgainViewBits:
                  mov A,ParamHL
                  rrc A
                  mov ParamHL,A
                  mov A,ParamLL
                  rrc A
                  mov ParamLL,A
                  mov F0,C
                  mov A,ParamHH
                  jnz NoViewDays
                   mov A,#8
                   clr C
                   subb A,ParamLH
NoViewDays:       jb F0,NoClearedBit
                   mov A,#z_-1
NoClearedBit:     call ViewByte
                 djnz ParamLH,AgainViewBits
                 ret
;------------------------------------------------------------
ViewLine16:
        clr ValueSelected
        mov ParamLL,A
        mov ParamHL,#8
AgainDrawLine:
         mov ParamLH,#zSP-1
         mov A,ParamLL
         jz NoLineSegL
          mov ParamLH,#zsE-1
          dec A
          jz NoLineSegL
           mov ParamLH,#zsEsC-1
           dec A
NoLineSegL:
         mov ParamLL,A
         mov A,ParamLH
;         dec A
         call ViewByte
        djnz ParamHL,AgainDrawLine
        ret
;------------------------------------------------------------
ViewEditMode:
        mov ParamXL,TypeMig
        mov ParamHL,#0
AgainViewEditMode:
         mov TypeMig,#NoMig
         mov A,PosEdit
         setb C
         subb A,ParamHL
         jnc NoClearedDataEnter
          inc A
          jnz NoNowSelected
           mov TypeMig,#MigType2
NoNowSelected:
          mov A,#z_-1
          jmp ViewNow_
NoClearedDataEnter:
         clr c
         rrc A
         mov F0,C
         cpl ACC.0
         add A,#EditBuff
         mov R0,A
         mov A,@R0
         jnb F0,NoLowHalfEdit
          swap A
NoLowHalfEdit:
         anl A,#0xF
         jnb PassEnter,ViewNow_
          mov A,#zo-1
ViewNow_:
         call ViewByte

        inc ParamHL
        mov A,LenEdit
        anl A,#0xF
        xrl A,ParamHL
        jnz AgainViewEditMode
        mov TypeMig,ParamXL
        ret
;------------------------------------------------------------
;ViewXString
;in: DPTR    - addr
;    ParamLL - Len
;out: DPTR+=ParamLL
;     ParamLL=0
;use: A
;------------------------------------------------------------
ViewXString:     mov A,ParamLL
                 jz ExitViewXString
                  call LoadByteFromAdrInRam
                  call ViewHexByte
                  inc DPTR
                  dec ParamLL
                  jmp ViewXString
ExitViewXString: ret
;------------------------------------------------------------
;A=MemCX[VA]
;DPTR=MemCX[VA]
;------------------------------------------------------------
LoadDPTRFromVideoAdr: setb F0
                      sjmp ?LoadDPTRFromVideoAdrNow
LoadByteFromVideoAdr: clr F0
?LoadDPTRFromVideoAdrNow:
                      call XchDP_VA     ;выход: VideoAdr++
                                        ;       A=mem[VideoAdr]
                      call LoadByteFromAdrInRomRam01A
                      inc DPTR
                      jnb F0,SkipLoadDPTRFromVideoAdr
                       mov VideoAdrHi,A
                       call LoadByteFromAdrInRomRam01A
                       inc DPTR
                       mov VideoAdrLo,A
                                        ;       VideoAdr++
                                        ;       DPTR=mem[VideoAdr]
SkipLoadDPTRFromVideoAdr:
                      call XchDP_VA
                      ret

;------------------------------------------------------------
;A=[DPTR] ROM/RAM=RomRam01A
;------------------------------------------------------------
LoadByteFromAdrInRomRam01A: ;mov C,RomRam01A
                            ;sjmp LoadByteFromAdrInRomRam01x
LoadByteFromAdrInRomRam01:  ;mov C,RomRam01
LoadByteFromAdrInRomRam01x: ;jnc LoadByteFromAdrInRom01x
                            ; jmp LoadByteFromAdrInRam
LoadByteFromAdrInRom01x:     clr A
                             movc A,@A+DPTR
                             ret
;------------------------------------------------------------
;push VA
;------------------------------------------------------------
PushProcView:
                  inc CallProcView
                  pop B
                  pop A
                  push VideoAdrHi
                  push VideoAdrLo
                  push A
                  push B
                  ret
;------------------------------------------------------------
;DPTR=StringEndGet(DPTR,A)
;...EndByte...EndByte
;------------------------------------------------------------
GetDPTRFromA:    inc A
                 mov B,A
AgainGetDPTRFromA:
                 djnz B,AgainNextDPTRFromA
                  ret
AgainNextDPTRFromA:
                 call LoadByteFromAdrInRomRam01
                 inc DPTR
                 cjne A,#vdExit,ExitNextDPTRFromA0
                  sjmp AgainGetDPTRFromA
ExitNextDPTRFromA0:
                 cjne A,#vdJumpcv,ExitNextDPTRFromA1
                  sjmp AgainGetDPTRFromB
ExitNextDPTRFromA1:
                 cjne A,#vdJump,ExitNextDPTRFromA2
AgainGetDPTRFromB:inc DPTR
                  inc DPTR
                  sjmp AgainGetDPTRFromA
ExitNextDPTRFromA2:
                 cjne A,#vdNone,ExitNextDPTRFromA3
                  sjmp AgainGetDPTRFromA
ExitNextDPTRFromA3:
                 cjne A,#vdViewDecMemI,ExitNextDPTRFromA4
                  inc DPTR
                  inc DPTR
                  sjmp AgainNextDPTRFromA
ExitNextDPTRFromA4:
                 cjne A,#vdViewHalfDecMemI,ExitNextDPTRFromA5
                  inc DPTR
                  inc DPTR
                  sjmp AgainNextDPTRFromA
ExitNextDPTRFromA5:
                 cjne A,#vdViewHoursDecMemI,ExitNextDPTRFromA6
                  inc DPTR
                  sjmp AgainNextDPTRFromA
ExitNextDPTRFromA6:
                 cjne A,#vdVwChTM,ExitNextDPTRFromA7
                  inc DPTR
                  sjmp AgainNextDPTRFromA
ExitNextDPTRFromA7:
                 cjne A,#vdChangeTM,ExitNextDPTRFromA8
                  inc DPTR
                  sjmp AgainNextDPTRFromA
ExitNextDPTRFromA8:
                 cjne A,#vdPixel,ExitNextDPTRFromA9
                  sjmp AgainNextDPTRFromA
ExitNextDPTRFromA9:
                 cjne A,#vdCallcv,ExitNextDPTRFromA10
                  inc DPTR
                  inc DPTR
                  sjmp AgainNextDPTRFromA
ExitNextDPTRFromA10:
                 cjne A,#vdCall,ExitNextDPTRFromA11
                  inc DPTR
                  inc DPTR
                  sjmp AgainGetDPTRFromA
ExitNextDPTRFromA11:
                 sjmp AgainNextDPTRFromA
;------------------------------------------------------------
;DPTR=DPTR[A*2]
;in:DPTR,A
;out:DPTR
;------------------------------------------------------------
LoadDPTRFromDPTRA:
                  mov B,#2
                  mul AB
                  call AddDPTR_BA
                  clr A
                  movc A,@A+DPTR
                  mov B,A
                  mov A,#1
                  movc A,@A+DPTR
                  mov DPH,B
                  mov DPL,A
                  ret
;------------------------------------------------------------
;ViewHexByte/ViewHexHalfByte
;in:A
;out: none
;use: A,B,ViewHalfByte
;------------------------------------------------------------
ViewHexHalfByte:
                call ConvHexAndViewByte
                call ViewByteA
                ret
ViewHexByte:
                mov B,A
                swap A
                call ConvHexAndViewByte
                call ViewByteA
                mov A,B
                call ConvHexAndViewByte
                orl A,#zpixel
                call ViewByteA
                ret
ConvHexAndViewByte:
                anl A,#0x0F
                add A,#HexConvTable-$-3
                movc A,@A+PC
                ret
HexConvTable: db z0,z1,z2,z3,z4,z5,z6,z7,z8,z9,zA,zb,zC,zd,zE,zF

View2HalfBytes:
                 mov B,A
                 swap A
                 call ViewHalfByte
                 mov A,B
                 call ViewHalfByte
                 ret
;------------------------------------------------------------
;GetCVValueW
; BA=uint ValueData[CurrentValue]
;GetCVValue
; A=uchar ValueData[CurrentValue]
;GetAValue
; A=uchar ValueData[A]
;in: A/CurrentValue
;out: A
;use: A,R0
;------------------------------------------------------------
GetCVValueW: call GetCVValue
             mov B,A
             call GetCVValue
             xch A,B
             ret

GetCVValue:      inc ViewSelectedValue
                 mov A,ViewSelectedValue
                 xrl A,SelectedValue
                 jnz GetCVValueA
                  setb ValueSelected
                  jnb EditModeValue,GetCVValueA
;                   mov A,TypeEdit
;                   xrl A,#teSerialEnter
;                   jnz GetCVValueA
                    setb ViewSerialPaste
GetCVValueA:     mov A,CurrentValue
                 inc CurrentValue
GetAValue:       add A,#ValueData
                 mov R0,A
                 mov A,@R0
                 ret
;------------------------------------------------------------
;Out byte in video buffer
;in: uchar A          - Byte to view
;    uchar VPos       - Video position
;    uchar LightLevel - Light level
;    uchar TypeMig    - Type of mig
;out: VPos++
;use: A,R0
;------------------------------------------------------------
ViewByteA: dec A
           jmp ViewByte
ViewHalfByte: anl A,#0Fh
ViewByte:
         jb ViewSerialPaste,ExitViewByte
         mov R0,VPos
         cjne R0,#MaxRazr,$+3
         jnc OutOfVideoBuffer
          push A
          mov A,SkipChars
          jz NoSkipCurrChar
           pop A
           dec SkipChars
           ret
NoSkipCurrChar:
          mov A,TypeMig
          anl A,#0xF0
          jnb ValueSelected,NoSetNewTypeMig
           mov A,SelectedMigType
NoSetNewTypeMig:
          orl A,LightLevel
          cjne A,#0xFF,NoLightLevelZerro
           pop A
           mov A,#zSP-1
           push A
           clr A
NoLightLevelZerro:
          xch A,R0
          rl A
          add A,#VideoBuffer
          xch A,R0
          mov @R0,A
          inc R0
          pop A
;          xch A,TypeMig
          mov C,ACC.7
          clr ACC.7
          mov F0,C
          cjne A,#MaxViewBytes,$+3
          jnc OutOfVideoBuffer
          add A,#CHARTBL-$-3
          movc A,@A+PC
          jnb F0,NoPixelSet
           orl A,#cpixel
NoPixelSet:
          mov @R0,A
          inc VPos
OutOfVideoBuffer:
ExitViewByte:
         ret
;Char table
CHARTBL: db c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,cMNS,cSP,c_
         db co,cA,cb,cC,cd,cE,cF,ct,cn,cS,cU,cP
         db cL,cr,cc,ch,cu,cH,cPr,cMl,cMr,ci,cIl
         db csE,csEsC,cY,cGr,cWl,cWr,cG,cEQ,cAGEl,cAGEr,ccb
         db cHio,cl,cV


;FindByteInRom
;In: DPTR=SI
;    A=al
;    R7=cl
;Out: C=1 - NotFound
;     C=0 - Found
;           R7=cl
ScasbRom:
             mov B,A
AgainScasbRom:
             clr A
             movc A,@A+DPTR
             cjne A,B,NoEqualScasbRom
;              clr C
              ret
NoEqualScasbRom:
             inc DPTR
            djnz R7,AgainScasbRom
            setb C
            ret

;-------------------Convert Key------------------------------
;Convert NowKey to specical key format
;In: none
;Out: ParamLL - converted key(FKey)
;------------------------------------------------------------
ConvertKey: ;Test Extended Key
            mov DPTR,#SpecicalKeyHwToSw
            mov ParamLL,#0
AgainTestExtendedKey:
             mov A,ParamLL
             movc A,@A+DPTR
             cjne A,NowKey,NoExtendedKeyHW
              mov A,ParamLL
              inc A
              movc A,@A+DPTR
              jmp ExtendedKeyHW
NoExtendedKeyHW:
             inc ParamLL
             inc ParamLL
            cjne A,#0xFF,AgainTestExtendedKey

            mov A,NowKey
            anl A,#0x0F
            mov B,#KeyPerLine
            mul AB
            mov B,A
            mov A,NowKey
            swap A
            anl A,#0x0F
            call GetNumberFirstBit1
            add A,B
            mov DPTR,#KeyHwToSw
            movc A,@A+DPTR
ExtendedKeyHW:
            jnb LongPressKey,NoLongPressed
             cjne A,#kfNone,NoUnuseKey
              jmp NoLongPressed
NoUnuseKey:   add A,#kfExtendedKey
NoLongPressed:
            mov ParamLL,A
;            clr LongPressKey
            clr KeyPresent
            mov C,FirstKeyt
            mov FirstKey,C
            clr FirstKeyt
            ret
;In: A - byte
;Out: A - first bit 0..8
;     if (A==8||!C) - error: no bits
;Use: ParamLL
GetNumberFirstBit1:
                   mov ParamLL,#0
AgainGetNumberFirstBit1:
                    rrc A
                    jc ExitGetNumberFirstBit1
                    inc ParamLL
                   cjne ParamLL,#8,AgainGetNumberFirstBit1
ExitGetNumberFirstBit1:
                   mov A,ParamLL
                   ret

;-------------------Get Event on FKey------------------------
;Convert NowKey to specical key format
;In: FKey    - Function Key
;    ParamLL - Number of Function Table
;Out: ParamLL - EventOnFKey
;------------------------------------------------------------
;#define Sevent      $LOCBD GetEventOnFKey;_R+2
#define LFKey       $LOCBD GetEventOnFKey+2
#define SFKey       $LOCBD GetEventOnFKey+3
#define OneOfAllKey $LOCBB GetEventOnFKey
#define Sevent      $LOCBD GetEventOnFKey
#define Levent      $LOCBD GetEventOnFKey+1
GetEventOnFKey:
;                mov A,Sevent
;                mov A,Levent
;                mov A,LFKey
;                mov A,SFKey
;                setb OneOfAllKey
                mov A,ParamLL
                mov DPTR,#EventOnKeyAddrTable
                call LoadDPTRFromDPTRA
                call XchDP_VA
;                clr RomRam01A
;-----------------StartGetKey-----------------
StartGetEventOnFKey:
                clr A
                mov CallProcView,A
                setb PlayOnKeyEvent
                mov Sevent,#eNone
                mov Levent,#eNone

                jnb EndPressKeyNow,NoSetFKey
                 mov ParamLL,EventKeyUp
                 clr PlayOnKeyEvent
                 jmp LeventEQeNone
NoSetFKey:
                mov A,FKey
                cjne A,#kfNone,NoNoneKey
                 jmp ExitOnExitOnEndPressKeyNow
NoNoneKey:
                cjne A,#kfExtendedKey,$+3
                jnc LongPressed
                 mov SFKey,A
                 add A,#kfExtendedKey
                 mov LFKey,A
                 jmp StartGetFKeyFunc
LongPressed:     mov LFKey,A
                 add A,#-kfExtendedKey
                 mov SFKey,A
StartGetFKeyFunc:
                 call PushProcView
                 mov A,#kmDefault
                 jmp ??NextFunctionKeyScanDCall

AgainGetFKeyFunc:
                clr RomRam01
                call LoadByteFromVideoAdr
;____________________________________________________________________________
;Function Exit
                cjne A,#kfExit,NextFunctionKeyScanExit
                 mov A,CallProcView
                 jnz NoEndKeyScan
                  mov A,FKey
                  mov ParamLH,Levent
                  mov ParamLL,Levent
                  cjne A,SFKey,NoSFKey
                   mov ParamLL,Sevent
NoSFKey:
                  jb EndPressKeyNow,ExitOnEndPressKeyNow
                  mov A,Levent
                  xrl A,#eNone
                  jz LeventEQeNoneA
                   jb LongKeyEvent,ExitOnExitOnEndPressKeyNow
                   mov A,Levent
                   cjne A,#eNoRepeat,NoLevent_eNoRepeat
                    jb FirstKey,LeventEQeNone
                    jmp ExitOnExitOnEndPressKeyNow
NoLevent_eNoRepeat:
                   mov EventKeyUp,ParamLL
                   jb FirstKey,FirstKeyPressed
                    mov A,LFKey
                    xrl A,FKey
                    jz NoThisIsFristKeyPressed
ExitOnExitOnEndPressKeyNow:
                     mov ParamLL,#eNone
ExitOnEndPressKeyNow:clr PlayOnKeyEvent
                     jmp ExitGetFKeyFunc
NoThisIsFristKeyPressed:
                  setb LongKeyEvent
LeventEQeNone:
                  mov EventKeyUp,#eNone
ExitGetFKeyFunc:  clr EndPressKeyNow
                  ret
FirstKeyPressed:  mov ParamLL,#eNone
                  jmp ExitGetFKeyFunc
LeventEQeNoneA:   mov ParamLL,Sevent
                  mov FKey,SFKey
                  jmp LeventEQeNone
NoEndKeyScan:
                 dec CallProcView
                 pop VideoAdrLo
                 pop VideoAdrHi
                 jmp AgainGetFKeyFunc
NextFunctionKeyScanExit:
                mov ParamLL,CallProcView
                cjne ParamLL,#0,NoHighLevelFKey
                 mov ParamLL,A
                 call PushProcView
                 mov A,ParamLL
                 jmp ??NextFunctionKeyScanDCall
NoHighLevelFKey:
;____________________________________________________________________________
;Function DCall
                cjne A,#kfDCall,NextFunctionKeyScanDCall
                  call PushProcView
?NextFunctionKeyScanDCall:
                  call LoadByteFromVideoAdr
??NextFunctionKeyScanDCall:
                  mov DPTR,#ProcEventOnKeyAddrTable
                  call LoadDPTRFromDPTRA
                  jmp ??NextFunctionKeyScanCall
NextFunctionKeyScanDCall:
;____________________________________________________________________________
;Function DJump
                cjne A,#kfDJump,NextFunctionKeyScanDJump
                 jmp ?NextFunctionKeyScanDCall
NextFunctionKeyScanDJump:
;____________________________________________________________________________
;Function Call
                cjne A,#kfCall,NextFunctionKeyScanCall
                  call PushProcView
?NextFunctionKeyScanCall:
                  call LoadDPTRFromVideoAdr
??NextFunctionKeyScanCall:
                  call XchDP_VA
                  clr A
NextFunctionKeyScanCall:
;____________________________________________________________________________
;Function Jump
                cjne A,#kfJump,NextFunctionKeyScanJump
                 jmp ?NextFunctionKeyScanCall
NextFunctionKeyScanJump:

;____________________________________________________________________________
;Function kfSetKeys
                cjne A,#kfSetKeys,NextFunctionKeyScanSetKeys
                  clr OneOfAllKey
?NextFunctionKeyScanSetKeys:
                  call LoadByteFromVideoAdr
                  mov ParamLL,A
                  call LoadByteFromVideoAdr
                  mov ParamLH,A
?NextFunctionKeyScanSetKeys1:
                  call SetKeys
                  clr A
NextFunctionKeyScanSetKeys:
;____________________________________________________________________________
;Function kfSetKeysTo
                cjne A,#kfSetKeysTo,NextFunctionKeyScanSetKeysTo
                  setb OneOfAllKey
                  jmp ?NextFunctionKeyScanSetKeys
NextFunctionKeyScanSetKeysTo:
;____________________________________________________________________________
;Function kfSet10
                cjne A,#kfSet10,NextFunctionKeyScanSet10
                  mov ParamLL,#kf0
                  mov ParamLH,#kf9
?NextFunctionKeyScanSet10:
                  clr OneOfAllKey
                  jmp ?NextFunctionKeyScanSetKeys1
NextFunctionKeyScanSet10:
;____________________________________________________________________________
;Function kfSetLong10
                cjne A,#kfSetL10,NextFunctionKeyScanSetLong10
                  mov ParamLL,#kfL0
                  mov ParamLH,#kfL9
                  jmp ?NextFunctionKeyScanSet10
NextFunctionKeyScanSetLong10:

               jz NoFunctionFKey
                mov ParamLL,A
                call LoadByteFromVideoAdr
                xch A,ParamLL
                cjne A,SFKey,NoShortKeyGet
                  mov Sevent,ParamLL
NoShortKeyGet:  cjne A,LFKey,NoLongKeyGet
                  mov Levent,ParamLL
NoLongKeyGet:   cjne A,#kfAnyKey,NoAnyKeySet
                  mov Sevent,ParamLL
NoAnyKeySet:    cjne A,#kfLAnyKey,NoLAnyKeySet
                  mov Levent,ParamLL
NoLAnyKeySet:
NoFunctionFKey:
                jmp AgainGetFKeyFunc
;--------------Set Keys--------------------------------------
;Set Levent,Sevent on FKey,Function
;In: FKey    - Function Key
;    ParamLL - Low limit
;    ParamLH - High limit
;Out: Sevent - Event on short FKey
;     Fevent - Event on long FKey
;------------------------------------------------------------
SetKeys:setb F0
        mov B,SFKey
Loop2SetKeys:                     ;do{
        mov A,ParamLH             ;if (FKey>=ParamLL&&FKey<=ParamLH)
        cjne A,B,$+3              ;
        jc FKeyOutOfLimit         ;
         mov A,B                  ;
         subb A,ParamLL           ;
         jc FKeyOutOfLimit        ;
          call XAddDPTR_A_G0      ;{ Tmp=MEM[VideoAdr+FKey-ParamLL];
          call LoadByteFromAdrInRomRam01;
          jb F0,NoLongGet         ;  if (!FirstLoop)
           mov Levent,A           ;    Levent=Tmp;
           jmp ExitSetKeys        ;  else
NoLongGet: mov Sevent,A           ;    Sevent=Tmp;
FKeyOutOfLimit:                   ;
        mov B,LFKey               ;
       jbc F0,Loop2SetKeys        ;while(FirstLoop--);
ExitSetKeys:                      ;
       xch A,ParamLH              ;VideoAdr+=ParamLH-ParamLL;
       clr C                      ;
       subb A,ParamLL             ;
       inc A
       call XAddDPTR_A_G0a        ;
       call XchDP_VA              ;
       ret

XAddDPTR_A_G0a:
                jnb OneOfAllKey,NoSetNextOnAll
                 mov A,#1
                 jmp NoSetNextOnAll
XAddDPTR_A_G0:
                jnb OneOfAllKey,NoSetNextOnAll
                 clr A
NoSetNextOnAll:
                mov DPL,VideoAdrLo
                mov DPH,VideoAdrHi
                jmp AddDPTR_A

;------------------------------------------------------------
;void InitSystem(void);
;Init Main Data
;------------------------------------------------------------
InitSystem:
           mov R0,#stack_begin-2
AgainClearData:
            mov @R0,#0
           djnz R0,AgainClearData

;           call SoundOff
;           mov ParamLL,#vAlarm4
;           call ViewDataBufferRom
;           mov ParamLL,#vViewEditNumberO
;           call ViewDataBufferRom

;           call GetMainModeVFuncData
;           mov ParamLL,#vMain
;           call ViewDataBufferRom

;           mov A,#0xFF
;           mov DPTR,#0
;AgainKAA:
;            call SaveByteFromAdrInRam
;            inc DPTR
;            mov A,DPH
;           cjne A,#0x8,AgainKAA
;           jmp $

           ret

;------------------------------------------------------------
StartLoadOpt:
;light
             mov ParamLL,#oLightLevel
             call LoadValueN
             cjne ParamLL,#MaxLightLevel+1,$+3
             jc NoMaxLightLevel
              mov ParamLL,#MaxLightLevel
NoMaxLightLevel:
             mov LightLevel,ParamLL

             mov ParamLL,#oMigLevel
             call LoadValueN
             mov A,#MaxLight+MaxMigLevel
             clr C
             subb A,ParamLL
             mov NiceMigDown,A
;bell
             mov ParamLL,#oFminCall
             call LoadValueN
             call Div500_ParamLL
             mov LBellMax,ParamLL

             mov ParamLL,#oFmaxCall
             call LoadValueN
             call Div500_ParamLL
             mov LBellMin,ParamLL

;Lock
             mov ParamLL,#oAreaLock
             call LoadValueN
             mov A,ParamLL
             rrc A
             mov LockCallAll,C

             mov ParamLL,#oLockAllCalls
             call LoadValueN
             mov A,ParamLL
             rrc A
             mov LockAllNumbers,C

             mov ParamLL,#oLockNumbers
             call LoadValueN
             mov A,ParamLL
             rrc A
             mov LockNumbers,C

             mov ParamLL,#oLockCode
             call LoadValueN
             mov A,ParamLL
             rrc A
             mov LockCountryCode,C

             clr SayNumeralAfterBeep

             mov A,Option
             xrl A,#oLightLevel
             jz NoSetLightLevelOfNight
              jnb LowBattery,NoLowBattery
               mov LightLevel,#LightPowerDown
NoLowBattery: mov R0,#Hours
              mov ParamLLd,@R0
              mov R0,#Minutes
              mov ParamLHd,@R0
              call TestNight
NoSetLightLevelOfNight:

             mov ParamLL,#oVolume
             call LoadValueN
             mov A,ParamLL
             rrc A
             mov Vol0,C
             ret

Div500_ParamLL:
           mov B,ParamLL
           mov A,#250
           div AB
           rl A
           mov R0,A
           mov A,B
           rl A
           mov B,ParamLL
           div AB
           add A,R0
           mov ParamLL,A
           ret

;------------------------------------------------------------
;------------------------------------------------------------
GetMainModeVFuncData:
             mov SelectedValue,#0xFF
             mov ParamLL,#o12ClkView
             call LoadValueN
             mov A,ParamLL
             rrc A
             mov HoursModeView,C

             jnb Saying,NoViewSayingMain
              mov R1,#SecSaying
              mov A,@R1
              mov ParamLL,A
              mov R1,#MinSaying
              mov A,@R1
              mov ParamLH,A
              mov R1,#HourSaying
              mov A,@R1
              mov ParamHL,A
              swap A
              orl A,ParamLH
              subb A,#9
              jc NoMaxHour
               mov ParamLL,ParamLHd
               mov ParamLH,ParamHLd
NoMaxHour:    mov R0,#ValueData
              mov @R0,#vsMainSaying
              inc R0
              mov @R0,ParamLHd
              inc R0
              mov @R0,ParamLLd
              ret
NoViewSayingMain:
             mov ParamLL,#oTypeMainView
             call LoadValueN
             mov R0,#ValueData
             mov @R0,ParamLLd
             inc R0

             mov R0,#ValueData
             inc R0
             clr A
             mov C,LinePresent
             mov ACC.0,C
             mov @R0,A

             cjne ParamLL,#1,NoModeShow1
              inc R0
              mov R1,#DayOfWeek
              mov A,@R1
              mov @R0,A
NoModeShow1:
             push _R+0
             mov ParamLL,#oNewNotSayCalls
             call LoadValueN
             pop _R+0
             inc R0
             mov @R0,ParamLLd
             ret
;------------------------------------------------------------
;Get video data on EFunc
;uchar GetVideoDataOnEFunc(uchar);
;In: EFunc - current function mode
;Out: ParamLL - video data on EFunc
;------------------------------------------------------------
GetVideoDataOnEFunc:
;        mov DPTR,#TblVDOnEFunc
;        mov ParamLL,EFunc
;        mov ParamLH,#2
;        mov ParamHL,#fNone
;        call ScanArray
;        mov A,#1
;        mov A,@A+DPTR
;        mov ParamLL,A
;        ret

        mov DPTR,#TblVDKOnEFunc
        mov A,EFunc
        clr C
        rlc A
        movc A,@A+DPTR
        cjne A,#vNone,NovNoneKKK
         mov A,VFunc
NovNoneKKK:
        mov ParamLL,A
        ret
;------------------------------------------------------------
;Scan const array
;uint ScanArray(uint,uchar,uchar,uchar);
;in: uint DPTR - Start address in ROM
;    uchar ParamLL - Find component
;    uchar ParamLH - Step
;    uchar ParamHL - Last component
;out: uint DPTR - address
;     bit  C  0 - Found
;             1 - not found
;------------------------------------------------------------
ScanArray:
         clr A
         movc A,@A+DPTR
         cjne A,ParamLLd,NoThisComponent
          ret
NoThisComponent:
         cjne A,ParamLHd,NoLastComponent
          setb C
          ret
NoLastComponent:
         mov A,ParamLH
         call AddDPTR_A
         jmp ScanArray

;------------------------------------------------------------
GetKeyMapOn:
         mov A,ParamLL
         setb C
         rlc A
         mov DPTR,#TblVDKOnEFunc
         movc A,@A+DPTR
         cjne A,#kmNone,NormalSet
          mov A,KFunc
NormalSet:
         cjne A,#kmEdEditNumberMainPipeUp,NoSpcFuncA
          jnb ToneCall,NoSpcFuncA
           inc ParamLL
           jmp GetKeyMapOn
NoSpcFuncA:
         mov ParamLL,A
         ret
;------------------------------------------------------------
EventOfModeKey: mov A,ParamLL
                add A,#TblSelModeKey-$-3
                movc A,@A+PC
                mov ParamLL,A
                jmp GetEventOnFKey
TblSelModeKey: db kmModeSubmit,kmSetupSubmit,kmBookSelect
               db kmBeepEmulationSubmit

;------------------------------------------------------------
;void SetCharInEditBuff(uchar);
;in: ParamLL - FKey
;------------------------------------------------------------
SetCharInEditBuff:
                 mov A,ParamLL
                 dec A
                 anl A,#0xF
                 mov ParamLL,A
                 mov R0,#EditBuff+1
                 mov A,@R0
                 swap A
                 mov B,A
                 anl A,#0xF0
                 orl A,ParamLL
                 mov @R0,A
                 dec R0
                 mov A,@R0
                 swap A
                 anl A,#0xF0
                 anl B,#0x0F
                 orl A,B
                 mov @R0,A
                 ret
;------------------------------------------------------------
DeleteCharInEditBuff:
                     mov R0,#EditBuff
                     mov A,@R0
                     swap A
                     mov B,A
                     anl A,#0xF
                     mov @R0,A
                     inc R0
                     mov A,@R0
                     swap A
                     anl B,#0xF0
                     anl A,#0xF
                     orl A,B
                     mov @R0,A
                     ret
;------------------------------------------------------------
;void TestSpecOpt(uchar)
;in: ParamLL - Option
;out: if (SpecOpt)
;        MinMax=new;
;        ValueData-new;
;------------------------------------------------------------
TestSpecOpt:
             cjne ParamLL,#oLenPlayAlarm,NoSpecOpt0
?NoSpecOpt0:  mov ParamLL,#oTypeAlarm
              call LoadValueN
              jmp InsertValueDataA
NoSpecOpt0:
             cjne ParamLL,#oPlayAlarm,NoSpecOpt1
              call ?NoSpecOpt0
              cjne ParamLL,#atSetMode,PlayView
               mov LenEdit,#0x1|(olMx9<<4)
               mov MinValue,#1
               mov MaxValue,#MaxAONModes
               setb CustomMinMax
               mov R0,#EditBuff+1
               mov ParamLLd,@R0
               call TestMinMaxValue
               mov @R0,ParamLLd
               mov R0,#ValueData+1
               mov @R0,ParamLLd
PlayView:     ret
NoSpecOpt1:
             cjne ParamLL,#oVolumeAlarm,NoSpecOpt2
              jmp ?NoSpecOpt0
NoSpecOpt2:
             ret
;------------------------------------------------------------
TestEnableOpt:
             mov ParamLL,Option
             cjne ParamLL,#oVolumeAlarm,NoSelectOpt0
SelectOpt1a:
              mov ParamLL,#oTypeAlarm
              call LoadValueN
              cjne ParamLL,#atSetMode,$+3
              jc ExitTestEnableOpt
;              jc NoSelectOpt0
SelectOpt1:    call NextPrevOption
               jmp TestEnableOpt
NoSelectOpt0:
             cjne ParamLL,#oPlayAlarm,NoSelectOpt1
              mov ParamLL,#oTypeAlarm
              call LoadValueN
              cjne ParamLL,#atWhiteChg,$+3
              jnc SelectOpt1
              ret
NoSelectOpt1:cjne ParamLL,#oAlarmNumberCall,NoSelectOpt1a
              jmp SelectOpt1a
NoSelectOpt1a:
             cjne ParamLL,#oPassword,NoSelectOpt2
              mov ParamLL,#oPassOn
              call LoadValueN
              cjne ParamLL,#0,ExitTestEnableOpt
              jmp SelectOpt1
NoSelectOpt2:
;             cjne ParamLL,#oLockNumbers,NoSelectOpt3
;?NoSelectOpt3:mov ParamLL,#oLockAllCalls
;              call LoadValueN
;              cjne ParamLL,#1,ExitTestEnableOpt
;              jmp SelectOpt1
;NoSelectOpt3:
;             cjne ParamLL,#oLockCode,NoSelectOpt4
;              jmp ?NoSelectOpt3
;NoSelectOpt4:
;             cjne ParamLL,#oRemoteAccess,NoSelectOpt5
;              jmp SelectOpt1
;NoSelectOpt5:
;             cjne ParamLL,#oParalTypeNumberSay,NoSelectOpt6
;              jmp SelectOpt1
;NoSelectOpt6:
ExitTestEnableOpt:
             ret
; mov MinOption,#1
; mov MaxOption,#2
; mov OOption,MinOption
; mov Option,MaxOption
NextPrevOption:
               mov A,OOption
               clr C
               subb A,Option
               jnc NextPrevOptionA
                mov A,OOption
                cjne A,MinOption,NoMinMaxOptA
                 mov A,Option
                 cjne A,MaxOption,NoMinMaxOptA
                  jmp MinMaxOptAPrev
NoMinMaxOptA:
                mov A,Option
                cjne A,MaxOption,$+3
                jc NoSetMinOptionX
MinMaxOptANext:  mov Option,MinOption
                 mov OOption,Option
                 dec OOption
                 ret
NoSetMinOptionX:inc Option
                ret
NextPrevOptionA:
                mov A,Option
                cjne A,MinOption,NoMinMaxOptB
                 mov A,OOption
                 cjne A,MaxOption,NoMinMaxOptB
                  jmp MinMaxOptANext
NoMinMaxOptB:
                mov A,Option
                setb C
                subb A,MinOption
                jnc NoSetMaxOptionX
MinMaxOptAPrev:  mov Option,MaxOption
                 mov OOption,Option
                 inc OOption
                 ret
NoSetMaxOptionX:dec Option
                ret
;------------------------------------------------------------
InsertValueDataA:
             mov ParamLH,#MaxValueData-1
             jmp ?InsertValueData
InsertValueData:
             mov ParamLH,#MaxValueData
?InsertValueData:
             mov R0,#ValueData
             mov A,ParamLL
AgainInsertValueData:
              xch A,@R0
              inc R0
             djnz ParamLH,AgainInsertValueData
             inc SelectedValue
             ret
;------------------------------------------------------------
;void DaySetOnKey(void);
;------------------------------------------------------------
DaySetOnKey:  mov R0,#EditBuff+1
              cjne ParamLL,#kf8,NoSetDays0
               mov @R0,#0x1F
               ret
NoSetDays0:
              cjne ParamLL,#kf9,NoSetDays1
               mov @R0,#0x60
               ret
NoSetDays1:
              cjne ParamLL,#kf0,NoSetDays2
               mov @R0,#0x7F
               ret
NoSetDays2:
;Keys 1..9 -> bits 0..8
BitSetOnKey:  mov R0,#EditBuff+1
              dec ParamLL
              dec ParamLL

              mov ParamXL,ParamLLd
              clr A
              mov B,A
              inc A
              call shlBA_ParamXL

              xrl A,@R0
              mov @R0,A
              dec R0
              mov A,B
              xrl A,@R0
              mov @R0,A
              ret
;------------------------------------------------------------
SetNumberBuff:
              cjne ParamLH,#kfNone,NoKeyNone
               dec LenNumber
               ret
NoKeyNone:
              cjne ParamLH,#kfL1,$+3
              jc NoLong1_6Buff
               mov A,ParamLH
               add A,#-kfL1+10+1
               mov ParamLH,A
NoLong1_6Buff:
              dec ParamLH
              cjne ParamLH,#numToneSet,NoToneSetNow
               mov ParamHL,ParamLLd
AgainFindToneSet:
                mov A,ParamHL
                jz NoToneSetNow
                 dec ParamHL
                 push ParamLLd
                 mov ParamLL,ParamHLd
                 call GetNumberBuff
                 pop ParamLLd
                 cjne A,#numToneSet,NoToneSetPresent
                  dec LenNumber
                  ret
NoToneSetPresent:jmp AgainFindToneSet
NoToneSetNow:

SetNumberBuffA:
              call GetByteNumberBuff
SetNumberBuffAA:
              mov B,@R0
              mov A,ParamLH
              mov ParamLL,#0x0F
              jb F0,NoHighHalfByteNumberBuff
               swap A
               mov ParamLL,#0xF0
NoHighHalfByteNumberBuff:
              anl A,ParamLL
              xch A,B
              xrl ParamLLd,#0xFF
              anl A,ParamLL
              orl A,B
              mov @R0,A
              ret

;------------------------------------------------------------
GetNumberBuff: call GetByteNumberBuff
               mov A,@R0
GetNumberBuffA:jb F0,NoHighHalfByteNumberBuffA
                swap A
NoHighHalfByteNumberBuffA:
               anl A,#0xF
               mov ParamLL,A
               ret
;------------------------------------------------------------

GetByteNumberBuff:
              mov A,ParamLL
              clr C
              rrc A
              mov F0,C
              add A,#Number
              mov R0,A
              ret
;------------------------------------------------------------
GetPauseRolNumber:
                  mov A,ParamLH
                  clr C
                  subb A,ParamLL
                  xrl A,#MaxNumeralView
                  jz PauseRolNumber
                  mov A,ParamLL
                  jz PauseRolNumber
                  jb ACC.7,NoPauseRolNumber
                  mov B,#MaxNumeralView
                  div AB
                  xch A,B
                  jnz NoPauseRolNumber
;                   jmp NoPauseRolNumber
                  mov A,#MaxNumeralView
                  mul AB
                  clr C
                  xch A,ParamLH
                  subb A,ParamLH
                  clr C
                  subb A,#MaxNumeralView
                  jc NoPauseRolNumber
PauseRolNumber:   setb C
                  ret
NoPauseRolNumber: clr C
                  ret
;------------------------------------------------------------
StartImpulse:orl P4,#P4KZ
;             mov DPTR,#HighP4Address
;             clr EA
;             mov A,P4
;             movx @DPTR,A
;             setb EA
             ret
StopImpulse: anl P4,#Low(~P4KZ)
;             mov DPTR,#HighP4Address
;             clr EA
;             mov A,P4
;             movx @DPTR,A
;             setb EA
             ret
InvertImpulse: xrl P4,#P4KZ
               ret
;------------------------------------------------------------
LoadCallParam:
              mov ParamLL,#oSpeedNumeralCall
              call LoadValueN
              call Convert10msTo4ms
              mov A,ParamLL
              clr C
              rrc A
              mov ParamLL,A
              mov LenPauseImpulse,ParamLL
              mov A,ParamLL
              mov B,#3
              div AB
              setb C
              rlc A
              mov ParamLL,A
              mov LenImpulse,ParamLL
              mov ParamLL,#oTypeLineCall
              call LoadValueN
              mov A,ParamLL
              mov C,ACC.0
              mov ToneCall,C
              mov ParamLL,#oEveryNumeralBeepTest
              call LoadValueN
              mov A,ParamLL
              mov C,ACC.0
              mov TestEveryNumeralBeep,C
              mov ParamLL,#oWaitNextNumeral
              call LoadValueN
              call Convert10msTo4ms
              mov PauseUntilNextNumeral,A
              ret
;------------------------------------------------------------
Convert10msTo4ms:mov A,ParamLL
                 setb C
                 rlc A
                 mov B,A
                 mov A,ParamLL
                 clr C
                 rrc A
                 add A,B
                 mov ParamLL,A
                 ret
;------------------------------------------------------------
GetEventOnBeepMap: mov DPTR,#BeepEvents
                   mov A,ParamLL
                   rl A
                   rl A
                   call AddDPTR_A
                   mov A,ParamLH
                   movc A,@A+DPTR
                   mov ParamLL,A
                   ret
;------------------------------------------------------------
RetEvent:
         mov A,EventPush
         jz NoNormalRet
          dec EventPush
          dec A
          jnz NormalRet
           pop A
           pop B
           pop ParamLLd
           pop ParamLLd
           push B
           push A
           ret
NormalRet:
          pop A
          pop A
NoNormalRet:
         ret
;------------------------------------------------------------
CallEvent:
          mov Event,ParamLL
          inc EventPush
          mov R0,SP
          mov A,EventPush
          rl A
          clr C
          xch A,R0
          subb A,R0
          inc A
          mov R0,A
          mov DPL,@R0
          inc R0
          mov DPH,@R0
          clr A
          jmp @A+DPTR
;------------------------------------------------------------
EventCallPosition: mov A,EventPush
                   jnz NoFirstCall
                    pop A
                    pop B
                    push B
                    push A
                    push B
                    push A
                    inc EventPush
NoFirstCall:       ret
;------------------------------------------------------------
LoadDefaultNumber:mov ParamLH,ParamLLd
                  mov DPTR,#DefaultNumberBuffer
                  call LoadByteFromAdrInRamP
                  mov B,A
                  anl A,#0x3f
                  mov ParamLL,A
                  cjne ParamLH,#0,NoFuncLoadAllNumber
                   mov LenNumber,A
                   mov C,B.6
                   mov EditCallBuff,C
                   mov C,B.7
                   mov TypeNumber,C
                   mov R0,#Number
AgainLoadNumberBuff:
                    call LoadByteFromAdrInRamP
                    mov @R0,A
                    inc R0
                   cjne R0,#Number+DataLenNumber,AgainLoadNumberBuff
NoFuncLoadAllNumber:
                  ret

;------------------------------------------------------------
SaveDefaultNumber:jb ParallelNumber,ExitSaveDefaultNumber
SaveDefaultNumberA: mov DPTR,#DefaultNumberBuffer
                    mov A,LenNumber
                    mov C,EditCallBuff
                    mov ACC.6,C
                    mov C,TypeNumber
                    mov ACC.7,C
                    call SaveByteFromAdrInRamFP
                    mov R0,#Number
AgainSaveNumberBuff:
                     mov A,@R0
                     call SaveByteFromAdrInRamFP
                     inc R0
                    cjne R0,#Number+DataLenNumber,AgainSaveNumberBuff
ExitSaveDefaultNumber:
                  ret
;------------------------------------------------------------
XchgNumbBuffers: mov DPTR,#DefaultNumberBuffer
                 call LoadByteFromAdrInRamP
                 anl A,#0x3f
                 mov ParamLL,A
                 inc A
                 clr C
                 rrc A
                 inc A
                 mov ParamLH,A
                 mov ParamHL,A
                 jmp StartFastLoadNumberBuff
AgainFastLoadNumberBuff:
                  call LoadByteFromAdrInRamP
                  push A
StartFastLoadNumberBuff:
                 djnz ParamLH,AgainFastLoadNumberBuff

                 mov DPTR,#DefaultNumberBuffer
                 mov A,LenNumber
                 mov C,EditCallBuff
                 mov ACC.6,C
                 mov C,TypeNumber
                 mov ACC.7,C
                 call SaveByteFromAdrInRamP
                 mov A,LenNumber
                 inc A
                 clr C
                 rrc A
                 inc A
                 mov ParamLH,A
                 mov R0,#Number
                 jmp StartFastSaveNumberBuffA
AgainFastSaveNumberBuffA:
                  mov A,@R0
                  call SaveByteFromAdrInRamP
                  inc R0
StartFastSaveNumberBuffA:
                 djnz ParamLH,AgainFastSaveNumberBuffA

                 mov LenNumber,ParamLL
                 mov A,ParamHL
                 add A,#Number-2
                 mov R0,A
                 jmp StartFastSaveNumberBuffB
AgainFastSaveNumberBuffB:
                  pop A
                  mov @R0,A
                  dec R0
StartFastSaveNumberBuffB:
                 djnz ParamHL,AgainFastSaveNumberBuffB
                 ret
;------------------------------------------------------------
ResetDefaultNumberBuff: mov DPTR,#DefaultNumberBuffer
                        clr A
                        call SaveByteFromAdrInRam
                        ret
SetDefaultLenNumberBuff:mov DPTR,#DefaultNumberBuffer
                        call LoadByteFromAdrInRam
                        anl A,#0xC0
                        orl A,ParamLL
                        call SaveByteFromAdrInRam
                        ret
;------------------------------------------------------------
SetDefaultNumeralBuff:mov DPTR,#DefaultNumberBuffer-Number+1
                      call GetByteNumberBuff
                      call AddDPTR_A
                      call LoadByteFromAdrInRam
                      mov ParamHL,A
                      mov R0,#ParamHLd
                      call SetNumberBuffAA
                      call SaveByteFromAdrInRam
                      ret
;------------------------------------------------------------
GetNumeralDefaultBuff:mov DPTR,#DefaultNumberBuffer-Number+1
                      call GetByteNumberBuff
                      call AddDPTR_A
                      call LoadByteFromAdrInRam
                      jmp GetNumberBuffA
;------------------------------------------------------------
;-----------------------------------------------------------
SetSpeakerOnOff: jnb SpeakerOn,SetSpeakerOff
SetSpeakerOn:     %setbit Amplifer,AmpliferOn
                  %setbit MuteSet,SetMuteOn
                  setb SpeakerOn
                  ret
SetSpeakerOff:    %setbit Amplifer,AmpliferOff
                  %setbit MuteSet,SetMuteOff
                  clr SpeakerOn
                  ret
SetSpeakerOnA:    %setbit MuteSet,SetMuteOn
                  ret
;-----------------------------------------------------------
PipeOnOff: jnb PipeUp,PipeOff
PipeOn:     %setbit MuteSet,SetMuteOn
            ret
PipeOff:    %setbit MuteSet,SetMuteOff
            ret
;-----------------------------------------------------------
LineUp:%setbit PipeSet,SetPipeUp
       setb LineLoad
       ret
LineDown:%setbit PipeSet,SetPipeDown
         clr LineLoad
         ret
;-----------------------------------------------------------
SoundOn:
          %setbit Sound,SetSoundOn
          setb Snd
          %setbit Amplifer,AmpliferOn
          ret
SoundOff:
          %setbit Sound,SetSoundOff
          clr Snd
          jnb EndTime_snd,NoEndPlaySnd
            %setbit Amplifer,AmpliferOff
NoEndPlaySnd:
          ret
;------------------------------------------------------------
;bit ParallelTest(void);
;out: bit 0 - not present
;         1 - present
;------------------------------------------------------------
TimeParallelTest = 200
ParallelTest: mov ParamLL,#Low(TimeParallelTest)
;              mov ParamLH,#High(TimeParallelTest)
              call LineDown
              setb C
AgainParallelTest:
                movx A,@R0
                cpl A
                mov P4IN,A
                jb Line,NoParallelUp           ;0 - line not present
               djnz ParamLL,AgainParallelTest
;              djnz ParamLH,AgainParallelTest
              clr C
NoParallelUp: call LineUp
              ret
;------------------------------------------------------------
GetLenPackOfLenNumberMinLen:
        mov ParamLL,#0
        mov A,LenNumber
        cjne A,#16,$+3
        jc NoLongLenNumber
         inc ParamLL
NoLongLenNumber:
        add A,ParamLL
        clr C
        rrc A
        inc A
        add A,MinLen
        mov ParamLL,A
        ret
;------------------------------------------------------------
ShowBusy:
         mov ParamLL,#vBusy
         jmp ViewDataBufferRom
;------------------------------------------------------------
DeviceReset: clr EA
             jmp 0
;------------------------------------------------------------
;TestNight
;in: ParamLL - hours
;    ParamLH - minutes
;------------------------------------------------------------
#define CurrH ParamLLd
#define CurrM ParamLHd
#define StartH ParamHLd
#define StartM ParamHHd
#define EndH ParamXLd
#define EndM ParamXHd
#define HComp1 ParamYLd
#define MComp1 ParamYHd
#define HComp2 VideoAdrLo
#define MComp2 VideoAdrHi

TestNight:
;               mov $PRMBD TestNight,ParamLL
;               mov $PRMBD TestNight+1,ParamLH
               push ParamLLd
               push ParamLHd
               mov ParamLL,#oNightOn
               CALL LoadValueN
               cjne ParamLL,#0,NoNightOff
                pop A
                pop A
                clr Night
                clr C
                ret
NoNightOff:
               mov ParamLL,#oNightFromHour
               CALL LoadValueN
               push ParamLLd
               mov ParamLL,#oNightFromMin
               CALL LoadValueN
               push ParamLLd
               mov ParamLL,#oNightToHour
               CALL LoadValueN
               push ParamLLd
               mov ParamLL,#oNightToMin
               CALL LoadValueN
               mov EndM,ParamLL
               pop EndH
               pop StartM
               pop StartH

               pop CurrM
               pop CurrH

;               mov StartH,#23
;               mov StartM,#0
;               mov EndH,#9
;               mov EndM,#0
;               mov CurrH,#10
;               mov CurrM,#0

               call TestTime
               mov Night,C
               jnc NoNightNow
                mov LightLevel,#0
;                mov ParamLL,#MinAONVolume
;                call SetVolume
NoNightNow:
               ret
;------------------------------------------------------------------
;------------------------------------------------------------------
#define InvertResult F0
TestTime:
        mov HComp1,StartH
        mov MComp1,StartM
        mov HComp2,EndH
        mov MComp2,EndM
        clr C
        call CompTimeC
        cpl C
        mov InvertResult,C
        jnc NoXCHStartEndT
         mov A,StartH
         xch A,EndH
         mov StartH,A
         mov A,StartM
         xch A,EndM
         mov StartM,A
NoXCHStartEndT:
        mov HComp1,StartH
        mov MComp1,StartM
        mov HComp2,CurrH
        mov MComp2,CurrM
        call CompTime
        jnc NoBiggerStart
         mov HComp1,CurrH
         mov MComp1,CurrM
         mov HComp2,EndH
         mov MComp2,EndM
         clr C
         call CompTimeC
NoBiggerStart:
        jnb InvertResult,NoInverResult
         cpl C
NoInverResult:
        ret

CompTime:
 setb C
CompTimeC:
 mov A,MComp1
 subb A,MComp2
 mov A,HComp1
 subb A,HComp2
 ret
;------------------------------------------------------------
;SetVolume:
;          ret

;------------------------------------------------------------
;------------------------------------------------------------
PrintError:
           mov R0,#ValueData
           mov @R0,ParamLLd
           mov ParamLL,#vShowError
           call ViewDataBufferRom
           jmp $
;------------------------------------------------------------
TestROM: clr BankB0
         mov DPTR,#0
         call LoadByteBankCDPTR

         clr C
         ret
;------------------------------------------------------------
ShowPowerDown:
               mov R0,#VideoBuffer
AgainClearVideoData:
                clr A
                mov @R0,A
                inc R0
                mov @R0,A
                inc R0
               cjne R0,#VideoBuffer+MaxRazr*2,AgainClearVideoData
               dec R0
               mov @R0,#cpixel
               dec R0
               mov @R0,#MigType2
               ret
;------------------------------------------------------------
;XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
;------------------------------------------------------------
          RSEG D_UDATA

EventPush:    DS 1

CallProcView: DS 1
VideoAdrLo:   DS 1
VideoAdrHi:   DS 1
;CurrentValue: DS 1
EventKeyUp:        DS 1
          RSEG BITVARS
RomRam01:       DS 1
;RomRam01A:      DS 1
FirstKey:       DS 1
PlayOnKeyEvent: DS 1
LongKeyEvent:   DS 1
EndPressKeyNow: DS 1
HoursModeView:  DS 1
 END