/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

#include <io51.h>
#define _C
#include <set.h>
#pragma language=extended
#pragma warnings=off

#define uchar unsigned char
#define uint  unsigned int
#define Halt while(1);
#define GetP4 {P4IN=~(*(char *) P4INAddress);}

typedef struct tagKvantDataS
        {
         uchar ToneType,
               BeepFreq;
        } KvantDataS;

char InitMain(void);
bit InitFlash(void);
void InitTimers(void);
char InitSystem(void);
void EnterFunc(void);
void LeaveFunc(void);
uchar GetVideoDataOnEFunc(void);
void LeaveAllFunc(void);
void BeepStart(uchar);
void BeepStop(void);
uchar GetKeyMapOn(uchar);
uchar EventOfModeKey(uchar);
uint LoadValue(uchar);
bit SaveValue(uchar,uint);
bit SaveValueN(uchar,uint);

bit SaveNumberOpt(uchar);
void EndOptionEdit(uchar SelOption);
void SelectOption(uchar SelOption);
uchar GetVideoDataOnOption(uchar);
uint HexToDecData(uint);
uint DecToHexData(uint);
uchar GetKeyEditOnTypeEdit(void);
void SetCharInEditBuff(uchar);
void DeleteCharInEditBuff(void);
void StartLoadOpt (void);
void TestSpecOpt(uchar);
void TestEnableOpt(void);
void DaySetOnKey(uchar);
void BitSetOnKey(uchar);
void ToneDebug(void);
void GetMainModeVFuncData(void);
void EnterMain(void);
void SetNumberBuff(uchar,uchar);
void SetNumberBuffA(uchar,uchar);
void TestFuncChg(void);
void SetTimeOutExit(void);
bit GetPauseRolNumber(uchar,uchar);
uchar SetCallData(uchar);
uchar GetNumberBuff(uchar);
void StartImpulse(void);
void StopImpulse(void);
void LoadCallParam(void);
uchar GetEventOnBeepMap(uchar,uchar);
void CallEvent(uchar);
void RetEvent(void);
void EventCallPosition(void);
uchar LoadDefaultNumber(uchar);
void SaveDefaultNumber(void);
void SaveDefaultNumberA(void);
uchar GetNumeralDefaultBuff(uchar);
KvantDataS ToneDetect(void); //25ms wait
uchar BeepDetect(void); //25ms wait
uchar AbsC(signed char);
uint LoadValueN(uchar);
void LineUp(void);
void LineDown(void);
void StopCall(void);
void PipeOn(void);
void PipeOff(void);
void PipeOnOff(void);
bit ParallelTest(void);
void SoundOn(void);
void SoundOff(void);
void StopBeepTesting(void);
uchar Convert10msTo4ms(uchar);
char IdleMode_WaitForEvent(void);
uchar RequestStart(uchar,bit);
void LineSoundStop(void);
uchar TestOnSendAnswer(uchar);
uchar NumeralDetect(void);
void GetAnswerAndDecode(char FirstByteSet);
data uint idata *stack_malloc(uchar);
bit stack_mfreelast(uchar);
void TestVoice(void);

int GetSayNumberWord(void);
uchar GetTypeSayingMH(uchar Value);
uchar SayInt(uint Value,bit typevoice12);
void StopPlayWav(void);
void StartPlayWav(uchar);
bit PlaySampleNext(void);
void SayTime(uchar nphrase,uchar Hours,uchar Minutes,uchar EndEvent);
void SayNumber(uchar nphrase,uchar EndEvent);
void SayKey(uchar nphrase,uchar keysay,uchar EndEvent);
bit GetNextPlay(void);
void LineSoundOn(void);
void LineSoundOff(void);
void BeepLineStart(void);
void BellPlay(void);
void StopPlay(void);

void ViewDataBufferRom(char);

char ConvertKey(void);
uint GetEventOnFKey(char);
void BeepOnKey(void);
void SndOnKey(char);

bit BuffWork(uint,uchar);
uint GetNumberNumber(uchar);
uchar GetNumberBook(uchar);


uchar LoadByteFromAdrInRamC(uint);
void SaveByteFromAdrInRamC(uint,uchar);
bit SaveOpt(uint,uchar);
uint LoadOpt(uchar);
uint TestOutOfBook(uint addr);
uchar GetLenNumber(uint addr);
bit GetNextNAT(void);
bit SetNAT(uint Number,bit value);
uint GetNumberBack(uint Number);
void CopyMemMOD(uint FromAddr,
           uint ToAddr,
           uint LenNumber,
           bit Direction);

