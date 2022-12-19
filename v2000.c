/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

#include <V2000.H>
/* bit */
//#define __DEBUG_RemoteAccessKey
 bit TypeOfData,
 EditModeValue,OptSelect,Error,OptChanged,EditingBuff,ViewOff,ShowSearch,CurrPipe,
 BeepTesting,CallSelect,TestEveryNumeralBeep,ToneCall,BackCall,MinOver,RemoteAccess,
 FastBeepTest,PipeUp,EditCallBuff,BeeperCall,TypeNumber,AutoUp,ContiueAlarm,TestEnterRemoteAccsess,
 SpeakerOn,DisableLKey,ToneTesting,DontView,DontPlaySounds,TodaySee,PauseBeep,
 ToneCallA,CallEnable,Calling,AutoDial,Saying,LineLoad,SecondCall,ConfidenceOn,
 HangUp,Snd,OldBeepTesting,PrefixTested,PrefixBeepTested,SayNumeralAfterBeep,
 OldLinePresent,EndAutoDialed,SaveNumberNow,EditingOptions,DirectionSay,LowBattery,
 Night,SoundsPlay,BlackNumber,InSaying,PlayExitSound;
 bit ParallelNumber,ParallelDetect,ToneStart;
 bit LockCallAll,LockCountryCode,LockNumbers,LockAllNumbers;
 bit StartPassword,AONLocked,PassEnter;

/* unsigned char */
 data uchar EFunc,OEFunc,VFunc,FKey,Event,FSP,KFunc,
 LightLevel,  //Light Level of LED. LightLevel=0..8
 ///...Options
 TypeEdit,SelectedValue,LenEdit,PosEdit,MinValue,MaxValue,
 Option,OOption,MaxOption,MinOption,
 ///...Timers
 Timer4msAEvent,Timer4msBEvent,Timer1sAEvent,
 ///...Parametrs Number
 LenNumber,OffsetNumberView,
 ///...Call
 PosCall,LoopImpulseCall,
 ///...Parametrs Call
 LenImpulse,LenPauseImpulse,PauseUntilNextNumeral,
 ///...Beep Testing
 BeepEventMap;
 idata uchar BeepTimeDetect,TypeBeep,OldBeepFreq,LenPeriod,
 BeepRepeat,

 MinSaying,HourSaying,SecSaying,
 Hours,Minutes,Seconds,
 Day,Month,Year,DayOfWeek,
//Number of alarm testing
 AlarmTest,
 NowHours,NowMinutes,

//Wav playing parametrs
 PosWavs,EventEndWavPlaying,WavData[MaxWavDataBuffer],NPhrase,
 PosNumberSX,

//tone detect data
 OldTN,ToneNumeral,

// Event on call complete
 EndCallEvent;
/* array */

 idata uchar ValueData[MaxValueData];
 idata uchar FunctionCalls[MaxFuncStack],
 VideoBuffer[MaxRazr][2],
 Number[MaxLenNumber/2],DayCall,MonthCall,DayOfWeekCall,HourCall,
  MinCall,HourSay,MinSay,
 EditBuff[2];

 code const uchar BookToOpt[]={oShowIn,oShowOut,oShowZK,oShowWhite,oShowBlack,oShowBlackLock};

#define ValueEdit (*(uint *) &EditBuff[0])//(uint) EditBuff[0]
#define WavDataW  (*(uint *) &WavData[0])
#define ResetType           PosEdit
#define SubmitKey           PosEdit
#define TimeOutViewRolNuber Timer4msA
#define TimerCall           Timer4msB
#define TimerCallEvent      Timer4msBEvent
#define TimeOutCall         TimeOut4msB
#define SndPlaying          TR1
//#define EventStopKZPipeUp   PosCall

#define Timer1sBEvent       BeepEventMap
#define Timer1sB            BeepTimeDetect

#define LoopRedial          MinOption       //Dial
#define LoopCallBeforePause MaxOption       //Dial

#define NCall               MinOption       //Indification
#define NRequest            MaxOption       //Indification
#define FormRequest         LenPeriod       //Indification
#define LenRequest          BeepEventMap    //Indification
#define PauseRequest0       BeepTimeDetect  //Indification
#define PauseRequest        TypeBeep        //Indification
#define CurrentPauseRequest BeepRepeat      //Indification
#define ListenAnswer        ToneCallA       //Indification
#define ListenLine          ToneCallA       //BeepEmulation
#define AONMode             PosCall         //Indification,Calling,BeepEmulation
#define NBeepPlaying        MinOption       //BeepEmulation
#define RepeatSayNumber     MaxOption       //BeepEmulation
#define PhrRepeat           PosEdit         //BeepEmulation
#define EventPhrRepeat      EndCallEvent    //BeepEmulation
#define CurrFilter          LoopImpulseCall //BeepEmulation
#define AbonentSaying       ToneCallA       //PagerReaddressing
#define LoopBCallRepeats    PosEdit         //Back Calling

#define EventEndMelodyPlaying EventEndWavPlaying
#define CurrentValueSaying PosNumberSX

#define NumberFound ValueEdit               //Search
#define BookFound   MinOption               //Search
#define LenShowA    TypeEdit                //Search

#define Timer10sA           PosEdit         //AutoDial
#define RAVFunc             PosCall         //RemoteAccess

#define MaxLn 1
code const char Lnumbers[MaxLn][32]=
{
 {3, 1,2,3},
/*
 {1, 0xC},
 {6, 1,2,3,4,5,6},
 {1, 2},
 {1, 0xC},
 {1, 3},
 {1, 0xC},
*/
};

code const char CompNumber[]={7, 1,2,3,4,5,6,0xC};


