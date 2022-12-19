/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

#include <V2000.H>
code const uchar SayVideoPhrase[]={
phrNone, //vMain                        -
phrNone, //vMode                        -
phrNone, //vSetup                       -
phrNone, //vViewEditNumber              -
phrNone, //vCalling                     -
phrNone, //vRequestOut                  -
phrNone, //vViewEditNumberO             -
phrNone, //vViewBookSelect              -
phrNone, //vClearNumber                 -
phrNone, //vClearNumber1                -
phrNone, //vBusy                        -
phrSayKateg,    //vKateg                +
phrSayTimeCall, //vTimeCall             +
phrSayTimeSay,  //vTimeSay              +
phrSayDateCall, //vDateCall             +
phrSayTodayCalls, //vCallsPerTime       +-(only today call)
phrNone, //vAllTimeSay                  -
phrNone, //vShowIndificated             -
phrNone, //vShowTimeSayingNow           -
phrNone, //vResetMode                   -
phrNone, //vTimeOutReset                -
phrNone, //vBCalling                    -
phrNone, //vSoundMode                   -
phrNone, //vParallelDetect              -
phrNone, //vLockingNumber               -
phrNone, //vHold                        -
phrNone, //vGetLine                     -
phrNone, //vSearchNumber                -
phrNone, //vShowNotFound                -
phrNone, //vFlash                       -
phrNone, //vAntiAON                     -
phrNone, //vShowLabelFilterStatus       -
phrNone, //vStoreCustomBook             -
phrNone, //vStoreCustomNumber           -
phrNone, //vTestPassword                -
phrNone, //vShowTestPassword            -
phrNone, //vSecondsSet                  -
phrNone, //vAlarmPlay                   -
phrNone, //vAlarmDial                   -
phrNone, //vAutoDial                    -
phrNone, //vConfidenceShow              -
phrNone, //vRemoteAccessKey             -
phrNone, //vAutoDialCustomNumber        -

phrNone, //vShowError                   -
phrNone, //vShowLogo                    -
phrNone, //vShowVersionInfo             -
phrNone, //vDebugBeep                   -

phrNone, //vTestHexI                    -
phrNone, //vTestHexString               -
phrNone, //vTestRAMdata                 -
phrNone, //vDebugKeyView                -
phrNone, //vTestEdit0                   -

phrSayi1i2,   //vOpt0A                  +
phrSayi1,     //vOpt1A                  +
phrSayi1,     //vOpt2A                  +
phrSayi1,     //vOpt3A                  +
phrSayi1,     //vOpt4A                  +
phrSayi1i2,   //vOpt5A                  +
phrSayi1,     //vOpt6A                  +
phrSayi1i2i3, //vOpt7A                  +
phrSayi1,     //vOpt8A                  +

phrSayi1, //vOpt0B                      +
phrSayi1, //vOpt1B                      +
phrSayi1, //vOpt2B                      +
phrSayi1, //vOpt3B                      +
phrSayi1i2, //vOpt4B                    +
phrSayi1, //vOpt5B                      +
phrSayi1, //vOpt6B                      +
phrSayi1, //vOpt7B                      +
phrSayi1, //vOpt8B                      +
phrSayi1, //vOpt9B                      +

phrSayi1, //vOpt0X                      +
phrSayi1, //vOpt1X                      +
phrSayi1, //vOpt2X                      +
phrSayi1, //vOpt3X                      +
phrSayi1, //vOpt4X                      +

phrSayi1,   //vOpt0C                    +
phrSayi1,   //vOpt1C                    +
phrSayi1i2, //vOpt2C                    +
phrSayi1,   //vOpt3C                    +
phrSayi1i2, //vOpt4C                    +
phrSayi1i2, //vOpt5C                    +

phrSayi1i2i3i4, //vAlarm0               +
phrNone, //vAlarm1                      -
phrNone, //vAlarm2                      -
phrNone, //vAlarm3                      -
phrOnNumber, //vAlarm4                  -

phrSayi1, //vNightOn                    +
phrSaySetInTime, //vNightFrom           +
phrSaySetInTime, //vNightTo             +
phrSayi1, //vNightBells                 +

phrSayi1i2, //vOpt0D                    +
phrSayi1, //vOpt1D                      +
phrSayi1, //vOpt2D                      +
phrSayi1, //vOpt3D                      +
phrSayi1, //vOpt4D                      +
phrSayi1, //vOpt5D                      +
phrSayi1, //vOpt6D                      +
phrSayi1i2, //vOpt7D                    +
phrSayi1i2, //vOpt8D                    +
phrSayi1, //vOpt9D                      +

phrSayi1number, //vBookShowSpecical     +
phrSayi1number, //vBookShowWhite        +
phrSayi1number, //vBookShowBlack        +
phrSayi1number, //vBookShowBlackLock    +
phrSayi1number, //vBookShowIn           +
phrSayi1number, //vBookShowOut          +
phrSayi1number, //vBookShowZK           +

phrSayi1, //vAONModeSelect              +
phrSayi1, //vBCall                      +
phrOnNumber, //vBCallNumber             +
phrOnNumber, //vReaddressNumber         +
phrSayIni1Hours, //vReaddressTime       +
phrOnPager, //vPagerNumber              +
phrForAbonent, //vPagerAbonent          +

phrNone, //vFilter                      -

phrSayi1, //vPassword0                  +
phrNone, //vPassword1                   -
phrSayi1, //vAONLock                    +
phrSayi1, //vLockArea                   +
phrSayi1, //vLockAllCalls               +
phrSayi1, //vLockNumber                 +
phrSayi1, //vLockCountry                +

phrSaySetTime, //vTimeSet              +
phrSayi1i2i3 //vDateSet                 +
};