bit InsertNumberBook(void);
uint DeleteNumberBook(void);
uint GetAddress(uint number);
uint ResetNumberAddr(uint number);
uint NextNumberAddr(uint addr,uint number);
bit SetStartNAT(void);
void SaveBookData(void);
uint LoadBookData(uint Number);
uint GetOffsetNextNumber(uint addr);
uint LoadNumber(uint Number,uchar book);
bit SaveNumber(uint Number,uchar book);
uint DeleteNumber(uint Number,uchar book);
uint SearchNumber(uint StartNumber,uint LenSearch,uchar book,uchar ModeSearch);
void ClearBook(uchar book);
uchar GetLenPackOfLenNumberMinLen(void);
void ResetBooks(void);
void ShowBusy(void);
void SetTimer1msA(uint);
void ResetOptions(uchar,uchar);
void PrepareSayingData(void);

void SetSpeakerOn(void);
void SetSpeakerOnA(void);
void SetSpeakerOff(void);
void SetSpeakerOnOff(void);
void SayPhrase(uchar nphrase,uchar EndEvent);

void StopTimer1sA(void);
void StopTimer4msA(void);
void DeviceReset(void);

void SetDefaultLenNumberBuff(uchar);
void SetDefaultNumeralBuff(uchar,uchar);
void ResetDefaultNumberBuff(void);

bit TestLock(bit locktype);
void XchgNumbBuffers(void);

void TestMelody(void);
bit NextNotePlay(void);
void StartMelody(uchar melody,uchar volume,uchar event);
void StartMelodyA(uchar melody,uchar volume);
bit VolumeUp(void);

void ResetArams(void);
void StopSearch(void);
uint GetNumberBackBook(uint number,uchar book);
void TestStartAutoSearch(void);
void TestStartAutoDial(void);
void InvertImpulse(void);

bit TestLockLevel1(void);
void ClearUndefinedNumbers(void);

bit InitClock(void);
bit PICwork(uchar command,uchar *buffer);
void SetClockTime(uchar hours,uchar minutes,uchar seconds);
void SetClockDate(uchar day,uchar month,uchar year);
void GetClockTimeDate(uchar ClockOper);

bit TestAlarm(uchar alarm);
void TestTime(void);
bit TestNight(uchar hours,uchar minutes);
bit TestSaveInUdefined(void);

void ResetAllOptions(uchar ResetType);
void PrintError(uchar);
bit TestROM(void);
void SetVolume(uchar volume);

void GetDataShowAllTimeSay(void);

uint FindTodayCall(uint StartNumber,uchar book,bit Direction);

bit TestTimeOutPowerDown(void);
void SetTimeOutPowerDown(void);
void ShowPowerDown(void);
bit PlayClock(void);

void StopRemoteAccessKey(void);
void StopToneTesting(void);

void StopSendFlash(void);
bit TestDayChange(void);
void Oper00_00(void);

#define MaxWavDataBuffer 2
#define MaxFuncStack 5
//#define MaxRazr 9
#define MaxEKT 5
#define MaxKeys 2
//specical key format:
// Key=0..LenKeyA-1 - short/repeat pressed key
// Key=LenKeyA..2*(LenKeyA-1) - long pressed key
// Key=2*LenKeyA..N  - specical function key

extern code const char EventKeyTable[MaxEKT];
extern code const char StandartEventKey[MaxKeys];
extern bit SecondOut,    //1 - Second is out
           KeyPresent,   //1 - Key is present
           EndPressKey,  //1 - End key pressed
           EndPressKeyNow,
           LongKeyEvent,
           FirstKey,
           LinePresent,
           TimeOut1sA,
           TimeOut4msA,
           TimeOut4msB,
           StartBell,
           EndBell,
           OldBell,
           EndWavPlay,
           PauseAfterSayWav,
           BookOpt,
           OptConst,
           TypeNumber,
           EndReciveNumeral,
           ToneHighQualityDetect,
           MelodyPlay,
           EndTime_snd,
           t2ms,
           SoundToLine,
           OldLine;

extern data char NowKey,     //X - Now key
                 EventKeyUp, //X - Event by EndPressed
                 Timer1sA,
                 Timer4msA,
                 Timer4msB,
                 LBell,LBellMin,LBellMax,RepeatLBell,
                 LenNumber,Book,
                 RecivedNumeral,
                 ImpulseNumeral,
                 XrlByte,
                 NiceMigDown;
extern idata char ValueData[MaxValueData],
                  Number[MaxLenNumber/2],
                  DayCall,MonthCall,HourCall,DayOfWeekCall,
                  MinCall,HourSay,MinSay,
                  VideoBuffer[MaxRazr][2],

                  Day,Month;

#define Kateg Number[10]

extern code const uchar code *TablePhrase[];
extern code const uchar SayVideoPhrase[];

#ifdef DEBUG
 extern data char Devider250;
 void BT(void);
#endif
#ifdef DEBUG_KeyEmulation
 extern data char PosEmulKey;
 extern const char KeyEmulData[100];
#endif

#pragma warnings=on