/* SOME CODE: ;) */
void main(void)
{
/*
  SaveValue(oPassOn,0);
  SaveValue(oAONlock,0);
  SaveValue(oPassword,0x0);
  SaveValue(oPassword,0xFFFF);
*/
/*
  NumberOfAlarm=0;
  SaveValue(oHoursAlarm,15);
  NumberOfAlarm=1;
  LoadValueN(oHoursAlarm);
  SaveValue(oHoursAlarm,15);
*/
/*
  SetNumberBuffA(0,num1);
  SetNumberBuffA(1,num1);
  SetNumberBuffA(2,num0);
  SetNumberBuffA(3,num2);
  SetNumberBuffA(4,num2);
  SetNumberBuffA(5,num2);
  SetNumberBuffA(6,num2);
  LenNumber=7;
  SayNumber(phrNumberSay,0);
  GetNextPlay();
  GetNextPlay();
  GetNextPlay();
  GetNextPlay();
  GetNextPlay();
  GetNextPlay();
  GetNextPlay();
*/

//  ResetOptions(oACallLoopBeforeTimeOut,oCountryBeepWait);
//  ResetOptions(oNightOn,oFlashPause);

//     GetLenNumber(0);
//     SaveValue(oShowZK,3);
//     SelectOption(oShowIn);
//     ViewDataBufferRom(VFunc);
//     SelectOption(oShowZK);
//     ViewDataBufferRom(VFunc);
//       LoadValue(mnBookShow);
//     SaveValue(oAlarmNumber,6);
//     GetNumberNumber(oAlarmNumberCall);
//     GetNumberBook(oAlarmNumberCall);
//     SaveValue(oShowZK,90);
//     SaveNumberNow=true;
//     SaveValue(oShowZK,3);
/*
 for (LenNumber=0;LenNumber<7;LenNumber++)
    SetNumberBuffA(LenNumber,LenNumber);
 SaveDefaultNumber();
 for (LenNumber=0;LenNumber<6;LenNumber++)
    SetNumberBuffA(LenNumber,numUndefined);
 XchgNumbBuffers();
 XchgNumbBuffers();
*/
/*
   ResetBooks();
   for (NCall=0;NCall<MaxLn;NCall++)
   {
     LenNumber=Lnumbers[NCall][0];
     for (PosEdit=0;PosEdit<LenNumber;PosEdit++)
       SetNumberBuffA(PosEdit,Lnumbers[NCall][PosEdit+1]);
     SaveNumber(nbAreaCode,bBookSpecical);//NCall
   }
//   ClearUndefinedNumbers();


   LenNumber=CompNumber[0];
   for (PosEdit=0;PosEdit<LenNumber;PosEdit++)
     SetNumberBuffA(PosEdit,CompNumber[PosEdit+1]);

 //  NumberFound=-1;
//   BookFound=bBookOut;
//   goto GGGGGGGGGG;

   SearchNumber(nbAreaCode,1,bBookSpecical,tcbUseLenPack);
*/
/*
 ResetBooks();
 for (LenNumber=0;LenNumber<7;LenNumber++)
    SetNumberBuffA(LenNumber,numUndefined);
 PrepareSayingData();
 MinSay=1;
 SaveNumber(0,bBookIn);
// LoadNumber(0,bBookIn);
// DeleteNumber(0,bBookIn);
 SaveNumber(0,bBookIn);
 LoadNumber(0,bBookIn);
 LoadNumber(1,bBookIn);
*/
/*
 for (LenNumber=0;LenNumber<7;LenNumber++)
    SetNumberBuffA(LenNumber,num1);
 SaveNumber(0,bBookIn);
 for (LenNumber=0;LenNumber<7;LenNumber++)
    SetNumberBuffA(LenNumber,num2);
 SaveNumber(0,bBookIn);
 DeleteNumber(1,bBookIn);
*/
 /*
 ResetBooks();
 for (LenNumber=0;LenNumber<7;LenNumber++)
    SetNumberBuffA(LenNumber,numUndefined);
 SaveNumber(0,bBookZK);
 ClearBook(bBookZK);
 */
/*
     ResetBooks();
     for (LenNumber=0;LenNumber<7;LenNumber++)
        SetNumberBuffA(LenNumber,numUndefined);
     for (MinOption=0;MinOption<10;MinOption++)
        SaveNumber(MinOption,bBookWhite);
     for (MinOption=0;MinOption<10;MinOption++)
        SaveNumber(MinOption,bBookZK);
     ClearBook(bBookWhite);
*/
/*
     LenNumber=8;
     SaveNumber(0,bBookZK);
*/
/*
     ClearBook(bBookZK);
     for (LenNumber=0;LenNumber<32;LenNumber++)
        SetNumberBuffA(LenNumber,LenNumber);
     SaveNumber(9,bBookZK);
//     LenNumber=1;
     SaveNumber(8,bBookZK);
     LoadNumber(9,bBookZK);
*/
/*
     ClearBook(bBookZK);
     for (MinOption=30;MinOption<32;MinOption++)
     {
       for (LenNumber=0;LenNumber<MinOption;LenNumber++)
          SetNumberBuffA(LenNumber,LenNumber);
       SaveNumber(8,bBookZK);
       for (LenNumber=0;LenNumber<32;LenNumber++)
          SetNumberBuffA(LenNumber,0);
       LoadNumber(8,bBookZK);
     }
     if (LenNumber==0)
       Halt;
*/
/*
     SaveValue(oAllHourSay,205);
     SaveValue(oAllMinSay,45);

     SaveValue(oCallsPerAllTime,12345);
     SaveValue(oTodayCalls,249);
*/
     InitMain();

     Night=false;
//     LockAllNumbers=false;
//     LockCallAll=LockCountryCode=LockNumbers=true;
     do
     {
//    ViewOff=true;
       if (!DontView&&!ViewOff)
         ViewDataBufferRom(VFunc);
       DontView=false;
       Event=IdleMode_WaitForEvent();
       EventCallPosition();
       do
       {
         TestFuncChg();
         switch (Event)
         {
            case eBeepStart:
                 EventKeyUp=eBeepEnd;
                 BeepStart(FKey);
                 break;
            case eBeepEnd:
                 BeepStop();
                 CallSelect=false;
                 break;
            case eTakeNumeralKey:
                 Event=eBeepStart;
                 continue;
            case eSubmitMode:
                 LeaveAllFunc();
                 Event=EventOfModeKey(SubmitKey);
                 continue;
            case eExitToMain:
                 StopSearch();
                 LeaveAllFunc();
                 break;
            case eReturn:
                 LeaveFunc();
                 break;
            case eMode:
                 LeaveAllFunc();
                 EFunc=fMode;
                 EnterFunc();
                 EFunc=fShowNumber;
                 SubmitKey=skMode;
                 break;
            case eCall:
                 SayPhrase(phrTestSamples,eNone);
                 break;
                 TestMelody();
                 TestVoice();
                 ToneDebug();
                 break;
            case eKeyPresent:
                 Event=GetEventOnFKey(KFunc); //Get Event on EFunc&OEvent
                 if (Timer1sAEvent==eExitToMainTime)
                   SetTimeOutExit();
                 if (RemoteAccess)
                   continue;
                 if (FKey!=kfVolume)
                   SndOnKey(FKey);
                 if (AONLocked&&Event!=eNone&&FKey!=kfSpkPhnOnOff)
                   if (LoadValueN(oPassOn)&&LoadValueN(oAONlock)==aonlAllModes)
                   {
                     Event=eEnterPassword;
                     continue;
                   }
                 SetTimeOutPowerDown();
                 continue;
            case eKeyPresentNoSnd:
                 Event=GetEventOnFKey(KFunc); //Get Event on EFunc&FKey
                 continue;

            case eBitDaySet:
                 DaySetOnKey(FKey);
                 OptSelect=true;
                 break;
            case eIncOption:
                 if (ValueEdit++==MaxValue)
                   ValueEdit=MinValue;
                 OptSelect=true;
                 Event=eAutoNext;
                 continue;
            case eIncOptionA:
                 ValueEdit++;
                 OptSelect=true;
                 Event=eAutoNext;
                 continue;
            case eDecOptionA:
                 ValueEdit--;
                 OptSelect=true;
                 break;
            case eSetMin:
                 ValueEdit=MinValue;
                 OptSelect=true;
                 Event=eAutoNext;
                 continue;
            case eSetMax:
                 ValueEdit=MaxValue;
                 OptSelect=true;
                 Event=eAutoNext;
                 continue;
            case eSetCharEditBuff:
                 if (EFunc!=fEditCharBuff)
                 {
                   EFunc=fEditCharBuff;
                   EnterFunc();
                 }
//Enter
                 SetCharInEditBuff(FKey);
                 if (++PosEdit==(LenEdit&0xF))
                 {
                   EditModeValue=false;
                   if (!TypeOfData)
                     ValueEdit=DecToHexData(ValueEdit);
                   LeaveFunc();
//                   if (EFunc==fEditOption)
//                     OptSelect=true;
                   Event=eAutoNext;
                   continue;
                 }
                 if (FunctionCalls[FSP-1]==fAutoDialCustom)
                   if (PosEdit==1)
                   {
#define LenWaitBeforeCustomDial 2
                     Timer1sA=LenWaitBeforeCustomDial;
                     Timer1sAEvent=eSubmitCustomDialNumber;
                   }
                   else
                     SetTimeOutExit();
                 break;
            case eDeleteCharEditBuff:
                 SetTimeOutExit();              //!!!
                 if (PosEdit--==0)
                 {
                   LeaveFunc();
                   Event=eAutoPrevious;
                   continue;
                 }
                 DeleteCharInEditBuff();
                 break;
            case eNextOption:
                 if (Option++==MaxOption)
                   Option=MinOption;
                 OptSelect=true;
                 break;
            case ePreviousOption:
                 if (Option--==MinOption)
                   Option=MaxOption;
                 OptSelect=true;
                 break;
            case eEditOpt0:
                 MinOption=mnEditOpt0;
                 MaxOption=mxEditOpt0;
                 Event=eEnterOption;
                 continue;
            case eEditOpt1:
                 MinOption=mnEditOpt1;
                 MaxOption=mxEditOpt1;
                 Event=eEnterOption;
                 continue;
            case eEditOpt2:
                 MinOption=mnEditOpt2;
                 MaxOption=mxEditOpt2;
                 Event=eEnterOption;
                 continue;
            case eEditOpt3:
                 MinOption=mnEditOpt3;
                 MaxOption=mxEditOpt3;
                 Event=eEnterOption;
                 continue;
            case eEditOpt4:
                 MinOption=mnEditOpt6;
                 MaxOption=mxEditOpt6;
                 Event=eEnterOption;
                 continue;
            case eEditBud:
                 MinOption=mnEditOpt4;
                 MaxOption=mxEditOpt4;
                 NumberOfAlarm=0;
                 Event=eEnterOption;
                 continue;
            case eEditNight:
                 MinOption=mnEditOpt5;
                 MaxOption=mxEditOpt5;
                 Event=eEnterOption;
                 continue;
            case eEnterOption:
                 if (TestLockLevel1())
                 {
                   Event=eEnterPassword;
                   continue;
                 }
                 LeaveAllFunc();
                 Option=MinOption;
                 EFunc=fEditOption;
                 if (Option==oShowIn)
                   SaveValueN(oNewNotSayCalls,false);
//                   NewNotSayCalls=false;
                 OptSelect=true;
                 break;
            case eSetupMode:
                 EFunc=fSetup;
                 SubmitKey=skSetup;
                 break;
            case eBookSelectMode:
                 EFunc=fBookSelect;
                 SubmitKey=skBookSelect;
                 break;
            case eUpdateView:
                 if (EFunc==fMain)
                   GetMainModeVFuncData();
//                   EnterMain();
                 break;
            case eAdd_CallNumeralBuff:
                 EndCallEvent=ePauseUntilStartSaying;
                 EditingBuff=EditCallBuff;
                 EditCallBuff=true;
                 if (CallSelect&&PosCall==MaxLenNumber-1)
                   break;
                 CallEvent(eAddNumeralBuff);
                 if ((PosCall+1)==LenNumber)
                 {
                  if (PosCall==0)
                  {
                    TypeNumber=false;
                    LoadCallParam();
                    TestEveryNumeralBeep=false;
                  }
                  if (ToneCall&&CallEnable)
                  {
                    EventKeyUp=eStopCallSet;
                    BeeperCall=true;
                  }
                  SecondCall=false;
                  Event=eNextNumeralCall;
                  continue;
                 }
                 break;
            case eAddNumeralBuff:
                 if (SayNumeralAfterBeep)
                 {
                   WavData[0]=FKey-kf0;
                   EventEndWavPlaying=eSayCurrKey;
                   if (!SndPlaying)
                     SayKey(phrSay0_B,WavData[0],eNone);
//                   SayPhrase(phrS1,eSayCurrKey);
                   SayNumeralAfterBeep=false;
                 }

                 if (!EditingBuff)
                 {
                  OffsetNumberView=LenNumber=0;
                  EditingBuff=true;
                 }
                 Timer4msAEvent=eNone;
                 if (LenNumber!=MaxLenNumber)
                   LenNumber++;
                 SetNumberBuff(LenNumber-1,FKey);

                 if (EditCallBuff)
                   SaveDefaultNumber();

                 TestStartAutoSearch();
                 TestStartAutoDial();

                 if ((OffsetNumberView=LenNumber-MaxNumeralView)&0x80)
                   OffsetNumberView=0;
                 break;
            case eDeleteNumeralBuff:
                 if (!EditingBuff||LenNumber==0)
                 {
                   if (EFunc==fEditNumber)
                   {
                     SaveNumberNow = true;
                     LeaveFunc();
                   }
                   Event=eAutoPrevious;
                   continue;
                 }
                 if (EditCallBuff&&PipeUp&&LenNumber<=PosCall+1)
                   break;
                 LenNumber--;

                 if (EditCallBuff)
                   SaveDefaultNumber();

                 TestStartAutoSearch();
                 TestStartAutoDial();

                 if ((OffsetNumberView=LenNumber-MaxNumeralView)&0x80)
                   OffsetNumberView=0;
                 break;
            case eAutoNext:
                  if (Error)
                    break;
                  FKey=kfAutoNext;
                  Event=GetEventOnFKey(KFunc);
                  continue;
            case eAutoPrevious:
                  if (Error)
                    break;
                  FKey=kfAutoPrevious;
                  Event=GetEventOnFKey(KFunc);
                  continue;
            case eMainEditNumber:
                 Event=EFunc;
                 LeaveAllFunc();
                 if (PipeUp)
                 {
                   EFunc=fMainEditNumberPipeUp;
                   EnterFunc();
                   EFunc=fShowNumber;
                 }
                 else
                   EFunc=fMainEditNumberPipeDown;
                 PlayExitSound=false;
                 if (FKey==kfNone)
                   break;
                 Event=eKeyPresentNoSnd;
                 continue;
            case eShowNumber:
                 EFunc=fShowMainNumber;
                 EnterFunc();
                 EFunc=fShowNumber;
                 break;
            case eRolNumber:
                 TimeOutViewRolNuber=DefaultTimeOutViewRolNuber;
                 OffsetNumberView++;
                 if (GetPauseRolNumber(OffsetNumberView,LenNumber))
                   TimeOutViewRolNuber=LongTimeOutViewRolNuber;
                 if (OffsetNumberView==LenNumber)
                   OffsetNumberView=-MaxNumeralView+1;
                 break;
            case eBeepDetected:
                 Event=GetEventOnBeepMap(BeepEventMap,TypeBeep);
                 StopBeepTesting();
                 FastBeepTest=false;
                 continue;
            case eNextNumeralCall:
//                 EndAutoDialed=false;
                 Calling=true;
                 if (CallEnable)
                 {
                   StopBeepTesting();
                   SetTimeOutExit();
                   if (PosCall==0)
                     LoadCallParam();
                   if (PosCall!=LoadDefaultNumber(dfnLenNumber)
                   &&(!SecondCall||PosCall!=MaxLenNumber-1))
                   {
                     Event=GetNumeralDefaultBuff(PosCall);
                     if (AutoDial)
                     {
                       if (PosCall==0)
                       {
                         if (!SecondCall&&!PrefixTested)
                         {
                           SecondCall=true;
                           BeepTesting=true;
                           BeepTimeDetect=AutoCallLineUpBeepWait;
                           BeepEventMap=bmCallWaitVeryLongBeepMap;
                           break;
                         }
                         if (!PrefixTested)
                         {
                           if (LoadValueN(oPrefixType)>0
                           &&LoadDefaultNumber(dfnLenNumber)>=LoadValueN(oATSLenNumber))
                           {
                             Event=LoadValueN(oPrefix);
                             PosCall--;
                             PrefixTested=true;
                           }
                         }
                         else
                           if (!PrefixBeepTested)
                           {
                             switch(LoadValueN(oPrefixType))
                             {
                               case pfxNone:
                               case pfxNoPause:
                                    break;
                               case pfxPause:
                                    PosCall--;
                                    Event=numPause;
                                    break;
                               case pfxWaitVeryLongBeep:
                                    PosCall--;
                                    Event=numWaitLongBeep;
                                    break;
                             }
                             PrefixBeepTested=true;
                           }
                       }
                       if (!SecondCall&&PosCall==1&&
                       GetNumeralDefaultBuff(0)==LoadValueN(oCountryCode))
                       {
                         SecondCall=true;
                         BeepTesting=true;
                         BeepTimeDetect=LoadValueN(oCountryBeepWait);
                         BeepEventMap=bmCallWaitVeryLongBeepMap;
                         break;
                       }
                       if ((OffsetNumberView=PosCall-MaxNumeralView+1)&0x80)
                         OffsetNumberView=0;
                     }
                     Event=SetCallData(Event);
                     SecondCall=false;
                     if (PosCall==MaxLenNumber-1)
                       SecondCall=true;
                   }
                   else
                   {
                     if (!LoadDefaultNumber(dfnLenNumber))
                     {
                      LeaveAllFunc();
                      break;
                     }
                     Event=EndCallEvent;                //End Call curr number
                     Calling=false;
                     EndAutoDialed=true;
                     if (PipeUp)
                     {
                       if (SpeakerOn)
                         SetSpeakerOn();
                       else
                         PipeOn();
                     }
                     SecondCall=false;
                   }
                   continue;
                 }
                 break;
            case eStopCallSet:
                 if (ToneCallA)
                   BeepStop();
                 else
                 {
                   StopImpulse();
                   if (LoopImpulseCall!=0)
                   {
                     TimerCall=LenPauseImpulse;
                     TimerCallEvent=eStartImpulseSetA;
                     break;
                   }
                 }
                 PipeOnOff();
                 SetSpeakerOnOff();
                 LineUp();
                 if (!AutoDial)
                   if (TestLock(lCall))   //Test Lock
                   {
                     Event=eEnterLock;
                     continue;
                   }
                 if (BeeperCall&&ToneCallA)
                 {
                   BeeperCall=false;
                   Event=eNextNumeralCallN;
                   continue;
                 }
                 else
                 {
                   TimerCall=PauseUntilNextNumeral;
                   TimerCallEvent=eNextNumeralCallN;
                 }
                 BeeperCall=false;
                 if (TestEveryNumeralBeep&&AutoDial)
                 {
                   BeepTesting=true;
                   FastBeepTest=true;
                   TimerCallEvent=eBeepDetected;
                   BeepEventMap=bmCallTestShortBeepMap;
                   BeepTimeDetect=FastBeepTestTime;
                 }
                 break;
            case eStartImpulseSetA:
                 LoopImpulseCall--;
                 GetP4;                                 //!!!!!!!!!!!!WARNING
                 if (!Line)
                 {
                   StopCall();
                   LeaveAllFunc();
                   PlayExitSound=false;
                   if (PipeUp)
                   {
                     PipeUp=false;
                     Event=ePipeIsUp;
                     continue;
                   }
                   break;
                 }
            case eStartImpulseSet:
                 TimerCall=LenImpulse;
                 TimerCallEvent=eStopCallSet;
                 LineDown();
                 StartImpulse();
                 break;
            case ePipeIsUp:
                 if (!PipeUp)
                   ConfidenceOn=false;
                 if (AutoDial)
                 {
                   PipeUp=true;
                   if (EndAutoDialed)
                   {
                     Event=EndCallEvent;
                     continue;
                   }
                   else
                     break;
                 }
                 if (EFunc==fBeepEmulation)
                   CallEvent(eStartSayingData);

                 if (EFunc==fHold)
                   PipeUp=true;

                 Event=eNone;
                 if (EFunc==fCalling)
                 {
                   Event=eIndification;
                   goto NextPipeUp;
                 }
                 if (EFunc==fIndification)
                   goto NextPipeUp;
                 Event=eMainEditNumber;
                 FKey=kfNone;
                 if (!LineLoad||EFunc==fLineGet)
                 {
                   TimerCall=Convert10msTo4ms(LoadValueN(oKvantPipeUp));
                   CallEvent(eStartKZ);
                   Event=eMainEditNumber;
                 }
                 if (!HangUp)
                   CallEnable=true;
                 StopPlay();
                 LeaveAllFunc();
NextPipeUp:
                 if (!PipeUp)
                 {
                   Calling=EditingBuff=EditCallBuff=false;
                   PosCall=0;
                 }
                 PipeUp=true;
                 if (SpeakerOn)
                   SetSpeakerOn();
                 else
                   PipeOn();
                 PlayExitSound=false;
                 continue;
            case ePipeIsDown:
                 PipeUp=false;          //PipeBits
                 SpeakerOn=false;
                 if (EFunc==fHold)
                   break;
                 SetSpeakerOff();
                 PipeOff();
                 LeaveAllFunc();
                 EditCallBuff=false;
                 EditingBuff=false;
                 Calling=false;
                 StopCall();
                 StopPlay();
                 PlayExitSound=false;
                 break;
            case eStartKZ:
                 HangUp=true;
                 BeeperCall=false;
                 CallEnable=false;
                 ToneCall=LoadValueN(oTypeLineCall);
                 TimerCallEvent=eStopKZ;
                 StartImpulse();
                 break;
            case eStopKZ:
                 StopImpulse();
                 HangUp=false;
                 CallEnable=true;
                 LineUp();
                 if (Calling)
                 {
                   Event=eNextNumeralCall;
                   continue;
                 }
                 break;
            case eNextNumeralCallN:
                 CallSelect=false;
                 if (SecondCall)
                 {
                    Event=eNextNumeralCall;
                    continue;
                 }
                 if (PosCall!=MaxLenNumber-1)
                 {
                    PosCall++;
                    Event=eNextNumeralCall;
                    continue;
                 }
                 break;
            case eToneSet:
                 Event=eAddNumeralBuff;
                 FKey=numToneSet+1;
                 continue;
            case eToneSetKey:
                 EFunc=fToneCall;
                 Event=eAdd_CallNumeralBuff;
                 FKey=numToneSet+1;
                 continue;
            case eSpeakerPhoneChange:
                 if (SpeakerOn++)
                   Event=ePipeIsUp;
                 else
                 {
                   Event=ePipeIsDown;
                   if (CurrPipe)
                     Event=ePipeIsUp;
                 }
                 continue;
            case ePipeChanged:
                 if (CurrPipe)
                 {
                   if (SpeakerOn)
                     SpeakerOn=false;
                   Event=ePipeIsUp;
                 }
                 else
                 {
                   Event=ePipeIsDown;
                   if (SpeakerOn)
                     Event=ePipeIsUp;
                 }
                 continue;
            case eReturnKeyEvent:
                 Event=EFunc;
                 LeaveFunc();
                 if (Event==fShowNumber)
                   if (GetEventOnFKey(KFunc)==(eNone+eNone*0x100))
                     EFunc=Event;
//                   EFunc=fShowNumber;
                 Event=GetEventOnFKey(KFunc); //Get Event on EFunc&FKey
                 continue;

            case eAutoDialKey:
                 if (RemoteAccess)
                 {
                   if (EditingOptions)
                     RAVFunc=-1;
                   break;
                 }
                 LoopRedial=AutoDialLoops;
                 EndCallEvent=eBeepTestCall;
                 SaveDefaultNumber();
                 LeaveAllFunc();
            case eAutoDial:
                 if (ParallelNumber)
                   break;
                 ShowSearch=false;
                 SaveDefaultNumber();
                 if (TestLock(lCall))
                 {
                   Event=eEnterLock;
                   continue;
                 }
                 EFunc=fAutoDial;
                 LoopCallBeforePause=LoadValueN(oACallLoopBeforeTimeOut)+1;
                 Event=eRedialA;
                 continue;
            case eAutoDialA:
                 EditCallBuff=true;
                 EndAutoDialed=false;
                 StopCall();
                 PipeOff();
                 LineUp();
                 TimeOutCall=false;
//                 SoundOn();
                 PrefixTested=false;
                 PrefixBeepTested=false;
                 HangUp=false;
                 if (LoopCallBeforePause--==0)
                 {
                  Timer1sA=LoadValueN(oACallTimeOut)*10+1;
                  Timer1sAEvent=eAutoDial;
                  break;
                 }
                 TimerCall=Convert10msTo4ms(LoadValueN(oKvantPipeUp));
                 PosCall=0;
                 Calling=true;
                 SecondCall=false;
#define LenWait10sAfterAutoDial 6;
                 Timer10sA=LenWait10sAfterAutoDial; //!!!!!
                 Event=eStartKZ;
                 continue;
            case eRedialA:
                 LoopCallBeforePause++;
                 LoopRedial++;
            case eRedial:
                 StopCall();
                 AutoDial=true;
                 if (--LoopRedial==0)
                 {
                   Event=eExitToMainTime;
                   continue;
                 }
                 HangUp=true;
                 TimeOutCall=false;
                 TimerCallEvent=eAutoDialA;
                 TimerCall=PauseBeforeNextDial;
                 break;
            case eBeepTestCall:
                 Event=eBeepTestCallA;
                 if (Timer10sA--==0)
                   Event=eRedial;
                 Timer1sA=BeepTestTimeAutoDialOnKey;
                 Timer1sAEvent=eBeepTestCall;
                 continue;
            case eBeepTestCallA:
                 SoundOn();
                 StopBeepTesting();
                 if (PipeUp||!ParallelTest())
                 {
                   LeaveAllFunc();
                   CallEvent(ePauseUntilStartSaying);
                   PlayExitSound=false;
                   FKey=kfNone;
                   Event=eMainEditNumber;
                   continue;
                 }
                 BeepTesting=true;
                 BeepEventMap=bmAutoDialEndTest;
                 BeepTimeDetect=BeepTestTimeAutoDialOnKey;
                 break;

            case eFlashStart:
                 if (!PipeUp&&!Calling&&!LineLoad)
                 {
                   Event=eExitToMain;
                   continue;
                 }
                 StopCall();
                 StopPlay();
                 TimerCall=Convert10msTo4ms(LoadValueN(oFlashPause));
                 TimerCallEvent=eFlashEnd;
                 EFunc=fFlash;
                 LoadDefaultNumber(dfnNumber);
                 EnterFunc();
                 DisableLKey=true;
                 break;
            case eFlashEnd:
                 LeaveFunc();
                 if (EFunc==fAutoDial)
                   Event=eAutoDial;
                 else
                 {
                   Event=ePipeIsUp;
                   PipeUp=false;
                 }
                 continue;

            case eStartSayingData:
                 if (Saying)
                   break;
                 if (AutoUp)
                   BackCall=false;
                 Saying=true;
                 PrepareSayingData();
                 if (EFunc==fParallelDetect&&Snd)
                   break;
                 if (EFunc!=fSoundMode&&EFunc!=fHold&&EFunc!=fLineGet)
                 {
//                 if (!Snd&&!SndPlaying)
//                 {
                   LeaveAllFunc();
                   PlayExitSound=false;
//                   Event=eUpdateView;
//                   continue;
//                 }
                 }
                 break;
            case eStopSayingData:
                 LoadDefaultNumber(dfnNumber);
                 if (++MinSaying==60)
                 {
                   MinSaying=0;
                   HourSaying++;
                 }
                 if (HourSaying>7)
                   HourSaying=7;
                 Saying=false;
                 Book=bBookOut;
                 if (!InSaying||TestSaveInUdefined())
                 {
                   if (InSaying)
                   {
                     LoadNumber(0,bBookIn);
                     DeleteNumber(0,bBookIn);
                     Book=bBookIn;
                   }
                   MinSay=MinSaying;
                   HourSay=HourSaying;
                   if (!InSaying)
                   {                                            //Save CxTimeSay
                     MinSaying+=LoadValueN(oAllMinSay);
                     if (MinSaying>59)
                     {
                       MinSaying-=60;
                       HourSaying++;
                     }
                     if (HourSaying+LoadValueN(oAllHourSay)>255)
                     {
                       HourSaying=255;
                       MinSaying=59;
                     }
                     else
                       HourSaying+=LoadValueN(oAllHourSay);
                     SaveValue(oAllHourSay,HourSaying);
                     SaveValue(oAllMinSay,MinSaying);
                   }
                   SaveNumber(0,Book);
//  VideoBuffer[0][1]=Book;
//  VideoBuffer[1][1]=InSaying;
//  Halt;
                 }
                 if (EFunc==fAutoDial||EFunc==fFlash)
                   break;
                 LeaveAllFunc();
                 EFunc=fShowTimeSayingNow;
                 PlayExitSound=false;
                 break;
            case ePauseUntilStartSaying:
                 InSaying=false;
                 Timer1sB=LenWaitOnEndCalled;
                 Timer1sBEvent=eStartSayingData;
                 break;
            case eStartBell:
                 StopPlay();
                 if (EFunc!=fCalling)
                 {
                   LeaveAllFunc();
                   EFunc=fCalling;
                   EnterFunc();
                   if (NCall==0)
                   {
                     Event=eIndification;
                     continue;
                   }
//                   Timer1sA=WaitTimeCallToExit;
//                   break;
                 }
                 Timer1sA=WaitTimeCallToExit;
                 break;
            case eEndBell:
                 if (NCall!=-1)
                   if (--NCall==0)
                   {
                     Event=eIndification;
                     continue;
                   }
                 if (ValueData[0]<99)
                   ValueData[0]++;
                 if (ValueData[0]!=1)
                 {
                   if (!Night)
                     BellPlay();
                 }
                 break;

            case eIndification:
                 BackCall=LoadValueN(oBCall);
                 AutoUp=true;
                 if (NCall!=0)
                 {
                   if (!LoadValueN(oAnswerBackParallel))
                     BackCall=false;
                   AutoUp=false;
                 }
                 EFunc=fIndification;
                 if (AONMode==modeNoIndification)
                 {
                   Event=eExitToMainTime;
                   continue;
                 }
                 Timer4msA=Convert10msTo4ms(LoadValueN(oKvantAutoPipeUp));
                 Timer4msAEvent=eStartIndificate;
                 StartImpulse();
                 break;
            case eStartIndificate:
                 StopImpulse();
                 CurrentPauseRequest=PauseRequest0;
                 if (PauseRequest0!=0)
                   Event=eAnswerListening;
                 else
                   Event=eSendRequest;
                 continue;
            case eAnswerListening:
                 LineSoundStop();
                 if (ListenAnswer)
                   SoundOn();
                 if ((ValueData[2]=TestOnSendAnswer(CurrentPauseRequest))!=opnMutByte)
                 {
                   Event=eIndificationGetAnswer;
                   continue;
                 }
                 Event=eSendRequest;
                 continue;
            case eSendRequest:
                 ValueData[0]++;
                 if (NRequest--==0)
                 {
                   ValueData[2]=opnMutByte;
                   Event=eIndificationGetAnswer;
                   continue;
                 }
                 Timer1sAEvent=eNone;
                 Timer4msA=LenRequest;
                 Timer4msAEvent=eAnswerListening;
                 TimeOut4msA=false;
                 if (LenRequest>1)
                   FormRequest=RequestStart(FormRequest,ListenAnswer);
                 CurrentPauseRequest=PauseRequest;
                 break;

            case eIndificationGetAnswer:
                 GetAnswerAndDecode(ValueData[2]);
                 SaveValue(oCallsPerAllTime,LoadValueN(oCallsPerAllTime)+1);
                 SaveValue(oTodayCalls,LoadValueN(oTodayCalls)+1);

                 LenNumber=7;
                 EditCallBuff=false;
                 TypeNumber=true;
                 SaveDefaultNumber();
                 LeaveFunc();
                 LineUp();
                 LoadDefaultNumber(dfnNumber);
                 EFunc=fBeepEmulation;
                 if (SearchNumber(nbAreaCode,1,bBookSpecical,tcbUseLenPack)!=-1)  //AreaCode
                 {
#define AC_TmpLen Event
#define AC_i      ValueEdit
                   LoadNumber(nbAreaCode,bBookSpecical);
                   AC_TmpLen=LenNumber;
                   LenNumber=LoadDefaultNumber(dfnLenNumber);
                   for(AC_i=0;AC_i<LenNumber-AC_TmpLen;AC_i++)
                     SetNumberBuffA(AC_i,GetNumberBuff(AC_i+AC_TmpLen));
                   LenNumber-=AC_TmpLen;
//                   LenNumber--;
                 }
                 else
                 {
                   Event=LoadValueN(oATSLenNumber);
                   for (LenNumber=0;LenNumber<Event;LenNumber++)
                     SetNumberBuffA(LenNumber,GetNumberBuff(LenNumber+7-Event)); //remove first numerals if len number<<
                 }
                 //change number search
                 ValueEdit=SearchNumber(nbChangeNumber,nbLenChangeNumber,bBookSpecical,tcbMaskBuff2);
                 if (ValueEdit!=-1)
                   LoadNumber(nbChangeNumberTo-nbChangeNumber+ValueEdit,bBookSpecical);
                 SaveDefaultNumber();

                 CurrFilter=LoadValueN(oFilter);
                 SoundsPlay=!Night;
                 //Black search
                 if (CurrFilter&fltrBlack)
                   if (SearchNumber(0,MaxNumbersBlack,bBookBlack,tcbMaskBuff2)!=-1)
                   {
                     BlackNumber=true;
                     SoundsPlay=false;
                   }
                 //White search
                 if (CurrFilter&fltrWhite)
                 {
                   SoundsPlay=false;
                   if (SearchNumber(0,MaxNumbersWhite,bBookWhite,tcbMaskBuff2)!=-1)
                     SoundsPlay=true;
                 }
                 PrepareSayingData();
                 if (TestSaveInUdefined())
                    SaveNumber(0,bBookIn);
                 InSaying=true;
                 ParallelDetect=false;
                 TestEnterRemoteAccsess=ToneTesting=LoadValueN(oRemoteAccess);
                 PlayExitSound=false;

                 Event=ePlayBellInRoom;
                 if (SearchNumber(nbSayNumber,nbLenSayNumber,bBookSpecical,tcbMaskBuff2)!=-1)
                 {
                   Event=eStartNumberSay;
                   Book=bBookIn;
                 }
                 PhrRepeat=NumberOfRepeatSayInLine;
                 switch (AONMode)
                 {
                   case modeNumberReaddress:
                   case modeFullReaddress:
                   case modeTimeReaddress:
                   case modePagerReaddress:
                        Event=eRecallReaddress;
                 }
                 //Black Lock search
                 if (CurrFilter&fltrBlackLock)
                   if (SearchNumber(0,MaxNumbersBlackLock,bBookBlackLock,tcbMaskBuff2)!=-1)
                     Event=eExitToMainTime;
                 //TestSayNuber/StarSaying
                 if (PipeUp||!ParallelTest())
                 {
                   if (!AutoUp&&!PipeUp&&(Event=LoadValueN(oParalTypeNumberSay))>0)
                   {
                     if (Event==1)
                       LineSoundOn();
                     SayNumber(phrNumberSay,eStartSayingData);
                     if (Event==3)
                     {
                       LineSoundOn();
                       SoundToLine=false;
                     }
                     Event=eNone;
                   }
                   else
                     Event=eStartSayingData;
                 }
                 Book=bBookIn;
                 continue;

            case eStartBeepLine:
                 StopTimer1sA();
                 StopBeepTesting();
#ifndef __DEBUG_RemoteAccessKey
                 if (PipeUp||!ParallelTest())
                 {
                   Event=eStartSayingData;
                   continue;
                 };
#endif
                 LineSoundOn();
                 BeepLineStart();
                 Timer4msA=TimeLenBeep4ms;
                 Timer4msAEvent=eEndBeepLine;
                 break;
            case eEndBeepLine:
                 LineSoundStop();
#ifndef __DEBUG_RemoteAccessKey
                 if (PipeUp||!ParallelTest())
                 {
                   Event=eStartSayingData;
                   continue;
                 };
#endif
                 BeepTesting=true;
                 BeepEventMap=bmToneBeepEmulation;
                 BeepTimeDetect=FastToneBeepDetectBeepEmulation;
                 break;
            case ePlayBellInRoom:
                 BeepTesting=true;
                 BeepEventMap=bmBeepEmulation;
                 BeepTimeDetect=TimeBeepDetectBeepEmulation;
                 if (SoundsPlay)
                 {
                   if (RepeatSayNumber>0&&NBeepPlaying!=0)
                   {
                     BeepTimeDetect=TimeSayBeepDetect;
                     SayNumber(phrNumberSay,eStartBeepLine);
                     RepeatSayNumber--;
                   }
                   else
                     BellPlay();
                 }
                 else
                 {
                   if (ListenLine)
                     SoundOn();
                 }

                 if (NBeepPlaying==NBeepsLineDown)
                 {
                   Event=eExitToMainTime;
                   continue;
                 }
                 if (!BlackNumber&&NBeepPlaying==LoadValueN(oNightBells))
                   SoundsPlay=true;
                 NBeepPlaying++;
                 break;

            case eNextPlayWav:                          //Next wav playing
                 if (PlaySampleNext())
                   if (GetNextPlay())
                   {
                     Event=EventEndWavPlaying;
                     StopPlay();
                     continue;
                   }
                 DontView=true;
                 break;
            case eSayCurrentTime:
                 SayTime(phrTimeSay,Hours,Minutes,eNone);
                 PlayExitSound=false;
                 break;
            case eStartEditNumber:
                 EFunc = fEditNumber;
                 break;
            case eStartEditNumberAddNumeral:
                 EFunc = fEditNumber;
                 Event = eAddNumeralBuff;
                 continue;
            case eSubmitEditNumber:
                 SaveNumberNow = true;
                 LeaveFunc();
                 Event = eAutoNext;
                 continue;

            case eClearBook:
                 ClearBook(GetNumberBook(Option));
                 LeaveFunc();
                 OptSelect=true;
                 break;
            case eDeleteNumber:
                 DeleteNumber(ValueEdit,GetNumberBook(Option));
                 LeaveFunc();
                 OptSelect=true;
                 break;

            case eShowBook:
                 LeaveAllFunc();
                 if (FKey>=kfBookSpecical)
                   FKey-=kfBookSpecical;
                 else
                 {
                   if (FKey >= kf7)
                     FKey -= kf7-kf4;
                   FKey -= kf0;
                 }
                 MinOption = MaxOption=mnBookShow+FKey;
                 SelNumberBook=0;
                 TodaySee=true;
                 Event = eEnterOption;
                 continue;
            case eSetUndefinedNumber:
                 Event=LoadValueN(oATSLenNumber);
                 for (LenNumber=0;LenNumber<Event;LenNumber++)
                    SetNumberBuffA(LenNumber,numUndefined);
                 SaveNumberNow = true;
                 break;
            case eEnterClearNumber:
                 EFunc=fClearNumber;
                 break;
            case eShowKateg:
                 EFunc=fShowKateg;
                 break;
            case eShowTimeCall:
                 EFunc=fShowTimeCall;
                 break;
            case eShowTimeSay:
                 EFunc=fShowTimeSay;
                 break;
            case eShowDateCall:
                 EFunc=fShowDateCall;
                 break;
            case eShowCallsPerTime:
                 EFunc=fShowCallsPerTime;
                 break;
            case eShowAllTimeSay:
                 EFunc=fShowAllTimeSay;
                 break;
            case eChangeShowAllTimeSay:
                 if (EFunc==fShowAllTimeSay)
                   GetDataShowAllTimeSay();
                 break;
            case eEnterClearPropAllNumber:
                 EFunc=fClearNumber1;
                 break;
            case eSubmitClearPropAllNumber:
                 LeaveFunc();
                 Event=EFunc;
                 if (EFunc==fShowAllTimeSay)
                   ResetOptions(oAllHourSay,oAllMinSay);
                 else
                   ResetOptions(oCallsPerAllTime,oTodayCalls);
                 LeaveFunc();
                 EFunc=Event;
                 OptSelect=false;
                 break;
            case eStartNumberSay:
                 DisableLKey=true;
                 DirectionSay=LoadValueN(oDirectionSay);
                 ValueEdit=-1;
                 if (EFunc==fRemoteAccessKey)
                 {
                   if (FKey==kf1)
                     Book=bBookIn;
                   else
                     Book=bBookOut;
                 }
                 Event=eNextNumberSay;
                 continue;
            case eNextNumberSay:
                 StopBeepTesting();
                 if (RemoteAccess&&ToneHighQualityDetect)
                 {
                   Timer1sA=1;
                   Timer1sAEvent=eNextNumberSay;
                   break;
                 }
                 SetTimeOutExit();
                 if (EFunc==fShowNumber)
                   LeaveFunc();
                 if (EFunc==fBeepEmulation||RemoteAccess)
                 {
                   LineSoundOn();
                   DirectionSay=dForward;
                 }
                 if ((ValueEdit=FindTodayCall(ValueEdit,Book,DirectionSay))!=-1)
                   SayNumber(phrNumberSay,eNextNumberSayInTime);
                 else
                 {
                   ValueEdit=0;
                   if (EFunc==fBeepEmulation||RemoteAccess)
                     LeaveAllFunc();
                 }
                 TodaySee=true;
                 if (EFunc==fEditOption)
                 {
                   OptSelect=true;
                   TestFuncChg();
                   DisableLKey=true;                      //some izvrat... ;)
                 }
                 break;
            case eNextNumberSayInTime:
                 Event=eNextNumberSay;
                 if (EFunc==fBeepEmulation||RemoteAccess)
                   Event=eNextLineNumberSay;
                 SayTime(phrInTime,HourCall,MinCall,Event);
                 ViewOff=true;
                 break;
            case eNextLineNumberSay:
#define LenBeepTestSayingNumber 1
#ifndef __DEBUG_RemoteAccessKey
                 if (PipeUp||!ParallelTest())
                 {
                   Event=eStartSayingData;
                   continue;
                 }
#endif
                 BeepTesting=true;
                 BeepTimeDetect=LenBeepTestSayingNumber;
                 BeepEventMap=bmBeepTestSayingNumber;
                 break;

            case eTestCurrBeepTone:
                 BeepLineStart();
//                 Event=eTestCurrBeepTone;
                 Amplifer=AmpliferOn;
                 EventKeyUp=eBeepEnd;
                 break;

            case eSetNoSoundPlay:                     //0
                 SoundsPlay=false;
                 break;
            case eSetSoundPlay:                       //1
                 SoundsPlay=true;
                 break;
            case eSetListenLine:                      //2
                 ListenLine=true;
                 SoundsPlay=false;
                 if (BeepTesting)
                 {
                   StopPlay();
                   SoundOn();
                 }
                 break;
            case eSayLineCurrPhrase:
                 Event=EventOfModeKey(skBeepEmulation);
                 StopTimer1sA();
                 StopTimer4msA();
                 LineSoundOn();
                 StopBeepTesting();
                 PhrRepeat=NumberOfRepeatSayInLine;
                 continue;
            case eRecallLater:                        //6
                 EventPhrRepeat=Event;
                 SayPhrase(phrRecallLater,eRepeatPhrase);
                 break;
            case eRecallTomorrow:                     //7
                 EventPhrRepeat=Event;
                 SayPhrase(phrRecallTomorrow,eRepeatPhrase);
                 break;
            case eRecallInTimeLater:                  //8
                 EventPhrRepeat=Event;
                 SayTime(phrRecallInTime,((uchar)(Hours+2))%24,0,eRepeatPhrase);
                 break;
            case eNumberUndefined:                    //9
                 EventPhrRepeat=Event;
                 SayPhrase(phrNumberUndefined,eExitToMainTime);
                 break;

            case eRecallReaddress:
                 EventPhrRepeat=eRecallReaddress;//Event;
                 StopTimer1sA();
                 StopTimer4msA();
                 LineSoundOn();
                 StopBeepTesting();
                 Event=eReaddressingNumber;
                 if (AONMode==modePagerReaddress)
                 {
                   Event=eReaddressingPager;
                   AbonentSaying=false;
                 }
                 SayNumber(phrRecall,Event);
                 break;
            case eReaddressingNumber:
                 if (AONMode==modeTimeReaddress)
                 {
                   Event=eReaddressingTime;
                   continue;
                 }
                 ViewOff=true;
                 LoadNumber(nbReaddressingNumber,bBookSpecical);
                 SayNumber(phrOnNumber,eReaddressingTime);
                 break;
            case eReaddressingTime:
                 if (AONMode==modeNumberReaddress)
                 {
                   Event=eRepeatPhrase;
                   continue;
                 }
                 Event=LoadValueN(oReaddressTime);
                 if (LoadValueN(oUpTimeReaddress))
                   Event=((uchar)(Hours+1))%24;
                 SayTime(phrPInTime,Event,0,eRepeatPhrase);
                 break;
            case eReaddressingPager:
                 ViewOff=true;
                 if (!AbonentSaying)
                 {
                   LoadNumber(nbPagerNumber,bBookSpecical);
                   SayNumber(phrOnPager,eReaddressingPager);
                   AbonentSaying++;
                 }
                 else
                 {
                   LoadNumber(nbPagerAbonent,bBookSpecical);
                   SayNumber(phrForAbonent,eRepeatPhrase);
                 }
                 break;
#define LenTimeBTBeforeRepeatSay 2
            case eRepeatPhrase:
                 if (--PhrRepeat==0)
                 {
                   Event=eExitToMainTime;
                   continue;
                 }
                 if (PipeUp||!ParallelTest())
                 {
                   Event=eStartSayingData;
                   continue;
                 }
                 BeepTesting=true;
                 BeepEventMap=bmBTBeforeRepeatSay;
                 BeepTimeDetect=LenTimeBTBeforeRepeatSay;
                 break;
            case eRepeatPhraseN:
                 SayPhrase(phrIRepeat,EventPhrRepeat);
                 break;

            case eEnterReset:
                 if (TestLockLevel1())
                 {
                   Event=eEnterPassword;
                   continue;
                 }
                 EFunc=fReset;
                 break;
            case eResetAll:
                 ResetType=FKey-kf1;
                 switch (ResetType)
                 {
                   case 0:
                   case 1:
                        ValueData[0]=TimeOutReset;
                        EFunc=fTimeOutReset;
                        Event=eReset;
                        continue;
                   case 2:
                        ResetArams();
                        LeaveAllFunc();
                        break;
                 }
                 break;
            case eReset:
                 Timer4msA=TimeOutReset4ms;
                 Timer4msAEvent=eReset;
                 if (--ValueData[0]==0)
                 {
                   VideoBuffer[8][1]=c0;
                   switch (ResetType)
                   {
                     case 0:
                          ResetBooks();
                     case 1:
                          ResetAllOptions(rstUser);
                   }
                   DeviceReset();
                 }
                 break;

            case eEditAONMode:
                 MinOption=mnAONMode;
                 MaxOption=mxAONMode;
                 Event=eEnterOption;
                 continue;

            case eAutoNext2ByOn:
                 if (ValueEdit==0)
                   break;
                 FKey=kfAutoNext2;
                 Event=GetEventOnFKey(KFunc);
                 continue;
            case eAModeSet:
                 Event=eNone;
                 switch (LoadValueN(oAONMode))
                 {
                   case modeFullReaddress:
                   case modeNumberReaddress:
                        Event=eEditReaddressingNumber;
                        break;
                   case modeTimeReaddress:
                        Event=eEditReaddressingTime;
                        if (MinOption==mnReaddressingTime)
                          Event=eEditAONMode;
                        break;
                   case modePagerReaddress:
                        Event=eEditReaddressingPager;
                 }
                 continue;

            case eEditBCallNumber:
                 MinOption=mnEditBCallNumber;
                 MaxOption=mxEditBCallNumber;
                 Event=eEnterOption;
                 continue;
            case eEditReaddressingNumber:
                 Event=LoadValueN(oAONMode);
                 if (Event==modeTimeReaddress)
                 {
                   Event=eEditReaddressingTime;
                   continue;
                 }
                 MinOption=mnReaddressingNumber;
                 MaxOption=mxReaddressingNumber;
                 Event=eEnterOption;
                 continue;
            case eEditReaddressingTime:
                 SaveValue(oUpTimeReaddress,0);
                 Event=LoadValueN(oAONMode);
                 if (Event==modeNumberReaddress)
                 {
                   Event=eExitToMain;
                   continue;
                 }
                 MinOption=mnReaddressingTime;
                 MaxOption=mxReaddressingTime;
                 Event=eEnterOption;
                 continue;
            case eEditReaddressingPager:
                 MinOption=mnReaddressingPager;
                 MaxOption=mxReaddressingPager;
                 Event=eEnterOption;
                 continue;
            case eMinOver:
                 if (EFunc==fMain)
                 {
                   if (LoadValueN(oReaddressTime)==Hours)
                     SaveValueN(oUpTimeReaddress,1);
                   if (LowBattery&&TestTimeOutPowerDown())
                   {
                     ViewOff=false;
                     DontView=false;
                   }
                 }
                 else
                   DontView=true;
                 break;

            case eBCallStart:
                 LeaveAllFunc();
                 EFunc=fBackCall;
                 EndCallEvent=eBCallStartTest;
                 LoadNumber(nbBCallNumber,bBookSpecical);
                 Event=eAutoDial;
                 continue;
            case eBCallStartTest:
                 LeaveFunc();
                 LineUp();
                 BeepTesting=true;
                 BeepEventMap=bmBCallStart;
                 BeepTimeDetect=LenTimeBCallStartTimeDetect;
                 break;
            case eBCallSay:
                 if (LoopBCallRepeats--==0)
                 {
                   Event=eExitToMainTime;
                   continue;
                 }
                 LineSoundOn();
                 ViewOff=true;
                 if (EFunc==fAlarmDial)
                 {
                   GetClockTimeDate(clkwNowTime);
                   SayTime(phrAlarmSay,NowHours,NowMinutes,eBCallBeepTest);
                   break;
                 }
                 LoadNumber(0,bBookIn);
                 SayNumber(phrNumberSay,eBCallBeepTest);
                 break;
            case eBCallBeepTest:
                 LoadDefaultNumber(dfnNumber);
                 BeepTesting=true;
                 BeepEventMap=bmBCallSaying;
                 BeepTimeDetect=LenTimeBCallPauseSaying;
                 break;
            case eSoundMode:
                 LeaveAllFunc();
                 EFunc=fSoundMode;
                 if (RemoteAccess)
                   EFunc=fRoomListen;
                 break;
            case eAddNumeralParallel:
                 if(!ParallelNumber)
                 {
                   ResetDefaultNumberBuff();
                   ParallelNumber=true;
                 }
                 //Test on lock by '8'
                 if (EFunc==fMain)
                   EFunc=fParallelDetect;
                 Event=LoadDefaultNumber(dfnLenNumber);
                 if (Event!=MaxLenNumber)
                   Event++;
                 SetDefaultLenNumberBuff(Event);
                 SetDefaultNumeralBuff(Event-1,RecivedNumeral);
                 if (EFunc==fParallelDetect||EFunc==fLockNumber)
                 {
                   if ((OffsetNumberView=Event-MaxNumeralView)&0x80)//PosCall
                     OffsetNumberView=0;
                   LoadDefaultNumber(dfnNumber);
                 }
//                 if (Saying)
//                   Timer1sBEvent=eNone;
//                 else
                 if (!Saying)
                 {
//                   Timer1sB=LenTimeWaitBeforeStartSayingParallel;
//                   Timer1sBEvent=eStartSayingData;
                   CallEvent(ePauseUntilStartSaying);
                 }
                 Timer1sAEvent=eNone;
                 if (LoadValueN(oParalOpr)==2)
                   SayKey(phrSay0_B,RecivedNumeral,eNone);
                 if (TestLock(lParallel))
                 {
                   Event=eEnterLock;
                   continue;
                 }
                 break;
            case eEnterLock:
                 LeaveAllFunc();
                 CallEvent(ePipeIsDown);
                 EFunc=fLockNumber;
                 Event=eTestLineFree;
                 Error=true;
                 continue;
            case eTestLineFree:
                 if (ParallelTest())
                 {
                   LeaveAllFunc();
                   break;
                 }
                 Timer1sA=LenTimeBeforeUnLockLine;
                 Timer1sAEvent=eTestLineFree;
                 break;

            case eNextNotePlay:
                 if (NextNotePlay())
                 {
                   Event=EventEndMelodyPlaying;
                   continue;
                 }
                 DontView=true;
                 break;

            case eTestMelody:
                 EventKeyUp=eStopTestMelody;
                 if (Option==oTypeHourSnd)
                 {
                   Event=eNone;
                   PlayClock();
                   continue;
                 }
                 if (Option==oBellTone)
                 {
                   BellPlay();
                   DontView=true;
                   break;
                 }
                 if (Option==oMelodyHold)
                 {
                   if (ValueData[0]==0)
                     break;
                   StartMelody(ValueData[0]-1,MaxVolume,eNone);
                   DontView=true;
                   break;
                 }
                 if (LoadValueN(oTypeAlarm)==atSetMode)
                   break;
                 if (ValueData[2]==0)
                   Event=MaxVolume;
                 else
                 {
                   Event=0;
                   Timer4msA=TimeBeforeNextVolume;
                   Timer4msAEvent=eVolumeUp;
                 }
                 StartMelody(ValueData[1],Event,eNone);
                 DontView=true;
                 break;
            case eVolumeUp:
                 if (VolumeUp())
                 {
                   ValueData[3]++;
                   Timer4msA=TimeBeforeNextVolume;
                   Timer4msAEvent=eVolumeUp;
                 }
                 DontView=true;
                 break;
            case eStopTestMelody:
                 StopPlay();
                 Timer4msAEvent=eNone;
                 break;

            case eHold_LineGet:
                 if (Calling||EFunc==fHold)
                   break;
                 LeaveAllFunc();
                 if (PipeUp)
                 {
                   EFunc=fHold;
                   Event=eStartMelodyHold;
                 }
                 else
                 {
                   EFunc=fLineGet;
                   Event=eTestLineFreeGetLine;
                 }
                 continue;
            case eTestLineHold:
                 if (ParallelTest())
                 {
                   Timer1sA=LenPeriodHold;
                   Timer1sAEvent=eTestLineHold;
                   break;
                 }
                 CallEvent(ePipeIsDown);
                 LeaveAllFunc();
                 break;
            case eStartMelodyHold:
                 if ((Event=LoadValueN(oMelodyHold))!=0)
                 {
                   LineSoundOn();
                   StartMelody(Event-1,MaxVolume,eBeepTestHold);
                   Event=eTestLineHold;
                 }
                 else
                   Event=eBeepTestHold;
                 continue;
            case eBeepTestHold:
                 BeepTesting=true;
                 BeepTimeDetect=LenBeepTestHold;
                 BeepEventMap=bmHold;
                 CallEvent(eTestLineHold);
                 Timer1sAEvent=eNone;
                 break;
            case eTestLineFreeGetLine:
                 if (LinePresent)
                   LineUp();
                 if (!LinePresent&&LineLoad&&!PipeUp)
                   StartMelody(mldyGetLine,MaxVolume,eNone);
                 Timer1sA=LenPeriodGetLine;
                 Timer1sAEvent=eTestLineFreeGetLine;
                 break;

            case eEnterSearch:
                 LeaveAllFunc();
                 if (PipeUp)
                   break;
                 if (!ShowSearch)
                 {
                   LoadDefaultNumber(dfnNumber);
                   if (LenNumber==0)
                     break;
                   LenShowA=LenNumber;
                   NumberFound=-1;
                   BookFound=0;
                 }
                 EFunc=fSearch;
                 Event=eSerachNext;
                 continue;
            case eSerachNext:
                 do
                 {
                   if ((NumberFound=SearchNumber(NumberFound+1,-1,BookFound,tcbLen1Use))==-1)
                     BookFound++;
                 }
                 while(NumberFound==-1&&BookFound!=bBookSpecical);
                 if (BookFound==bBookSpecical)
                 {
                   LeaveAllFunc();
                   EFunc=fMainEditNumberPipeDown;
                   EnterFunc();
                   EFunc=fShowNotFound;
                   EditingBuff=true;
                   break;
                 }
                 ValueData[0]=BookFound;
                 LoadNumber(GetNumberBackBook(NumberFound,BookFound),BookFound);
                 SaveDefaultNumber();
                 EFunc=fShowNumber;
                 break;
            case eReturnSearch:
                 LeaveFunc();
                 EFunc=fMainEditNumberPipeDown;
                 EnterFunc();
                 EditingBuff=true;
                 Event=eKeyPresentNoSnd;
                 continue;

            case eAntiAONStart:
//                 if (Calling)
//                   break;
                 if (EFunc==fAntiAON)
                 {
                   Timer1sAEvent=eNone;
                   EventKeyUp=eExitToMain;
                   break;
                 }
                PosCall=LoadDefaultNumber(dfnLenNumber);
                if (PosCall==MaxLenNumber)
                  PosCall--;
                CallSelect=false;
                 EFunc=fAntiAON;
                 Event=eImpulseAntiAON;
                 continue;
            case eImpulseAntiAON:
#define LenTimeImpulseAntiAON 20
                 InvertImpulse();
                 TimerCall=LenTimeImpulseAntiAON;
                 TimerCallEvent=eImpulseAntiAON;
                 DontView=true;
                 break;

            case eEditCharBuff:
                 EFunc=fEditCharBuff;
                 break;

            case eEditFilter:
                 MinOption=mnEditFilter;
                 MaxOption=mxEditFilter;
                 Event=eEnterOption;
                 continue;
            case eSetFilter:
                 BitSetOnKey(FKey);
                 OptSelect=true;
                 TestFuncChg();
                 ValueData[0]=FKey-kf1;
                 ValueData[1]=(ValueEdit>>FKey-kf1)&1;
                 EFunc=fShowLabelFilterStatus;
                 break;

            case eEnterStore:
                 if (TestLockLevel1())
                 {
                   Event=eEnterPassword;
                   continue;
                 }
                 if (EFunc!=fEditOption)
                   LeaveAllFunc();
                 EFunc=fStore;
                 break;
            case eEnterStoreCustomNumber:
                 LeaveFunc();
                 EFunc=fStoreCustom;
                 OptSelect=false;
                 Event=eEditCharBuff;
                 continue;
            case eStoreCustomNumber:
                 ValueData[0]=ValueEdit;
                 SaveNumber(ValueEdit,bBookZK);
                 LeaveFunc();
                 break;

            case eStoreCustomBook:
                 switch(FKey)
                 {
                   case kf1:
                   case kfBookWhite:
                        FKey=kf1;
                        ValueEdit=bBookWhite;
                        break;
                   case kf2:
                   case kfBookBlack:
                        FKey=kf2;
                        ValueEdit=bBookBlack;
                        break;
                   case kf3:
                   case kfBookBlackLock:
                        FKey=kf3;
                        ValueEdit=bBookBlackLock;
                        break;
                   case kf9:
                   case kfBookZK:
                        FKey=kf9;
                        ValueEdit=bBookZK;
                        break;
                   default:
                        Error=true;
                 }
                 if (Error)
                 {
                   LeaveFunc();
                   break;
                 }
                 ValueData[0]=FKey-kf0;
                 Event=eStoreFirstFree;
                 continue;
            case eStoreFirstFree:
                 Event=ValueEdit;
                 ValueEdit=SearchNumber(0,-1,ValueEdit,tcbFreeSearch);
                 if (ValueEdit==-1)
                 {
                   Error=true;
                   LeaveFunc();
//                   EFunc=fShowNoSpace;
                   break;
                 }
                 SaveNumber(ValueEdit,Event);
                 LeaveFunc();
                 break;

            case eNewPasswordEnter:
                 CallEvent(eNextOption);
                 Event=eEditCharBuff;
                 continue;
            case eEditLock:
                 MinOption=mnEditLock;
                 MaxOption=mxEditLock;
                 CallEvent(eEnterOption);
                 AONLocked=false;
                 break;

            case eEnterPassword:
                 LeaveAllFunc();
                 EFunc=fEnterPassword;
                 EnterFunc();
                 EFunc=fShowPasswordTest;
                 StartMelody(mldyStartPassEnter,MaxVolume,eNone);
                 break;
            case ePasswordSubmit:
                 LeaveAllFunc();
                 if (LoadValueN(oPassword)==ValueEdit)
                 {
                   PlayExitSound=false;
                   StartMelody(mldyPassEnter,MaxVolume,eNone);
                   AONLocked=false;
                   break;
                 }
#define ResetPassword 1234
                 if (StartPassword&&ValueEdit==ResetPassword)
                 {
                   Event=eReset;
                   ValueData[0]=1;
                   ResetType=0;
                   continue;
                 }
                 if (RemoteAccess)
                 {
                   FKey=kfNone;
                   Event=eExitToMainTime;
                   continue;
                 }
                 Error=true;
                 break;
            case eReturnShowPass:
                 LeaveFunc();
                 Event=eEditCharBuff;
                 continue;

            case eSayCurrKey:
                 SayKey(phrSay0_B,WavData[0],eNone);
                 break;

            case eExitToMainTime:
                 StopRemoteAccessKey();
                 PlayExitSound=false;
                 CallEvent(eExitToMain);
                 AONLocked=true;
                 StartPassword=false;
                 EnterMain();
                 Timer1sA=LenWaitBeforeTestBeepToPipeDown;
                 Timer1sAEvent=eTestBeepToPipeDown;
                 break;

            case eEditTimeDate:
                 MinOption=mnEditTimeDate;
                 MaxOption=mxEditTimeDate;
                 Event=eEnterOption;
                 continue;

            case eSetDate:
                 SetClockDate(Day,Month,Year);
                 SaveValueN(oODay,Day);
                 GetClockTimeDate(clkwDate);
                 if (Option==oDay)
                   ValueEdit=Day;
                 break;
//                 Event=eNextOption;
//                 continue;

            case eHoursSet:
                 SetClockTime(Hours,-1,-1);
                 GetClockTimeDate(clkwTime);
                 break;
//                 Event=eNextOption;
//                 continue;

            case eMinutesSet:
                 SetClockTime(Hours,Minutes,0);
                 GetClockTimeDate(clkwTime);
                 StartMelody(mldySettedTime,MaxVolume,eNone);
                 break;
//                 Event=eNextOption;
//                 continue;

            case eEnterSetSecondsZeroMode:
                 LeaveAllFunc();
                 EFunc=fSetSecondsZero;
                 break;
            case eSetSecondsZero:
                 SetClockTime(-1,-1,0);
                 GetClockTimeDate(clkwTime);
                 StartMelody(mldySettedTime,MaxVolume,eNone);
                 break;

            case eContinueTestTime:
                 TestTime();
                 continue;
            case eStartTestTime:
                 MinOver=false;
                 AlarmTest=0;
                 TestTime();
                 continue;

            case eStartPlayAlarm:
                 StartMelody(LoadValueN(oPlayAlarm),ValueData[3],eSayTimeAlarm);
                 Timer4msA=TimeBeforeNextVolume;
                 Timer4msAEvent=eVolumeUp;
                 break;
            case eSayTimeAlarm:
                 GetClockTimeDate(clkwNowTime);
                 SayTime(phrTimeSay,NowHours,NowMinutes,eStartPlayAlarm);
                 Timer4msAEvent=eNone;
                 break;

            case eDecMinAlarm:
                 if (--ValueData[1]==0)
                 {
                   LeaveAllFunc();
                   break;
                 }
                 Timer1sA=60;
                 Timer1sAEvent=eDecMinAlarm;
                 DontView=true;
                 break;

           case eVolumeChange:
#define mldyChangeVolumeHi 31
#define mldyChangeVolumeLo 34
                SetVolume(volUp);
                SaveValueN(oVolume,Vol0);
                if (!DontPlaySounds&&!SndPlaying)
                {
                  if (Vol0)
                    Event=mldyChangeVolumeLo;
                  else
                    Event=mldyChangeVolumeHi;
                  StartMelody(Event,MaxVolume,eNone);
                }
                PlayExitSound=false;
                if (EFunc==fEditOption&&Option==oVolume)
                {
                  Event=eIncOption;
                  continue;
                }
                break;

           case eShowLogo:
                EFunc=fShowLogo;
              ValueData[0]=0;
              Timer4msA=LenWaitContinueShow;
              Timer4msAEvent=eContinueShowLogoA;
                LightLevel=0xFF;
                StartMelody(mldyLogo,MaxVolume,eNone);
                break;
           case eContinueShowLogoA:
                if (LightLevel!=MaxLightLevel)
                {
                  LightLevel++;
                  Timer4msA=LenWaitContinueShow;
                  Timer4msAEvent=eContinueShowLogoA;
                }
                else
                {
                  Timer1sA=LenWaitShowCurrLogo;
                  Timer1sAEvent=eContinueShowLogoB;
                }
                break;
           case eContinueShowLogoB:
                if (LightLevel!=0xFF)
                {
                  LightLevel--;
                  Timer4msA=LenWaitContinueShow;
                  Timer4msAEvent=eContinueShowLogoB;
                }
                else
                {
                  if (++ValueData[0]==MaxCharsLogo)
                  {
                    Event=eExitToMainTime;
                    continue;
                  }
                  Timer4msA=LenWaitBeforeShowNextLogo;
                  Timer4msAEvent=eContinueShowLogoA;
                }
                break;

           case eSet8Book:
                if (ValueEdit!=0)
                  ValueEdit=0;
                else
                {
                  ValueEdit=MaxValue;
                  if (Book==bBookIn||Book==bBookOut)
                    if ((ValueEdit=FindTodayCall(-1,Book,dBackward))==-1)
                      ValueEdit=MaxValue;
                }
                OptSelect=true;
                break;

           case eConfidenceOnOff:
                LeaveAllFunc();
                if (PipeUp)
                {
                  EFunc=fShowConfidence;
                  ConfidenceOn++;
                }
                break;
           case eTestConfidence:
                if (PipeUp)
                  Error|=!ParallelTest();
                break;
           case eTestBeepToPipeDown:
                if (PipeUp)
                {
                  Timer1sA=LenWaitBeforeTestBeepToPipeDown;
                  Timer1sAEvent=eTestBeepToPipeDown;
                  if (!Calling)
                  {
                    BeepTesting=true;
                    BeepEventMap=bmTestBeepToPipeDown;
                    BeepTimeDetect=LenTestBeepToPipeDown;
                    Timer1sAEvent=eNone;
                  }
                }
                break;
           case eTestPipeDownNow:
                if (Timer1sAEvent!=ePipeIsDown)
                  Timer1sA=LenWaitBeforePipeDownNow;
                Timer1sAEvent=ePipeIsDown;
                BeepTesting=true;
                BeepEventMap=bmTestBeepToPipeDown;
                BeepTimeDetect=LenTestBeepToPipeDown;
                break;

           case eEnterPowerDown:
                LightLevel=LightPowerDown;
                SetVolume(volLow);
                SetTimeOutPowerDown();
                break;
           case eLeavePowerDown:
                LightLevel=LoadValueN(oLightLevel);
                SetVolume(volHigh);
                ViewOff=false;
                break;
           case eTestPowerDown:
                if (LowBattery&&TestTimeOutPowerDown())
                {
                  ViewOff=true;
                  ShowPowerDown();
                }
                break;

           case eEnterFoundBook:
                LeaveAllFunc();
                SelNumberBook=GetNumberBackBook(NumberFound,BookFound);
                MinOption = MaxOption= BookToOpt[BookFound];
                TodaySee=true;
                CallEvent(eEnterOption);
                TestFuncChg();
                DisableLKey=true;
                break;

           case eEnterRemoteAccess:     //Event on found tone in incoming call
                if (RecivedNumeral!=tn0)
                  break;
                RemoteAccess=true;
                AONLocked=true;
                LeaveAllFunc();
                OldLine=0;
                ImpulseNumeral=0;
                Event=eRemoteAccessKey;
                continue;
           case eRemoteAccessKey:
                LineSoundOn();
                SetTimeOutExit();
                CallEvent(eContinueTestBeepRemoteAccess);
                if (AONLocked&&LoadValueN(oPassOn))
                {
                  Event=eEnterPassword;
                  continue;
                }
                ViewOff=false;
                if (RecivedNumeral==tnPriston)
                  SayPhrase(phrSExit,eSayVideoData);
                else
                  SayKey(phrSay0_B,RecivedNumeral,eSayVideoData);
                if (RecivedNumeral==tnPriston&&EFunc!=fRemoteAccessKey)
                  EventEndMelodyPlaying=eExitToMain;
#define LenWaitBeforeRAKeyUp 80;
                break;
           case eSayVideoData:
                FirstKey=true;
                LongKeyEvent=false;
                FKey=RecivedNumeral+kf0;
                CallEvent(eKeyPresent);
                if (EditingOptions)
                {
                  if (Option==oAlarmNumber)
                    RAVFunc=-1;
                  if (Option>=oShowSpecical&&Option<=oShowZK&&EFunc==fShowNumber)
                    RAVFunc=VFunc;
                }
                Timer4msA=LenWaitBeforeRAKeyUp;
                Timer4msAEvent=eKeyUpEmulation;
                break;
#define TimeRemoteAcessKey 60
           case eContinueTestBeepRemoteAccess:
                BeepTesting=true;
                BeepEventMap=bmRemoteAccessKey;
                BeepTimeDetect=TimeRemoteAcessKey;
                break;
           case eKeyUpEmulation:
                EndPressKey=true;
                break;

           case eShowVersionInfo:
                LeaveAllFunc();
                EFunc=fShowVersionInfo;
                ValueData[0]=-10;
//                Event=eMoveVersioInfo;
//                continue;
           case eMoveVersioInfo:
#define LenWaitBeforeMove 80
                ValueData[0]++;
                Timer4msA=LenWaitBeforeMove;
                Timer4msAEvent=eMoveVersioInfo;
                break;

           case eAutoDialCustomNumber:
                LeaveAllFunc();
                OptSelect=false;
                EFunc=fAutoDialCustom;
                LenEdit=2;
                TypeOfData=false;
//                ValueData[0]=ValueEdit=0;
                SelectedValue=0;
                CallEvent(eEditCharBuff);
                DisableLKey=true;
                break;
           case eSubmitCustomDialNumber:
                LoadNumber(ValueEdit,bBookZK);
                Event=eAutoDialKey;
                continue;

           case eDebugBeep:                             //Beep Debug
                EFunc=fDebugBeep;
#define LenDebugBeepWait 60
                Timer1sAEvent=eNone;
                BeepTesting=true;
                BeepTimeDetect=LenDebugBeepWait;
                BeepEventMap=bmDebugBeep;
#define LenUpdateWait 20
                Timer4msA=LenUpdateWait;
                Timer4msAEvent=eDebugBeep;
                break;
           case eEnterExtFunct:
                LeaveAllFunc();
                EFunc=fExtFunc;
                break;

         }
         Event=eNone;
         TestFuncChg();
         RetEvent();
       }
       while(Event!=eNone);
       RetEvent();
       TestFuncChg();
       if (PlayExitSound&&EFunc==fMain)
       {
         PlayExitSound=false;
         SayPhrase(phrSExit,eNone);
       }
       if (Error)
       {
         Error = false;
         DisableLKey=true;
         if (!DontPlaySounds)
           if (LoadValueN(oTypeKeyBeep)<tkbWav0)
             StartMelody(mldyError,MaxVolume,eNone);
           else
             SayPhrase(phrOOw,eNone);
       }
       if (RemoteAccess)
       {
         LineSoundOn();
         if (VFunc!=RAVFunc)
         {
           SayPhrase(SayVideoPhrase[VFunc],eNone);
           if (EFunc==fRemoteAccessKey)
             StartMelody(mldyEnterRemoteAccessKey,MaxVolume,eNone);
         }
         RAVFunc=VFunc;
       }
    }
    while(1);

}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void SetTimeOutPowerDown(void)
{
  if (LowBattery)
  {
    SaveValueN(oPowerDownTimeOut,LenWaitBeforePowerDown);
    ViewOff=false;
  }
}
bit TestTimeOutPowerDown(void)
{
  uchar t=LoadValueN(oPowerDownTimeOut);
  if (t!=0)
    SaveValueN(oPowerDownTimeOut,--t);
  return t==0;
}
uchar SetCallData(uchar NumeralCall)
{
 PipeOff();
 ToneCallA=ToneCall;
 CallSelect=true;
 switch(NumeralCall)
 {
  case numPause:
       BeepTesting=true;
       BeepTimeDetect=Pause4sWait;
       BeepEventMap=bmPause4sWait;
       return eNone;
  case numStarTone:
       ToneCallA=true;
       NumeralCall=10;
       break;
  case numWaitLongBeep:
       BeepTesting=true;
       BeepTimeDetect=BeepLongWaitTime;
       BeepEventMap=bmCallWaitVeryLongBeepMap;
       return eNone;
  case numPristonTone:
       ToneCallA=true;
       NumeralCall=11;
       break;
  case numShortBeepWait:
       BeepTesting=true;
       BeepTimeDetect=BeepShortTestWaitTime;
       BeepEventMap=bmCallTestShortBeepMap;
       return eNone;
  case numToneSet:
       ToneCall=true;
#define Pause1sWait 1
       BeepTesting=true;
       BeepTimeDetect=Pause1sWait;
       BeepEventMap=bmPause4sWait;
       return eNone;
//       return eNextNumeralCallN;
  case 0:
       LoopImpulseCall=10;
       break;
  default:
       LoopImpulseCall=NumeralCall;
 }
 TimerCallEvent=eStopCallSet;
 if (ToneCallA)
 {
   if (!BeeperCall)
     TimerCall=LenTone;
   BeepStart(NumeralCall+1);
 }
 else
 {
   if (CurrPipe)
   {
     PipeOff();
     TimerCall=PausePipeOff;
     TimerCallEvent=eStartImpulseSet;
   }
   else
     return eStartImpulseSet;
 }
 return eNone;
}

