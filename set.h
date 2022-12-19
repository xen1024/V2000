/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */


#define DEBUG           //DEBUG MODE
//#define DEBUG_KeyEmulation
//#define DEBUG_FLASH
#define GetAnswerSizeBuff 12+3

//Time
#define Minms 4
#define FREQ 16000000                        //Freq OSC Hz
#define CYCLE FREQ/12                        //Cycle
#define DefaultTimeOutViewRolNuber 70        //4ms
#define LongTimeOutViewRolNuber    250       //4ms
#define TimeOutExitMain            60        //s
#define KvantTimeBeep              0x10000-33333//25ms=Timer
#define TXSquare500Hz              0x520     //2ms=~Timer   0x524
#define LenPauseAfterSayWav        200      //ms
#define TXSine500Hz                Tone_f0   //Request Timer
#define RequestStep500Hz           0x08C0    //Request 0x88A 0x8b8
#define TXwav                      0x1C      //Wav Timer
#define TX1ms                      0x10000-1333//1ms=Timer
#define PausePipeOff               10        //4ms
#define BeepLineFreq               0x0600    //StartBeepFreq

#define PauseBeforeNextDial        250       //4ms
#define FastBeepTestTime           250       //s
#define BeepTestTimeAutoDialOnKey  10        //s
#define LenTone                    100/Minms //ms
#define PauseCallLen               4         //s
#define BeepLongWaitTime           15        //s
#define BeepShortTestWaitTime      5         //s
#define Pause4sWait                4         //s
#define AutoCallLineUpBeepWait     5         //s
#define LenWaitOnEndCalled         10        //s
#define WaitTimeCallToExit         10        //s
#define DefaultTimeShow            200       //4ms
#define LenMinPauseWav             50        //ms

//#define TimeLenBeep                     1    //s
#define TimeLenBeep4ms                  250  //4ms
#define TimeBeepDetectBeepEmulation     3    //s
#define TimeSayBeepDetect               15   //s
#define FastToneBeepDetectBeepEmulation 2    //s
#define TimeOutReset                    6    //s
#define TimeOutReset4ms                 250  //4ms
#define LenTimeBCallPauseSaying         1    //s
#define LenTimeBCallStartTimeDetect     180  //s
#define LenTimeWaitBeforeAutoStartAutoDial 4 //s
#define LenTimeWaitBeforeStartSayingParallel 10 //s
#define LenTimeBeforeUnLockLine         2    //s
#define TimeBeforeNextVolume            200  //4ms
#define LenPeriodHold                   2    //s
#define LenBeepTestHold                 3    //s
#define LenPeriodGetLine                2    //s
#define LenWaitBeforeAutoSearch         4    //s
#define LenDefaultTimeShowFilter        2    //s
#define LenDefaultTimeShowPassTest      2    //s

#define LenPeriodConfidence             8    //s
#define LenTestBeepToPipeDown           20   //s
#define LenWaitBeforeTestBeepToPipeDown 20   //s
#define LenWaitBeforePipeDownNow        30   //s


#define NumberOfRepeatSayInLine         3    //NRepeats say in line

#define NBeepsLineDown                  200

#define AutoDialLoops                   30
#define RepeatLoopBCallSay              20   //Back call: NRepeats say in line

#define MaxVolume 63


#define ParamYL R0      //Addon2 parametr 0
#define ParamYH R1      //Addon2 parametr 1
#define ParamXL R2      //Addon1 parametr 0
#define ParamXH R3      //Addon1 parametr 1
#define ParamLL R4      //Proc parametr 0
#define ParamLH R5      //Proc parametr 1
#define ParamHL R6      //Proc parametr 2
#define ParamHH R7      //Proc parametr 3
#define ParamYLd 0
#define ParamYHd 1
#define ParamXLd 2
#define ParamXHd 3
#define ParamLLd 4
#define ParamLHd 5
#define ParamHLd 6
#define ParamHHd 7

#define NumbBuffer 0

#define MaxValueData 5

#define HighVideoAddress 0x7f //Mem high address for Video Output
#define HighP4Address    0xbf //Mem high address for emul P4
#define P4INAddress      0x010000

#define SoundsTable      40000

//Line WORK
#define LineData P1.2
#ifdef _ASM
// #define P4IN     0x20 //P4IN !!!!!! BITVARS must +8!!!
Line    EQU P4IN.1
Bell    EQU P4IN.0
GetPipe EQU P4IN.2
LowBatteryData EQU P4IN.3
#endif
#ifdef _C
 sfr P4IN = 0x20;
 bit Line = P4IN.1;
 bit Bell = P4IN.0;
 bit GetPipe = P4IN.2;
 bit LowBatteryData = P4IN.3;
#endif
#define PipeSet   P1.1
#define LineSet   PipeSet
#define MuteSet   P1.5
#define SndToLine P3.2
#define Sound     P3.3
#define BankB0    P1.3
#define BankB1    P1.4
#define Amplifer  P3.5
#define DATAbusPIC  P1.0        //PIC BUS
#define Vol0      P3.4

#define P4KZ          0x02
#define P4MaxLevelSnd 0xFC
#define SetPipeUp   0
#define SetPipeDown 1
#define SetMuteOn   0
#define SetMuteOff  1
#define AmpliferOn  0
#define AmpliferOff 1
#define SetSoundOn  1
#define SetSoundOff 0
#define SetLineUp   SetPipeUp
#define SetLineDown SetPipeDown
#define SndToLineOn   0
#define SndToLineOff  1
#define MuteOn       1
#define MuteOff      0

//Sound
#define StartSquareFreq 349
#define StepSquareFreq  0x7b
#define SndCenter 0x80
#define LenBeepKey      15
 //Tone
#define Tone_f0 0xA5
#define yf0 0x0BE7
#define yf1 0x0D27
#define yf2 0x0E8D
#define yf3 0x1012
#define xf0 0x14A6
#define xf1 0x16D1
#define xf2 0x18B7


//FLASH 24CXX
#ifndef DEBUG_FLASH
#define SDA  P1.7
#define SCL  P1.6
#endif


// INDIKATOR
// RAZR[0..7]:
//   NRazr=0x01..0x80(rl);
//   MEMB[0x80][NRazrB]=DataRazr;
//   MEMB[0x40][0]=P4=xxxxxxx0;
// RAZR[8]:
//   xxxxxxxxx=P4;
//   MEMB[0x40][0]=P4=xxxxxxx1;
//   MEMB[0x80][0]=DataRazr;
#define Bit9IndHW        1<<0 //Bit ind in P4

