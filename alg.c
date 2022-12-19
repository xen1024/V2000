/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

void TimerKey(void);
void TestKey(void);
#include "io51.h"
#define realkey P1
#define MinKeySpeed 20
#define MaxPovtorKey 10
#define StartKeySpeed 10
#define PauseAntiIskr 10
#define StartPause0   10
data char Key,KeyCx1,KeyCx2,NowKey,PovtorKey,KeySpeed,OldKey; /* KeyCx, */
bit LongPressKey,KeyPresent,EndPressKey;

/**********Процедура клавы*****/
void main(void)
{
     TimerKey();
}
void TimerKey(void)
{
 Key=realkey;
/* if (KeyCx!=0) KeyCx--; */
 if (KeyCx1!=0)
    KeyCx1--;
 else
    if (Key!=0)
    {
       if (KeyCx2!=0)
          KeyCx2--;
       else
       {
           if (NowKey!=Key)  //NowKey==0||
           {
              RepeatKey=0;
              KeyCx1=PauseAntiIskr;
              KeyCx2=StartPause0;
              KeySpeed=StartKeySpeed;
              FirstKey=1
           }
           else
           {
                 KeyCx2=KeySpeed;
                 if (KeySpeed!=MinKeySpeed) KeySpeed-=DecraseSpeed;
                 if (RepeatKey!=0xff) RepeatKey++;
                 if (RepeatKey==LongRepeatKey) LongPressKey=1;
           }
           KeyPresent=1;
           NowKey=Key;
       }
    else
       if (NowKey!=0)
       {
          EndPressKey=1;
          KeyCx2=0;
          NowKey=0;
       }
}

/*
           if (NowKey!=Key&&KeyCx1>0&&KeyFirst==0)
              {
               KeyFirst=1;
               NowKeyA=Key;
               NowKeyB=NowKey;
               goto xA;
xA:
              }
*/
/*
KeyPresent=1    нажата кнопка
FirstKey=1      первое нажатие
LongPressKey=1  долгое удержание
EndPressKey=1   клавиша отпущена

NowKey          нажатая клавиша
*/

if (KeyPresent==1)
  {
/*   xKey=GetEvent(NowKey,EKey); */
   KeyPresent=0;
/*   EndPressKey=0; */
   LongPressKey=0;
  }

if (LongPressKey==1&&EndPressKey==1)
  {
/*   xKey=GetEvent(NowKey,EKey); */
   KeyPresent=0;
/*   EndPressKey=0; */
   LongPressKey=0;
  }
}

/* IJKLMNOPQRSTUVWXYZ
            0123456789ABCDEF
 ViewByte: "0123456789 _-└┘▄▀AbCcdEFGHhIiJLlnOoPStUuYZП"
 CallFunc=0
    0                   1  2  3
 Call                   hh ll      SP+2 CallFunc++
 Jump                   hh ll
 Call[cv]               hh ll      SP+2 CallFunc++
 Jump[cv]               hh ll
 ViewDec[cv]
 ViewHex[cv]
 ViewDecRegister        rr
 ViewHexRegister        rr
 ChangeTypeMig          tm
 ViewOneCharNewTypeMig  tm ch

 ViewRamString Nbytes   hh ll ln
? ViewRomString Nbytes   hh ll ln

 SelectConvertTable     rr

 hh-high
 ll-low   \
 ln-length
 tm-type mig
 ch-view char

 VBuffer[9,2]
 VBuffer[x,1] ViewBytes
 VBuffer[x,0] Attribute
Attribute 000000mm
 mm=0 NotMig
 mm=1 FastMig
 mm=2 SlowMig





  ═
 │ │
  ═
 ║ ║
  ═ .


  Принципы и задачи V2000, которые следует придерживатся и достигнуть:

   I) О буфферах
     а) Главный буффер длины на максимальное к-во символов текста + служебные
        символы (время). С ним проходят все операции.
        Память: FDATA
     б) Быстрый дополнительный буффер используется для поиска.
        Память: DATA
     в..n) Дополнительный в книжках. Для временного перемещения данных
        Память: BOOKDATA

   II) О Скорости
     а) Скорость должна достигатся только в определенных местах, где она
        действительно необходима. Возможен запрет прерываний.
     б) Процессор должен находится в Idle Mode до происхождения какого-либо
        события. В Active Mode проц. должен находится только в конкретных
        процедурах.

   III) О таймерах
     а) Таймер времени должен вызватся с Т = 1 ms т.е. F=1 кГц.
        Таймер времени должен загружать CPU не больше чем 40% за 10T в крит.
        ситуациях, в среднем 10%.
        Включен всегда.
        Приоритет низкий.
     б) Таймер звука должен иметь частоту вызова F<22 кГц.
        Таймер звука должен загружать CPU не больше чем 90% за T в крит.
        ситуациях, в среднем 50%-60%.
        Включается временно при выводе звука.
        Приоритет высокий.
        Этот же таймер используется для работы с PICом во время выключения
        выдачи звука.
     в) Возможен также эффект яркости индикатора на таймере загасания.
        Таймер яркости должен загружать CPU на минимум 1-5% за T.
     г) Дополнительные таймера
        1) Дополнительный таймер 5ms должен идти в таймере времени.
           T = 5 ms T=0 ms
           PauseMax = 5*255 = 1275 ms
           Idle/Active mode 0-1% CPU/T.
        2) Дополнительные 2 таймера s должены идти в таймере времени.
           T = 1 s T=0 ms
           Idle/Active mode 0-1% CPU/T.
        3) Возможен постоянный таймер секунд должены идти в таймере времени.
           T = 1 s
           Генерирует событие "ESecondOut" ???
        4) Возможен при необходимости дополнительный таймер 1ms, должен идти
           в таймере времени.
           T = 1 ms T=1 ms
           PauseMax = 255 ms
           Idle/Active mode 0-1% CPU/T.   ???
     е) Клава может загружать CPU до 100% на T при 10% на 10T при
        событии.
        Idle mode 0-1% CPU/T.
     ж) Проверка звонка должна загружать CPU не больше 10% на 10T.
     з) "ESecondOut" происходит при переходе DX=x->y ???

   IV) О событиях
     а) События в основных режимах
        "EKeyPresent"     Поступили данные с клавы
        "EOverTimeX"      Вышло время заданного таймера
        "EBellPresent"    Произошел звонок
        "ELineNotPresent" Пропала линия
        "EOverPlaySample" Закончилось проигрывание sampl`a
        "EBreak"          Требуется прервать выполняемую процедуру
        "ESecondOut"      Прошла секунда
     б) Событие "EKeyPresent"
        Генерирует обращение к "FPlaySound"
        Генерирует обращение к "FPlayVoice"
        Приоритет +++
     в) Событие "EOverTimeX"
        Приоритет +
     д) Событие "EBellPresent"
        Генерирует обращение к "FIndificationNumber"
        Приоритет ++
     е) Событие "ELineNotPresent"
        Генерирует обращение к "FIndificationParallel"
        Приоритет ++
     ж) Событие "EOverPlaySample"
        Генерирует обращение к "FGetDataForPlaySample"
        Приоритет +++
     ж) Событие "EBreak"
        Генерирует выход из выполняемой процедуры
        Приоритет +
     з) Событие "ESecondOut"
        Генерирует обращение к "FGetTimeDateCMOS"
        Приоритет +

   V) О времени
     а) Время идет в процессоре времени и должно запрашиваться процедурой "FGetTimeDateCMOS"
        в процедурах:
       "FIndificationNumber"
       "FIndificationParallel"
       "FViewSecMode"
       "FPowerOn"
     б) Время устанавливается в процессоре времени процедурой "FSetTimeDateCMOS"
        после выполнения процедур:
       "FОptionTimeDateChange=1"
     г) Время хранится в EEPROM/FLASH

   XX) O функциях
     а) После вызова "FXXXXXXXXXXXXXXXXXXXXXXXXXX" происходит обновление видео.

  Key=FuncKey(HwKey);
  Event=FuncEvent(Key);

 0          1..x
 Set10      1..10=E[0..9]   - set event for FSKEY[0..9]=E[0..9]
 SetL10     1..10=E[0..9]   - set event for FLKEY[0..9]=E[0..9]
 SetKeys    1-FIRST 2-LAST 3..x=E[FIRST..LAST] - set keys events FIRST..LAST=E[FIRST..LAST]
 SetKeysTo  1-FIRST 2-LAST 3=E - set keys events FIRST..LAST=E
 KEY        1=E             - set event KEY
 Call       1..2=addr       - call string
 Jump       1..2=addr       - jump string
 DCall      1 = N           - call string of table
 DJump      1 = N           - call string of table
 End String                 - if (strSP==0) exit; else strSP--;

char Levent   - Event on long pressed key
char Sevent   - Event on short pressed key
char SELevent - Selected Event on pressed key

PlayKey=true;
if (!FirstKey)
 if (Levent!=eNone)
    PlayKey=false;
 if (SELevent!=Levent)
    SELevent=eNone;
FirstKey=0;

Key=0..MaxKey-1
LongKey=MaxKey+80h
ModeSet:
      Func=WorkModeEvent(Event);
AgainWait:
          OnEvent=IdleWaitToEvent(Key,Bell,Line);
          if (GetEventOnFunc(OnEvent,EFunc)!=NoEVENT)
             Event=GetEventOnFunc(OnEvent,EFunc);
          else Event=GetEventStandart(OnEvent);
          Event=WorkEvent(Event,NFunc);
      if (Event==AgainEvent) goto AgainWait
      goto ModeSet;



;Value--
;Value++
;CurrenByte++ If CurrenByte<MaxCurrenByte Else CurrenByte=0
;ExitCode=Next Value
;ExitCode=Exit To Main and AutoCall
;Value++ If Value=MaxValue then ExitCode=Moved To End
;CurrenByte++ If CurrenByte<MaxCurrenByte Else Event3
;Store
;ExitCode=3=EM1
;ExitCode=4=EM2
;ExitCode=5=EM3
;FindAgain
;RemoveByte
;InsertByte
;ClearBuffer
;ExitCode=ExitToMain
;ничего

0..3*4      ShortPressKey
3*4..2*3*4  LongPressKey




  DATA     Регистры
  FDATA    Флэш память
  BOOKDATA Память номеров
*/
000 0
001 1
010 2
100 3

;*****************************************************************************
;голос
;*****************************************************************************
X0633:  push    psw                 ;do
        mov     psw,#10h            ;{
        push    b                   ;
        xch     a,r6                ;
        xch     a,dpl               ;
        xch     a,r7                ;
        xch     a,dph               ;
        xch     a,r2                ;
        anl     29h,#3              ;
        orl     a,29h               ;
        mov     29h,a               ;
        movx    @r0,a               ;hP4=OutA|(P4&3);
        clr     a                   ;
        movc    a,@a+dptr           ;
        mov     b,a                 ;XADR=XMEM[ADDR];
        mov     a,r1                ;if (R1!=0)
        jz      X065d               ;
         add     a,#47h             ;{
         movc    a,@a+pc            ; XADR=XADRt=High(X6c4[R1]*XMEM[ADDR+1])
         mov     r0,a               ;        |Low(X6c4[R1]*XMEM[ADDR]);
         mul     ab                 ;
         mov     r3,a               ;
         mov     a,#1               ;
         movc    a,@a+dptr          ;
         mov     b,r0               ;
         mul     ab                 ;
         mov     a,r3               ;}
X065d:  orl     a,b                 ;
        mov     r0,dpl              ;
        mov     r3,dph              ;
        mov     dptr,#X6c4h         ;
        movc    a,@a+dptr           ;;//X6c4[XMEM[ADDR]] or X6c4[XADRt]
        mov     dpl,r0              ;
        mov     dph,r3              ;
        mov     b,a                 ;
        anl     a,#7                ;
        inc     a                   ;
        add     a,r1                ;R1=X6c4[XADR]&7+R1+1;
        jnb     acc.3,X0677         ;if (R1&8)
         anl     a,#7               ;{ R1&=7;                 // R1=00000xxx;
         inc     dptr               ;  ADDR++;
X0677:  mov     r1,a                ;}
        mov     a,b                 ;
        swap    a                   ;
        anl     a,#0fh              ;A=X6c4[XADR]>>4;     //A=0..7..0xA
        jnb     acc.3,X0689         ;                     //A=0..7,FF,FE,FD
                                    ;                      +0..7/-1..-3
         clr     acc.3              ;if (A&8) A~=A&7;     //A=11111xxx;
         cpl     a                  ;
X0689:  add     a,3eh               ;A=x3eh=x3eh+A;      //
        mov     3eh,a               ;
        swap    a                   ;
        rr      a                   ;
        xch     a,r2                ;OutA=A.43210765;     //OutA=xXXXXXxx=xxxxxx000
        xch     a,dph               ;
        xch     a,r7                ;
        xch     a,dpl               ;
        xch     a,r6                ;
        djnz    r5,X0680            ;if (LEN--) tr0=false; //end loop
         djnz    r4,X0680           ;
          clr     tr0               ;}
X0680:                              ;
        pop     b                   ;while(tr0);
        pop     psw                 ;
        reti
;H 0..A 1010
;L 1..6 0110
x69b:
02 04 08 10 20 40 80

93 23 65 82 2E FE 50 01 1F
A3 E5 82 70 13 E5 83 54 1F 70 07 20 16 04 B1 A0
00 00 E5 83 30 D1 01 04 22