code const uchar SSayi1number[]={tsSetWavData0cv,tsSayChar,
  tsSetPause,10,tsSayNumberStart,tsSayNumber,tsEndPhrase};

code const uchar SSayIni1Hours[]={tsIn,tsSetWavData0cv,tsSayChar,tsSayH,
  tsEndPhrase};

code const uchar SSayi1i2i3i4[]={tsSetWavData0cv,tsSayChar,
  tsIn,tsSetWavData0cv,tsSetWavData1cv,
  tsSayChar,tsSayH,tsSetPause,5,tsSayMinutes,tsSayM,
  tsSetWavData0cv,tsSayChar,tsEndPhrase};
code const uchar SSayi1i2i3[]={tsSetWavData0cv,tsSayChar,tsSetWavData0cv,tsSayChar,
  tsSetWavData0cv,tsSayChar,tsEndPhrase};
code const uchar SSayi1i2[]={tsSetWavData0cv,tsSayChar,tsSetWavData0cv,tsSayChar,tsEndPhrase};
code const uchar SSayi1[]={tsSetWavData0cv,tsSayChar,tsEndPhrase};

code const uchar SSayTodayCalls[]={
tsSetWavData0cv,tsSetWavData0cv,tsSetWavData0cv,tsSayChar,tsEndPhrase};

extern code const uchar SSayKateg[1],SSayTimeCall[1],SSayDateCall[1],SSayTimeSay[1],
  SSaySetTime[1],SSaySetInTime[1];

code const uchar STimeSay[]={
  tsSayChar,tsSayH,tsSetPause,5,tsSayMinutes,tsSayM,tsEndPhrase};
code const uchar SSayNumber[]={
  tsNumber,tsSayNumberStart,tsSayNumber,tsSetPause,5,tsEndPhrase};
code const uchar SSayInTime[]={
  tsIn,tsSayChar,tsSayH,tsSetPause,5,tsSayMinutes,tsSayM,
  tsSetPause,20,tsEndPhrase};
code const uchar SSayRecallLater[]={
  tsRecall,tsSetPause,5,tsLater,tsEndPhrase};
code const uchar SSayRecallTomorrow[]={
  tsRecall,tsSetPause,5,tsTomorrow,tsEndPhrase};