#define segA 0x1
#define segB 0x2
#define segC 0x4
#define segD 0x8
#define segE 0x10
#define segF 0x20
#define segG 0x40
#define segH 0x80
#define cpixel segH
// Chars define table
#define c0 segA|segB|segC|segD|segE|segF
#define c1 segB|segC
#define c2 segA|segB|segD|segE|segG
#define c3 segA|segB|segC|segD|segG
#define c4 segB|segC|segF|segG
#define c5 segA|segC|segD|segF|segG
#define c6 segA|segC|segD|segE|segF|segG
#define c7 segA|segB|segC
#define c8 segA|segB|segC|segD|segE|segF|segG
#define c9 segA|segB|segC|segD|segF|segG
#define cMNS segG
#define cSP 0
#define c_ segD
#define co segC|segD|segE|segG
#define cA segA|segB|segC|segE|segF|segG
#define cb segC|segD|segE|segF|segG
#define cC segA|segD|segE|segF
#define cd segB|segC|segD|segE|segG
#define cE segA|segD|segE|segF|segG
#define cF segA|segE|segF|segG
#define ct segD|segE|segF|segG
#define cn segC|segE|segG
#define cS segA|segC|segD|segF|segG
#define cU segB|segC|segD|segE|segF
#define cP segA|segB|segE|segF|segG
#define cL segD|segE|segF
#define cr segE|segG
#define cc segD|segE|segG
#define ch segC|segE|segF|segG
#define cu segC|segD|segE
#define cH segB|segC|segE|segF|segG
#define cPr segA|segB|segC|segE|segF
#define cMl segA|segB|segE|segF
#define cMr segA|segB|segC|segF
#define ci segC
#define cIl segE|segF
#define csE segE
#define csEsC segC|segE
#define cY segB|segC|segD|segF|segG
#define cGr segA|segE|segF
#define cWl segC|segD|segE|segF
#define cWr segB|segC|segD|segE
#define cG segA|segC|segD|segE|segF
#define cEQ segD|segG
#define cAGEl segD|segE
#define cAGEr segC|segD
#define ccb segC|segD|segG
#define cHio segA|segB|segF|segG
#define cl segE|segF
#define cV segB|segC|segD|segE|segF

#define NoMig    0x00           //No Mig
#define MigType1 0x10           //Mig 1/2s
#define MigType2 0x20           //Mig 1/4s
#define MaxLight 7+3            //Max light seg
#define MaxRazr  9              //Max razr ind
#define MaxLightLevel 7         //Max value for LightLevel
#define MaxMigLevel 5

// KEYBOARD
#define DecreaseSpeed    1     //KeySpeed down speed
#define MinKeySpeed      4     //Min value of KeySpeed(max speed repeat)
#define PauseAntiSpark   6     //Anti spark pause
#define StartPause0      35    //Pause on first key pressed
#define MaxLevelSpeedKey 10    //Levels speed key
#define StartKeySpeed MinKeySpeed+DecreaseSpeed*MaxLevelSpeedKey
                               //Start speed key(min speed key)
#define LongRepeatKey    3     //Long press key
#define KeyPerLine       4     //Keys per line
#define KeyLines         8     //Number of lines
#define LenKeyA          KeyPerLine*KeyLines
                               //Max real keys
// Reset  0x15 Fire   0x3
// Store  0x11 Police 0x7
// Flash  0x14 Doctor 0xB
// Mode   0xF  Pause  0x17
// Redial 0x12 Recall 0x13

#define MaxAONLabelType 3
#define MaxAONModes     7

#define CheckResetData 0xAAA

#define mldyGetLine             31
#define mldyStartPassEnter      34
#define mldyPassEnter           31
#define mldySettedTime          31
#define mldyError               33
#define mldyTodaySeeMldy        31
#define mldyHourBeep            34

#define mldyBell                35
#define mldyEnterRemoteAccessKey mldyBell+10
#define mldyLogo                 mldyBell+11 //22 //11

#define MaxCharsLogo            3
#define LenWaitShowCurrLogo             3  //s
#define LenWaitContinueShow             20 //4ms
#define LenWaitBeforeShowNextLogo       250//4ms

#define volUp     0x2
#define volLow    0x0
#define volHigh   0x1

#define MaxValueAllCalls 16300

#define LightPowerDown          1              //Light
#define LenWaitBeforePowerDown  10             //s

#define MaxAlarmModes 8

#ifdef _C
//---------------------------------------------------------------
enum Events {eMode,           // Set Function FSelectMode
             eCall,           // Call user
             eMinOver,        // Minute is over
             eTakeNumeralKey, // Take numeral from key
             eBeepStart,      // Start Beep tone
             eBeepEnd,        // Stop Beep tone
             eSubmitMode,     // Selected mode(fMode)
             eExitToMain,     // Exit to MainMode
             eReturn,         // Return to previous function(exit form fMode)

             eKeyPresent,     // PressKey
             eKeyPresentNoSnd,// PressKey without snd
             eK0_9,           // Insert 0..9

             eBitDaySet,
             eIncOption,
             eIncOptionA,
             eDecOptionA,
             eSetMin,
             eSetMax,
             eSetCharEditBuff,
             eDeleteCharEditBuff,
             eNextOption,
             ePreviousOption,
             eEnterOption,
             eSetupMode,
             eBookSelectMode,

             eEditOpt0,
             eEditOpt1,
             eEditOpt2,
             eEditOpt3,
             eEditOpt4,
             eEditBud,
             eEditNight,

             eUpdateView,
             eAdd_CallNumeralBuff,
             eAddNumeralBuff,
             eDeleteNumeralBuff,
             eMainEditNumber,
             eShowNumber,
             eRolNumber,

             eBeepDetected,
             eNextNumeralCall,
             eStopCallSet,
             eStartImpulseSet,
             eStartImpulseSetA,
             ePipeIsUp,
             eStartKZ,
             eStopKZ,
             ePipeIsDown,
             eNextNumeralCallN,
             eToneSet,
             eToneSetKey,
             eSpeakerPhoneChange,
             ePipeChanged,
             eReturnKeyEvent,

             eAutoDialKey,
             eAutoDial,
             eAutoDialA,
             eFlashStart,
             eFlashEnd,
             eRedialA,
             eRedial,
             eBeepTestCallA,
             eBeepTestCall,
             eStartSayingData,
             eStopSayingData,
             ePauseUntilStartSaying,

             eStartBell,
             eEndBell,
             eIndification,
             eStartIndificate,
             eAnswerListening,
             eSendRequest,
             eIndificationGetAnswer,
             eStartBeepLine,
             eEndBeepLine,
             ePlayBellInRoom,

             eNextPlayWav,
             eSayCurrentTime,

             eStartEditNumber,
             eStartEditNumberAddNumeral,
             eSubmitEditNumber,
             eAutoNext,
             eAutoPrevious,
             eClearBook,
             eDeleteNumber,
             eShowBook,
             eSetUndefinedNumber,
             eEnterClearNumber,
             eEnterClearPropAllNumber,
             eSubmitClearPropAllNumber,

             eShowKateg,
             eShowTimeCall,
             eShowTimeSay,
             eShowDateCall,
             eShowCallsPerTime,
             eShowAllTimeSay,
             eChangeShowAllTimeSay,
             eStartNumberSay,
             eNextNumberSay,
             eNextNumberSayInTime,
             eNextLineNumberSay,

             eTestCurrBeepTone,

             eSetNoSoundPlay,
             eSetSoundPlay,
             eSetListenLine,