81 81 81 81 81 81 81
81 81 81 81 81 81 81 81 81 81 81 81 81 81 81 81
81 81 81 81 81 81 81 81 81 81 81 81 81 81 81 81
81 81 81 81 81 81 81 81 81 81 81 81 81 81 81 81
81 81 81 81 81 81 81 81 81 33 33 33 33 33 33 33
33 33 33 33 33 33 33 33 33 A3 A3 A3 A3 A3 A3 A3
A3 A3 A3 A3 A3 A3 A3 A3 A3 44 44 44 44 44 44 44
44 C5 C5 C5 C5 55 55 55 55 75 75 75 75 F7 D7 66
66 E5 E5 E5 E5 B5 B5 B5 B5 01 01 01 01 01 01 01
01 01 01 01 01 01 01 01 01 01 01 01 01 01 01 01
01 01 01 01 01 01 01 01 01 01 01 01 01 01 01 01
01 01 01 01 01 01 01 01 01 01 01 01 01 01 01 01
01 01 01 01 01 01 01 01 01 23 23 23 23 23 23 23
23 23 23 23 23 23 23 23 23 93 93 93 93 93 93 93
93 93 93 93 93 93 93 93 93 12 12 12 12 12 12 12
12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
12 12 12 12 12 12 12 12 12

X092b:  mov     tl0,TReloadH
        mov     th0,TReloadL
        xch     a,SndAddr
        xch     a,DPH
        xch     a,OutByte
        xrl     a,XrlByte
        movx    @DPTR,a
        xch     a,OutByte
        xch     a,DPH
        xch     a,SndAddr
        reti














struct DateNumber   12 bits
{
 uchar Day  =0..30,   5 bits a
       Month=0..11    4 bits b
       DayOfWeek=0..6 3 bits c
}
struct TimeNumberCall   11 bits
{
 uchar Minutes  =0..59, 6 bits d
       Hours    =0..23  5 bits e
}
struct TimeNumberSay    9 bits
{
 uchar Minutes  =0..59, 6 bits
       Hours    =0..7   3 bits
}

Out: Len=0..31           4
     DateNumber          12
     TimeNumberCall      11
     TimeNumberSay       9
     Number              X 4*(1..32)

 min = 5
 max = 21
 x7  = 8
 free7=0 bits                           =1bit
size=100*8=800

In:  DateNumber          12
     TimeNumberCall      11
     TimeNumberSay       9
     Number              4*8
 min = 8
 max = 8
 x7  = 8
 free7=0 bits
size=100*8=800

ZK:  Len < 16
       Len                 4
     Len = 16
       Len                 8
     Number              X 4*(1..32)
 min = 1
 max = 17
 x7  = 4
 free7=0 bits
size=100*4=400

ZK:
 N=100
Black:
 N=50
White:
 N=50
BlackLock:
 N=50
Specical:
 Lock        10 Lx.
 Chg         10 Fx.
 Say numbers 5  Cx.
 ChgTo       10 tx.
 AreaCode    1  Гo.

 PN          1  ПН.
 Bcall       1  bc.
 Pager       1  PG.
 PagerNumber 1  Pn.
 Alarm       10 Ex.

 ShowN=10*3+1+5=36
 N=10*4+5+5=50

LenNAT = 37

Format number
ZK/Out:
 Len<16
   Len [0..3]
   Number [3..x]
 Len==16
   Len [3..7]
   Number [3..x]
In:
 Number[0..x]
Data In/Out:
 Data [x+1..y]

 0e - 15
 0f - 16
 1f - 17

0 - 1
1 - 2
2 - 2
3 - 3
4 - 3

------------------------------------------------------------------------------
TwoToneOut:
        push    psw
        xch     a,OutByte
        anl     a,#0fch
        anl     P4,#3
        orl     a,P4
        mov     P4,a
        movx    @r0,a

        mov     a,XTone1Lo
        add     a,StepTone1
        mov     XTone1Lo,a
        mov     a,XTone1Hi
        addc    a,StepTone1+1
        mov     XTone1Hi,a
        jbc     acc.7,InvertTone1
         add     a,#HalfSin-$-3
         movc    a,@a+pc
NextTone1:
        mov     tmp1,a
        mov     a,XTone2Lo
        add     a,StepTone2
        mov     XTone2Lo,a
        mov     a,XTone2Hi
        addc    a,StepTone2+1
        mov     XTone2Hi,a
        jbc     acc.7,InvertTone2
         add     a,#HalfSin-$-3
         movc    a,@a+pc
NextTone2:
        add     a,tmp1
        xch     a,OutByte
        pop     psw
        reti

InvertTone2:
        add     a,#$-HalfSin-3
        movc    a,@a+pc
        xrl     a,#7fh
        sjmp    NextTone2

InvertTone1:
        add     a,#$-HalfSin-3
        movc    a,@a+pc
        xrl     a,#7fh
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




#define yf0 0x0BE7
#define yf1 0x0D27
#define yf2 0x0E8D
#define yf3 0x1012
#define xf0 0x14A6
#define xf1 0x16D1
#define xf2 0x18B7

 dw yf3,xf1 ;0
 dw yf0,xf0 ;1
 dw yf0,xf1 ;2
 dw yf0,xf2 ;3
 dw yf1,xf0 ;4
 dw yf1,xf1 ;5
 dw yf1,xf2 ;6
 dw yf2,xf0 ;7
 dw yf2,xf1 ;8
 dw yf2,xf2 ;9
 dw yf3,xf0 ;*
 dw yf3,xf2 ;#

 dw 0x088A,0x088A ;request
 dw 0x0742,0x0742 ;start tone for beep
 dw 0x854C,0x4E85 ;?
 dw 0x4D4F,0x01EA ;?

Опции:

TypeByte
 76543210
 │└┬┘└─┬┘
 │ │   └ BitLen
 │ └──── TypeMinMax
 └────── TypeOfData

 BitLen       4 bits
 0  - Max 1
 3  - Max 15
 5  - Max 99
 9  - Max 999
 13 - Max 9999
 15 - Max 65535
 TypeMinMax  Min    Max       KeyMapEdit
 0           0      1         Next Value     N
 1           0      9         Enter numbers  S
 2           0      99        Enter numbers  S
 3           0      0xFF      custom         C
 4           0      custom    Enter numbers  S
 5           0      custom    NextValue      N
 6           custom custom    Enter numbers  S
 7           custom custom    custom         C
 TypeOfData
 0 - DecByteData
 1 - HalfByteData
 KeyMapView
 KeyMapEdit

custom KeyMapEdit: MaxValue=[X+1]
custom max: MaxValue=[X+1]
custom min: MinValue=[X+1+Z]
DefaultData=[X+1+Z]
 0 TypeByte
 1 KeyMapView
 2+ KeyMapEdit   1/0
    MaxValue     2/1/0
    MinValue     2/1/0
    DefaultValue 2/1


LenMinMax=1*(((BitLen+1)&0x8)>>3+1)

tmp=MaxValue-MinValue;
Len=1;
if (tmp-100>0)
{
  Len++;
  if (tmp-1000+100>0)
     Len++;
     if (tmp-10000+1000+100>0)
        Len++;
}

VIEW:
ViewDec3
ViewDecW

if (SelectedValue==ViewSelectedValue)
{
   ValueSelected=true;
   if (EditModeValue)
     if(TypeEdit=SerialPaste)
       ViewSerialPaste=true;
}

if(ViewSerialPaste)
{
 uchar ValueView=0,C;
 while (ValueView<LenData)
 {
  if (EditingValue==ValueView) TypeMig=MigType2;
  else TypeMig=MigNone;
  C=0xF&(EditBuff[CurrenValue+ValueView>>1]>>(4*(ValueView+1)&1));
  if (EditingValue>=ValueView) C=z_;
  ViewByte(C);
 }
}

EDIT:
StartOptionEdit()
{
 uint Value=LoadValue();
 if (TypeOfData==DecByteData)
    Value=HexToDecData(Value);
 EditBuff[]=Value;
 EditModeValue=true;
}

EndOptionEdit()
{
 uint Value=EditBuff[];
 if (TypeOfData==DecByteData)
    Value=DecToHexData();
 EditModeValue=false;
 SaveData(SelValue,Value);
 GetVideoDataOption()
}

GetVideoDataOption()
{
 VFunc=GetSelValueData(SelValue);
// Value=LoadValue(SelValue); //Loading parametrs
}

SetCharEditBuff(uchar C)
{
 if (PosEdit==0xFF)
    StartOptionEdit();
 EditBuff[PosEdit>>1]=(C<<(PosEdit&1)*4)&0xF;
 if (PosEdit++==LenEdit)
    EndOptionEdit();
}



;21MHz
X9549:  djnz    59h,X9570
        mov     59h,#4
        push    dpl
        push    dph
        mov     a,r3
        dec     a
        add     a,#50h
        mov     r0,a
        add     a,#0bch
        movc    a,@a+pc
        mov     dpl,a
        mov     dph,#7fh
        mov     a,@r0
        movx    @dptr,a
        pop     dph
        pop     dpl
        ret
;
 FE FD FB F7 EF DF BF 7F FF

X9570:  mov     a,#0ah
X9572:  djnz    acc,X9572
        nop
        ret


X9577:  lcall   X9549
        mov     a,r7
        rlc     a
        nop
        mov     c,p1.2
        rlc     a
        mov     r7,a
        lcall   X95ef
        djnz    r3,X959c
        mov     r3,#9
        nop
X9589:  cjne    r5,#10h,X9598
        mov     r2,#0ffh
        mov     r4,#2bh
        nop
        nop
X9592:  mul     ab
        mul     ab
        mul     ab
        nop
        sjmp    X95bb
;
X9598:  nop
        nop
        sjmp    X9592
;
X959c:  sjmp    X9589

X959e:  mov     psw,#10h
        clr     ea
        mov     dph,#0bfh
        orl     29h,#1
        mov     a,29h
        movx    @dptr,a
        mov     59h,#5
        mov     r5,#21h
        mov     r3,#9
        clr     a
        mov     r7,a
        mov     r2,a
        mov     dptr,#09c6bh
        mov     r4,#1fh
X95bb:  mov     a,r7
        xrl     a,r2
        mov     r6,a
        mov     r1,#40h
X95c0:  nop
X95c1:  mov     c,p1.2
        lcall   X95ef
        mov     a,r7
        rlc     a
        mov     r7,a
        mov     a,r4
        add     a,#9
        movc    a,@a+pc
        xrl     a,r6
        rrc     a
        movc    a,@a+dptr
        addc    a,@r1
        mov     @r1,a
        inc     r1
        inc     r4
        mov     a,r4
        movc    a,@a+pc
        xrl     a,r6
        clr     c
        rrc     a
        movc    a,@a+dptr
        addc    a,@r1
        mov     @r1,a
        inc     r1
        inc     r4
        mov     a,r1
        jb      acc.1,X95c0
        cjne    r1,#4ch,X95c1
        mov     c,p1.2
        lcall   X95ef
        djnz    r5,X9577
        ljmp    X96c1
;
X95ef:  mov     a,#10h
X95f1:  djnz    acc,X95f1
        ret
00 00 00 00 00 00 00 00 00 00 00 00
FF FF FF FE FF FC FF F8 FF F0 FF F0
FF 80 FC 00 F0 00 C0 01 80 07 01 1F
C0 00 00 07 01 7F 0F FF 7F F8 FE E0
00 1F 0F FF FF F8 FC 80 C0 03 03 3F
07 FF FF F0 E0 00 01 3F 3F FC FC C0
FF FC E0 00 01 7F FF F0 E0 01 07 7F
FE 00 00 3F FF F0 80 03 1F FE F8 80
00 00 7F FF C0 00 1F FF F0 00 0F FF
00 FF FE 00 03 FF F8 00 0F FF F0 00
7F FF 00 03 FF F0 01 3F F8 80 1F FE
FF C0 07 FF 80 01 FF F0 07 7F E0 01
E0 00 FF F0 07 FF 80 03 FC C0 3F FC
00 07 F0 00 FF E0 3F FE 03 3F C0 03
03 FF 00 1F 80 01 F0 00 FE E0 7F F8
FF FE 3F FF 0F FF 03 7F 01 1F 80 07
FF 00 FF 80 FF C0 FF E0 FF F0 FF F0
x96c5:
X96c1:  mov     63h,#5
        mov     r5,#1
        mov     tl1,#8ch
        lcall   X2adf
        setb    ea
        mov     r0,#6
        lcall   X9ac9
        add     a,#6
        movc    a,@a+pc
        mov     b,a
        inc     74h
        clr     rs1
        ret

0A 01 02 04 07 0A 01 0A 03 05 08 0A 02 03 0A 06
09 0B 04 05 06 0A 00 0C 07 08 09 00 0A 0A 0A 0A
0B 0C 0A 0A 12 13 32 C2 2C 53 71 BF D2 1C D2 1D

X2adf:  setb    tr1
        setb    27h.1
        setb    tf1
        setb    ea
;
        org     02ae8h
;
        clr     ea
        mov     a,5dh
        clr     c
        subb    a,r5
        mov     5dh,a
        jnc     X2afa
X2af2:  add     a,#0eh
        mov     5dh,a
        setb    27h.1
        setb    tf1
X2afa:  jz      X2af2
        setb    ea
        ret

X9ac9:  clr     a
        mov     r4,a
        mov     5eh,a
        mov     5fh,a
X9acf:  mov     r2,#2
X9ad1:  dec     r1
        mov     r3,b
        xch     a,@r1
        jbc     acc.7,X9adb
        xrl     a,#7fh
        inc     a
X9adb:  mov     b,a
        djnz    r2,X9ad1
        add     a,@r1
        mov     @r1,#0
        inc     r1
        mov     @r1,#0
        dec     r1
        xch     a,r3
        addc    a,b
        mov     r2,a
        cjne    a,5fh,X9af1
        mov     a,r3
        cjne    a,5eh,X9af1
X9af1:  jc      X9aff
        mov     a,r2
        xch     a,5fh
        mov     r5,a
        mov     a,r3
        xch     a,5eh
        mov     r4,a
        mov     a,r0
        xch     a,r6
        sjmp    X9b0e
;
X9aff:  mov     a,r2
        cjne    a,rb2r5,X9b07
        mov     a,r3
        cjne    a,rb2r4,X9b07
