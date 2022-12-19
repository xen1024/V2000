/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

#define _ASM
$set.h
#define Kateg                   Number+10
#define OffsetBankFunctions     0x80
#define LenShowA                TypeEdit

; T2 bits
TF2       = 0xCF
EXF2      = 0xCE
RCLK      = 0xCD
TCLK      = 0xCC
EXEN2     = 0xCB
TR2       = 0xCA
C_T2      = 0xC9
CP_RL2    = 0xC8
; T2 registers
T2CON     = 0xC8
T2MOD     = 0xC9
RCAP2L    = 0xCA
RCAP2H    = 0xCB
TL2       = 0xCC
TH2       = 0xCD

; uchar
 extern _R,LightLevel,FKey
 extern DayCall,MonthCall,HourCall,DayOfWeekCall,MinCall,HourSay,MinSay
 extern EFunc,KFunc,TypeEdit,PosEdit,LenEdit
 extern SelectedValue,Option,OOption,MinValue,MaxValue
 extern OffsetNumberView,LenNumber,PosCall,Event,LenPauseImpulse
 extern LenImpulse,PauseUntilNextNumeral
 extern Seconds,MinSaying,HourSaying,VFunc,MinLen
 extern MinSaying,HourSaying,Hours,Minutes,DayOfWeek,Day,Month,Seconds
 extern NPhrase,MaxOption,MinOption,Year,SecSaying
; bit
 extern TypeOfData,EditModeValue,OptChanged,CallSelect,PassEnter
 extern TypeNumber,EditCallBuff,DontPlaySounds,ToneCall
 extern TestEveryNumeralBeep,LineLoad,PipeUp,AutoDial,ShowSearch
 extern HangUp,Snd,Saying,SaveNumberNow,SpeakerOn,ParallelNumber
 extern LockAllNumbers,LockCallAll,LockCountryCode,LockNumbers
 extern SayNumeralAfterBeep,PlayExitSound,Night,TodaySee,LowBattery
; char array
 extern ValueData,VideoBuffer,EditBuff,Number,WavData
; functions
 extern LoadNumber
 $DEFFN LoadNumber(3,0,0,0)
 extern SaveNumber
 $DEFFN SaveNumber(3,0,0,0)
 extern SayPhrase
 $DEFFN SayPhrase(2,0,0,0)
 extern SayKey
 $DEFFN SayKey(3,0,0,0)

T0_1ms = -(FREQ/12/4500)+9 ;Reset timer value

#define ByteLo    ParamLLd
#define ByteHi    ParamLHd
#define BitShift  ParamHL
#define BitLen    ParamHH

#define XOption   ParamLH
#define ByteLen   ParamYL
#define AddrPlusO ParamYH



;FUNCTIONS
#ifndef __HD_CHG
 extern XchDP_VA,AddDPTR_BA,AddDPTR_A,rrcA_B,SubDPTR_BA
 extern HexToDec,DecToHex,DecDPTR,ABTabelAHTDW_A
 extern GetMemDataaR0,MulaR1_AtoaR1,AddwaR0_aR1toaR1,IncwaR0
 extern LoadByteFromAdrInRamaR0,AddwaR0_A,DecwaR0,CompaR0_aR1
 extern SubwaR1_aR0toaR1,SaveByteFromAdrInRamaR0P,LoadByteFromAdrInRamaR0P
 extern SubwaR0_A,stack_begin,stack_malloc
 extern shrA_B,shlA_B,shlBA_ParamXL,shrBA_ParamXL
 extern Append2Bytes,GetByteFromWord,rlcA_B
 extern LoadByteFromAdrInRamP,SaveByteFromAdrInRamP
 extern SaveByteFromAdrInRamF,SaveByteFromAdrInRamFP
 extern GetDPTR_BA,stack_mfreelast,HexTo5DecWord
#endif
#ifndef __System
 extern VideoAdrLo,VideoAdrHi
 extern PlayOnKeyEvent
 extern FormatOptionsTBL,StartVideoTbl,SoundUnPackTbl,GetNumberBuff
 extern SetNumberBuffA,ViewDataBufferRom,PrintError
 extern RomRam01
#endif
#ifndef __Timers
 extern NowKey,LongPressKey,KeyPresent,FirstKeyt,NiceMigDown
 extern DetectingTone,StartT1_8,StopPlay,OutByte,EndKvantDecode
 extern XrlByte,XTone1Lo,XTone1Hi,StepTone1,DeviderTo2ms
 extern LinePresent,EndReciveNumeral,RecivedNumeral,ImpulseNumeral
 extern LBell,LBellMin,LBellMax,DebugLBell,P4,EndTime_snd
 extern NRazr,NRazrB,VideoBit9,BankPlay,StepTone2,TReload,EndWavPlay
 extern TCXsnd,MeandrPlay,StartPlay16,MelodyPlay,TimerModePIC
 extern LoadByteBankCDPTR
 extern P4IN
#endif
#ifndef __Flash
 extern LoadByteFromAdrInRam,SaveByteFromAdrInRam
 extern PushC1,StopSendFlash
#endif
#ifndef __OptWork
 extern LoadValue,SaveValue,LoadValueN,CustomMinMax
 extern TestMinMaxValue
#endif
#ifndef __ToneDetect
 extern ToneDetect
 extern TimerToneDecode
#endif

#define PosDataSoundLo StepTone1+1
#define PosDataSoundHi StepTone1
#define WawLenLo       TReload+1
#define WawLenHi       TReload
#define SamplePosLo    TCXsnd+1
#define SamplePosHi    TCXsnd

#define DATABitToPIC   RomRam01

F2E_7 equ BankPlay
;#define F2E_7 BankPlay                  ;MelodyPlay