             eSayLineCurrPhrase,
             eRecallLater,
             eRecallTomorrow,
             eRecallInTimeLater,
             eNumberUndefined,
             eRecallReaddress,
             eReaddressingNumber,
             eReaddressingTime,
             eReaddressingPager,

             eRepeatPhrase,
             eRepeatPhraseN,

             eEnterReset,
             eResetAll,
             eReset,

             eEditAONMode,

             eAutoNext2ByOn,
             eAModeSet,
             eEditBCallNumber,

             eEditReaddressingNumber,
             eEditReaddressingTime,
             eEditReaddressingPager,

             eBCallStart,
             eBCallStartTest,
             eBCallSay,
             eBCallBeepTest,
             eSoundMode,

             eAddNumeralParallel,
             eEnterLock,
             eTestLineFree,

             eNextNotePlay,
             eTestMelody,
             eVolumeUp,
             eStopTestMelody,

             eHold_LineGet,
             eTestLineHold,
             eStartMelodyHold,
             eBeepTestHold,
             eTestLineFreeGetLine,

             eEnterSearch,
             eSerachNext,
             eReturnSearch,

             eAntiAONStart,
             eImpulseAntiAON,

             eEditCharBuff,
             eEditFilter,
             eSetFilter,

             eEnterStore,
             eEnterStoreCustomNumber,
             eStoreCustomNumber,
             eStoreCustomBook,
             eStoreFirstFree,

             eNewPasswordEnter,
             eEditLock,

             eEnterPassword,
             ePasswordSubmit,
             eReturnShowPass,

             eSayCurrKey,
             eExitToMainTime,

             eEditTimeDate,

             eSetDate,
             eHoursSet,
             eMinutesSet,
             eEnterSetSecondsZeroMode,
             eSetSecondsZero,

             eContinueTestTime,
             eStartTestTime,

             eStartPlayAlarm,
             eSayTimeAlarm,
             eDecMinAlarm,

             eVolumeChange,

             eShowLogo,
             eContinueShowLogoA,
             eContinueShowLogoB,

             eSet8Book,

             eConfidenceOnOff,
             eTestConfidence,
             eTestBeepToPipeDown,
             eTestPipeDownNow,

             eEnterPowerDown,
             eLeavePowerDown,
             eTestPowerDown,

             eEnterFoundBook,

             eEnterRemoteAccess,
             eRemoteAccessKey,
             eSayVideoData,
             eContinueTestBeepRemoteAccess,
             eKeyUpEmulation,

             eShowVersionInfo,
             eMoveVersioInfo,
             eAutoDialCustomNumber,
             eSubmitCustomDialNumber,

             eDebugBeep,

             eEnterExtFunct,

             eNoRepeat,
             eNone           // No Events
            };
//---------------------------------------------------------------
enum FunctionMode {
                fMain,
                fMode,
                fSetup,
                fMainEditNumberPipeUp,
                fMainEditNumberPipeUpTn,
                fMainEditNumberPipeDown,
                fShowNumber,
                fToneCall,
                fShowMainNumber,
                fAutoDial,
                fCalling,
                fIndification,
                fEditNumber,
                fBookSelect,
                fClearNumber,
                fClearNumber1,

                fShowKateg,
                fShowTimeCall,
                fShowTimeSay,
                fShowDateCall,
                fShowCallsPerTime,
                fShowAllTimeSay,
                fShowTimeSayingNow,

                fBeepEmulation,

                fReset,
                fTimeOutReset,

                fBackCall,
                fSoundMode,
                fParallelDetect,
                fLockNumber,

                fHold,
                fLineGet,
                fSearch,
                fShowNotFound,

                fFlash,
                fAntiAON,

                fEditCharBuff,
                fShowLabelFilterStatus,

                fStore,
                fStoreCustom,

                fEnterPassword,
                fShowPasswordTest,

                fSetSecondsZero,

                fPlayAlarm,
                fAlarmDial,

                fShowLogo,
                fShowConfidence,

                fRemoteAccessKey,
                fRoomListen,

                fShowVersionInfo,
                fAutoDialCustom,
                fDebugBeep,

                fExtFunc,

                fEditOption,
                fNone
               };
//---------------------------------------------------------------
enum {skMode,skSetup,skBookSelect,skBeepEmulation};
enum {Off,On};
enum {false,true};

enum {dForward,dBackward};
enum {nNotPresent=false,nPresent=true};
enum {bBookIn,bBookOut,bBookZK,bBookWhite,bBookBlack,bBookBlackLock,bBookSpecical};
enum {oStartAddr,oEndAddr,oLen,oUseLen,oMaxNumbers,oUseNumbers,oOffsetAddr,oAddrNAT};
enum {optOffsetAddrIn,optOffsetAddrOut,
      optUseNumbersIn,optUseNumbersOut,//optUseNumbersZK,
      optUseLenOut,optUseLenZK};

#define StartAddr  BookDataI[oStartAddr]
#define EndAddr    BookDataI[oEndAddr]
#define Len        BookDataI[oLen]
#define UseLen     BookDataI[oUseLen]
#define MaxNumbers BookDataI[oMaxNumbers]
#define UseNumbers BookDataI[oUseNumbers]
#define OffsetAddr BookDataI[oOffsetAddr]
#define AddrNAT    BookDataI[oAddrNAT]

enum {kf0=1,kf1,kf2,kf3,kf4,kf5,kf6,kf7,kf8,kf9,
 kfStar,kfPriston,kfMode,kfFlash,kfRedial,kfTone,
 kfSpkPhnOnOff,
 kfBookSpecical,kfBookWhite,kfBookBlack,kfBookBlackLock,kfBookIn,kfBookOut,kfBookZK,
 kfHold,kfAntiAON,kfStore,kfVolume,

 kfAutoPrevious,kfAutoNext,kfAutoNext2,kfAnyKey,kfLAnyKey,

 kfNone,
 kfExtendedKey,
 kfL0,kfL1,kfL2,kfL3,kfL4,kfL5,kfL6,kfL7,kfL8,kfL9,
 kfLStar,kfLPriston,kfLMode,kfLFlash,kfLRedial,kfLTone,
 kfLSpkPhnOnOff,
 kfLBookSpecical,kfLBookWhite,kfLBookBlack,kfLBookBlackLock,kfLBookIn,kfLBookOut,kfLBookZK,
 kfLHold,kfLAntiAON,kfLStore,kfLVolume,

 kfLastKey};

enum BeepMapEvent {bmCallTestShortBeepMap,
                   bmCallWaitVeryLongBeepMap,
                   bmPause4sWait,
                   bmAutoDialEndTest,

                   bmBeepEmulation,
                   bmToneBeepEmulation,

                   bmBTBeforeRepeatSay,
                   bmBCallStart,
                   bmBCallSaying,

                   bmHold,

                   bmBeepTestSayingNumber,

                   bmTestBeepToPipeDown,

                   bmRemoteAccessKey,

                   bmDebugBeep
                   };