X9b07:  jc      X9b0f
        mov     r5,rb2r2
        mov     r4,rb2r3
        mov     a,r0
X9b0e:  mov     r7,a
X9b0f:  djnz    r0,X9acf
        lcall   X44d6
        mov     r0,a
        rl      a
        mov     r6,a
        rl      a
        add     a,r6
        add     a,r7
        ret

X44d6:  mov     a,#0fh
        mov     dph,#0
        lcall   X0565 ;???

;****************************TONE DETECT************************************
;TIMER TONE DETECT
        push    psw
        mov     c,p1.2
        rlc     a
X003e:  xch     a,rb2r4
        jc      X0045
        pop     psw
        reti
X0045:  jmp X9bd0
X0368:  reti

X9bd0:  mov     psw,#10h
        xch     a,r7
        xch     a,dph
        xch     a,r6
        xch     a,dpl
        mov     r5,a
        mov     a,#1
        xch     a,r4
        lcall   X0368
        mov     r1,#50h
        mov     r3,a
X9be3:   dec     r1
         clr     a
         movc    a,@a+dptr
         inc     dptr
         xrl     a,r3
         setb    c
         rrc     a
         movc    a,@a+pc
         addc    a,@r1
         mov     @r1,a
        cjne    r1,#40h,X9be3
        djnz    r2,X9bf8
         clr     tr0
         mov     2ah,r0
X9bf8:  mov     a,r5
        xch     a,dpl
        xch     a,r6
        xch     a,dph
        xch     a,r7
        pop     psw
        ret

FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
FF FF FF FF FF FF FF FF 00 01 01 02 01 02 02 03
01 02 02 03 02 03 03 04 01 02 02 03 02 03 03 04
02 03 03 04 03 04 04 05 01 02 02 03 02 03 03 04
02 03 03 04 03 04 04 05 02 03 03 04 03 04 04 05
03 04 04 05 04 05 05 06 01 02 02 03 02 03 03 04
02 03 03 04 03 04 04 05 02 03 03 04 03 04 04 05
03 04 04 05 04 05 05 06 02 03 03 04 03 04 04 05
03 04 04 05 04 05 05 06 03 04 04 05 04 05 05 06
04 05 05 06 05 06 06 07
x9ceb:
00 FF FE FF 01 00 00 FF 01 00 02 FF 01 FE FE FE
FF F0 FF F0 FE E0 FC E0 F8 C1 F0 C3 F0 C3 E1 87
00 07 00 0F 03 3F 07 7F 3E F0 78 E0 F0 C3 E1 87
7F FC FF F0 F8 C0 E0 01 0F 3E 3E F0 F8 C1 E3 8F
C0 01 00 0F 07 7F 3F F8 83 0F 1F 7C 78 E1 C3 0F
1F FF FF F0 F0 00 81 0F F0 83 07 3E 78 E0 C3 0F
F0 00 00 0F 1F FE FC C0 7C E0 83 0F 3C F0 87 1E
07 7F FF F0 E0 03 0F 7F 1F FC E1 07 3C F0 87 1E
FC C0 00 0F 3F FC E0 03 07 1F F0 C3 3E F8 8F 1C
01 3F FF F0 80 07 3F F8 C0 07 78 E0 1E 78 0F 3C
FF E0 00 0F 7F F0 01 0F F8 C1 3E F0 1F 78 0F 3C
00 0F FF F0 01 1F F8 C0 3E F0 1F 7C 0F 3C 1E 78
7F F8 00 0F FC E0 0F 7E 0F 3E 07 3E 0F 3C 1E 78
C0 03 FF F8 03 3F E0 03 83 0F 83 0F 07 3E 1C 70
1F FE 80 07 F8 80 7F F8 F0 83 E1 07 87 1E 3C F0
F0 00 7F F8 0F 7F 01 1F 7C E0 F0 C3 87 1F 3C F0
0F FF 80 07 F0 01 F8 C0 1F FC 78 E0 C3 0F 78 E1
F8 80 7F F8 1F FE 0F FE 07 1F 3E F0 C3 0F 78 E1
03 3F 80 07 C0 03 C0 03 C0 07 1F 7C E1 07 70 E3
FE E0 7F F8 3F F8 7F F0 F8 C1 07 3E E1 87 F0 C3
00 0F 80 07 80 07 03 1F 3E F0 83 0F E0 87 F0 C3
FF F8 7F F8 FE F0 F8 C0 0F 3E E1 07 F0 C3 E1 87
80 03 80 07 01 1F 1F FE 83 0F F0 83 F0 C3 E1 87
3F FE 7F F8 FC C0 C0 07 F0 83 F8 E1 F8 E1 E3 8F
E0 01 80 07 07 3F 7E F0 7C E0 3C F0 78 E1 C3 0F
0F FF 7F F8 F8 80 03 1F 1F FC 1F 78 78 E0 C3 0F
F8 00 C0 03 0F FF F0 80 07 1F 0F 3E 3C F0 87 1E
03 7F 3F FC E0 01 1F FC E0 07 83 1F 3C F0 87 1E
FE C0 C0 03 1F FC C0 07 F8 C1 C1 07 1E F8 8F 1C
00 1F 3F FC C0 03 FE F0 3E F8 F0 83 1E 78 0F 3C
FF F0 C0 03 7F F8 03 3F 0F 3E F8 E1 1F 7C 0F 3C
80 07 3F FC 80 0F F0 81 81 0F 3C F0 0F 3C 1E 78
7F FC C0 03 FE E0 1F FC F0 83 1F 78 0F 3C 1E 78
C0 01 3F FC 03 1F 80 07 7C E0 0F 3E 07 1E 1C 78
1F FF C0 03 FC C0 FE E0 1F 7C 83 1F 87 1E 3C F0
F0 00 3F FC 07 7F 07 3F 07 1F C1 07 83 1F 3C F0
07 7F C0 03 F0 80 F0 81 E0 07 F0 83 C3 0F 78 E1
X9b5d:  push    psw
        mov     psw,#10h
        mov     r2,#24h
        clr     a
        mov     r1,#40h
        mov     dptr,#09cebh
        mov     th0,#70h
        mov     r4,#10h
X9b6f:   clr     a
         movc    a,@a+dptr
         inc     dptr
         mov     @r1,a
         inc     r1
        djnz    r4,X9b6f
        mov     r7,dph
        mov     r6,dpl
        mov     r1,#40h
        mov     r4,#1
        anl     tmod,#0fch
        orl     tmod,#2
        mov     2ah,#4
        setb    et0
        setb    tr0
X9b8b:  jb      tr0,X9b8b
        mov     r1,#50h
X9b90:   dec     r1
         mov     a,@r1
         cjne    a,#90h,X9b95
X9b95:   mov     a,#90h
         jc      X9b9a
          xch     a,@r1
X9b9a:   clr     c
         subb    a,@r1
         mov     @r1,a
        cjne    r1,#40h,X9b90
        lcall   X9c02
        jz      X9bc8
        mov     r2,a
        lcall   X9c02
        jz      X9bc8
        dec     a
        rl      a
        rl      a
        add     a,r2
        mov     r2,a
        lcall   X4e5f
        mov     a,r2
        pop     psw
        movc    a,@a+pc
        ret
01 02 03 0C 04 05 06 0C 07 08 09 0C 0A 00 0B 0C
X9bc8:  lcall   X4e5f
        mov     a,#0ch
        pop     psw
        ret

X9c02:  mov     r5,#0
        mov     r4,#0
        mov     r3,#4
X9c08:  mov     a,@r1
        inc     r1
        add     a,@r1
        inc     r1
        cjne    a,#1eh,X9c0f
X9c0f:  jnb     2bh.4,X9c15
        cjne    a,#32h,X9c15
X9c15:  jc      X9c1f
        cjne    a,rb2r5,X9c1a
X9c1a:  jc      X9c1f
        mov     r5,a
        mov     r4,rb2r3
X9c1f:  djnz    r3,X9c08
        mov     a,r4
        ret

X4e5f:  mov     b,r0
        mov     r0,#49h
X4e63:  dec     r0
        mov     @r0,#0
        cjne    r0,#40h,X4e63
        mov     r0,b
        ret

;-------------------------------16MHz
X7b24:  push    dph
        mov     dph,#7fh
        clr     a
        movx    @dptr,a
        anl     p1,#0f0h
        orl     p1,#0
        mov     a,r3
        dec     a
        xrl     p1,#0
        xrl     p1,a
        orl     a,#50h
        mov     r0,a
        mov     a,@r0
        movx    @dptr,a
        pop     dph
        ret

X7b40:  lcall   X7b24
        mov     a,r7
        rlc     a
        mov     c,int1
        rlc     a
        mov     r7,a
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        djnz    r3,X7b69
        mov     r3,#9
        nop
X7b57:  cjne    r5,#10h,X7b65
        mov     r2,#0ffh
        mov     r4,#2fh
        nop
X7b5f:  mul     ab
        mul     ab
        mul     ab
        nop
        sjmp    X7b7f
;
X7b65:  nop
        nop
        sjmp    X7b5f
;
X7b69:  sjmp    X7b57


X7b6b:  orl     p3,#6fh
        mov     psw,#10h
        clr     ea
        mov     r5,#21h
        mov     r3,#9
        clr     a
        mov     r7,a
        mov     r2,a
        mov     dptr,#0815ah
        mov     r4,#23h
X7b7f:  mov     a,r7
        xrl     a,r2
        mov     r6,a
        mov     r1,#40h
X7b84:  nop
X7b85:  mov     c,int1
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        nop
        mov     a,r7
        rlc     a
        mov     r7,a
        mov     a,r4
        add     a,#9
        movc    a,@a+pc
        xrl     a,r6
        rrc     a
        movc    a,@a+dptr
        addc    a,@r1
        mov     @r1,a
        inc     r1
        inc     r4
        mov     a,r4
        movc    a,@a+pc
        xrl     a,r6
        clr     c
        rrc     a
        movc    a,@a+dptr
        addc    a,@r1
        mov     @r1,a
        inc     r1
        inc     r4
        mov     a,r1
        jb      acc.1,X7b84
        cjne    r1,#4ch,X7b85
        mov     c,int1
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        movc    a,@a+pc
        nop
X7bbe:  djnz    r5,X7bc3
        ljmp    X7c91
;
X7bc3:  ajmp    X7b40
00 00 00 00 00 00 00 00 00 00 00 00 FF FF FF FE
FF FC FF F8 FF F0 FF F0 FF 80 FC 00 F0 00 C0 01
80 07 01 1F C0 00 00 07 01 7F 0F FF 7F F8 FE E0
00 1F 0F FF FF F8 FC 80 C0 03 03 3F 07 FF FF F0
E0 00 01 3F 3F FC FC C0 FF FC E0 00 01 7F FF F0
E0 01 07 7F FE 00 00 3F FF F0 80 03 1F FE F8 80
00 00 7F FF C0 00 1F FF F0 00 0F FF 00 FF FE 00
03 FF F8 00 0F FF F0 00 7F FF 00 03 FF F0 01 3F
F8 80 1F FE FF C0 07 FF 80 01 FF F0 07 7F E0 01
E0 00 FF F0 07 FF 80 03 FC C0 3F FC 00 07 F0 00
FF E0 3F FE 03 3F C0 03 03 FF 00 1F 80 01 F0 00
FE E0 7F F8 FF FE 3F FF 0F FF 03 7F 01 1F 80 07
FF 00 FF 80 FF C0 FF E0 FF F0 FF F0 75 76 05 7D
x7c95:
X7c91:  mov     76h,#5
        mov     r5,#1
        mov     tl1,#8ch
        lcall   X0fb1
        setb    ea
        mov     r0,#6
        lcall   X80a8
        add     a,#6
        movc    a,@a+pc
        mov     b,a
        inc     60h
        clr     rs1
        ret
0A 01 02 04 07 0A 01 0A 03 05 08 0A 02 03 0A 06
09 0B 04 05 06 0A 00 0C 07 08 09 00 0A 0A 0A 0A
0B 0C 0A 0A 12 34 54 C2 3C 53 6B BF D2 2C D2 2D



//use         7
//optimize    6
//without *** 4
bit BeepEnd;
uchar F;//Local
uchar OldF;
uchar BeepTimeDetect;
uchar TypeBeep,BeepRepeat,LenBeep;
uchar Fmin,Fmax;//***

while (TypeBeep!=bpUnknown);
{
 F=KvantBeep();
 if (--BeepTimeDetect==0)
    TypeBeep=NoBeeps;
 if (Fmin<F&&F<Fmax&&Abs(F-OldF)<Delta)
 {
    if (FastBeepTest)
       BeepTimeDetect+=UpTimeBeepWait;
    if (LenBeep!=MaxLen)
       LenBeep++;
    else
       TypeBeep=bpVeryLong;
    BeepEnd=true;
 }
 else
 {
   if (BeepEnd)
   {
    if (MinLen<=LenBeep)
       if (LenBeep<=LenShortBeep)
       {
          if (++BeepRepeat==NBeepDetect)
             TypeBeep=bpShort;
          BeepTimeDetect+=UpTimeBeepWait;
       }
       else
          TypeBeep=bpLong;
     else
       BeepRepeat=0;
     LenBeep=0;
    }
    BeepEnd=false;
 }
 OldF=F;
}
Event=eBeepDetected;


//uchar 5
bit OldBell;
bit StartBell,EndBell;
uchar LBell,TimeKvantBell,LBellMin,LBellMax,RepeatFBell;

KvantBellDetect()
{
 if (Bell)
    OldBell=true;
 else
 {
    if (OldBell)
    {
       if (LBellMin<=LBell&&LBell<=LBellMax)
       {
          if (++RepeatFBell==StartNumberBells)
             StartBell=true;
       }
       else
       {
          if (RepeatFBell>0)
             EndBell=true;
          RepeatFBell=0;
       }
       FBell=0;
    }
    OldBell=false;
 }
 if (LBell!=0xFF)
    LBell++;
}