void TestFuncChg(void)
{
  if (OEFunc!=EFunc)
    EnterFunc();
  if ((OptSelect||SaveNumberNow)&&EditingOptions)
  {
    if (OOption!=0xFF)
    {
      EndOptionEdit(OOption);
    }
    TestEnableOpt();
//    if (Option!=OOption||OptChanged)
      SelectOption(Option);

    if (BookOpt)
    {
      EFunc=fShowNumber;
      EnterFunc();
      if (Book==bBookIn||Book==bBookOut)
      {
        OptSelect=(Day==DayCall+1&&Month==MonthCall+1);
        if (TodaySee!=OptSelect)
          StartMelody(mldyTodaySeeMldy,MaxVolume,eNone);
        TodaySee=OptSelect;
      }
    }
    OOption=Option;
    OptSelect=false;
    OptChanged=false;
  }
}

char InitMain(void)
{
     InitSystem();
     InitTimers();

     LightLevel=MaxLightLevel;
     NiceMigDown=MaxLight+1;

     if (TestROM())
       PrintError(errTestROM);
     InitClock();
     if (InitFlash())
       PrintError(errInitFlash);

     GetClockTimeDate(clkwTime);
     GetClockTimeDate(clkwDate);

     if (LoadValueN(oCheckReset)!=CheckResetData)
     {
       ResetBooks();
       ResetAllOptions(rstAuto);
//       if (TestFlash())
//         PrintError(errInitFlash);
     }

     SaveDefaultNumber();

     OEFunc=EFunc=fMain;
     FSP=0;
     EnterMain();


     StartLoadOpt();

     if (LoadValueN(oAONlock)!=aonlNone)
       AONLocked=StartPassword=true;

//     SetVolume(volHigh);

     Timer4msBEvent=Timer4msAEvent=Timer1sAEvent=eNone;

     if (LoadValueN(oShowLogo)!=true)
     {
       SaveValueN(oShowLogo,true);
       Timer1sAEvent=eShowLogo;
       TimeOut1sA=true;
     }
     LineDown();

     if (TestDayChange())
       Oper00_00();
     return(0);
}