enum NumeralType {num0,num1,num2,num3,num4,num5,num6,num7,num8,num9,
                  numStarTone,
                  numPristonTone,
                  numToneSet,
                  numPause,
                  numWaitLongBeep,
                  numShortBeepWait
                  };
enum Soundkeys {tkbNone,tkb1tone,tkb2tone,tkbBeeper,tkbWav0,tkbWav1,tkbSayKeys};
enum DToneType {tn0,tn1,tn2,tn3,tn4,tn5,tn6,tn7,tn8,tn9,tnStar,
                tnPriston,tnNoNumeral};
enum {vsMain0,vsMain1,vsMain2,vsMainSaying};
enum {dfnNumber,dfnLenNumber};
enum {pfxNone,pfxNoPause,pfxPause,pfxWaitVeryLongBeep};
enum LockType {lCall,lParallel};
enum UndefinedOperation {undefNone,undefNotFix,undef12HSClear};
enum ClockWorkOperation {clkwTime,clkwDate,clkwNowTime};
enum SayHour {hsndNone,hsndBeep,hsndSayTime,hsndClock,
  hsndClock_SayTime,hsndBeep_SayTime};


enum Beeps {bpNoBeeps,
            bpShort,
            bpLong,
            bpVeryLong};

enum Pharses {phrTimeSay,phrNumberSay,phrInTime,
  phrRecallLater,phrRecallTomorrow,phrRecallInTime,phrNumberUndefined,
  phrIRepeat,phrRecall,phrOnNumber,phrPInTime,phrOnPager,
  phrForAbonent,phrSay0_B,phrOOw,
  phrS0,phrS1,phrS2,phrSExit,phrBoomClock,phrAlarmSay,

  phrSayi1,phrSayi1i2,phrSayi1i2i3,phrSayi1i2i3i4,
  phrSayi1number,
  phrSayKateg,phrSayTimeCall,phrSayDateCall,phrSayTimeSay,phrSayIni1Hours,
  phrSaySetTime,phrSaySetInTime,phrSayTodayCalls,

  phrTestSamples,
  phrNone
  };

enum TypeWorkBuff {tcbPack,tcbUnPack,tcbMaskBuff2,tcbLen1Use,
 tcbSkipBigger9,tcbUndefinedSearch,tcbFreeSearch,tcbUseLenPack};

enum AONModes {modeAutoUp=1,
               modeUserUp,
               modeFullReaddress,
               modeNumberReaddress,
               modeTimeReaddress,
               modePagerReaddress,
               modeNoIndification};
enum AlarmModes {atNone,atCustomDays,atAllDays,atACall,atSetMode,atWhiteChg,atBlackChg,atBlackLockChg};
enum AONlockModes {aonlNone=0,aonlMainModes,aonlAllModes};
enum ResetTypes {rstUser,rstAuto};

enum Errors {errInitFlash,errTestROM,errClock};

enum Options{
 oACallLoopBeforeTimeOut,oACallTimeOut,oAutoACall,oACallLoops,
 oWaitCalls,oAutoSearch,o12ClkView,oTypeMainView,oAnswerBackParallel,
 oSignCorr,oMinCorr,oSecCorr,oUnknownOper,

 oTypeKeyBeep,oTypeHourSnd,oMelodyHold,oBellTone,
 oParalListen,oAutoUpListen,oRepNumberSay,oParalTypeNumberSay,
 oAnswerListen,oDirectionSay,oAlarmStopOnLineOff,

 oLightLevel,oBeepLineFreq,oSpeedOfVoice,
 oMigLevel,oVolume,

 oATSLenNumber,oTypeLineCall,oParalOpr,oToneParalOpr,
 oRemoteAccess,oPrefix,oPrefixType,oCountryCode,oCountryBeepWait,
//alarm options
 oAlarmNumber,oHoursAlarm,oMinutesAlarm,oTypeAlarm,
 oLenPlayAlarm,oPlayAlarm,oVolumeAlarm,oDaysAlarm,oAlarmNumberCall,

 oNightOn,oNightFromHour,oNightFromMin,oNightToHour,oNightToMin,
 oNightBells,

 oRequests,oFormRequest,oLenRequest,oPauseRequest0,oPauseRequest,
 oSpeedNumeralCall,oWaitNextNumeral,oEveryNumeralBeepTest,
 oFminCall,oFmaxCall,oKvantPipeUp,oKvantAutoPipeUp,oFlashPause,

 oShowSpecical,oShowWhite,oShowBlack,oShowBlackLock,oShowIn,oShowOut,oShowZK,

 oAONMode,oBCall,oBCallNumber,
 oReaddressNumber,oReaddressTime,
 oPagerNumber,oPagerAbonent,oFilter,

 oPassOn,oPassword,oAONlock,oAreaLock,oLockAllCalls,oLockNumbers,oLockCode,

 oHours,oMinutes,oDay,oMonth,oYear,

 oUpTimeReaddress,oPowerDownTimeOut,oNewNotSayCalls,

 oCheckReset,oShowLogo,

 oAllHourSay,oAllMinSay,
 oCallsPerAllTime,oTodayCalls,
 oODay,

 oLastOption
 };
enum FilterOfLabel {xfltrWhite,xfltrBlack,xfltrBlackLock};
#define fltrWhite       1<<xfltrWhite
#define fltrBlack       1<<xfltrBlack
#define fltrBlackLock   1<<xfltrBlackLock
#endif
//RAM
#define MaxBooks             7
#define MaxNumbersIn         100
#define MaxNumbersOut        100
#define MaxNumbersZK         100
#define MaxNumbersBlack      50
#define MaxNumbersWhite      50
#define MaxNumbersBlackLock  50
#define MaxNumbersSpecical   50
#define MaxNumbersZKall      (MaxNumbersZK+MaxNumbersBlack+MaxNumbersWhite+MaxNumbersBlackLock+MaxNumbersSpecical)
#define MinLenIn        8
#define MinLenOut       4
#define MinLenZK        0
#define MaxLenNumberIn  7
#define LenOneNumberIn  MinLenIn
#define LenOneNumberOut (MinLenOut+4)
#define LenOneNumberZK  (MinLenZK+4)
#define LenIn           LenOneNumberIn*MaxNumbersIn
#define LenOut          LenOneNumberOut*MaxNumbersOut-100
#define LenZKall        LenOneNumberZK*MaxNumbersZK

#define StartAddrNAT    0
#define LenNAT          MaxNumbersZKall/8+1
#define StartAddrIn     StartAddrNAT+LenNAT
#define EndAddrIn       StartAddrIn+LenIn
#define StartAddrOut    EndAddrIn
#define EndAddrOut      StartAddrOut+LenOut
#define StartAddrZKall  EndAddrOut
#define EndAddrZKall    StartAddrZKall+LenZKall

#define DefaultNumberBuffer EndAddrZKall
#define StartSpecOpt    DefaultNumberBuffer+LenDefaultNumberBuffer

#define LenBookData     6*2
//#define NumberOfAlarm   StartSpecOpt+LenBookData //SPC OPT
#define LenSpecOpt      LenBookData //+1 //len specical options
#define StartAddrOpt    StartSpecOpt+LenSpecOpt
#define LenDefaultNumberBuffer DataLenNumber+1