KvantImpulseDetect()
{
 if (Line)
 {
    if (!OldLine)
    {
       if (ImpulseNumeral!=0xFF)
          ImpulseNumeral++;
       OldLine=true;
       TimeImpulseDetect=DefaultTimeImpulseDetect;
    }
 }
 else
    if (OldLine)
    {
      OldLine=false;
      TimeImpulseDetect=DefaultTimeImpulseDetect;
     }

 if (--TimeImpulseDetect==0)
 {
    if (!OldLine)
    {
      if (DetectImpulse)
      {
        NumeralRecived=true;
        RecivedNumeral=ImpulseNumeral;
        TimeImpulseDetect=PauseTimeImpulse;
        ImpulseNumeral=0;
       }
    }
    else
    {
       LinePresent=true;
       TimeOutLineDetect=DefaultTimeOutLineDetect;
    }
 }
}
//uchar 1
uchar TimeOutLineDetect;
KvantLineDetect()
{
 if (LinePresent)
 {
  if (Line)
     TimeOutLineDetect=DefaultTimeOutLineDetect;
     OldLine=true;
  else
  {
     OldLine=false;
     if (--TimeOutLineDetect==0)
        LinePresent=false;
  }
 }
}

KvantLineOper()
{
 if (LinePresent)
 {
    KvantLineDetect();
    KvantBellDetect();
 }
 else
 {
    KvantImpulseDetect();
 }
}

0..9t-P_П*
PosCall          - position call numeral
PosEdit          - position edit
LenNumber        - length number
OffsetNumberView - start offset number view


CallNumber:
eNextNumeralCallA:
 CallSelect=false;
 if (TestEveryNumeralBeep)
 {
  BeepTesting=true;
  TimeOut=FastBeepTestTime;
  BeepEventMap=bmACallTestShortBeepMap;
  break;
 }
eNextNumeralCall:
 if (PosCall!=LenNumber)
 {
  SetCallData(GetNumeral(PosCall));
 }
 else
  Event=EndCallEvent;
 break;

eStopCallSet:
 CallSelect=false;
 TimeOut=PauseUntilNextNumeral;
 TimeOutEvent=eNextNumeralCallA;
 if (Tone)
   BeepStop();
 else
 {
   StopImpulse();
   if (--LoopImpulseCall>0)
   {
     TimeOut=LenPauseImpulse;
     TimeOutEvent=eStartCallSet;
     CallSelect=true;
   }
 }
 break;
eStartCallSet:
 TimeOut=LenImpulse;
 TimeOutEvent=eStopCallSet;
 StartImpulse();
 break;

void SetCallData(uchar NumeralCall)
{
 CallSelect=true;
 TimeOut=LenImpulse;
 if (ToneCall)
   TimeOut=LenTone;
 TimeOutEvent=eStopCallSet;
 switch(NumeralCall)
 {
  case numlPause:
       TimeOut=PauseLen;
       TimeOutEvent=eNextNumeralCall;
       break;
  case numlStarTone:
       TimeOut=LenTone;
       BeepStart(kfStar);
       return;
  case numlWaitLongBeep:
       BeepTesting=true;
       TimeOut=BeepLongWaitTime;
       BeepEventMap=bmACallWaitVeryLongBeepMap;
       return;
  case numlPristonTone:
       TimeOut=LenTone;
       BeepStart(kfPriston);
       return;
  case numlShortBeepWait:
       BeepTesting=true;
       TimeOut=BeepShortBeepTestWaitTime;
       BeepEventMap=bmACallTestShortBeepMap;
       return;
  case 0:
       LoopImpulseCall=10;
       break;
  default:
       LoopImpulseCall=NumeralCall;
 }
 if (ToneCall)
   BeepStart(NumeralCall);
 else
   StartImpulse();
}

DATA SOUND
 ALL:
      char PosWavs
      char PosNumWav
      char EventEndPlayWav
      char WavNPharse

 tsSayInt
      char WavHours
      char WavMinutes
 tsSayNumber:
      char WavN65
      char WavN43
      char WavN21
 else
   sample number

TableTypesSaying[]={tsMH0,tsMH1,tsMH2,tsMH2,tsMH2,tsMH0,tsMH0,tsMH0,tsMH0,tsMH0};
uchar GetTypeSayingMH(uchar Value)
{
  if (Value>9&&Value<20)
    return(tsMH0);
  return(TableTypesSaying[HexToDec(Value)&0xF]);
}

uchar SayInt(uint Value,uchar Pos)
{
  uchar i,SaySoundN;
  Value=HexToDecW(Value);
  switch (Pos)
  {
    case 0:
         if (!(Value&0xF00))
         {
           SaySoundN=(Value>>16)+tsv100-1;
           break;
         }
    case 1:
         if (!(Value&0x0F0))
         {
           SaySoundN=(Value>>8)&0xFF+tsv20-2;
           if (Value&0x0F0==0x010)
           {
             SaySoundN=tsv10+Value&0x00F;
             Pos=3;
             return SaySoundN;
           }
           break;
         }
    case 2:
         if (!(Value&0x00F))
         {
           SaySoundN=Value&0xFF+tsv0;
           break;
         }
         else
         {
           if (Value==0)
             SaySoundN=tsv0;
         }
  }

  for(i=Pos;i<3;i++)
  {
    if (!((Value<<i)&0xF00))
      Pos++;
  }
  Pos++;

  return SaySoundN;
}

 0                нуль   часов      минут   0        +1
 1                один   час   одна минута  1
 2                два    часа  две  минуты  2
 3                три    часа       минуты  2
 4                четыре часа       минуты  2
 5                пять   часов      минут   0
 6                шесть  часов      минут   0
 7                семь   часов      минут   0
 8                восемь часов      минут   0
 9                девять часов      минут   0
 10      десять          часов              0        +2
 11      одиннадцать     часов
 12      двенадцать      часов
 13      тринадцать      часов
 14      четырнадцать    часов
 15      пятнадцать      часов
 16      шестнаднать     часов
 17      семнадцать      часов
 18      восемнадцать    часов
 19      девятнадцать    часов

 20      двадцать        часов                  +2
 21      двадцать один   час                    +1
 22      двадцать два    часа
 23      двадцать три    часа
 24      двадцать четыре часа

 100     сто                                    +3
 101     сто один                               +2 +1
 120     сто двадцать                           +2 +2
 -20
 121     сто двадцать один                      +1 +1 +1
 -21
 --1
 111
 -11

 ++  x x x x x x
 7   xxx xx xx
 6   xx xx xx
 5   x xx xx
 4   xx xx
 3   x xx
 2   xx
 1   x

 xx:
      0x  x x
      --  x x
      -x  x x
      x-  x x
      xx  xx
 xxx: 0xx     x xx
      -xx     x xx
      xxx     xxx
      x--     x x x
      x-x     x x x
      xx-     x x x

 len pos spos
  1   0   0

  2   0   0
  2   1   0

  3   0   0
  3   1   1
  3   2   1

  4   0   0
  4   1   0
  4   2   2
  4   3   2

  5   0   0
  5   1   1
  5   2   1
  5   3   3
  5   4   3

int GetSayNumberWord(uchar Pos)
{
  int SetC;
  uchar Len=2,i,
  StartPos=((Pos+LenNumber&1)>>1)<<1,
  N=GetNumberBuff(0);

  if (Pos==0)
    if (LenNumber&1)
      Len=1;


  if (LenNumber==7)
    if (Pos<3&&N!=0&&N<10)      // only if N=1..9
    {
      Len=3;
      StartPos=0;
    }

  if ((N=GetNumberBuff(StartPos))==0)
  {
    PosX++;
    return GetNumberBuff(Pos);
  }

  for (i=0;i<LenPos;i++)
  {
    N=GetNumberBuff(StartPos);
    if (N>9)
    {
      PosX++;
      return GetNumberBuff(Pos);
    }
    SetC=SetC<<4|N;
    StartPos++;
  }

  PosX+=LenPos;
  return SetC;
}

 shl 0
       ---
     1
       clr C
       rlc A
     2
       rl A
       rl A
       anl A,#0xFC
     3
       swap A
       rr A
       anl A,#0xFE
     4
       swap A
       anl A,#0xF0
     5
       swap A
       rl A
       anl A,#0xE0
     6
       rr A
       rr A
       anl A,#0xC0
     7
       rr A
       anl A,#0x80

Search:
 mask - '_'
 Len1 - Buff number
 Len2 - Pack number
 if (Len2==0)
   return false;
 if (Compare(tcMaskBuff2))  //Black test
   return true;
 if (Compare(tcLen1Use))      //Auto search
   return true;
 if (Compare(tcSkipBigger9))  //Lock numbers

tcMaskBuff2:
 if (Len1!=Len2)
   return false;
 for (i=0;i<Len1;i++)
   if (Number[i]!=PackNumber[i])
     if (PackNumber[i]!=Mask)
       return false;
 return true;

tcLen1Use:
 if (Len1>Len2)
   return fasle;
 for (i=0;i<Len1;i++)
   if (Number[i]!=PackNumber[i])
     return false;
 return true;

tcSkipBigger9:
 if (Len1<Len2)
   return fasle;
 for (i=0;i<Len1;i++)
 {
   do
   {
     if (k++==Len1)
       return false;
   }
   while(Number[k]>9&&Number[k]!=PackNumber[i]);
   if (Number[k]!=PackNumber[i])
     return false;
 }
 return true;


Show number In/Out/ZK:
 1 - Clear number(s)
     break;
 9 - autodial
 * - next number
 # - previous number
 L0 - exit

In:  2 - show kateg
     3 - numbers calls

     4 - time call
     5 - time say
     6 - date call
     8 - set number end
     0 - say number

Out: 3 - all time say

     4 - time call
     5 - time say
     6 - date call
     8 - set number end
     0 - say number

ZK:  4 - set '-------'
     5 - start edit number
     8 - set number free number
     0 - set new number of number

mode 7 - In
mode 8 - Out
mode 9 - ZK
mode 6 1 - White
mode 6 2 - Black
mode 6 3 - Black Lock
mode 6 0 - Specical

Show number Other
 0-9 - start edit number add numeral
 * - next option
 # - previous option

Edit number
 0-9,L1-L6 - add numeral
 # - delete
 * - eSubmitNumber

 eStartEditNumber:
     EFunc = fEditNumber;
     FKey = fAutoAddNumber;
     Event = GetEventOnKey(KFunc);
     continue;

 eSubmitNumber:
     LeaveFunc();
     Event = eAutoNext;
     continue;


 EndEditNumberFunc:
     SaveNumber = true;

0 addr Nextaddr uselen
Out/ZK:
len = StartAddr+uselen-Nextaddr
In:
len = (UseNumbers-Number)*MinLen

 11 1111
if (Direction==dForward)
  number=0;
else
  number=UseNumbers;
while(1)
{
  if (Direction==dForward)
    if (number++>=UseNumbers)
      break;
  else
    if (number--==0)
      break;

  LoadNumber(number,Book);
  if (DateNumber==CurrDate)
    SayNumber();
}

------------------------------------------------------------------------
Start:
BCall=true;
if ((number=SearchNumber(nbChangeNumber,snLenChangeNumber))!=-1)
  LoadNumber(number);
SetTimeDateCall();
SaveNumber(bBookIn,0);
SaveDefaultNumber();

Event=eEndBeep;
if (Night)
  SoundPlay=false;
if (Black)
  SoundPlay=false;
if (White)
  SoundPlay=true;
if (BlackLock)
  Event=eExitToMain;
if (ModeCalled==mcPagerRecall)
  Event=ePagerRecall;
if (ModeCalled==mcReaddressingAll||
  ModeCalled==mcReaddressingTime||
  ModeCalled==mcReaddressingNumber||)
  Event=eReaddressing;
DontPlaySounds=true;
if (SayingNumbers)
  Event=eSayingNumbers;


eStartBeep:
 SoundOff();
 BeepStart();
 LineSoundOn();
 Timer1sA=TimeLenBeep;
 TimeOut1sA=eEndBeep;
 break;

eEndBeep:
 BeepStop();
 LineSoundOff();
 if (SoundPlay&&CurrLoopSnd)
 {
   if (TypeCurrSnd)
     Event=eStartBell;
   else
     Event=eSayNumber;
   TypeCurrSnd++;
 }
 else
 {
   CurrLoopSnd=true;
   Event=eToneTest;
   if (ListenLine)
     SoundOn();
 }
 break;


eReaddressingNumber:
 if (ModeCalled==modeTimeReaddress)
 {
    Event=eReaddressingTime;
    continue;
 }
 LoadNumber(nbReaddressing,bSpecical);
 Say(phrOnNumber,Event);
 break;
eReaddressingTime:
 if (ModeCalled==modeNumberReaddress)
 {
    Event=eRepeatPhrase;
    continue;
 }
 Say(phrInTime,LoadOption(oReaddressTime),0,eRepeatPhrase);
 break;

ePagerRecall:
// recall on pager xxxxx
 SoundLine();
 LoadNumber(bBookSpecical,nbPagerNumber);
 Say(phrRecallOnPager,ePagerRecallContinue);
 break;
ePagerRecallContinue:
// for abonent xxxx
 LoadNumber(bBookSpecical,nbPagerAbonent);
 Say(phrForAbonent,eExitToMain);
 break;

eSetNoSoundPlay:                                        //0
 SoundPlay=false;
 break;
eSetSoundPlay:                                          //1
 SoundPlay=true;
 break;
eSetListenLine:                                         //2
 ListenLine=true;
 SoundPlay=false;
 if (BeepTesting)
 {
   StopPlay();
   SoundOn();
 }
 break;

eSayLineCurrPhrase:
 Event=EventOfModeKey(skBeepEmulation);
 SoundLine();
 StopBeepTesting();
 continue;

eRecallLater:                                           //6
 EventPhrRepeat=Event;
 Say(phrRecallLater,eRepeatPhrase);
 break;