//-----------------------------------------------------------
//IDLE MODE
char IdleMode_WaitForEvent(void)
{
 KvantDataS KvantData;

#ifdef DEBUG_KeyEmulation
 if (FirstKey)
 {
  FirstKey=false;
  EndPressKey=true;
  KeyPresent=false;
 }
 else
  if (KeyEmulData[PosEmulKey]!=kfLastKey)
  {
   FKey=KeyEmulData[PosEmulKey];
   Event=eKeyPresent;
   PosEmulKey++;
   FirstKey=true;
   return Event;
  }
  else
   while(1);
#endif
     StopSendFlash();
     if (BeepTesting&&!OldBeepTesting)
     {
       LenPeriod=BeepRepeat=0;
       TypeBeep=bpNoBeeps;
       PauseBeep=false;
     }

     Event=eNone;
     do
     {
       if (MelodyPlay)
       {
         if (EndTime_snd)
         {
           Event=eNextNotePlay;
           break;
         }
       }

       if (GetPipe==CurrPipe)
       {
         CurrPipe=!GetPipe;
         Event=ePipeChanged;
         break;
       }
       if (LinePresent!=OldLinePresent)
       {
         OldLinePresent=LinePresent;
         if (EFunc==fMain)
           Event=eUpdateView;
         if (EFunc==fCalling)
           Event=eIndification;
         if (LinePresent)
         {                                              //OnLinePresent
           StopRemoteAccessKey();
           StopToneTesting();
           ParallelNumber=false;
           Timer1sBEvent=eNone;
           if (EFunc==fParallelDetect)
             Event=eExitToMainTime;
           if (Saying)
             Event=eStopSayingData;
         }
         else
         {                                              //OnLineNotPresent
           if (EFunc==fPlayAlarm&&LoadValueN(oAlarmStopOnLineOff))
             Event=eExitToMainTime;
           StopToneTesting();
           if (!LineLoad)
             if ((ParallelDetect=(LoadValueN(oParalOpr))>0))
               ToneTesting=LoadValueN(oToneParalOpr);
           ToneNumeral=OldTN=tnNoNumeral;
           ToneStart=false;
         }
         break;
       }
       if (BackCall&&EFunc==fMain&&LinePresent)
       {
          BackCall=false;
          Event=eBCallStart;
          break;
       }

       if (KeyPresent)
       {
          if (RemoteAccess)
          {
            Event=eExitToMainTime;
            break;
          }
          FKey=ConvertKey();     //Convert NowKey to specformat
          if (!(!FirstKey&&DisableLKey))
          {
            DisableLKey=false;
            Event=eKeyPresent;     //Generate event eKeyPresent
            break;
          }
       }
       if (EndPressKey)
       {
          EndPressKey=false;
          EndPressKeyNow=true;
          LongKeyEvent=false;
          Event=eKeyPresent;
          break;
       }
       if (TimeOut4msA)
       {
        TimeOut4msA=false;
        Event=Timer4msAEvent;
        break;
       }
       if (TimeOut4msB)
       {
        TimeOut4msB=false;
        Event=Timer4msBEvent;
        break;
       }
       if (TimeOut1sA)
       {
        TimeOut1sA=false;
        Event=Timer1sAEvent;
        break;
       }

       if (SecondOut)                                           //SecondOut
       {
          SecondOut=false;
          if (Saying)
          {
            if (++SecSaying==60)
            {
              SecSaying=0;
              if (++MinSaying==60)
              {
                MinSaying=0;
                if (HourSaying!=9)
                  HourSaying++;
              }
            }
          }
          if (++Seconds==60)
          {
            Seconds=0;
            MinOver=true;
            Event=eMinOver;        //Generate event eMinOver
            break;
          }
          if (BeepTesting)
          {
            if (--BeepTimeDetect==0)
            {
              BeepTesting=false;
              Event=eBeepDetected;
              break;
            }
          }
          else
          {
            if (Timer1sB!=0)
            {
              if (--Timer1sB==0)
              {
                Event=Timer1sBEvent;
                break;
              }
            }
          }
          Event=eUpdateView;
          if (LowBattery&&!Calling&&EFunc!=fIndification&&EFunc!=fBeepEmulation)
            Event=eTestPowerDown;
          if (ConfidenceOn&&(Seconds%LenPeriodConfidence)==0)
            Event=eTestConfidence;
          break;
       }

       if (ToneTesting&&!Calling&&!SndPlaying&&!MelodyPlay)
       {
         if (EndWavPlay)
         {
           Event=eNextPlayWav;
           break;
         }
         KvantData=ToneDetect();
/*
     VideoBuffer[0][1]=ToneNumeral;
     VideoBuffer[1][1]=KvantData.ToneType;
     VideoBuffer[2][1]=OldTN;
     VideoBuffer[3][1]=ToneHighQualityDetect;
*/
         if (KvantData.ToneType!=OldTN)
         {
           ToneNumeral=KvantData.ToneType;                //if new tone detected
//           if (ToneNumeral!=tnNoNumeral)
           if (RemoteAccess&&ToneHighQualityDetect)
             EndReciveNumeral=true;
           ToneHighQualityDetect=false;
         }
         else
         {
           if ((ToneNumeral&0xF)!=tnNoNumeral)
           {
             if ((ToneNumeral&0xF0)==0x10)
             {
               if (!ToneStart&&ParallelDetect)
               {
                 if(!ParallelNumber)
                 {
                   ResetDefaultNumberBuff();
                   ParallelNumber=true;
                 }
                 Event=LoadDefaultNumber(dfnLenNumber);
                 if (ImpulseNumeral!=0||EndReciveNumeral)
                 {
                   EA=false;
                   if (!EndReciveNumeral)
                     RecivedNumeral=ImpulseNumeral;
                   ImpulseNumeral=0;
                   EA=true;
                   if (RecivedNumeral==10)
                     RecivedNumeral=0;
                   SetDefaultNumeralBuff(Event,RecivedNumeral);
                   if (Event!=MaxLenNumber)
                     Event++;
                 }
                 if (Event!=0)
                 {
                   SetDefaultNumeralBuff(Event,numToneSet);
                   if (Event!=MaxLenNumber)
                     Event++;
                   SetDefaultLenNumberBuff(Event);
                 }
                 Event=eNone;
                 ToneStart=true;
               }
               if (!RemoteAccess)
                 EndReciveNumeral=true;
               RecivedNumeral=ToneNumeral&0xF;
               ToneHighQualityDetect=true;
             }
             if ((ToneNumeral&0xF0)!=0x20)
               ToneNumeral+=0x10;
           }
         }
         OldTN=KvantData.ToneType;
       }
       else
         if (BeepTesting)
           KvantData.BeepFreq=BeepDetect();

       if (EndReciveNumeral)
       {
         EndReciveNumeral=false;
         if (!Calling)
         {
           if (ParallelDetect)
           {
             Event=eAddNumeralParallel;
             break;
           }
           if (RemoteAccess)
           {
             Event=eRemoteAccessKey;
             break;
           }
           if (TestEnterRemoteAccsess)
           {
             Event=eEnterRemoteAccess;
             break;
           }
         }
       }

       if (EndWavPlay)
       {
         Event=eNextPlayWav;
         break;
       }

       if (BeepTesting&&!(SoundToLine&&SndPlaying))
       {
          if (EFunc==fDebugBeep)
          {
            ValueData[0]=KvantData.BeepFreq;
            if (ValueData[1]<KvantData.BeepFreq)
              ValueData[1]=KvantData.BeepFreq;
            ValueData[4]=BeepRepeat;
          }
          if (Fmin<=KvantData.BeepFreq&&KvantData.BeepFreq<=Fmax
              &&AbsC(KvantData.BeepFreq-OldBeepFreq)<=DeltaBeep)
          {
            if (PauseBeep)
            {
              if (LenPeriod>=MinLenPeriod)
              {
                if (EFunc==fDebugBeep)
                {
                  ValueData[3]=LenPeriod;
                  ValueData[1]=0;
                }
                if (++BeepRepeat==NBeepDetect)
                {
                  TypeBeep=bpShort;                             //Short
                  BeepTesting=false;
                }
              }
              else
                BeepRepeat=0;
              LenPeriod=0;
              PauseBeep=false;
            }

            if (FastBeepTest)
            {
              TimerCallEvent=eNone;
              if (BeepTimeDetect<UpTimeBeepWait)
                BeepTimeDetect+=UpTimeBeepWait;
            }
            else
              if (LenPeriod>4)
                if (BeepTimeDetect<UpTimeBeepWait)
                  BeepTimeDetect+=UpTimeBeepWait;
            FastBeepTest=false;
            if (LenPeriod!=MaxLenBeep)
              LenPeriod++;
            else
            {
              TypeBeep=bpVeryLong;                              //Very long
              BeepTesting=false;
            }
            if (EFunc==fDebugBeep)
              ValueData[2]=LenPeriod;
          }
          else
          {
            PauseBeep=true;
            if (LenPeriod>=MinLenPeriod)
            {
              if (++LenPeriod==LenLongPeriod)
              {
                TypeBeep=bpLong;                                //Long
                BeepTesting=false;
              }
            }
          }
          OldBeepFreq=KvantData.BeepFreq;
          if (!BeepTesting)
          {
             Event=eBeepDetected;
             break;
          }
       }
/*    if (EFunc==fCalling)
    {
      VideoBuffer[0][1]=LBell;
      VideoBuffer[1][1]=LBellMin;
      VideoBuffer[2][1]=LBellMax;
      VideoBuffer[3][1]=RepeatLBell;
      VideoBuffer[4][1]=OldBell;
    }*/
       if (StartBell&&LinePresent)
       {
         StartBell=false;
         if (EFunc!=fAntiAON)
         {
           Event=eStartBell;
           break;
         }
       }
       if (EndBell)
       {
//         VideoBuffer[5][1]=false;
         EndBell=false;
         if (EFunc==fCalling)
         {
           Event=eEndBell;
           break;
         }
       }

       if (!SndPlaying&&!EndWavPlay&&!MelodyPlay&&(EFunc==fMain||EFunc==fSoundMode||EFunc==fSetSecondsZero))
       {
         if (ContiueAlarm)
         {
           Event=eContinueTestTime;
           break;
         }
         if (MinOver&&!Calling)
         {
           Event=eStartTestTime;
           break;
         }
       }
       if (LowBattery==LowBatteryData)
       {
         LowBattery=!LowBatteryData;
         if (LowBattery)
           Event=eEnterPowerDown;
         else
           Event=eLeavePowerDown;
         break;
       }

     }
     while(Event==eNone);
     OldBeepTesting=BeepTesting;
     return Event;
}
//-----------------------------------------------------------