code const uchar SSayRecallInTime[]={
  tsRecall,tsIn,tsSayChar,tsSayH,tsSetPause,5,tsSayMinutes,
  tsSayM,tsEndPhrase};

code const uchar SSayNumberUndefined[]={
  tsNumber,tsUndefined,tsEndPhrase};

code const uchar SSayIRepeat[]={
//  tsSetPause,20,
  tsRepeat,tsEndPhrase};
code const uchar SSayRecall[]={tsRecall,tsSetPause,5,tsEndPhrase};

code const uchar SSayOnNumber[]={
  tsOnNumber,tsSayNumberStart,tsSayNumber,tsEndPhrase};
code const uchar SPSayInTime[]={
  tsIn,tsSayChar,tsSayH,tsEndPhrase};//tsSetPause,20,

code const uchar SSayOnPager[]={
  tsOnPager,tsSetPause,3,tsSayNumberStart,tsSayNumber,tsSetPause,5,
  tsEndPhrase};
code const uchar SSayForAbonent[]={
  tsForAbonent,tsSayNumberStart,tsSayNumber,tsEndPhrase};//tsSetPause,20,
code const uchar SSay0_9[]={tsSayKey,tsEndPhrase};

code const uchar SSayOOw[]={tsOOw,tsEndPhrase};

code const uchar SPlayS0[]={tsS0,tsEndPhrase};
code const uchar SPlayS1[]={tsS1,tsEndPhrase};
code const uchar SPlayS2[]={tsS2,tsEndPhrase};
code const uchar SPlaySExit[]={tsS2Exit,tsEndPhrase};
code const uchar SPlayBoomClock[]={tsClock,tsEndPhrase};
code const uchar SSAlarmSay[]={tsClock,
  tsSayChar,tsSayH,tsSetPause,5,tsSayMinutes,tsSayM,tsEndPhrase};
code const uchar SNone[]={tsEndPhrase};
code const uchar STestSamples[]={tsTestSample,tsEndPhrase};

code const uchar code *TablePhrase[]=
{STimeSay,SSayNumber,SSayInTime,
 SSayRecallLater,SSayRecallTomorrow,SSayRecallInTime,
 SSayNumberUndefined,SSayIRepeat,SSayRecall,SSayOnNumber,
 SPSayInTime,SSayOnPager,SSayForAbonent,SSay0_9,SSayOOw,
 SPlayS0,SPlayS1,SPlayS2,SPlaySExit,SPlayBoomClock,SSAlarmSay,

 SSayi1,SSayi1i2,SSayi1i2i3,SSayi1i2i3i4,SSayi1number,
 SSayKateg,SSayTimeCall,SSayDateCall,SSayTimeSay,SSayIni1Hours,
 SSaySetTime,SSaySetInTime,SSayTodayCalls,

 STestSamples,
 SNone
 };

#ifdef DEBUG_KeyEmulation
 data char PosEmulKey=0;
 const char KeyEmulData[]=
{kfMode,kf5,kfStar,kf1,kf5,
kfLastKey};

#endif

const char SystemData[]="\n\nCompiled:\n Time: "__TIME__"\n Date: "__DATE__"\nDAY: ";
const char StatusDay[]="Testing...\n\n";

const char *CopyRight[]={
"\n\n"
"ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸\n"
"³ú          ‚¥àá¨ï € \"UA\"         ú³\n"
"³³ú      (C)Victor Kozub 2000      ú³³\n"
"ÀÅ´     vi-comp@vi-comp.kiev.ua    ÃÅÙ\n"
" ³ú      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿     ú³ \n"
" ³ ÚÄÄÄÄÄ´For +380-44-2429848ÃÄÄÄÄ¿ ³ \n"
" ³ ÆÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÏÍÍÍÍµ ³ \n"
"ÚÅÄÅÄÄú  Author  Kozub Victor   úÄÅÄÅ¿\n"
"³³ ÀÄÄ´CoAuthor Igor BenderskiyÃÄÄÙ ³³\n"
"ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n"
"\n\n"
};