eRecallTomorrow:                                        //7
 EventPhrRepeat=Event;
 Say(phrRecallTomorrow,eRepeatPhrase);
 break;
eRecallInTimeLater:                                     //8
 EventPhrRepeat=Event;
 Say((Hours+2)%24,0,phrRecallInTime,eRepeatPhrase);
 break;
eNumberUndefined:                                       //9
 EventPhrRepeat=Event;
 Say(phrNumberUndefined,eRepeatPhrase);
 break;

eRepeatPhrase:
 Event=EventPhrRepeat;
 if (PhrRepeat-->0)
   Event=eExitToMain;
 continue;

eRemoteAccess:
 break;
------------------------------------------------------------------------
call
indification

Bell
{
Beep
SayNumber/Bell
Beep
ToneBeepTest
Beep
}

Sound to room:
 amplifer on
 sound off
 sndtoline off
Sound to line:
 amplifer off
 sound off
 sndtoline on
Sound from line:
 amplifer on
 sound on
 sndtoline off

(only tone&requests)
Sound to line & room:
 amplifer on
 sound off
 sndtoline on

start:
if (SndToLine==off)
  Amplifer=on;
else
  Amplifer=off;
Sound=off;

if (Xsound=on)
{
  Amplifer=on;
  Sound=on;
}
else
  Amplifer=off;

if (t>=12)
  t-=12;
if (t==0)
  t=12;
0 - 12
1 - 1
11 - 11
12 - 12
13 - 1

AONModeSelect
 NumberReaddressing
 TimeReaddressing
 PagerReaddressingNumber
 PagerReaddressingAbonent
BackCallSelect
 BackCallNumber
NightSelect
 NightData
FilterEdit

eEditNight:
eEditReaddressing:
eEditBCallNumber:


night Select:
 # - eEditAONMode
 * - eNextOption
 a* - eAutoNext2ByOn
...
night BCalls:
 # - ePrevious
 * - eEditAONMode
 a* - eEditAONMode

oBCall:
 * - eNextOption
 # - ePreviousOption
 a* - eAutoNext2ByOn
 a2* - eEditBCallNumber

case eEditReaddressingNumber:
     Event=LoadValueN(oAONMode);
     if (Event==modeFullReaddressing||
         Event==modeNumberReaddressing)
     {
       Event=eEditReaddressingTime;
       continue;
     }
     MinOption=mnReaddressingNumber;
     MaxOption=mxReaddressingNumber;
     Event=eEnterOption;
     continue;

case eEditReaddressingTime:
     Event=LoadValueN(oAONMode);
     if (Event==modeFullReaddressing||
         Event==modeTimeReaddressing)
     {
       Event=eEditAONMode;
       continue;
     }
     MinOption=mnReaddressingTime;
     MaxOption=mxReaddressingTime;
     Event=eEnterOption;
     continue;

case eEditPagerReaddressing:
     MinOption=mnPagerReaddressing;
     MaxOption=mxPagerReaddressing;
     Event=eEnterOption;
     continue;

ReaddressingNumber
 * - eEditReaddressingNumber
 # - eEditAONMode
 a# - eEditAONMode
 a* - eEditReaddressingNumber
ReaddressingTime
 * - eEditAONMode
 # - eEditAONMode
 a# - eEditAONMode
 a* - eEditAONMode



//BCall
if (LineSetToPresent)
if (EFunc==fMain&&BackCall)
{
  BackCall=false;
  Event=eBCallStart;
  break;
}

BackCall=LoadValueN(oBCallSelect);
if (NCall>0&&!LoadValueN(oAnswerback))
  BackCall=false;
saying:
if (!LoadValueN(oAnswerback))
  BackCall=false;


case eBCallStart:
     LeaveAllFunc();
     EFunc=fBackCall;
     EndCallEvent=eBCallStartTest;
     LoadNumber(nbBCallNumber,bBookSpecical);
     Event=eAutoDial;
     continue;
case eBCallStartTest:
#define LenTimeBCallStartTimeDetect 180
     LeaveFunc();
     LineUp();
     BeepTesting=true;
     BeepEventMap=bmBCallStart;
     BeepTimeDetect=LenTimeBCallStartTimeDetect;
     break;
case eBCallSay:
     if (LoopBCallRepeats--==0)
     {
       Event=eExitToMain;
       continue;
     }
     LineSoundOn();
     ViewOff=true;
     LoadNumber(0,bBookIn);
     SayNumber(phrNumber,eBCallBeepTest);
     break;
case eBCallBeepTest:
#define LenTimeBCallPauseSaying 2
     BeepTesting=true;
     BeepEventMap=bmBCallSaying;
     BeepTimeDetect=LenTimeBCallPause;
     break;

//Enter
case fBackCall:
     LoopDial=LoadOption(oAutoACall);
#define RepeatLoopBCall 20;
     LoopBCallRepeats=RepeatLoopBCall;
     break;
//Leave
case fBackCall:
     StopBeepTesting();
     LineDown();
     break;

; none shrt long vlong
BCallStartBT:
 db eBCallStart,eBCallStart,eBCallSay,eBCallStart
BCallSayingBT:
 db eBCallSay,eExitToMain,eBCallSay,eExitToMain

xxx +1  0 1
xx0 +1  0 1
x0x +2  1 2
x00 +3  2 1
000 +3  3 0

0xx +2  1 1
0x0 +3  2 1
00x +3  2 1
000 +3  3 0

00x +3  2 1
000 +3

bit ParallelNumber,ParallelDetect

uchar ToneNumeral; //Local
uchar OldTN,ToneNumeral;

if (ToneDetect&!SoundPlaying)
{
  KvantData=KvantTone();
  if (!Calling)
  {
    if (KvantData.ToneNumeral!=OldTN)
      ToneNumeral=OldTN;
    else
    {
      if (ToneNumeral!=tnNoNumeral)
      {
        EndReciveNumeral=true;
        RecivedNumeral=ToneNumeral;
      }
      ToneNumeral=tnNoNumeral;
    }
    OldTN=KvantData.ToneNumeral;
  }
}

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
//    if (RemoteAccess)
//    {
//      Event=eRemoteAccessKey;
//      break;
//    }
  }
}

case eAddNumeralParallel:
     if(!ParallelNumber)
     {
       SetDefaultLenNumberBuff(0);
       PosCall=0;
       SaveDefaultNumber();
       ParallelNumber=true;
       if (EFunc==fMain)
         EFunc=fParallelDetect;
     }
     if (PosCall!=MaxLenNumber)
       PosCall++;
     SetDefaultLenNumberBuff(PosCall);
     SetDefaultNumeralBuff(PosCall,RecivedNumeral);
     Timer1sB=LenTimeWaitBeforeAutoStartAutoDial;
     Timer1sBEvent=eStartSayingData;
     if (EFunc==fParallelDetect)
       if ((OffsetNumberView=LenNumber-MaxNumeralView)&0x80)
         OffsetNumberView=0;
     XchBuff();
     XchBuff();
     break;

case eStopSayingData:
     ParallelNumber=false;

void SaveDefaultNumber(void)
{
  if (!ParallelNumber)
  {
    ...
  }
}
// printf("%io.%s",ImpulseNumeral,NumberToStr());
// 0o.1234567
// Пo.1234567
0 1 2 3
L H H H
H L L L



#define LenTimeBeforeUnLockLine  3
enum LockType  {lCall,lParallel};

case eAddNumeralParallel:
     if (TestLock(lParallel))
     {
        Event=eEnterLock;
        continue;
     }
case eAdd_CallNumeralBuff:
     if (TestLock(lCall))
     {
        Event=eEnterLock;
        continue;
     }
case eAutoDial:
     if (TestLock(lCall))
     {
        Event=eEnterLock;
        continue;
     }

case eEnterLock:
     LeaveAllFunc();
     EFunc=fLockNumber;
     Event=eTestLineFree;
     continue;
case eTestLineFree:
     if (ParallelTest())
       LeaveAllFunc();
     Timer1sA=LenTimeBeforeUnLockLine;
     Timer1sAEvent=eTestLineFree;
     Error=true;
     break;

//Enter
case fLockingCall:
     LineUp();
     break;
//Leave
case fLockingCall:
     LineDown();
     break;

bit LockOn,LockCallAll,LockCountryCode,LockNumbers;

bit TestLock(bit locktype)
{
  if (LockOn)
  {
    if (LockCallAll||locktype==lParallel)
    {
      if (LockNumbers)
        if (SearchNumber(nbLockNumbers,nbLenLockNumbers,bBookSpecical,tcbSkipBigger9)!=-1)
          return true;
      if (LockCountryCode)
      {
        char ln=LoadDefalultNumber(dfnLenNumber),ps,
             lockbyte=LoadValueN(oCountryCode);
        for (pos=0;pos<ln;pos++)
        {
          char CurrByte;
          if ((CurrByte=GetByte(pos))>0)
            if (CurrByte==lockbyte)
              return true;
        }
      }
    }
  }
  return false;
}

ChangeNumber
test lock black
test black
test white
tcbMaskBuff2,tcbLen1Use,tcbSkipBigger9,tcbFreeSearch

ValueEdit=SearchNumber(nbChangeNumber,nbLenChangeNumber,bBookSpecical,tcbMaskBuff2);
if (ValueEdit!=-1)
  LoadNumber(nbChangeNumberTo+ValueEdit,bBookSpecical);
SoundsPlay=!Night;
if (SearchNumber(0,MaxNumbersBlack,bBookBlack,tcbMaskBuff2)!=-1)
  BlackNumber=true;
if (SearchNumber(0,MaxNumbersWhite,bBookWhite,tcbMaskBuff2)!=-1)
  SoundsPlay=true;

if (SearchNumber(0,MaxNumbersBlackLock,bBookBlackLock,tcbMaskBuff2)!=-1)
  Event=eExitToMain;


//Мелодии
X0C07:  dec     A
X0C08:  mov     DPTR,#MelodyTBL         ;MelodyTable //7d9f
        rl      A
        push    PSW
        anl     PSW,#0xE7
        lcall   X39EC                   ;GETDPTR
;        mov     74H,#0
        mov     R1,#0xFF
        setb    2EH.7
X0C1B:  push    DPH
        push    DPL
        lcall   X39EB                   ;GETDPTR
        clr     A
        movc    A,@A+DPTR
        mov     R5,A
        clr     F0
X0C27:  inc     DPTR
X0C28:
        ;jb      PSW.1,X0C3D
        ; mov     A,#6BH
        ; add     A,74H
        ; movc    A,@A+PC
        ; jz      X0BBB
        ; xrl     A,#0DAH
        ; mov     R0,#58H
X0C36:  ;  xch     A,@R0
        ;  dec     R0
        ; cjne    R0,#4FH,X0C36
        ; inc     74H
X0C3D:  mov     A,#1
        movc    A,@A+DPTR
        mov     R0,A
        clr     A
        movc    A,@A+DPTR
        mov     R4,A
        jnb     F0,X0C83
         inc     R6
         mov     A,R6
         dec     A
         jz      X0C75
         dec     A
         jz      X0C67
         dec     A
         jz      X0C5B
          mov     R6,#0
          mov     A,R4
          anl     A,#0FCH
          rr      A
          rr      A
          sjmp    X0C79

X0C5B:  mov     A,R4
        swap    A
        anl     A,#0FH
        mov     R2,A
        mov     A,R0
        swap    A
        anl     A,#30H
        orl     A,R2
        sjmp    X0C79

X0C67:  mov     A,R4
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
X0C75:  lcall   X2D96           //DECDPTR
        mov     A,R4
X0C79:  jnz     X0C83
         clr     F0
         inc     DPTR
         movc    A,@A+DPTR
         jnz     X0C83
          inc     DPTR
          movc    A,@A+DPTR
X0C83:  cjne    A,#0FFH,X0CB4
;         jb      PSW.1,X0C96
;          lcall   X1332                   ;STOPPLAY
;          mov     A,#0CH
;          lcall   X41A5
;          jnc     X0C28
;          lcall   X485A
X0C96:   mov     R1,#0FFH
         ljmp    X0B3C
TBLA:
 DB 0xe9,0xfd,0xa3,0xe2,0xa2,0x9a,0x81,0xe5,0xe5,0xe5,0x82,0xda,0xe3,0x82,0xd5,0xda
 DB 0x9a,0xe9,0xfd,0xa3,0xe2,0xa2,0x9a,0xda,0x00

X0CB4:  mov     R4,A
        cjne    A,#3DH,X0CBC
         setb    2EH.7
X0CBA:   ajmp    X0C27
X0CBC:  cjne    A,#3EH,X0CC3
         clr     2EH.7
         sjmp    X0CBA
X0CC3:  cjne    A,#3FH,X0CCD
         setb    F0
         mov     R6,#0
         ljmp    X0D5E
X0CCD:  mov     R0,DPH
        mov     R2,DPL
        anl     A,#3FH
        cjne    A,#3CH,X0CF2
         lcall   X1342
         mov     R1,#0FFH
         sjmp    X0D2F

X0CDD:   mov     A,70H
         mov     B,#0AH
         div     AB
         add     A,#5
X0CE5:   movc    A,@A+PC
         lcall   X29A6          //STARTPLAY
         sjmp    X0D2F
 DB 0x0f,0x0f,0x08,0x04,0x02,0x01,0x01

X0CF2:  mov     B,#0CH
        div     AB
        inc     A
        xch     A,B
        anl     A,#0FH
        cjne    A,RB0R1,X0D00
        sjmp    X0D2F
;
X0D00:  mov     R1,A
        orl     PSW,#10H
        inc     R3
        anl     RB2R3,#7
        mov     A,R3
        jnz     X0D0E
;         lcall   X53D4
X0D0E:  mov     A,RB0R1
        rl      A
        mov     DPTR,#0937DH
        lcall   X39EC