#define LenTmpBookData  14

#define LenOpt0                 13
#define LenOpt1                 11
#define LenOpt2                 5
#define LenOpt3                 9
#define LenOpt4                 9
#define LenOpt5                 6
#define LenOpt6                 13
#define LenBookShow             7
#define LenAONMode              2
#define LenEditBCallNumber      1
#define LenReaddressingNumber   1
#define LenReaddressingTime     1
#define LenReaddressingPager    2
#define LenFilter               1
#define LenLock                 7
#define LenTimeDate             5

#define mnEditOpt0 0
#define mxEditOpt0 mnEditOpt0+LenOpt0-1
#define mnEditOpt1 mxEditOpt0+1
#define mxEditOpt1 mnEditOpt1+LenOpt1-1
#define mnEditOpt2 mxEditOpt1+1
#define mxEditOpt2 mnEditOpt2+LenOpt2-1
#define mnEditOpt3 mxEditOpt2+1
#define mxEditOpt3 mnEditOpt3+LenOpt3-1
#define mnEditOpt4 mxEditOpt3+1
#define mxEditOpt4 mnEditOpt4+LenOpt4-1
#define mnEditOpt5 mxEditOpt4+1
#define mxEditOpt5 mnEditOpt5+LenOpt5-1
#define mnEditOpt6 mxEditOpt5+1
#define mxEditOpt6 mnEditOpt6+LenOpt6-1
#define mnBookShow mxEditOpt6+1
#define mxBookShow mnBookShow+LenBookShow-1
#define mnAONMode mxBookShow+1
#define mxAONMode mnAONMode+LenAONMode-1
#define mnEditBCallNumber mxAONMode+1
#define mxEditBCallNumber mnEditBCallNumber+LenEditBCallNumber-1
#define mnReaddressingNumber mxEditBCallNumber+1
#define mxReaddressingNumber mnReaddressingNumber+LenReaddressingNumber-1
#define mnReaddressingTime mxReaddressingNumber+1
#define mxReaddressingTime mnReaddressingTime+LenReaddressingTime-1
#define mnReaddressingPager mxReaddressingTime+1
#define mxReaddressingPager mnReaddressingPager+LenReaddressingPager-1
#define mnEditFilter mxReaddressingPager+1
#define mxEditFilter mnEditFilter+LenFilter-1
#define mnEditLock mxEditFilter+1
#define mxEditLock mnEditLock+LenLock-1
#define mnEditTimeDate mxEditLock+1
#define mxEditTimeDate mnEditTimeDate+LenTimeDate-1

#define MaxLenNumber 32
#define DataLenNumber MaxLenNumber/2+5
#define MaxNumeralView 7

#define MaxAlarms       10
#ifdef _ASM
#define NumberOfAlarm   0xFF00|(ValueData+4)
#define SelNumberBook   0xFF00|(ValueData+2)
//#define Year            0xFF00|(ValueData+3)
#endif
#ifdef _C
#define NumberOfAlarm   ValueData[4]
#define SelNumberBook   ValueData[2]
//#define Year            ValueData[3]
#endif

//Beep testing
#define Fmin           15 //Fmin=300 Hz
#define Fmax           35 //Fmax=700 Hz
#define DeltaBeep      1
#define UpTimeBeepWait 5
#define MinLenPeriod   5  //MinLenBeep
#define LenLongPeriod  50 //LongPeriod
#define MaxLenBeep     60 //VeryLongBeep
#define NBeepDetect    3

#define MaxDoubleCx 2-1
#define opnRepeat      0xC
#define opnBegin       0xB
#define opnMutByte     0xF

#define dtsndEndSound 0xFF
#define dtsndPauseB   0xFE
#define dtsndPauseW   0xFD

#define tsEndPhrase     0xFF
#define tsSayChar       0xFE
#define tsSayMinutes    0xFD
#define tsSayInt        0xFC
#define tsSayNumber     0xFB
#define tsSayM          0xFA
#define tsSayH          0xF9
#define tsSetPause      0xF8
#define tsSayKey        0xF7

#define tsSetWavData0cv   0xF6
#define tsIncCV           0xF5
#define tsSetWavData0MemI 0xF4
#define tsTestSample      0xF3
#define tsSayNumberStart  0xF2
#define tsSetWavData1MemI 0xF1
#define tsSetWavData1cv   0xF0

#define tsv0        0
#define tsv1        1
#define tsv2        2
#define tsv9        9
#define tsv1a       35
#define tsv2a       36
#define tsv10       10
#define tsv20       20
#define tsv100      41
#define tsH0        29
#define tsH1        30
#define tsH2        31
#define tsM0        37
#define tsM1        38
#define tsM2        39
#define tsMNS       28
#define tsIn                32
#define tsRecall            33
#define tsOnNumber          34
#define tsNumber            40
#define tsUndefined         50
#define tsAnswerbackWorking 51
#define tsSayAfterSignal    52
#define tsOnPager           53
#define tsForAbonent        54
#define tsClock             55
#define tsS0                56
#define tsS1                57
#define tsS2Exit            58
#define tsOOw               59
#define tsRepeat            60
#define tsExactly           61
#define tsLater             62
#define tsTomorrow          63
#define tsS2                64
#define tsMH0       2
#define tsMH1       0
#define tsMH2       1

#define numMask         14
#define numEndNumberIn  15
#define numUndefined    10

#define nbStartAlarm     40
#define nbBCallNumber    37
#define nbPagerNumber    38
#define nbPagerAbonent   39
#define nbReaddressingNumber 36
#define nbAreaCode       35
#define nbLockNumbers    0
#define nbChangeNumber   10
#define nbSayNumber      30
#define nbChangeNumberTo 20

#define nbLenLockNumbers  10
#define nbLenChangeNumber 10
#define nbLenSayNumber    5