void EnterFunc(void)                            //Enter
{
 DisableLKey=false;
 if (FSP<MaxFuncStack)
 {
  if (EFunc!=fMode&&EFunc!=fMain&&EFunc!=fShowNumber&&EFunc!=fExtFunc&&
      EFunc!=fStore&&EFunc!=fStoreCustom&&EFunc!=fEditCharBuff)
    StopSearch();
  FunctionCalls[FSP++]=OEFunc;
  SetTimeOutExit();
  KFunc=GetKeyMapOn(EFunc);
  VFunc=GetVideoDataOnEFunc();
  if (OEFunc==fMain)
  {
    SaveDefaultNumber();
  }
  switch(EFunc)
  {
   case fMode:
//        ValueData[0]=vsMode;
        LoadDefaultNumber(dfnNumber);
        break;
//   case fMain:
//        LoadDefaultNumber(dfnNumber);
//        break;
   case fMainEditNumberPipeDown:
        TestStartAutoSearch();
        TestStartAutoDial();
   case fMainEditNumberPipeUp:
   case fShowMainNumber:
        break;
   case fAutoDial:
        AutoDial=EditCallBuff=true;
        CallSelect=false;
        OffsetNumberView=0;
        ViewOff=false;
        break;
   case fShowNumber:
        if (LenNumber>7)
        {
         OffsetNumberView=-MaxNumeralView+1;
         TimeOutViewRolNuber=DefaultTimeOutViewRolNuber;
         Timer4msAEvent=eRolNumber;
        }
        else
        {
         OffsetNumberView=0;
         Timer4msAEvent=eNone;
        }
        break;
   case fEditOption:
        OOption=-1;
        SaveNumberNow=false;
        EditingOptions=true;
        break;
   case fCalling:
        ToneTesting=ParallelDetect=false;
        ValueData[0]=0;
        NCall=LoadValueN(oWaitCalls);
        NRequest=LoadValueN(oRequests);
        FormRequest=LoadValueN(oFormRequest);
        LenRequest=Convert10msTo4ms(LoadValueN(oLenRequest));
        PauseRequest0=LoadValueN(oPauseRequest0);
        PauseRequest=LoadValueN(oPauseRequest);
        ListenAnswer=LoadValueN(oAnswerListen);
        AONMode=LoadValueN(oAONMode);
//        ListenSoundOnSpeaker=&!Night;
        if (AONMode==modeUserUp||AONMode==modeNoIndification)
          NCall=-1;
        if (AONMode>=modeFullReaddress&&AONMode<=modePagerReaddress)
          ListenAnswer=false;
        break;
   case fIndification:
        ToneTesting=ParallelDetect=false;
        StopPlay();
        EditCallBuff=EditingBuff=false;
        ValueData[0]=0;
        stack_malloc(GetAnswerSizeBuff);
        if (LinePresent)
          LineUp();
        DontPlaySounds=true;
        break;
   case fEditNumber:
        EditCallBuff=EditingBuff=false;
        OffsetNumberView=0;
        break;
   case fShowKateg:
   case fShowTimeCall:
   case fShowTimeSay:
   case fShowDateCall:
        if (RemoteAccess)
        {
          RAVFunc=-1;
          break;
        }
        Timer4msAEvent=eReturn;
        Timer4msA=DefaultTimeShow;
        TimeOut4msA=false;
        break;
   case fShowAllTimeSay:
        ValueData[0]=1;
        SelectedValue=-1;
        GetDataShowAllTimeSay();
        break;
   case fShowCallsPerTime:
        (*(uint *) &ValueData[0])=LoadValueN(oCallsPerAllTime);
        ValueData[2]=LoadValueN(oTodayCalls);
        SelectedValue=-1;
        break;
   case fBeepEmulation:
        ListenLine=(NBeepPlaying=LoadValueN(oAutoUpListen))>0;
        ListenLine&=!Night;
        if (NBeepPlaying==2)
          ListenLine=true;
        RepeatSayNumber=LoadValueN(oRepNumberSay);
        NBeepPlaying=0;
        DontPlaySounds=true;
        OffsetNumberView=0;
        break;
   case fShowTimeSayingNow:
        Timer1sA=3;
        Timer1sAEvent=eExitToMain;
        break;

   case fBackCall:
        LoopRedial=LoadValueN(oACallLoops);
        LoopBCallRepeats=RepeatLoopBCallSay;
        break;
   case fSoundMode:
        SoundOn();
        Timer1sA=LenWaitBeforeTestBeepToPipeDown;
        Timer1sAEvent=eTestBeepToPipeDown;
        break;
   case fLockNumber:
        StopCall();
        Timer1sBEvent=eNone;
        Timer4msAEvent=eNone;
        Timer1sA=LenTimeBeforeUnLockLine;
        Timer1sAEvent=eTestLineFree;
        LineUp();
        PosCall=0;
        break;
   case fSearch:
        ShowSearch=true;
        break;
   case fShowNotFound:
#define TimeShowNotFound 100
        Timer4msA=TimeShowNotFound;
        Timer4msAEvent=eReturn;
        TimeOut4msA=false;
        Error=true;
        break;
   case fAntiAON:
#define LenDefaultTimeAntiAON 3
        Timer1sA=LenDefaultTimeAntiAON;
        Timer1sAEvent=eExitToMain;
        PipeOnOff();
        LineDown();
        break;
   case fEditCharBuff:
        PosEdit=0;
        EditModeValue=true;
//        KFunc=GetKeyEditOnTypeEdit();
//        EditBuff[0]=EditBuff[1]=0;
        ValueEdit=0;
        break;
   case fShowLabelFilterStatus:
        Timer1sA=LenDefaultTimeShowFilter;
        Timer1sAEvent=eReturn;
        break;
   case fStore:
        LenEdit=1;
        ValueData[0]=9;
        ValueEdit=bBookZK;
        SelectedValue=0;
        break;
   case fStoreCustom:
        LenEdit=2;
        TypeOfData=false;
//        ValueData[0]=ValueEdit=0;
        SelectedValue=0;
        break;
   case fEnterPassword:
        AONLocked=false;
        LenEdit=4;
        TypeOfData=false;
        PassEnter=true;
        SelectedValue=0;
        break;
   case fShowPasswordTest:
        Timer1sA=LenDefaultTimeShowPassTest;
        Timer1sAEvent=eReturnShowPass;
        break;
   case fPlayAlarm:
        ValueData[0]=NumberOfAlarm;
        Timer1sA=60;
        Timer1sAEvent=eDecMinAlarm;
        if (LoadValueN(oVolumeAlarm))
          ValueData[3]=0;
        else
          ValueData[3]=MaxVolume;
#define ShortLenPlay 2
#define LongLenPlay  30
        if (LoadValueN(oLenPlayAlarm))
          ValueData[1]=LongLenPlay;
        else
          ValueData[1]=ShortLenPlay;
        break;
   case fAlarmDial:
        LoadValueN(oAlarmNumberCall);
        LoopRedial=LoadValueN(oACallLoops);
#define RepeatLoopAlarmSay RepeatLoopBCallSay
        LoopBCallRepeats=RepeatLoopAlarmSay;
        EndCallEvent=eBCallStartTest;
        if (LoadValueN(oAutoDialSndOnAlarm))
          EndCallEvent=eBeepTestCall;
        break;
   case fSetSecondsZero:
#define LenTimeModeSetSecondsZero 60*3
        Timer1sA=LenTimeModeSetSecondsZero;
        break;
   case fParallelDetect:
        ListenLine=(NBeepPlaying=LoadValueN(oParalListen))>0;
        ListenLine&=!Night;
        if (NBeepPlaying==2)
          ListenLine=true;
        if (ListenLine)
          SoundOn();
        break;
   case fHold:
        SetSpeakerOff();
        PipeOff();
        LineUp();
        PipeUp=false;
        SpeakerOn=false;
        DontPlaySounds=true;
        break;
   case fShowConfidence:
        ValueData[0]=ConfidenceOn;
        SelectedValue=0;
#define LenTimeShowConfidence 2
        Timer1sA=LenTimeShowConfidence;
        Timer1sAEvent=eExitToMain;
        break;
   case fRoomListen:
        SetSpeakerOnA();
        EFunc=fMain;
        VFunc=GetVideoDataOnEFunc();
        EFunc=fRoomListen;
        GetMainModeVFuncData();
        Timer1sAEvent=eNone;
        break;
   case fFlash:
        HangUp=true;
        LineDown();
        break;
   case fDebugBeep:
        ValueData[0]=ValueData[1]=ValueData[2]=ValueData[3]=0;
        break;
  }
  OEFunc=EFunc;
 }
}