X0D17:   mov     A,R7
         clr     C
         rrc     A
         mov     R7,A
         mov     A,R6
         rrc     A
         mov     R6,A
        djnz    B,X0D17
        cpl     A
        mov     R6,A
        mov     A,R7
        cpl     A
        mov     R7,A                     ;R67=~(ROM[937D+A]>>B)

        anl     PSW,#0EFH
        jb      23H.2,X0CDD
;        lcall   X297D
X0D2F:  mov     DPL,R2
        mov     DPH,R0
        jnb     24H.6,X0D43
         mov     A,RB3R3
         cpl     A
         jnz     X0D43
          clr     27H.7
          pop     ACC
          pop     ACC
          ajmp    X0B4D

X0D43:  mov     A,R4
        jnb     F0,X0D48
         mov     A,R7
X0D48:  anl     A,#0C0H
        mov     R7,A
        rl      A
        rl      A
        inc     A
        mov     R0,A                    ;R0=(A>>6)+1;
X0D4F:   mov     A,R5
         rrc     A
         rrc     A
         rrc     A
         anl     A,#1FH
         add     A,R5
         lcall   X13BE                  ;WAIT A
        djnz    R0,X0D4F
        jnb     2EH.7,X0D60
X0D5E:   mov     R1,#0FFH
X0D60:  ajmp    X0C27

X13C8:  mov     A,#0AH
        sjmp    X13D9
X13D9:  mov     67H,A
X13DB:  ;lcall   X3C24
        mov     A,67H
        jnz     X13DB
        ret

X0BBB:  ajmp    X0B39
X0B39:  ;lcall   X13C8
X0B3C:  pop     DPL
        pop     DPH
        inc     DPTR
        inc     DPTR
        clr     A
        movc    A,@A+DPTR
        inc     A
        jnz     X0B4B
         mov     A,#1
         movc    A,@A+DPTR
         inc     A
X0B4B:  jnz     X0B56
X0B4D:   pop     PSW
         pop     DPH
         pop     DPL
         ljmp    X1332
X0B56:  ljmp    X0C1B

//OUT: r76b=dptr=ROM[DPTR]
X39EB:  clr     A
//OUT: r76b=dptr=ROM[DPTR+A]
X39EC:  mov     RB2R6,A
        movc    A,@A+DPTR
        mov     RB2R7,A
        mov     A,RB2R6
        inc     A
        movc    A,@A+DPTR
        mov     DPL,A
        mov     RB2R6,A
        mov     DPH,RB2R7
        ret

//stopplay
X1332:  mov     B,DPH
        anl     29H,#3
        lcall   X5B63
        mov     DPH,B
        clr     23H.3
        clr     24H.1
X1342:  clr     TR0
        clr     ET0
        ret
X5B63:  clr     C
        anl     C,/23H.4
        anl     C,/2DH.4
        orl     C,25H.2
        mov     INT1,C
        mov     DPH,#0BFH
        clr     EA
X5B71:  mov     A,29H
        movx    @DPTR,A
        setb    EA
        ret

X41A5:  mov     RB2R6,A
X41A7:   mov     6EH,#0AH
X41AA:   ;lcall   X3C24
         jb      22H.3,X41BA
         jb      27H.7,X41BC
         mov     A,6EH
         jnz     X41AA
        djnz    RB2R6,X41A7
X41BA:  clr     C
        ret
X41BC:  setb    C
        ret

X485A:  jbc     27H.7,X4862
        ;lcall   X3C24
X4860:  setb    C
        ret
X4862:  ;lcall   X487F
        mov     A,6DH
        clr     C
        ret
//decdptr
X2D96:  dec     DPL
        mov     A,DPL
        cjne    A,#0FFH,X2D9F
         dec     DPH
X2D9F:  ret

//startplay
//IN: A - len
X29A6:  jb      27H.3,X29AC
         jnb     27H.5,X29B7
X29AC:   mov     A,3BH
        jnb     ACC.2,X29B5
         mov     A,#4
         sjmp    X29B7
X29B5:  mov     A,#0AH
X29B7:  jz      X29E2
        rl      A
        rl      A
        rl      A
X29BC:  anl     29H,#3
        mov     RB2R0,29H
        mov     RB2R2,A
        mov     2AH,#8
        mov     RB2R1,#0BFH
        jb      27H.5,X29E3
        jb      27H.3,X29E3
        setb    23H.3
X29D2:  anl     TMOD,#0FCH
        orl     TMOD,#1
        mov     TL0,#0FFH
        mov     TH0,#0FFH
X29DE:  setb    ET0
        setb    TR0
X29E2:  ret
X29E3:  setb    24H.1
        sjmp    X29D2

MelodyTBL: dw Melody1
Melody1: dw Melody1A,-1
Melody1A:
 db 0x32,0xd0,0x4e,0x4c,0xce,0x4c,0x4e,0xd0,0x53,0x50,0xce,0xff,0x82,0x71,0x82,0x71
 db 0x82,0x71,0x82,0x71,0x82,0x71,0x82,0x71,0x82,0x71,0x82,0x71,0xff,0xff,0x30,0x1a
 db 0x3f,0x5d,0xa8,0x75,0xa1,0xd6,0x85,0x5a,0x17,0x6a,0x5d,0x08,0x00,0xff,0x82,0x93
 db 0x82,0x93,0x82,0x93,0x82,0x93,0x82,0x93,0x82,0x93,0x82,0x93,0x82,0x93,0xff,0xff
 db 0x30,0x1d,0x3f,0x5f,0xf8,0x85,0x5f,0xf7,0x85,0x5f,0xf8,0x75,0x5f,0xf8,0x85,0x1f
 db 0x00,0xff,0x82,0xb7,0x82,0xb7,0x82,0xb7,0x82,0xb7,0x82,0xb7,0x82,0xb7,0x82,0xb7
 db 0x82,0xb7,0xff,0xff,0x30,0x1c,0x3f,0x1f,0x17,0x72,0x1f,0x17,0x72,0x1f,0x17,0x72
 db 0x1f,0x17,0x02,0xff,0x82,0xcb,0xff,0xff,0x60,0x1d,0x3f,0x5f,0xf8,0x85,0x1f,0x00
 db 0x5d,0xff,0x82,0xd9,0xff,0xff,0x40,0x3d,0x49,0x4c,0x50,0x4c,0xce,0x4c,0x4b,0xd0
 db 0xce,0x3e,0xc9,0x3d,0x49,0x7c,0x4c,0x50,0x53,0x53,0xd5,0x53,0x51,0x3e,0xd0,0x90
 db 0x7c,0xd0,0xd4,0x57,0x55,0xd0,0x50,0x7c,0x4c,0x4b,0x50,0x4e,0xd1,0x51,0x7c,0x53
 db 0x51,0xd0,0x4e,0x4c,0xd0,0xce,0xc9,0xff,0x83,0x21,0x83,0x3f,0x83,0x21,0x83,0x43
 db 0x83,0x47,0x83,0x47,0x83,0x21,0x83,0x3f,0x83,0x21,0x83,0x3f,0xff,0xff,0x38,0x3d
 db 0x13,0x11,0x13,0x0e,0x0a,0x0e,0x47,0x13,0x11,0x13,0x0e,0x0a,0x0e,0x47,0x13,0x15
 db 0x16,0x15,0x16,0x13,0x15,0x13,0x15,0x11,0x13,0x11,0x13,0xff,0x38,0x0f,0x53,0xff
MTBL2:
 db 0x35,0x83,0x32,0x82,0x2F,0xAC,0x2C,0xFF,0x2A,0x79,0x28,0x17,0x25,0xD7,0x23,0xB7
 db 0x21,0xB6,0x1F,0xD1,0x1E,0x08,0x1C,0x59,0xC0,0xD0,0xC5,0x17,0x53,0x29,0x03,0x45
 db 0x29,0xF5,0x29,0xF2,0xE5,0x10,0x25,0x4C,0xF5,0x10,0xE5,0x11,0x35,0x4D,0xF5,0x11
 db 0x10,0xE7,0x27,0x24,0x2B,0x83,0xF5,0x14,0xE5,0x12,0x25,0x4E,0xF5,0x12,0xE5,0x13

 db 0x35,0x4F,0xF5,0x13,0x10,0xE7,0x0C,0x24,0x17,0x83,0x25,0x14,0x54,0xFC,0xC5,0x17
 db 0xD0,0xD0,0x32,0x24,0x0B,0x83,0x64,0x7F,0x80,0xF0,0x24,0x04,0x83,0x64,0x7F,0x80
 db 0xD5,0x40,0x41,0x43,0x44,0x46,0x47,0x49,0x4A,0x4C,0x4D,0x4F,0x50,0x52,0x53,0x55
 db 0x56,0x58,0x59,0x5B,0x5C,0x5D,0x5F,0x60,0x61,0x63,0x64,0x65,0x67,0x68,0x69,0x6A

 db 0x6B,0x6C,0x6D,0x6F,0x70,0x71,0x72,0x73,0x73,0x74,0x75,0x76,0x77,0x78,0x78,0x79
 db 0x7A,0x7A,0x7B,0x7B,0x7C,0x7C,0x7D,0x7D,0x7D,0x7E,0x7E,0x7E,0x7F,0x7F,0x7F,0x7F
 db 0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7E,0x7E,0x7E,0x7D,0x7D,0x7D,0x7C,0x7C,0x7B
 db 0x7B,0x7A,0x7A,0x79,0x78,0x78,0x77,0x76,0x75,0x74,0x73,0x73,0x72,0x71,0x70,0x6F

 db 0x6D,0x6C,0x6B,0x6A,0x69,0x68,0x67,0x65,0x64,0x63,0x61,0x60,0x5F,0x5D,0x5C,0x5B
 db 0x59,0x58,0x56,0x55,0x53,0x52,0x50,0x4F,0x4D,0x4C,0x4A,0x49,0x47,0x46,0x44,0x43
 db 0x41,0x83,0x22,0xA0,0x0B,0x90,0xFD,0x05,0xFE,0x00,0x00,0xBC,0x00,0xBC,0x00,0xBD
 db 0x0C,0x98,0x01,0x08,0x01,0x01,0x20,0x01,0x05,0x0D,0x01,0x00,0xE4,0xFE,0x01,0xFE

8534 8534 859C 85F1 85F4 8600 8603 8534
859C 85F1 85F4 8600 8603 FFFF
Melody2:
 dw Melody2A,Melody2A,Melody2B,Melody2C,Melody2D,Melody2E,Melody2F,Melody2A
 dw Melody2B,Melody2C,Melody2D,Melody2E,Melody2F,-1
Melody2A:
 db 0x1C,0xE1,0x64,0x61,0xDC,0x61,0x5C,0xD8,0x5C,0x58,0x3E,0xD5,0x3D,0xD5,0x50,0x3F
 db 0x15,0x56,0x5D,0xD5,0x55,0x51,0x97,0x76,0x61,0x17,0x56,0x01,0xE1,0x64,0x61,0xDC
 db 0x61,0x5C,0xD8,0x5C,0x58,0x3E,0xD5,0x3D,0xD5,0x58,0x57,0xD8,0x58,0x57,0xD8,0xE1
 db 0x98,0x1A,0xD8,0xD7,0x5C,0x5B,0xDC,0x5C,0x5B,0xDC,0xE4,0x9C,0x1D,0xDC,0xDB,0x57
 db 0x3F,0xDC,0xC7,0x79,0x9C,0xC7,0x6D,0x5E,0xE8,0x7D,0xDE,0xE7,0x71,0x1F,0xB7,0x71
 db 0x21,0xB7,0x71,0x23,0xB7,0x71,0x24,0xB7,0x71,0xE4,0x18,0x8E,0x9F,0xC7,0x01,0xDF
 db 0x1E,0x1F,0x5E,0x3E,0xDC,0x3D,0xDC,0xFF
Melody2B:
 db 0x1C,0xDC,0x5F,0x5C,0xD7,0x5C,0x57,0xD3,0x57,0x53,0x3E,0xD0,0x3D,0xD0,0xD5,0xD4
 db 0xDA,0xD9,0xDF,0x5D,0x5C,0xDD,0xDA,0xDD,0x61,0x5D,0xDA,0x5D,0x5A,0xD7,0x5A,0x57
 db 0x3E,0xD3,0x3D,0xD3,0xD8,0x5C,0x3F,0x98,0x86,0x69,0xD8,0xA5,0x75,0x1A,0xA7,0x71
 db 0x1A,0xC6,0x61,0x17,0xD6,0x61,0x17,0xF6,0x61,0x17,0x16,0x62,0x17,0x16,0x7E,0xDD
 db 0xC7,0x69,0x18,0x00,0xDC,0x1A,0x1C,0x5A,0x3E,0xD8,0x3D,0xD8,0x5C,0x5A,0xDC,0x5C
 db 0x5A,0xDC,0xE4,0xDC,0xFF
Melody2C:
 db 0x0E,0x1D,0xFF
Melody2D:
 db 0x38,0x5C,0x5A,0x1A,0x18,0x5A,0x1A,0x18,0x5A,0x63,0x5A,0xFF
Melody2E:
 db 0x0E,0x1C,0xFF
Melody2F:
 db 0x38,0x5A,0x58,0x61,0x24,0x21,0x1F,0x3E,0xDD,0x3D,0x5D,0x21,0x1D,0x1C,0x3E,0xDA
 db 0x3D,0x5A,0x1D,0x1A,0x18,0xD6,0x16,0x15,0x16,0x15,0xD4,0x51,0x50,0x55,0x54,0x5A
 db 0x18,0x3F,0x17,0x56,0x61,0x1C,0x00,0x61,0x5C,0x1A,0x18,0x17,0x18,0xD5,0xFF