//#ifdef _C
#include <mldydata.h>
#include <vbus.inc>
//#endif
#ifdef _ASM
$vmacro.inc
//$mldydata.h
 %defenum 1                     //Video
 %enum z0,z1,z2,z3,z4,z5,z6,z7,z8,z9
 %enum zMNS,zSP,z_,zo,zA,zb,zC,zd,zE,zF
 %enum zt,zn,zS,zU,zP, zL,zr,zc,zh,zu
 %enum zH,zPr,zMl,zMr,zi,zIl,zsE,zsEsC
 %enum zY,zGr,zWl,zWr,zG,zEQ,zAGEl,zAGEr,zcb
 %enum zHio,zl,zV
 #define zpixel 0x80
 #define zI   z1
 #define zChr z4
 #define zNr  zH
 #define zO   z0
 #define zRr  zP
 #define zBr  z6
 #define zVr  z8
 #define zN   zPr
 #define zZr  z3
 #define zB   z8
 #define zll  zAGEl

 %enum MaxViewBytes
 %redefenum MaxViewBytes
 %enum vdCall,vdJump,vdCallcv,vdJumpcv,vdExit,vdChangeTM
 %enum vdVwChTM,vdViewDeccv,vdView3Deccv,vdViewDecMemI,vdViewHoursDecMemI,vdViewHexcv
 %enum vdViewHexMemI,vdViewHexStringMemX,vdView3HexMemI,vdDecCV
 %enum vdTXTCharcv,vdViewHalfDeccv,vdViewLinecv,vdPixel,vdNone
 %enum vdViewDayscv,vdViewNumber,vdViewNumberMig,vdViewNumberType,vdHangUpTM
 %enum vdSetTM,vdIncPosView,vdViewHalfDecMemI,vdChangeSMT,vdShowPWDcv
 %enum vdShowFiltercv,vdTodaySeeSTM,vdCallSpeaker,vdViewDec5cv
 %enum vdViewOffsetDatacv

 %redefenum 0
 %enum tcbPack,tcbUnPack,tcbMaskBuff2,tcbLen1Use
 %enum tcbSkipBigger9,tcbUndefinedSearch,tcFreeSearch,tcbUseLenPack

 %redefenum 1                   //Keys
 %enum kf0,kf1,kf2,kf3,kf4,kf5,kf6,kf7,kf8,kf9
 %enum kfStar,kfPriston,kfMode,kfFlash,kfRedial,kfTone
 %enum kfSpkPhnOnOff
 %enum kfBookSpecical,kfBookWhite,kfBookBlack,kfBookBlackLock,kfBookIn,kfBookOut,kfBookZK
 %enum kfHold,kfAntiAON,kfStore,kfVolume

 %enum kfAutoPrevious,kfAutoNext,kfAutoNext2,kfAnyKey,kfLAnyKey

 %enum kfNone
 %enum kfExtendedKey
 %enum kfL0,kfL1,kfL2,kfL3,kfL4,kfL5,kfL6,kfL7,kfL8,kfL9
 %enum kfLStar,kfLPriston,kfLMode,kfLFlash,kfLRedial,kfLTone
 %enum kfLSpkPhnOnOff
 %enum kfLBookSpecical,kfLBookWhite,kfLBookBlack,kfLBookBlackLock,kfLBookIn,kfLBookOut,kfLBookZK
 %enum kfLHold,kfLAntiAON,kfLStore,kfLVolume

 %enum kfLastKey
 %redefenum kfLastKey
 %enum kfSet10,kfSetL10,kfSetKeys,kfSetKeysTo,kfCall,kfJump,kfDCall,kfDJump
 #define kfExit 0xFF
 #define MaxPlayKey kfPriston

//Events
 %redefenum 0
 %enum eMode,eCall,eMinOver,eTakeNumeralKey
 %enum eBeepStart,eBeepEnd,eSubmitMode,eExitToMain,eReturn
 %enum eKeyPresent,eKeyPresentNoSnd,eK0_9


 %enum eBitDaySet,eIncOption,eIncOptionA,eDecOptionA
 %enum eSetMin,eSetMax,eSetCharEditBuff,eDeleteCharEditBuff,eNextOption
 %enum ePreviousOption,eEnterOption,eSetupMode,eBookSelectMode

 %enum eEditOpt0,eEditOpt1,eEditOpt2,eEditOpt3,eEditOpt4
 %enum eEditBud,eEditNight

 %enum eUpdateView,eAdd_CallNumeralBuff,eAddNumeralBuff,eDeleteNumeralBuff
 %enum eMainEditNumber,eShowNumber,eRolNumber

 %enum eBeepDetected,eNextNumeralCall
 %enum eStopCallSet,eStartImpulseSet,eStartImpulseSetA,ePipeIsUp
 %enum eStartKZ,eStopKZ,ePipeIsDown
 %enum eNextNumeralCallN,eToneSet,eToneSetKey,eSpeakerPhoneChange,ePipeChanged
 %enum eReturnKeyEvent
 %enum eAutoDialKey,eAutoDial,eAutoDialA,eFlashStart,eFlashEnd,eRedialA
 %enum eRedial,eBeepTestCallA,eBeepTestCall,eStartSayingData,eStopSayingData,ePauseUntilStartSaying
 %enum eStartBell,eEndBell,eIndification,eStartIndificate,eAnswerListening,eSendRequest
 %enum eIndificationGetAnswer,eStartBeepLine,eEndBeepLine,ePlayBellInRoom
 %enum eNextPlayWav,eSayCurrentTime
 %enum eStartEditNumber,eStartEditNumberAddNumeral,eSubmitEditNumber
 %enum eAutoNext,eAutoPrevious,eClearBook,eDeleteNumber,eShowBook
 %enum eSetUndefinedNumber,eEnterClearNumber,eEnterClearPropAllNumber,eSubmitClearPropAllNumber
 %enum eShowKateg,eShowTimeCall,eShowTimeSay,eShowDateCall,eShowCallsPerTime,eShowAllTimeSay
 %enum eChangeShowAllTimeSay
 %enum eStartNumberSay,eNextNumberSay,eNextNumberSayInTime,eNextLineNumberSay
 %enum eTestCurrBeepTone
 %enum eSetNoSoundPlay,eSetSoundPlay,eSetListenLine
 %enum eSayLineCurrPhrase,eRecallLater,eRecallTomorrow,eRecallInTimeLater
 %enum eNumberUndefined,eRecallReaddress,eReaddressingNumber,eReaddressingTime
 %enum eReaddressingPager
 %enum eRepeatPhrase,eRepeatPhraseN
 %enum eEnterReset,eResetAll,eReset
 %enum eEditAONMode
 %enum eAutoNext2ByOn,eAModeSet,eEditBCallNumber
 %enum eEditReaddressingNumber,eEditReaddressingTime,eEditReaddressingPager
 %enum eBCallStart,eBCallStartTest,eBCallSay,eBCallBeepTest
 %enum eSoundMode,eAddNumeralParallel,eEnterLock,eTestLineFree
 %enum eNextNotePlay,eTestMelody,eVolumeUp,eStopTestMelody
 %enum eHold_LineGet,eTestLineHold,eStartMelodyHold,eBeepTestHold
 %enum eTestLineFreeGetLine
 %enum eEnterSearch,eSerachNext,eReturnSearch
 %enum eAntiAONStart,eImpulseAntiAON
 %enum eEditCharBuff,eEditFilter,eSetFilter
 %enum eEnterStore,eEnterStoreCustomNumber,eStoreCustomNumber
 %enum eStoreCustomBook,eStoreFirstFree
 %enum eNewPasswordEnter,eEditLock
 %enum eEnterPassword,ePasswordSubmit,eReturnShowPass
 %enum eSayCurrKey,eExitToMainTime
 %enum eEditTimeDate
 %enum eSetDate,eHoursSet,eMinutesSet,eEnterSetSecondsZeroMode
 %enum eSetSecondsZero
 %enum eContinueTestTime,eStartTestTime
 %enum eStartPlayAlarm,eSayTimeAlarm,eDecMinAlarm
 %enum eVolumeChange
 %enum eShowLogo,eContinueShowLogoA,eContinueShowLogoB
 %enum eSet8Book,eConfidenceOnOff,eTestConfidence,eTestBeepToPipeDown
 %enum eTestPipeDownNow
 %enum eEnterPowerDown,eLeavePowerDown,eTestPowerDown
 %enum eEnterFoundBook
 %enum eEnterRemoteAccess,eRemoteAccessKey,eSayVideoData,eContinueTestBeepRemoteAccess
 %enum eKeyUpEmulation
 %enum eShowVersionInfo,eMoveVersioInfo
 %enum eAutoDialCustomNumber,eSubmitCustomDialNumber
 %enum eDebugBeep,eEnterExtFunct

 %enum eNoRepeat,eNone

