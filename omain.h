/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

#define LenString 15
#define LenNumber 7

#define MaxZK 300
#define MaxIn 300

#define BuffSeach MaxZK+3
#define NM1 MaxZK+4
#define NM2 MaxZK+5
#define NM3 MaxZK+6
#define StartNM1 NM1
enum ExitCodes {
                EMainMode,
                ENext=3,
                ERedial=4,
                EM1=8,
                EM2=9,
                EM3=10,
                EStore=7,
                ESearch=11,
                EMovedToEnd=12
               };


enum GetAdrN {
              BNumber=2,
              BString
             };

enum BookType {
                BookZK,
                BookIn
              };
enum Zapros {
             AD,DA,AA,DD
            };


enum ReturnBeepsType {
                      NoBeeps,
                      ShortBeeps,
                      LongBeeps,
                      OneLongBeep
                     };

/*#define NoBeeps         0
#define ShortBeeps      1
#define LongBeeps       2
#define OneLongBeep     3 */

enum AdrData {
              MaxNumberZKD,
              MaxNumberIND,
              StartNumbIND
             };
enum Bmps {
           ClearModeBmp,
           ModeTableBmp,
           ModeViewNumberBmp,
           NoNumberInBuffBmp,
           NoSpaceBmp,
           StoredBmp,
           OutOfNumbersBmp,
           ModeViewOnlyNumberBmp,
           ModeViewOnlyStringBmp,
           ModeViewNumberZKBmp,
           ModeViewNumberInBmp,
           MenuBookZKBmp,
/*           MenuBookInBmp, */
/*           ViewOprNumberStrBmp, */
           ResetModeBmp,
           MaxBmp
          };

/*define MenuBookINBmp         12 */

#define MaxMenuItem   3
enum MainMenuModes {
                    AlarmSelect,
                    OptionsSelect,
                    ResetSelect
                   };

/*#define ViewNKBmp       MaxBmp+2
#define ViewTimeBmp     MaxBmp+3
#define TmpABmp         MaxBmp+4
#define ViewBeepTestBmp MaxBmp+5
#define Timer2Bmp       MaxBmp+6
#define ViewNumbBellBmp MaxBmp+7 */

/* Коды клавиш */
#define KeyRedialF 1
#define KeyErase   2
#define KeyUp      3
#define KeyDown    4
#define KeyM1      5
#define KeyM2      6
#define KeyM3      7
#define KeyMem     8
#define KeyStore   9
#define StartKeyM1 KeyM1


#define OKeyRedialF 0x09
#define OKeyErase   0x0a
#define OKeyUp      0x0c
#define OKeyDown    0x24
#define OKeyM1      0x11
#define OKeyM2      0x12
#define OKeyM3      0x14
#define OKeyMem     0x21
#define OKeyStore   0x22

#define KeyMenu  KeyErase
#define CKeyMenu  CKeyErase

#define KeyModeMainMenu   1
#define KeyModeViewBook   2
#define KeyModeOptions    3
#define KeyModeEditNumber 4
#define KeyModeEditString KeyModeEditNumber
#define KeyModeSelectStoreTo 5
#define KeyModeReset KeyModeViewBook
#define ______A 0

/* bit StartSend = P3.0; */
/* bit DataInd01 = P1.7; */

 bit Led0      = P2.7;          /* светодиод */
 bit ResetInd  = P2.1;          /* Ресет инд. */
 bit LineUp    = P2.4;          /* подгрузка/поднятие линии */
 bit LineKz    = P3.4;          /* Выкорачивание линии */
 bit BeepOn    = P2.5;          /* компаратор (для кор. гудк) */

 bit HandsFree = P3.1;
 bit Hook      = P3.5;

 bit Bell      = P3.2;          /*звонок*/

 bit Line      = P3.7;          /* проверка Line */
 bit HoldIn    = P3.3;          /* проверка Hold'a */

#define SpeakerPhone     0x08
#define RedialF          0x02
#define Redial           0x04

#define  HoldNotPresent 1
#define  HoldPresent    0
#define  SpkOff      1
#define  SpkOn       0
#define  LineLoad    1
#define  LineFree    0
#define  KZon        1
#define  KZoff       0
#define  HookUp      1
#define  HookDown    0
#define  LinePresent    0
#define  LineNotPresent 1


#define  LedOn       1
#define  LedOff      0
#define  ResetIndOn  0
#define  ResetIndOff 1

#define OverWaitTimeX OverWaitTime1
#define OverWaitTimeY OverWaitTime2


#define T2R500HzO   0xE890      /* частота синуса  500 Hz */
#define T2R500HzI   0xFc18      /* частота меандра 500 Hz */
#define T2RBEEPHzO  0xE4BF      /* частота синуса 430 Hz */

#define ExitNowBell  0

enum ReturnCode {Ok,NoOk};

/*#define Ok    0 */
/*#define NoOk  1 */
#define WaitTimeToUp 0
#define WaitTimeToUpBell 200
#define WaitTimeToNBreakBell 20