void LeaveFunc(void)                            //Leave
{
 ViewOff=false;
 if (FSP>0)
 {
  SetTimeOutExit();
//Functions on leave function
  switch(EFunc)
  {
   case fEditOption:
        if (mnEditLock<=Option&&Option<=mxEditLock)
        {
          AONLocked=true;
          StartPassword=false;
        }
        OOption=SelectedValue=-1;
        EditingOptions=false;
        EndOptionEdit(Option);
        Option=-1;
        StartLoadOpt();
        StopPlay();
        break;
   case fMainEditNumberPipeUp:
        EditingBuff=false;
        break;
   case fMainEditNumberPipeDown:
        EditingBuff=false;
        SaveDefaultNumber();
        break;
   case fShowNumber:
        Timer4msAEvent=eNone;
        OffsetNumberView=0;
//        if ((OffsetNumberView=LenNumber-MaxNumeralView)&0x80)
//          OffsetNumberView=0;
        break;
   case fAutoDial:
        AutoDial=false;
        StopCall();
        Timer4msAEvent=eNone;
        Calling=false;
        if (PipeUp)
        {
          LineUp();
          CallEnable=true;
          if (SpeakerOn)
            SetSpeakerOn();
          else
            PipeOn();
          EditCallBuff=true;
          PosCall=LoadDefaultNumber(dfnLenNumber);
          for (OEFunc=0;OEFunc<PosCall;OEFunc++)
            if (GetNumeralDefaultBuff(OEFunc)==numToneSet)
              ToneCall=true;
          if (!EndAutoDialed)
          {
            EditCallBuff=false;
            PosCall=0;
            BeeperCall=false;
            ToneCall=LoadValueN(oTypeLineCall);
          }
          SaveDefaultNumber();
        }
        break;
   case fCalling:
        StopPlay();
//        StopTimer4msA();
        break;
   case fIndification:
        StopImpulse();
        SoundOff();
        StopPlay();
        LineSoundOff();
        if (PipeUp)
        {
          LineUp();
          //PrepareToCall
          EditCallBuff=false;
          PosCall=0;
          BeeperCall=false;
          ToneCall=LoadValueN(oTypeLineCall);
          if (SpeakerOn)
            SetSpeakerOn();
          else
            PipeOn();
        }
        else
          LineDown();
        stack_mfreelast(GetAnswerSizeBuff);
        StopTimer4msA();
        DontPlaySounds=false;
        break;
   case fEditNumber:
//        if (EditingBuff)
//          SaveNumberNow = true;
        EditingBuff=false;
        break;
   case fShowKateg:
   case fShowTimeCall:
   case fShowTimeSay:
   case fShowDateCall:
   case fShowCallsPerTime:
   case fShowAllTimeSay:
        Timer4msAEvent=eNone;
        OptSelect=true;
        break;
   case fBeepEmulation:
        if (!PipeUp)
          LineDown();
        LineSoundStop();
        SoundOff();
        StopPlay();
        StopBeepTesting();
        DontPlaySounds=false;
        EventEndWavPlaying=eNone;
        StopToneTesting();
        if (!Saying)
          SaveValue(oNewNotSayCalls,true);
        break;
   case fTimeOutReset:
        StopTimer4msA();
        break;
   case fBackCall:
        StopBeepTesting();
        LineSoundOff();
        LineDown();
        break;
   case fSoundMode:
        SoundOff();
        break;
   case fLockNumber:
        LineDown();
        break;
   case fHold:
        StopPlay();
        if (CurrPipe)
        {
          PipeUp=true;
          SpeakerOn=false;
          PipeOn();
        }
        if (PipeUp)
          LineUp();
        else
          LineDown();
//        if (PipeUp)
//          if (SpeakerOn)
//            PipeOn();
//          else
//            SetSpeakerOn();
        LineSoundOff();
//        Timer1sAEvent=eNone;
        StopBeepTesting();
        DontPlaySounds=false;
        break;
   case fLineGet:
        if (!PipeUp)
          LineDown();
        break;
   case fShowNotFound:
        StopTimer4msA();
        break;
   case fAntiAON:
        TimerCall=0;
        TimerCallEvent=eNone;
        StopImpulse();
        if (PipeUp)
          LineUp();
        break;
   case fStoreCustom:
        EditModeValue=false;
        break;
   case fEnterPassword:
        AONLocked=true;
        PassEnter=false;
        break;
   case fPlayAlarm:
        StopPlay();
        Timer1sAEvent=Timer4msAEvent=eNone;
        break;
   case fAlarmDial:
        StopBeepTesting();
        LineSoundOff();
        LineDown();
        break;
   case fShowLogo:
        StartLoadOpt();
        StopPlay();
        break;
   case fParallelDetect:
        SoundOff();
        break;
   case fRoomListen:
        SetSpeakerOff();
        break;
   case fFlash:
        HangUp=false;
        break;
   case fAutoDialCustom:
        EditModeValue=false;
        break;
   case fDebugBeep:
        StopBeepTesting();
        StopTimer4msA();
        break;
  }
  OEFunc=EFunc;
  EFunc=FunctionCalls[--FSP];
  VFunc=GetVideoDataOnEFunc();
  KFunc=GetKeyMapOn(EFunc);
//Functions on return to function
  switch (EFunc)
  {
    case fEditOption:
         if (OEFunc==fEditCharBuff)             //some izvrat ;))))
           EndOptionEdit(Option);
         SelectOption(Option);
         if (OEFunc==fStore||OEFunc==fStoreCustom)
           OptSelect=true;
         break;
    case fMainEditNumberPipeDown:
         TestStartAutoDial();
         if ((OffsetNumberView=LenNumber-MaxNumeralView)&0x80)
           OffsetNumberView=0;
         break;
  }
  OEFunc=EFunc;
 }
 if (FSP==0)
   EnterMain();
}