//Key maps
 %redefenum 0
 %enum kmMain,kmMode,kmCallFromKey,kmModeSubmit,kmSetupSubmit
 %enum kmEdMinMax,kmEdIncDec,kmEdSerialPaste,kmEdMinMaxLine
 %enum kmEdBudEdit,kmEdBudModeSel,kmEdEditNumber
 %enum kmEdEditNumberMainPipeUp,kmEdEditNumberMainPipeDown
 %enum kmEdEditNumberMainPUpTone,kmEdEditNumberMainPipeUpTn
 %enum kmShowNumber,kmShowMainNumber,kmAutoDial,kmCalling
 %enum kmShowNumberOpt,kmEditNumberOpt,kmEdSerialPasteA,kmBookSelect
 %enum kmBookShowIn,kmBookShowOut,kmBookShowZK,kmClearNumber
 %enum kmShowNumberProperties,kmClearPropAllNumber,kmBeepEmulation
 %enum kmTestOptionA,kmTestOptionB,kmBeepEmulationSubmit
 %enum kmResetMode,kmEdMinMaxNight,kmEdSerialPasteNBells,kmEdSerialPasteAMode
 %enum kmEdMinMaxBCall,kmShowNumberBCall
 %enum kmEditReaddressNumber,kmEditReaddressTime,kmEditReaddressPagerNumber
 %enum kmEditReaddressPagerAbonent,kmSound,kmEdSerialPasteMT
 %enum kmSearchNumber,kmAntiAON,kmEditCharBuff,kmEdFilterEdit
 %enum kmStoreCustomBook,kmStoreCustomNumber,kmEdMinMaxPass
 %enum kmTestPassword
 %enum kmEdSerialPasteHours,kmEdSerialPasteMinutes,kmEdSerialPasteDate
 %enum kmSecondsSet,kmRemoteAccessKey,kmAutoDialCustomNumber,kmExtFuncSubmit
 %enum kmEdK0_2,kmEdK0_3

 %redefenum 0
 %enum kmDefault,kmSet0_BtoBeepKey,kmDisableRepeat0_B,kmSet0_AtoSubmitMode
 %enum kmProcModeSubmit,kmProcSetupSubmit
 %enum kmProcEdMinMax,kmProcEdIncDec,kmProcEdSerialPaste
 %enum kmProcEdMinMaxLine,kmProcStarPriston_NextPrev
 %enum kmProcEdBudEdit,kmProcEdBudModeSel,kmSetL0_LBNone
 %enum kmProcEdEditNumber,kmProcEdEditNumberMainPipeUp,kmProcEdEditNumberMainPipeDown
 %enum kmProcMainKey,kmProcEdEditNumberMainPUpTone,kmProcSetL0NoRepeat
 %enum kmProcSetL1_6PipeUp,kmProcShowNumber,kmProcShowMainNumber
 %enum kmProcAutoDial,kmProcCalling,kmProcEditNumberStar,kmShowNumber0_9
 %enum kmProcAutoNextOption
 %enum kmProcBookSelect,kmShowAllBookKeys,kmProcShowIn,kmProcShowOut,kmProcShowZK
 %enum kmProcClearBook,kmProcShowNumberProperties
 %enum kmProcClearPropAllNumber,kmProcBeepEmulation
 %enum kmProcTestOptionA,kmProcTestOptionB,kmProcBeepEmulationSubmit
 %enum kmProcResetMode,kmProcEdMinMaxNight
 %enum kmProcEdSerialPasteAMode
 %enum kmProcEdMinMaxBCall,kmProcNxtANxt_EditAONMode,kmProcPrvAPrv_EditAONMode
 %enum kmProcReaddressNumber,kmProcReaddressTime,kmProcSound,kmProcEdSerialPasteMT
 %enum kmProcSearchNumber,kmProcAntiAON,kmProcEdFilterEdit
 %enum kmProcStoreCustomNumber,kmProcStoreCustomBook,kmProcEdMinMaxPass
 %enum kmProcTestPassword
 %enum kmProcEdSerialPasteHours,kmProcEdSerialPasteMinutes,kmProcEdSerialPasteDate
 %enum kmProcSecondsSet,kmProcRemoteAccessKey,kmProcAutoDialCustomNumber,kmProcExtFuncSubmit
 %enum kmProcEdK0_2,kmProcEdK3

 %enum kmNone

 %redefenum 0                   //Books
 %enum bBookIn,bBookOut,bBookZK,bBookWhite,bBookBlack,bBookBlackLock,bBookSpecical
 #define bBIn  1<<bBookIn
 #define bBOut 1<<bBookOut
 #define bBZK  1<<bBookZK
// %redefenum 0                   //Data for books
// %enum AddrNATZK,StartAddrIn,StartAddrZK
// %enum EndIn,EndOut,EndZK,MaxAddressOut,MaxAddressZK,MaxIn,MaxOut,MaxZK
// %enum StartOffsetIn,NumbersIn,NumbersOut,NumbersZK

 %redefenum 0
 %enum oStartAddr,oEndAddr,oLen,oUseLen,oMaxNumbers,oUseNumbers,oOffsetAddr,oAddrNAT

// Function mode
// %redefenum 0
// %enum fMain,fMode,fNone
// Video Data
 %redefenum 0
 %enum vMain,vMode,vSetup,vViewEditNumber,vCalling,vRequestOut
 %enum vViewEditNumberO,vViewBookSelect
 %enum vClearNumber,vClearNumber1,vBusy
 %enum vKateg,vTimeCall,vTimeSay,vDateCall,vCallsPerTime,vAllTimeSay
 %enum vShowIndificated,vShowTimeSayingNow
 %enum vResetMode,vTimeOutReset,vBCalling,vSoundMode,vParallelDetect
 %enum vLockingNumber,vHold,vGetLine,vSearchNumber,vShowNotFound,vFlash
 %enum vAntiAON,vShowLabelFilterStatus,vStoreCustomBook,vStoreCustomNumber
 %enum vTestPassword,vShowTestPassword,vSecondsSet,vAlarmPlay
 %enum vAlarmDial,vAutoDial,vConfidenceShow,vRemoteAccessKey
 %enum vAutoDialCustomNumber
 %enum vShowError,vShowLogo,vShowVersionInfo,vDebugBeep,vExtFunc