Melody3: db Melody3A
Melody3A:
 db 0x34,0x0D,0x3F,0x11,0x95,0x75,0x54,0xD6,0x35,0x11,0x95,0x75,0x54,0xD6,0x35,0x8F
 db 0xB5,0x79,0xD6,0xE6,0x35,0x8F,0xB5,0x79,0xD6,0xE6,0x31,0x0F,0xB5,0x79,0xD4,0xE6
 db 0x31,0x0F,0xB5,0x79,0xD4,0xE6,0x35,0x11,0x95,0x75,0x54,0xD6,0x35,0x11,0x95,0x75
 db 0x54,0xD6,0x35,0x91,0xD5,0x89,0x56,0x27,0x36,0x91,0xD5,0x89,0x56,0x27,0x36,0xCF
 db 0x64,0x6D,0x93,0xB5,0x35,0xCF,0x64,0x6D,0x93,0xB5,0x31,0x0F,0xB5,0x81,0xD4,0x06
 db 0x32,0x0F,0xB5,0x81,0xD4,0x06,0x32,0x4D,0x44,0x65,0x11,0x95,0x31,0x4D,0x44,0x65
 db 0x11,0x95,0x29,0x4D,0x44,0x65,0x11,0x95,0x29,0x4D,0x44,0x65,0x11,0x95,0x0D,0xCA
 db 0x33,0x65,0xCF,0x94,0x0D,0xCA,0x33,0x65,0xCF,0x94,0x21,0xCC,0x43,0x61,0x0F,0x85
 db 0x21,0xCC,0x43,0x61,0x0F,0x85,0x21,0x4B,0x44,0x69,0x11,0xA5,0x21,0x4B,0x44,0x69
 db 0x11,0xA5,0x19,0xCA,0x63,0x6D,0x8F,0xB5,0x19,0xCA,0x63,0x6D,0x8F,0xB5,0x19,0xC9
 db 0x23,0x61,0x8F,0x84,0x19,0xC9,0x23,0x61,0x8F,0x84,0x15,0x48,0x43,0x65,0x0D,0x95
 db 0x15,0x48,0x43,0x65,0x0D,0x95,0x15,0x86,0xD2,0x48,0x4A,0x23,0x15,0x86,0xD2,0x48
 db 0x4A,0x23,0x0D,0x86,0xD2,0x48,0x4A,0x23,0x0D,0x86,0xD2,0x48,0x4A,0x23,0x51,0x03
 db 0xC2,0x48,0x08,0x23,0x51,0x03,0xC2,0x48,0x08,0x23,0x05,0x05,0xD2,0x44,0x48,0x13
 db 0x05,0x05,0xD2,0x44,0x48,0x13,0x05,0xC8,0xD2,0x44,0x4B,0x13,0x05,0xC8,0xD2,0x44
 db 0x4B,0x13,0x49,0x86,0xD2,0x44,0x4A,0x13,0x49,0x86,0xD2,0x44,0x4A,0x13,0x4D,0x81
 db 0xD2,0x40,0x4A,0x03,0x4D,0x81,0xD2,0x40,0x4A,0x03,0x51,0x04,0xD3,0x40,0x4C,0x03
 db 0x51,0x04,0xD3,0x40,0x4C,0x03,0x55,0x06,0xD3,0x3C,0x4C,0xF3,0x54,0x06,0xD3,0x3C
 db 0x4C,0xF3,0x50,0x06,0xC2,0x3C,0x08,0xF3,0x50,0x06,0xC2,0x3C,0x08,0xF3,0x50,0x05
 db 0xD2,0x44,0x48,0x13,0x51,0x05,0xD2,0x44,0x48,0x13,0x51,0x03,0xD2,0x48,0x48,0x23
 db 0x51,0x03,0xD2,0x48,0x48,0x23,0x51,0x03,0xC2,0x48,0x08,0x23,0x51,0x03,0xC2,0x48
 db 0x08,0x23,0x51,0x84,0xD2,0x4C,0x4A,0x33,0x51,0x84,0xD2,0x4C,0x4A,0x33,0x51,0x05
 db 0xD2,0x50,0x48,0x43,0x51,0x05,0xD2,0x50,0x48,0x43,0x51,0x03,0xD2,0x48,0x48,0x23
 db 0x51,0x03,0xD2,0x48,0x48,0x23,0x51,0x03,0xC2,0x48,0x08,0x23,0x51,0x03,0xC2,0x48
 db 0x08,0x23,0x35,0x01,0xB2,0x44,0xC8,0x12,0x35,0x01,0xB2,0x44,0xC8,0x12,0x35,0x81
 db 0xA1,0x34,0x52,0xA3,0x34,0x8A,0xA1,0x18,0x83,0x31,0x04,0x0C,0x85,0x6D,0xDE,0x86
 db 0x6D,0x18,0x85,0x3D,0x52,0xF4,0x00,0x3E,0xCD,0xCD,0xCD,0x3D,0xCD,0xFF

 88A6 88AA 88D6 88AA 8A19 FFFF
Melody4: dw Melody4A,Melody4B,Melody4C,Melody4B,Melody4D,
 8A29 FF FF
Melody5: dw Melody5A

Melody4A:
 db 0x36,0x0F,0x0C,0xFF
Melody4B:
 db 0x36,0x0F,0x3F,0x13,0xB6,0x69,0xD8,0x35,0x5D,0xDA,0xD7,0x6D,0xDA,0x86,0x6D,0x1F
 db 0x79,0x9A,0xA4,0x49,0x8E,0xE1,0xD7,0x6D,0xDA,0x86,0x6D,0x1F,0x79,0x9A,0xE4,0xF8
 db 0x8D,0xE6,0x9A,0x9E,0xE6,0x49,0x9E,0x2B,0x3C,0xCB,0x00,0xFF
Melody4C:
 db 0x36,0x30,0x3F,0x32,0xFC,0xB6,0x6B,0x7A,0x9A,0x27,0xF9,0x6D,0x18,0xBC,0x9E,0x6C
 db 0x54,0x61,0x1D,0x48,0x9E,0xA6,0xD8,0x69,0x96,0x9B,0x9A,0xEB,0x33,0x59,0xDB,0x27
 db 0x9A,0x64,0x08,0x86,0x64,0x08,0x86,0x27,0xF9,0x85,0x27,0xF9,0x85,0x26,0xE9,0x85
 db 0x2D,0xE9,0x85,0x2A,0xA9,0x85,0x64,0xE8,0x69,0xE2,0xA1,0x38,0x93,0x55,0x4D,0x92
 db 0x23,0x55,0x1A,0x66,0x55,0xD6,0x64,0x69,0x9F,0x18,0x7E,0xE1,0xE7,0x71,0x1A,0x66
 db 0x55,0xD6,0x64,0x69,0x9F,0x18,0x7E,0x9E,0xE6,0x85,0x26,0x29,0x86,0xE2,0x27,0x9A
 db 0xAB,0xDB,0xAE,0xED,0xAA,0xA2,0x26,0x29,0x86,0xE2,0x27,0x9A,0xAB,0x29,0x7E,0xD1
 db 0x6A,0x8E,0xDF,0x68,0xAE,0xE4,0xB7,0x7E,0xE4,0xB7,0x7E,0xE3,0x97,0x7E,0xE3,0x97
 db 0x7E,0x27,0x79,0xAE,0xF0,0x7A,0x92,0x16,0xBC,0xA2,0x24,0xBA,0xC2,0x29,0x09,0x93
 db 0x29,0x09,0x93,0x28,0xE9,0x92,0x28,0xE9,0x92,0x6C,0x81,0x30,0x11,0x35,0x45,0x10
 db 0x03,0x4D,0x98,0x45,0x4D,0x54,0x44,0x61,0x1D,0xF8,0x75,0x5F,0xC7,0x69,0x98,0x45
 db 0x4D,0x54,0x44,0x61,0x1D,0xF8,0x75,0x1C,0xC6,0x7D,0xA4,0x08,0x7E,0x60,0x07,0x92
 db 0x29,0xBB,0xA6,0x6B,0x8A,0x9A,0xA4,0x08,0x7E,0x60,0x4A,0x82,0x1D,0x09,0x76,0x18
 db 0xD8,0x61,0x54,0x87,0x51,0x00,0x3E,0xCD,0x3D,0xCD,0x2C,0x3F,0x29,0x9A,0xAE,0x29
 db 0x9A,0x02,0x3E,0xCC,0x3D,0xCC,0x20,0x3F,0x1D,0xD7,0x7D,0x1D,0xD7,0x01,0x3E,0xCB
 db 0x3D,0xCB,0x32,0x3F,0xE9,0xCA,0xAE,0xE9,0x69,0x9E,0x2B,0xBC,0xBA,0xEC,0x9A,0x02
 db 0xE7,0xE6,0x24,0x3F,0xDF,0xFA,0x91,0xDF,0xFA,0x8D,0x5F,0xFA,0x8D,0xDF,0xFA,0x89
 db 0x1F,0xFA,0x89,0x1F,0xFA,0x85,0x27,0x7C,0x86,0x27,0x7C,0x82,0x9D,0xD9,0x81,0x9D
 db 0xD9,0x7D,0xA5,0x5B,0x7E,0xA5,0x5B,0x7A,0x1B,0xB9,0x79,0x1B,0xB9,0x6D,0x24,0x4C
 db 0x6E,0x24,0x4C,0x6E,0xE4,0xB9,0xC2,0xF7,0x0C,0xDF,0x33,0xFC,0xA5,0xE6,0xD8,0x6D
 db 0x0C,0x00,0xFF
Melody4D:
 db 0x36,0x2F,0x3F,0xF0,0x7A,0x9A,0xE4,0xB7,0x69,0x00,0x18,0xFF

Melody5A:
 db 0x40,0x0C,0x3F,0xD0,0x54,0x59,0xD5,0x04,0x31,0xD0,0x54,0x59,0xD5,0x04,0x45,0x15
 db 0xA6,0x6D,0x1A,0x56,0x31,0xD0,0x54,0x59,0xD5,0x04,0x4D,0x97,0xC6,0x75,0x9C,0x76
 db 0x45,0x15,0xA6,0x6D,0x1A,0x56,0x31,0xD0,0x54,0x59,0xD5,0x04,0x01,0x4C,0xFF,0x8A
 db 0x5C,0xFF,0xFF,0x3A,0x10,0x3F,0x15,0x54,0x61,0x15,0xC6,0x61,0x1D,0x87,0x55,0x17
 db 0x84,0x5D,0x14,0x54,0x41,0xD8,0xC5,0x43,0x15,0x54,0x61,0x15,0xC6,0x61,0x1D,0x87
 db 0x55,0x17,0x84,0x5D,0x14,0x54,0x41,0x54,0xC5,0x4F,0xD8,0x84,0x71,0x18,0xF7,0x71
 db 0xE1,0xC7,0x61,0xDA,0xC4,0x69,0xD7,0x84,0x4D,0x9C,0xC6,0x4F,0xD8,0x84,0x71,0x18
 db 0xF7,0x71,0xE1,0xC7,0x61,0xDA,0xC4,0x69,0xD7,0x84,0x4D,0x17,0x06,0x00,0xFF,0x8A

824F+ 8518+ 86E8+ 889A+ 8E90+ 9049+ 90F0 8366
81CF 830B 7E1F 83B4 84D3 843A 82D5 7DDF
7DE3 7DE7 7DEB 7DEF 7DF3 7DF7 7E07 7E13
7E1B 825F 8281 82A5 8CA8 824F 8236 82C7

7E39 FFFF 7E69 FFFF 7EAE FFFF 7F28 FFFF
7F4D FFFF 7F80 FFFF 8035 806B 8068 8035
8073 8068 807A FFFF 80D4 80D4 80E4 80D4

MelodyX:                        ;82C7
 dw MelodyXA,-1
MelodyXA:
 db 60,0x1D,0x3F,0x5F,0xF8,0x85,0x1F,0x00,0x5D,0xFF
8293 8293 8293 8293 8293 8293 8293 8293

MelodyY:                        ;8281
 dw MelodyYA,MelodyYA,MelodyYA,MelodyYA,MelodyYA,MelodyYA,MelodyYA,MelodyYA,-1
MelodyYA:
 db 0x30,0x1D,0x3F,0x5F,0xF8,0x85,0x5F,0xF7,0x85,0x5F,0xF8,0x75,0x5F,0xF8,0x85,0x1F
 db 0x00,0xFF

MelodyZ:                        ;8236
 dw MelodyZ,-1
MelodyZA:
 db 0x11,0x1F,0x3C,0x1C,0x3C,0x19,0xFF

MelodyQ:                        ;82C7
 dw MelodyQA,-1
MelodyQA:
 db 0x60,0x1D,0x3F,0x5F,0xF8,0x85,0x1F,0x00,0x5D,0xFF

15 23
00001111 11111111
00001100 00000000
      xx       xx
12 00
Melody7A 9150
Melody7B 9169
Melody7C 9190
Melody7D 919C
Melody7E 91A0
Melody7F
Melody7E
Melody7E


Melody7:


Melody7A,Melody7B,Melody7A,Melody7B,Melody7C,Melody7D,Melody7C,Melody7E,
Melody7A,91B9 91CE 91F0 91CE 9201 91CE 91F0
91CE 9201 9211 921E 9211 9231 9211 921E
9211 9231 9242 9257 9242 937A 9264 9271
9286 9271 9264 9211 921E 9292 91CE 91F0
91CE 9201 91CE 91F0 91CE 9201 92AC FFFF

Store:
SelectBook: 1,2,3,7,8,9
"Store 9"
* - Enter

Password:
#define PWDEvent ValueData[2]
 Level0:
  eEnterOption:
  if (AONLocked)
    if (LoadValueN(oPasswordOn)&&LoadValueN(oAONLock)==aonlMainModes)
    {
      PWDEvent=Event;
      Event=eEnterPassword;
      break;
    }
 Level1:
  eKeyPresent:
  if (AONLocked)
    if (LoadValueN(oPasswordOn)&&LoadValueN(oAONLock)!=0)
    {
      PWDFKey=FKey;
      Event=eEnterPassword;
      break;
    }