void EnterMain(void)
{
     if (RemoteAccess)
     {
       EFunc=fRemoteAccessKey;
       EnterFunc();
       FSP=0;
      LineUp();
      ToneTesting=true;
      BeepTesting=true;
      BeepEventMap=bmRemoteAccessKey;
      BeepTimeDetect=TimeRemoteAcessKey;
      LineSoundOn();

      Timer4msAEvent=eNone;
       return;
     }
     LoadDefaultNumber(dfnNumber);
     EFunc=fMain;
     EnterFunc();
     FSP=0;
     GetMainModeVFuncData();
     DisableLKey=true;
     Timer4msAEvent=eNone;
#define LenWaitBeforeLock 30
     Timer1sA=LenWaitBeforeTestBeepToPipeDown;
     Timer1sAEvent=eTestBeepToPipeDown;
     if (!AONLocked&&LoadValueN(oAONlock)!=aonlNone)
     {
       Timer1sA=LenWaitBeforeLock;
       Timer1sAEvent=eExitToMainTime;
     }
}

void LeaveAllFunc(void)
{
  while(FSP>0)
    LeaveFunc();
}

void EndOptionEdit(uchar SelOption)
{
 if (!EditModeValue)
 {
   Error|=!SaveValue(SelOption,ValueEdit);
   if (OptChanged&&(SelOption<oShowSpecical||SelOption>oShowZK))
     StartLoadOpt();
 }
 EditModeValue=false;
}

void SelectOption(uchar SelOption)
{
  VFunc=GetVideoDataOnOption(SelOption);
  ValueEdit=LoadValue(SelOption);
  TestSpecOpt(SelOption);
  if (OOption==oLightLevel||Option==oLightLevel)
    StartLoadOpt();
//  if (BookOpt)
//    SelectedValue=-1;
}

void SetTimeOutExit(void)
{
  Timer1sAEvent=eExitToMainTime;
  Timer1sA=TimeOutExitMain;
  TimeOut1sA=false;
}

void StopCall(void)
{
  TimerCallEvent=Timer1sAEvent=eNone;
  StopImpulse();
  if (DontPlaySounds)
    BeepStop();
  CallSelect=false;
  SoundOff();
  StopBeepTesting();
  LineDown();
}

void StopBeepTesting(void)
{
  FastBeepTest=false;
  OldBeepTesting=BeepTesting=false;
  Timer1sB=0;
}

void SayPhrase(uchar nphrase,uchar EndEvent)
{
//  SayTime(nphrase,0,0,EndEvent);
//  CurrentValueSaying=0;
  PosNumberSX=0;
  PosWavs=0;
  EventEndWavPlaying=EndEvent;
  NPhrase=nphrase;
  GetNextPlay();
}
void SayKey(uchar nphrase,uchar keysay,uchar EndEvent)
{
  SayTime(nphrase,keysay,0,EndEvent);
}
void SayTime(uchar nphrase,uchar Hours,uchar Minutes,uchar EndEvent)
{
  PosWavs=0;
  WavData[0]=Hours;
  WavData[1]=Minutes;
  EventEndWavPlaying=EndEvent;
  NPhrase=nphrase;
  GetNextPlay();
}

void SayNumber(uchar nphrase,uchar EndEvent)
{
//  PosWavs=0x3;
  PosWavs=0;
  EventEndWavPlaying=EndEvent;
  NPhrase=nphrase;
  PosNumberSX=0;
  GetNextPlay();
}

bit GetNextPlay(void)
{
  uchar TypeOfDataWav,tmp;
  bit type1a2a;
AgainGetNextPlay:
  type1a2a=false;
  switch(TypeOfDataWav=TablePhrase[NPhrase][PosWavs>>4])
  {
    case tsSayM:
         StartPlayWav(GetTypeSayingMH(WavData[((PosWavs>>2)&0x3)-1])+tsM0);
         PosWavs+=1<<4;
         break;
    case tsSayH:
         StartPlayWav(GetTypeSayingMH(WavData[(PosWavs>>2)&0x3-1])+tsH0);
         PosWavs+=1<<4;
         break;
    case tsSayInt:
         break;
    case tsSayMinutes:
         type1a2a=true;
         if (WavData[(PosWavs>>2)&0x3]==0)
         {
           PosWavs+=2<<4;
//           goto AgainGetNextPlay;
           StartPlayWav(tsExactly);
           break;
         }
    case tsSayChar:
         StartPlayWav(SayInt(WavData[(PosWavs>>2)&0x3],type1a2a));
         if ((PosWavs&0x3)==3)
         {
           PosWavs&=0xFC;
           PosWavs+=1<<4;
           PosWavs+=1<<2;
           PauseAfterSayWav=true;
         }
         break;
    case tsSayNumberStart:
         PosWavs&=0xF0;
         PosWavs+=1<<4;
         PosWavs|=0x3;
         PosNumberSX=0;
    case tsSayNumber:
         if ((PosWavs&0x3)==3)
         {
           if (LenNumber==0)
           {
             PosWavs+=1<<4;
             goto AgainGetNextPlay;
           }
           if (PosNumberSX==0)
           {
             bit UndefinedNumber;
             UndefinedNumber=true;
             for(TypeOfDataWav=0;TypeOfDataWav<LenNumber;TypeOfDataWav++)
               if (GetNumberBuff(TypeOfDataWav)<=num9)
                 UndefinedNumber=false;
             if (UndefinedNumber)
             {
               PosNumberSX=LenNumber;
               StartPlayWav(tsUndefined);
               PauseAfterSayWav=true;
               break;
             }
           }
           if (PosNumberSX==LenNumber)
           {
             PosWavs+=1<<4;
             goto AgainGetNextPlay;
           }
           WavDataW=GetSayNumberWord();
           PosWavs&=0xFC;
         }
         StartPlayWav(SayInt(WavDataW|0x8000,0));
         if ((PosWavs&0x3)==3)
           PauseAfterSayWav=true;
         break;
    case tsEndPhrase:
         return true;
    case tsSetPause:
         SetTimer1msA(TablePhrase[NPhrase][(PosWavs>>4)+1]*LenMinPauseWav);
         PosWavs+=2<<4;
         return false;
    case tsSayKey:
         TypeOfDataWav=tsv0+WavData[PosWavs&0x3];
         if (TypeOfDataWav>tsv9)
           TypeOfDataWav=tsMNS;
         StartPlayWav(TypeOfDataWav);
         PosWavs+=1<<4;
         break;

    case tsSetWavData1cv:
    case tsSetWavData0cv:
         tmp=0;
         if (TypeOfDataWav==tsSetWavData1cv)
           tmp++;
         WavData[tmp]=ValueData[CurrentValueSaying];
         PosWavs&=0xF0;
         PosWavs+=1<<4;
         CurrentValueSaying++;
         goto AgainGetNextPlay;
    case tsIncCV:
         CurrentValueSaying++;
         goto AgainGetNextPlay;
    case tsSetWavData1MemI:
    case tsSetWavData0MemI:
         tmp=0;
         if (TypeOfDataWav==tsSetWavData1MemI)
           tmp++;
         TypeOfDataWav=(PosWavs>>4)+1;
         WavData[tmp]=(*(uchar *)TablePhrase[NPhrase][TypeOfDataWav])+TablePhrase[NPhrase][TypeOfDataWav+1];
         PosWavs&=0xF0;
         PosWavs+=3<<4;
         goto AgainGetNextPlay;

#define MaxSoundSamples 64
    case tsTestSample:
         if (++CurrentValueSaying==MaxSoundSamples)
         {
           PosWavs+=1<<4;
           goto AgainGetNextPlay;
         }
         StartPlayWav(CurrentValueSaying);
         PauseAfterSayWav=true;
         break;

    default:
         StartPlayWav(TypeOfDataWav);
         PosWavs+=1<<4;
         PauseAfterSayWav=true;
  }
  return false;
}