#define vShowNumber vViewEditNumber

 %enum vTestHexI,vTestHexString,vTestRAMdata,vDebugKeyView
 %enum vTestEdit0

 %enum vOpt0A,vOpt1A,vOpt2A,vOpt3A,vOpt4A,vOpt5A,vOpt6A,vOpt7A
 %enum vOpt8A

 %enum vOpt0B,vOpt1B,vOpt2B,vOpt3B,vOpt4B,vOpt5B,vOpt6B,vOpt7B
 %enum vOpt8B,vOpt9B

 %enum vOpt0X,vOpt1X,vOpt2X,vOpt3X,vOpt4X
 %enum vOpt0C,vOpt1C,vOpt2C,vOpt3C,vOpt4C,vOpt5C

 %enum vAlarm0,vAlarm1,vAlarm2,vAlarm3,vAlarm4

 %enum vOpt0D,vOpt1D,vOpt2D,vOpt3D,vOpt4D,vOpt5D,vOpt6D,vOpt7D
 %enum vOpt8D,vOpt9D

 %enum vBookShowSpecical,vBookShowWhite,vBookShowBlack,vBookShowBlackLock
 %enum vBookShowIn,vBookShowOut,vBookShowZK

 %enum vAONModeSelect,vBCall,vBCallNumber
 %enum vReaddressNumber,vReaddressTime,vPagerNumber,vPagerAbonent

 %enum vFilter

 %enum vPassword0

#define vStartVideoForOptions vOpt0A
 %enum vNone
// Options type edit
 %redefenum 0
 %enum teIncDec,teSerialEnter,tectmV,teNone
// Options
 %redefenum 0
 %enum oACallLoopBeforeTimeOut,oACallTimeOut,oAutoACall,oACallLoops
 %enum oWaitCalls,oAutoSearch,o12ClkView,oTypeMainView,oAnswerBackParallel
 %enum oSignCorr,oMinCorr,oSecCorr,oUnknownOper

 %enum oTypeKeyBeep,oTypeHourSnd,oMelodyHold,oBellTone
 %enum oParalListen,oAutoUpListen,oRepNumberSay,oParalTypeNumberSay
 %enum oAnswerListen,oDirectionSay,oAlarmStopOnLineOff

 %enum oLightLevel,oBeepLineFreq,oSpeedOfVoice
 %enum oMigLevel,oVolume

 %enum oATSLenNumber,oTypeLineCall,oParalOpr,oToneParalOpr
 %enum oRemoteAccess,oPrefix,oPrefixType,oCountryCode,oCountryBeepWait
//alarm options
 %enum oAlarmNumber,oHoursAlarm,oMinutesAlarm,oTypeAlarm
 %enum oLenPlayAlarm,oPlayAlarm,oVolumeAlarm,oDaysAlarm,oAlarmNumberCall

 %enum oNightOn,oNightFromHour,oNightFromMin,oNightToHour,oNightToMin
 %enum oNightBells

 %enum oRequests,oFormRequest,oLenRequest,oPauseRequest0,oPauseRequest
 %enum oSpeedNumeralCall,oWaitNextNumeral,oEveryNumeralBeepTest
 %enum oFminCall,oFmaxCall,oKvantPipeUp,oKvantAutoPipeUp,oFlashPause

 %enum  oShowSpecical,oShowWhite,oShowBlack,oShowBlackLock,oShowIn,oShowOut,oShowZK

 %enum oAONMode,oBCall,oBCallNumber
 %enum oReaddressNumber,oReaddressTime
 %enum oPagerNumber,oPagerAbonent,oFilter

 %enum oPassOn,oPassword,oAONlock,oAreaLock,oLockAllCalls,oLockNumbers,oLockCode

 %enum oHours,oMinutes,oDay,oMonth,oYear

 %enum oUpTimeReaddress,oPowerDownTimeOut,oNewNotSayCalls

 %enum oCheckReset,oShowLogo

 %enum oAllHourSay,oAllMinSay
 %enum oCallsPerAllTime,oTodayCalls
 %enum oODay

 %enum oLastOption
//alarm types
 %redefenum 0
 %enum atNone,atCustomDays,atAllDays,atACall,atSetMode,atWhiteChg,atBlackChg,atBlackLockChg

 %redefenum 0
 %enum num0,num1,num2,num3,num4,num5,num6,num7,num8,num9,
 %enum numStarTone,numPristonTone,numToneSet,numPause,numWaitLongBeep,numShortBeepWait

 %redefenum 0
 %enum vsMain0,vsMain1,vsMain2,vsMainSaying

 %redefenum 0
 %enum tkbNone,tkb1tone,tkb2tone,tkbBeeper,tkbWav0,tkbWav1,tkbSayKeys

 %redefenum 0
 %enum phrTimeSay,phrNumberSay,phrInTime
 %enum phrRecallLater,phrRecallTomorrow,phrRecallInTime,phrNumberUndefined
 %enum phrIRepeat,phrRecall,phrOnNumber,phrPInTime,phrOnPager
 %enum phrForAbonent,phrSay0_B,phrOOw
 %enum phrS0,phrS1,phrS2,phrSExit,phrBoomClock,phrAlarmSay
 %enum phrSayi1,phrSayi1i2,phrSayi1i2i3,phrSayi1i2i3i4
 %enum phrSayi1number

 %enum phrTestSamples
 %enum phrNone

 %redefenum 0
 %enum errInitFlash,errTestROM,errClock

 %endenum

//#define AONModes 6

mmo0_1N     = 0x00
mmo0_9S     = 0x10
mmo0_99S    = 0x20
mmo0_ctmS   = 0x30
mmo0_ctmN   = 0x40
mmoctm_ctmS = 0x50
mmo0_0xFFC  = 0x60
mmoctm_ctmC = 0x70
// 0           0      1         Next Value     N
// 1           0      9         Enter numbers  S
// 2           0      99        Enter numbers  S
// 3           0      custom    Enter numbers  S
// 4           0      custom    NextValue      N
// 5           custom custom    Enter numbers  S
// 6           0      0xFF      custom         C
// 7           custom custom    custom         C
mmoctmV = 0xAA

olBit    = 0  //1
olMx3    = 1  //3
olMx7    = 2  //7
olMx15   = 3  //15
olMx31   = 4  //31
olMx63   = 5  //63
olMx127  = 6  //127
olMx255  = 7  //255
olMx9    = 3  //15
olMx99   = 6  //99
olMxByte = 7  //255
olMx999  = 9  //1023
olMx9999 = 13 //16383
ohDecByteData=0x00
ohHalfByteData=0x80
ohHBD=ohHalfByteData
Array256=mmo0_9S|olBit
DAChar=mmo0_99S|olBit
NumberBookO=mmo0_ctmS|olBit
NumberConstO=mmoctm_ctmS|olBit
#endif

#define oAONModeAlarm  oPlayAlarm
#define oAutoDialSndOnAlarm    oLenPlayAlarm
#define oRepPModeAlarm oLenPlayAlarm
#define oSetLabel      oLenPlayAlarm