case eEnterPassword:
     EFunc=fEnterPassword;
     EnterFunc();
 AONLocked=false;
 LenEdit=4;
 TypeOfData=false;
//     PlayMelody
     EFunc=fShowPasswordTest;
     Event=eEditCharBuff;
     continue;
case ePasswordSubmit:
     LeaveFunc();
 AONLocked=true;
     if (ValueEdit!=LoadValueN(oPassword))
     {
       Error=true;
       break;
     }
 AONLocked=false;
     PWDFKey=FKey;
     Event=eKeyPresent;
     AONLocked=false;
     continue;
case eAONLock:
     AONLocked=true;
     break;

#define LenWaitBeforeLock 10
EnterMain:
LenWaitBeforeLock;
  if (!AONLocked&&LoadValueN(oAONLock)!=0)
  {
    Timer1sA=LenWaitBeforeLock;
    Timer1sAEvent=eAONLock;
  }

0bf 0ff 09f
01011111 11111111 10011111
 baxxxxx bbbbbbbb xccbbbbb

xxyyyyyy

x - len play
y - note play
0:
 temp
1:
 0xff: end melody
 0x3c: Pause
 0x3d: ModeX enable
 0x3e: ModeX disable
 0x3f: ModeY enable

0x4220

0x18EA

SetDate:
 Day:
 Month:
 Year:
  kfAutoNext,eSetDate
SetTime
 Hours:
  kfAutoNext,eHoursSet
 Minutes:


case eSetDate:
     if (OptChanged)
       SetPICDate(Day,Month,Year);
     Event=eNextOption;
     continue;

case eHoursSet:
     if (OptChanged)
       SetPICTime(Hours,-1,-1);
     GetPICTime();
     Event=eNextOption;
     continue;
case eMinutesSet:
     if (OptChanged)
       SetPICTime(Hours,Minutes,0);
     GetPICTime();
     MelodyPlay(mldySettedTime,eNone);
     Event=eNextOption;
     continue;
Err.12C509

TestNight:
               mov ParamLL,#oNightOn
               CALL LoadValueN
               cjne ParamLL,#0,NoNightOff
                clr Night
                clr C
                ret
NoNightOff:
               mov ParamLL,#oNightFromHour
               CALL LoadValueN
               push ParamLL
               mov ParamLL,#oNightFromMin
               CALL LoadValueN
               push ParamLL
               mov ParamLL,#oNightToHour
               CALL LoadValueN
               push ParamLL
               mov ParamLL,#oNightToMin
               CALL LoadValueN
               mov MBud2,ParamLL
               pop HBud2
               pop MBud1
               pop HBud1

               mov HoursBud,$PRMBD TestNight
               mov MinutesBud,$PRMBD TestNight+1
               call TestTime
               mov Night,C
               ret

HBud2=_R+3 ;EndHours
MBud2=_R+2 ;EndMinutes
HBud1=_R+1 ;StartHours
MBud1=_R+0 ;StartMinutes
#define HoursBud   _R+7
#define MinutesBud _R+6
TestTime:
STestTime:mov R5,HBud2
          mov R4,MBud2
          call BiggerTime
          mov CompBitB,C
;   CompBitB=Bigger(H,H,H2,H2)
          mov R5,HBud1
          mov R4,MBud1
          call BiggerTime
          mov CompBitA,C
;   CompBitB=Bigger(H,H,H1,H1)
          mov R7,HBud2
          mov R6,MBud2
          call BiggerTime
;   CompBitB=Bigger(H2,H2,H1,H1)
          jnc NoBiggerH
           mov C,CompBitA
           anl C,/CompBitB
           ret

NoBiggerH:
          clr A
          mov C,CompBitA
          rlc A
          mov C,CompBitB
          subb A,#0
          cpl C
          ret

BiggerTime:
; 88.       if (H2!=H1)
;        MOV     $LOCBD Bigger,R7
;        MOV     A,R7
;        xrl A,R6
;        XRL     A,$LOCBD Bigger+2
;        JZ      e?0004
;e?0003:
; 89.         if (H2>=H1)
        mov A,R7
;        CLR     C
        cjne A,_R+5,e?Ex1
         MOV     A,R6
         CLR     C
         SUBB    A,R4
e?Ex1:
        cpl C
        ret

if (StartTime<EndTime)
{
//  if (Time>=StartTime&&Time<EndTime)
//    return true;
//  else
//    return false;
  return (Time>=StartTime&&Time<EndTime);
}
else
  return (!(Time>=EndTime&&Time<StartTime));
//  if (Time>=EndTime&&Time<StartTime)
//    return false;
//  else
//    return true;

bit CompTimeC(h1,m1,h2,m2)
if (C)
  return (t1<t2);
else
  return (t1<=t2);

mov HComp1,StartH
mov MComp1,StartM
mov HComp2,EndH
mov MComp2,EndM
call CompTime
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
 call CompTime
NoBiggerStart:
 jnb InvertResult,NoInverResult
  cpl C
NoInverResult:
 ret

CompTime:
 clr C
CompTimeC:
 mov A,MComp1
 subb A,MComp2
 mov A,HComp1
 subb A,HComp2
 cpl C
 ret

-Hchar
-Jsize,alg,compl
-Hff -J2,0,2

300ms - 2400
300ms - 1800
600ms - 2400

200ms - 1550
200ms - 1300
200ms - 1100

300ms - 2583
300ms - 1879

30ms - 4000
30ms - 3000

180ms - 4180
185ms - 3130
190ms - 2630

if (SearchNumber(nbAreaCode,1,bBookSpecical,nbUseLenPack)!=-1);
{
  LoadNumber(nbAreaCode,bBookSpecical);
  AC_TmpLen=LenNumber;
  LenNumber=LoadDefaultNumber(dfnLenNumber);
  for(AC_i=0;AC_i<LenNumber-AC_TmpLen;i++)
    SetNumberBuffA(GetNumberBuff(AC_i+AC_TmpLen),AC_i);
  LenNumber-=AC_TmpLen;
}

ValueEdit
                 if ((ValueEdit=FindTodayCall(ValueEdit,Book,DirectionSay))!=-1)
                   SayNumber(phrNumberSay,eNextNumberSayInTime);


case eEnterRemoteAccess:
     RemoteAcess=true;
     break;
case eRemoteAccesKey:
     SoundToLine();
     if (AONLocked&&LoadOption(oPassOn))
     {
       Event=eEnterPassword;
       continue;
     }
     SayKey(phrSay0_B,RecivedNumeral,eSayVideoData);
     FKey=RecivedNumeral;
     continue;
case eSayVideoData:
     SayPhrase(SayVideoPhrase[VFunc],eNone);
     break;
;------------------------------------------------------------------------------
 SayIntcv,Address,StartValue
 SayMemI,Address,StartValue

tsInccv
tsSetWavDatacv
tsSetWavDataMemI,MemI,1
tsSetWavDataMemI0,MemI


//............................................................................
Оределение параллельного телефона                                   (++)
Блокировка номеров                                                  (++)
 - номеров                                                          (+)
 - межгород                                                         (+)
Поиск                                                               (++)
 - ЧС                                                               (+)
 - БС                                                               (+)
 - СС                                                               (+)
 - подмена                                                          (+)
 - блокировка номеров                                               (+)
 - поиск пустого(store)                                             (+)
 - Входящие                                                         (+)
 - Исходящие                                                        (+)
 - Поиск неопределенных                                             (+)
Мелодии                                                             (++)
 - сами мелодии                                                     (+)
 - hold                                                             (+)
 - будильники                                                       (+)
 - звонки                                                           (+)
 - заставка                                                         (+)
Другое                                                              (+-)
 - Фильтр                                                           (+)
 - режим sound                                                      (+)
 - режим захвата линии                                              (+)
 - работа с массивами(будильники)                                   (+)
 - АнтиАОН                                                          (+)
 - Автопоиск/поиск                                                  (+)
 - режим настройки даты/времени                                     (+)
 - Store                                                            (+)
 - пароли                                                           (+)
 - Ночь                                                             (+)
 - звоноки                                                          (+)
 - опция "неопр"                                                    (+)
   - очистка неопр. номеров в 00:00                                 (+)
   - игнорировать занесение неопр. номеров                          (+)
 - обнуление некоторых опций                                        (+)
 - Звук при просмотре исходящих если дата номера != дате            (+)
 - Кнопка Volume                                                    (+)
 - шаблон города                                                    (+)
 - прослушивание параллельного тел.("Listn. x")                     (+)
 - Общее время разговоров(счет)                                     (+)
 - Общее число звонков(счет)                                        (+)
 - Обнуление к-ва звонков в 00:00                                   (+)
 - звуки кнопок                                                     (+)
 - звук Error                                                       (+)
 - режим точной настройки часов ("h.xx-xx-xx")                      (+)
 - при поднятии трубки говорить номер("Say.HP.-x")                  (+)
 - работа с ячейками C0-C5                                          (+)
 - кнопка 8 в книжках                                               (+)
 - Conf                                                             (+)
 - (поиск) Вход в книжку на найденную ячейку                        (+)
 - точка в последнем разряде если есть непросмотренные номера       (+)
 - Автодозвон из выбранной ячейки                                   (+)
 - Переадресации перезвониет завтра/позже
 - Мелодия будильника кукушка
Спикер&труба                                                        (++)
 - автодозвон                                                       (+)
 - эмуляция АТС(Выдача гудков в линию)                              (+)
 - Flash                                                            (+)
 - режимы                                                           (+)
 - Hold                                                             (+)
 - GetLine                                                          (+)
 - труба                                                            (+)
 - ложение трубки если идут короткие гудки > 1 мин                  (+)
Часы                                                                (+-)
 - Работа с ExternalClock                                           (+)
 - ночь                                                             (+)
 - очистка неопр. номеров в 00:00                                   (+)
 - будильники                                                       (+)
 - "кукушка"                                                        (+)
 - коррекция
Запуск                                                              (+-)
 - Проверка инициализации флешки                                    (+)
 - Проверка пзу
 - Проверка часов                                                   (+)
 - Обнуление данных                                                 (+)
 - Заставка                                                         (+)
 - Полная проверка флешки
Батарейки                                                           (++)
ДУ                                                                  (++)
 - Восприятие                                                       (+)
 - Проговаривание                                                   (+)
 - Полная ДУшка                                                     (+)
 - Ламо-ДУшка                                                       (+)
//............................................................................
ADD                                                                 (+-)
 - Автоответчик
 - Время разговоров по межгороду
 - Параллельное управление
 - Параллельное отключение будильника                               (+)
 - Прослушивание помещения                                          (+)
 - Настройка гудков/запросов
  - Громкости гудка
  - Формы (синус/меандр/мелодия)
 - Время ожидания следующей цифры при определения параллельного тел.
 - Опция ожидания длинного гудка перед набором (автодозвон)
 - Опция ожидания длинного гудка после цифры выхода на межгород
   (автодозвон)
 - Плавное поднятие громкости звонка
 - Звонок параллельных ???
 - Connect
 - Засылка номера
 - МиниАТС
 - Транспейджер
 - Калькулятор
 - Определение номера во время разговора
//............................................................................
ADD2
 - Сделать коррекцию времени                                        (+)
 - Переделать короткие гудки
 - Опция реакции на звонок без линии
//............................................................................


       if (BeepTesting&&!(SoundToLine&&SndPlaying))
       {
          if (Fmin<=KvantData.BeepFreq&&KvantData.BeepFreq<=Fmax
              &&AbsC(KvantData.BeepFreq-OldBeepFreq)<=DeltaBeep)
          {
            if (PauseBeep)
            {
              if (LenPeriod>MinLenPeriod)
              {
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
          }
          else
          {
            PauseBeep=true;
            if (LenPeriod>MinLenPeriod)
            {
              if (++LenPeriod==LenLongPeriod)
              {
                TypeBeep=bpLong;                                //Long
                BeepTesting=false;
              }
            }

          }
          OldBeepFreq=KvantData.BeepFreq;
470 - max 1000
0.002127
0.001 - min
T=1333
LI=T/2=666
#define MinTBeep 666
if (LineData!=OldLineData)
{
  Impulse++;
  OldTX=TX;
  while (TX-OldTX<MinT)
  {
   if (OldLineData==LineData)
   {
     Impulse--;
     break;
   }
  }
  OldLineData=LineData;
}
xxLineEQ:
          mov A,TL2
          add A,#2
          mov OldTL2,A
          mov A,TH2
          addc A,#0
          mov OldTH2,A
          ret

        jb LineData,xxLine1
        jnb OldLineData,xxLineNoEQ
         jmp  xxLineEQ
         xxLine1:
         jnb OldLineData,xxLineEQ

xxLineNoEQ:
            mov A,TL2
            add A,#6
            clr C
            subb A,OldTL2
            mov B,A
            mov A,TH2
            subb A,OldTH2
            xch A,B
            cjne A,#Low(MinTBeep),$+3
            mov A,B
            subb A,#High(MinTBeep)
            jc NoIncImpulse
             inc XImpulse
             mov C,LineData
             mov OldLineData,C
NoIncImpulse:
            ret
1/(0.025/(35/2))

if (Hours==0&&Minutes==10)
  TestDayChange();


550*8+250*8+(100*4)*4=8000 [8192]
200*8+200*8+(100*4)*2=4000 [4096]
100*8+100*8+100*4-100=1900 [2048]

50 50 50 100 50

void TestDayChange()
{
  if (Day!=LoadValueN(oODay)&&Month!=LoadValueN(oOMonth))
  {
    ClearUndefinedNumbers();             //Clear Undefined
    SaveValue(oTodayCalls,0);            //ClearTodayCallCounter
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
      SetClockTime(NowHours,NowMinutes,NowSeconds);
    }

    GetClockTimeDate(clkwDate);          //Get Date
    SaveValueN(oODay,Day);
    SaveValueN(oOMonth,Month);
  }
}