/* Смещения настроек  */
enum OffsOpt {
              NumbBellsOpt,                /* К-во звонков до поднятия */
              HourOpt,
              MinOpt,
              DayOpt,
              MonthOpt,
              YearOpt,
              NightFromOpt,                /* Night From */
              NightToOpt,                  /* Night To */
              NightCallsOpt,               /* к-во звонков в ночном режиме */
              AreaCodeOpt,                 /* Маска города */
/*              AtsTypeOpt,                  /* вид АТС */ */
              LenPauseKzZaprOpt,           /* длина выкорачивания */
              LenPause0ZaprOpt,            /* длина 1й паузы */
              NumbZaprOpt,                 /* к-во запросов */
              LenZaprOpt,                  /* длина запроса */
              FormZaprOpt,                 /* форма запроса */

              AlarmOnOpt,                  /* Будильник On/Off */
              AlarmHourOpt,                /* Будильник Часы */
              AlarmMinuteOpt               /* Будильник минуты */
             };
#define MaxPrefer  FormZaprOpt+1/*2+3+1+1+1+1+1+1+1+1+1+1+1 */
#define StartPrefer NumbBellsOpt
#define AlarmStartOpt AlarmOnOpt
#define AlarmEndOpt   AlarmMinuteOpt+1

/*#define LenPauseZaprOpt   0               /* длина паузы между запросами */ */
/*#define BeepTimeOutGetOpt 0               /* К-о гудков выдаваемых в линию*/ */

#define MutByte           0xf             /* код мути */
#define MinQuality        0x10             /* минимальное качество */

#define ForwardCopy 0
#define BackwardCopy 1
#define MutViewByte 0x0B
#define PovtorByte 0x0C
#define TheBeginNumber 0x0B
#define NotFound 0xffff

#define FFindN 1
#define FFindS 2
#define FFindPlus 4

/* extern char CopyMem(unsigned int,unsigned int,unsigned int,bit); */
/* CopyMem Argumets
   1 AddressFromCopy
   2 AddressToCopy
   3 Length
   4 Direction
*/


extern char GetCodeOnKey(char);                   /* Asm Опр. код наж. кл. */
extern int GetMemData(char);
extern void SetMemData(int,char);
extern char CallNumber(char Func);
extern char BeepTest(char Func,char LenWaitTimeBeep);
extern char UnPackC(int,char);
extern char DeleteNumberC(int,char);
extern int OpredNumber();
extern void SaveOprNumb(void);
extern int SeachTusBook(char,char,int,int);
extern char EditPrefer(char,char);
extern char EditFunc(char Nfunc,char);
extern int ViewDataBufferRom(char);
extern int LoadValue(char);
extern int SaveValue(char,int);
extern int MigTestSave(char,int);
extern int GetMigOnFunct(char,int);
extern int WaitTimeX(char);
extern int WaitTimeXms(char);
extern int WaitTimeY(char);
extern int SetWaitTimeX(char);
extern int SetWaitTimeXms(char);
extern int SetWaitTimeY(char);
extern int BEEP();
extern int InitA();
extern void SaveNumberInZK(void);
extern int PackZK(int NBook1);
extern char PackIN(int);
extern int VDBRa(char Bmp);
extern int FuncOnEventKey(char NFuncEvent1,char NowKey11,char ValueX1);
extern int EditNewNumber();
extern int EditNewString();
extern int ClearNumbBuffer();
extern int ClearStringBuffer();
extern char LoadMinMax_Value(char);
extern char SaveMinMax_Value(char);
/*xtern int LoadByteInMemFromXXXX(unsigned int); */
/*extern int SaveByteInMemFromXXXX(unsigned int,unsigned char); _bellC*/
extern bit GetHF(void);
extern void WaitNSec(char);
extern void SetT2(int);
extern void ResetCSRST(void);
extern char GetOverBell(void);
extern char ZaprosOut(void);
extern void StopT2(void);
extern bit TestOnSendAnswer(char);
extern char OPRED_C(void);
extern void BellBeepOut(char);
extern void PlayBell(char);

 extern char ClearAllBuffers();

 extern char PackC(int,char);
 extern char UnPackC(int,char);

 extern void InsertNumber(int,char);
 extern bit TestLinePresent(void);
 char ViewBook(char);
 char InsertNumberC(int,char);
 int FastFindNumberStringC(int,char,char);
 void ClrValueDataNValue(void);
 void MenuBook(char);
 int GetR67NVValue(void);
 void SetNVValueR67(int);
 void ResetOptions(void);
 void LoadConst(void);
 void TestHFHLDHOOK(void);
 void FindK(void);
 void FindBlack(void);
 char LoadOption(char);
 void TestMinOver(void);
 void EditNumberZK(void);
 void SeachN(char);
 void SetNVMaxValue(void);
 void CorrTime(void);
 void TestAreaCode(void);