uchar SayInt(uint Value,bit typevoice12)
{
  uchar i,SaySoundN;
  if (!(Value&0x8000))
    Value=HexToDecData(Value);
  Value&=0x7fff;
  switch (PosWavs&0x3)
  {
    case 0:
         if (Value&0xF00)
         {
           SaySoundN=(Value>>8)+tsv100-1;
           break;
         }
    case 1:
         if (Value&0x0F0)
         {
           SaySoundN=((Value>>4)&0x00F)+tsv20-2;
           if ((Value&0x0F0)==0x010)
           {
             SaySoundN=(Value&0x00F)+tsv10;
             PosWavs|=3;
             return SaySoundN;
           }
           break;
         }
    case 2:
         if (Value&0x00F)
         {
           SaySoundN=(Value&0x00F)+tsv0;
           if ((Value&0x00F)>9)
             SaySoundN=tsMNS;
           if (typevoice12)
             if (SaySoundN==tsv1||SaySoundN==tsv2)
               SaySoundN+=-tsv1+tsv1a;
           break;
         }
         else
         {
           if (Value==0)
           {
             SaySoundN=tsv0;
             PosWavs|=3;
             return SaySoundN;
           }
         }
  }

  for(i=PosWavs&0x3;i<3;i++)
  {
    if (i==0&&(Value&0xF00)&&(Value&0x0F0))
      break;
    if (((Value<<(4*i))&0xF00)==0)
      PosWavs++;
  }
  PosWavs++;
  return SaySoundN;
}

code const uchar TableTypesSaying[]={tsMH0,tsMH1,tsMH2,tsMH2,tsMH2,tsMH0,tsMH0,tsMH0,tsMH0,tsMH0};
uchar GetTypeSayingMH(uchar Value)
{
  if (Value>9&&Value<20)
    return(tsMH0);
  return(TableTypesSaying[HexToDecData(Value)&0xF]);
}

int GetSayNumberWord(void)
{
  int SetC=0;
  uchar LenAdd=2,i,
        StartPos=((PosNumberSX+(LenNumber&1))&0xFE)-(LenNumber&1),
        N=GetNumberBuff(0);

  if (StartPos&0x80)
    StartPos=0;
  if (PosNumberSX==0)
    if (LenNumber&1)
      LenAdd=1;

  if (LenNumber>7)
  {
     LenAdd=1;
     StartPos=PosNumberSX;
  }

  if (LenNumber==7)
    if (PosNumberSX==0&&N!=0&&N<10)      // only if N=1..9
      LenAdd=3;

  if ((N=GetNumberBuff(StartPos))==0)
  {
    PosNumberSX++;
    return GetNumberBuff(PosNumberSX-1);
  }

  for (i=PosNumberSX-StartPos;i<LenAdd;i++)
  {
    if ((N=GetNumberBuff(StartPos+i))>9)
    {
      PosNumberSX++;
      return GetNumberBuff(PosNumberSX-1);
    }
    SetC=SetC<<4|N;
  }

  PosNumberSX+=LenAdd-(PosNumberSX-StartPos);
  return SetC;
}

void PrepareSayingData(void)
{
  LoadDefaultNumber(dfnNumber);
  HourCall=Hours;
  MinCall=Minutes;
  DayCall=Day-1;
  MonthCall=Month-1;
  DayOfWeekCall=DayOfWeek;
  MinSay=HourSay=MinSaying=HourSaying=SecSaying=0;
  SaveDefaultNumberA();
}

void StopTimer1sA(void)
{
  Timer1sAEvent=eNone;
}
void StopTimer4msA(void)
{
  Timer4msAEvent=eNone;
}

bit TestLock(bit locktype)
{
  if (LockCallAll||locktype==lParallel)
  {
    if (LockAllNumbers)
      return true;
//      LockNumbers=false;
    if (LockNumbers)
    {
      bit Found;
      XchgNumbBuffers();
      Found=SearchNumber(nbLockNumbers,nbLenLockNumbers,bBookSpecical,tcbSkipBigger9)!=-1;
      XchgNumbBuffers();
      if (Found)
        return true;
    }

//  return false;
    if (LockCountryCode)
    {
      char ln=LoadDefaultNumber(dfnLenNumber),pos,
           lockbyte=LoadValueN(oCountryCode);
      for (pos=0;pos<ln;pos++)
      {
        char CurrByte=GetNumeralDefaultBuff(pos);
        if (CurrByte<10)
        {
          if (CurrByte==lockbyte)
            return true;
          else
            return false;
        }
      }
    }
  }
  return false;
}

void StartMelody(uchar melody,uchar volume,uchar event)
{
  EventEndMelodyPlaying=event;
  StartMelodyA(melody,volume);
}

void ResetArams(void)
{
  for(NumberOfAlarm=0;NumberOfAlarm<MaxAlarms;NumberOfAlarm++)
  {
     ResetOptions(oHoursAlarm,oDaysAlarm);
     DeleteNumber(nbStartAlarm+NumberOfAlarm,bBookSpecical);
  }
}

void StopSearch(void)
{
    if (ShowSearch)
    {
      ShowSearch=false;
      LenNumber=LenShowA;
      SaveDefaultNumber();
    }
}

void TestStartAutoSearch(void)
{
  if (EditingBuff)
  {
    if (EFunc==fMainEditNumberPipeDown&&
        LoadValueN(oAutoSearch))
    {
      Timer1sA=LenWaitBeforeAutoSearch;
      Timer1sAEvent=eEnterSearch;
    }
  }
}

void TestStartAutoDial(void)
{
  if (EditingBuff)
  {
    if (EFunc==fMainEditNumberPipeDown&&
        LoadValueN(oAutoACall)&&
        LoadValueN(oATSLenNumber)==LenNumber)
    {
      Timer1sA=LenTimeWaitBeforeAutoStartAutoDial;
      Timer1sAEvent=eAutoDialKey;
    }
  }
}

bit TestLockLevel1(void)
{
  return AONLocked&&LoadValueN(oPassOn)&&LoadValueN(oAONlock)==aonlMainModes;
}

void ClearUndefinedNumbers(void)
{
  uint UndefinedNumber=0;
  if (LoadValueN(oUnknownOper)==undef12HSClear)
    while((UndefinedNumber=SearchNumber(UndefinedNumber,-1,bBookIn,tcbUndefinedSearch))!=-1)
      DeleteNumber(GetNumberBackBook(UndefinedNumber,bBookIn),bBookIn);

}

void SetClockTime(uchar hours,uchar minutes,uchar seconds)
{
  uchar SendData[3];
  SendData[0]=hours;
  SendData[1]=minutes;
  SendData[2]=seconds;
  PICwork(clcmdSetTime,&SendData[0]);
}

void SetClockDate(uchar day,uchar month,uchar year)
{
  uchar SendData[3];
  SendData[0]=day-1;
  SendData[1]=month-1;
  SendData[2]=year;
  PICwork(clcmdSetDate,&SendData[0]);
}

void GetClockTimeDate(uchar ClockOper)
{
  uchar GetData[4];
  switch (ClockOper)
  {
    case clkwTime:
         PICwork(clcmdGetTime,&GetData[0]);
         Hours=GetData[0];
         Minutes=GetData[1];
         Seconds=GetData[2];
         SecondOut=false;
         MinOver=false;
         break;
    case clkwDate:
         PICwork(clcmdGetDate,&GetData[0]);
         Day=GetData[0]+1;
         Month=GetData[1]+1;
         Year=GetData[2];
         DayOfWeek=GetData[3];
         break;
    case clkwNowTime:
         do
         {
           PICwork(clcmdGetTime,&GetData[0]);
           t2ms=false;
           Devider250=0;
           NowHours=GetData[0];
           NowMinutes=GetData[1];
           Seconds=GetData[2];
         }
         while (Seconds==59);
         SecondOut=false;
         MinOver=false;
         break;
  }
}

bit TestAlarm(uchar alarm)
{
  NumberOfAlarm=alarm;
  if (LoadValueN(oMinutesAlarm)==Minutes)
    if (LoadValueN(oHoursAlarm)==Hours)
      if ((LoadValueN(oDaysAlarm)>>DayOfWeek)&1)
        return true;
  return false;
}

#define MaxAllAlarms 10
void TestTime(void)
{
  GetClockTimeDate(clkwNowTime);
  ContiueAlarm=true;
  Event=eNone;
  while(Minutes!=NowMinutes||AlarmTest!=0||Hours!=NowHours)
  {
    if (AlarmTest--==0)
    {
      AlarmTest=MaxAllAlarms;
      if (Minutes!=NowMinutes||Hours!=NowHours)
      {
        if (++Minutes==60)
        {
          Minutes=0;
          if (++Hours==24)
            Hours=0;
        }
        StartLoadOpt();                         //!!! TOO SLOW
      }
    }
//    Event=eNone;
    if (AlarmTest==MaxAllAlarms)
    {
      if (Minutes==0)
      {
        if (Hours==0)
        {
          GetClockTimeDate(clkwDate);          //Get Date
          Oper00_00();
        }
        if (Hours==3)
          TestDayChange();
        if (!Night)
          if (PlayClock())
            return;
        break;
      }
    }

    if (AlarmTest<MaxAlarms) //AlarmTest
    {
      if (TestAlarm(AlarmTest))
      {
        ContiueAlarm=true;
//          AlarmOn
        switch(LoadValueN(oTypeAlarm))
        {
          case atNone:
               break;
          case atCustomDays:
               SaveValueN(oTypeAlarm,atNone);
          case atAllDays:
               LoadValueN(oAlarmNumberCall);
               EFunc=fPlayAlarm;
               Event=eStartPlayAlarm;
               return;
          case atACall:
               EFunc=fAlarmDial;
               Event=eAutoDial;
               return;
          case atSetMode:
               SaveValueN(oAONMode,LoadValueN(oPlayAlarm));
               if (LoadValueN(oRepPModeAlarm))
                 SaveValueN(oTypeAlarm,atNone);
               break;
          case atWhiteChg:
               SaveValueN(oFilter,(LoadValueN(oFilter)&~fltrWhite)|(LoadValueN(oSetLabel)<<xfltrWhite));
               break;
          case atBlackChg:
               SaveValueN(oFilter,(LoadValueN(oFilter)&~fltrBlack)|(LoadValueN(oSetLabel)<<xfltrBlack));
               break;
          case atBlackLockChg:
               SaveValueN(oFilter,(LoadValueN(oFilter)&~fltrBlackLock)|(LoadValueN(oSetLabel)<<xfltrBlackLock));
               break;
        }
      }
    }
  }
  ContiueAlarm=false;
  MinOver=false;
}

bit TestSaveInUdefined(void)
{
  uchar i;
  if (LoadValueN(oUnknownOper)>0)
    return true;
  for (i=0;i<LenNumber;i++)
    if (GetNumberBuff(i)<=num9)
      return true;
  return false;
}

void ResetAllOptions(uchar ResetType)
{
  ResetOptions(oACallLoopBeforeTimeOut,oCountryBeepWait);
  ResetOptions(oNightOn,oEveryNumeralBeepTest);
  if (ResetType==rstAuto)
  {
    ResetOptions(oFminCall,oFmaxCall);
    ResetOptions(oAllHourSay,oAllMinSay);
    ResetOptions(oCallsPerAllTime,oTodayCalls);
  }
  ResetOptions(oKvantPipeUp,oFlashPause);
  ResetOptions(oAONMode,oLockCode);

  ResetOptions(oUpTimeReaddress,oShowLogo);
//  ResetOptions(oHours,oYear);
//  SetClockTime(Hours,Minutes,Seconds);
//  SetClockDate(Day,Month,Year);
  SaveValueN(oODay,Day);

  ResetArams();
}

void BellPlay(void)
{
  StartMelody(mldyBell+LoadValueN(oBellTone),MaxVolume,eNone);
}

void SetVolume(uchar volume)
{
  if (volume==volUp)
    Vol0++;
  else
    Vol0=volume;
}

void GetDataShowAllTimeSay(void)
{
  if (ValueData[0])
  {
    ValueData[1]=LoadValueN(oAllHourSay);
    ValueData[2]=LoadValueN(oAllMinSay);
    ValueData[0]=0;
  }
  else
  {
    (*(uint *) &ValueData[1])=ValueData[1]*60+ValueData[2];
    ValueData[0]++;
  }
}

bit PlayClock(void)
{
  switch(LoadValueN(oTypeHourSnd))     //Say Clock
  {
    case hsndNone:
         return false;
    case hsndBeep:
         StartMelody(mldyHourBeep,MaxVolume,eNone);
         break;
    case hsndSayTime:
         Event=eSayCurrentTime;
         break;
    case hsndClock:
         SayPhrase(phrBoomClock,eNone);
         break;
    case hsndClock_SayTime:
         SayPhrase(phrBoomClock,eSayCurrentTime);
         break;
    case hsndBeep_SayTime:
         StartMelody(mldyHourBeep,MaxVolume,eSayCurrentTime);
         break;
  }
  return true;
}

void StopRemoteAccessKey(void)
{
  if (RemoteAccess)
  {
// VideoBuffer[0][1]=(*(uchar *)(SP-1));
// VideoBuffer[1][1]=(*(uchar  *)(SP));
// Halt;
    LineDown();
    RemoteAccess=false;
    LineSoundOff();
    Event=eExitToMain;
    StopToneTesting();
    StopBeepTesting();
  }
}
void StopToneTesting(void)
{
  TestEnterRemoteAccsess=ToneTesting=false;
  ToneNumeral=OldTN=tnNoNumeral;
  ToneHighQualityDetect=false;
}

bit TestDayChange(void)
{
  if (Day!=LoadValueN(oODay))
  {
    if (NowHours!=0&&NowHours!=23)
    {
      GetClockTimeDate(clkwNowTime);
      if (LoadValueN(oSignCorr))
      {
        Seconds-=LoadValueN(oSecCorr);
        if (Seconds>59)
        {
          Seconds+=60;
          NowMinutes--;
        }
        NowMinutes-=LoadValueN(oMinCorr);
        if (NowMinutes>59)
        {
          NowMinutes+=60;
          NowHours--;
        }
        Minutes=NowMinutes;
        Hours=NowHours;
      }
      else
      {
        Seconds+=LoadValueN(oSecCorr);
        if (Seconds>59)
        {
          Seconds-=60;
          NowMinutes++;
        }
        NowMinutes-=LoadValueN(oMinCorr);
        if (NowMinutes>59)
        {
          NowMinutes-=60;
          NowHours++;
        }
      }
      SetClockTime(NowHours,NowMinutes,Seconds);
    }
    SaveValueN(oODay,Day);
    return true;
  }
  return false;
}

void Oper00_00(void)
{
  ClearUndefinedNumbers();             //Clear Undefined
  SaveValue(oTodayCalls,0);            //ClearTodayCallCounter
}