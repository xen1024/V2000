/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

/*#define VideoOut (*(char*)0x017fff) */
/*#define SoundOut (*(char*)0x01Bfff) */
/*#define MaxNumberInZK (*(char*)0x0101F0) */

#define MaxNumbIn 301+2
#define MaxNumbZK 301+2+1+1+1
#define LenIn LenPackIn*(MaxNumbIn+1)
#define LenZK LenPackZK*(MaxNumbZK+1)
#define EndIn       StartIn+LenIn
#define EndZK       StartZK+LenZK
#define LenPackIn 7
#define LenPackZK 19
#define StartIn     0x0000
#define StartZK     EndIn+1
#define OptionData  EndZK+1
/*#define NumbBuff1   0x0000+13+16+20*/
/*#define NumbBuff0   0x0000+0x1f00 */
/*#define BuffNumber  0x0000         */
/*#define BuffMin     BuffNumber+10  */

/*extern idata char BuffNumberA[7+1+5+15+1];*/
extern idata char BuffNumberA[7];

#define ABuffString    7+1+5

#define BuffStringA    BuffNumber[7+1+5]
#define BuffKategA     BuffNumber[8]
#define NumbParametrsA BuffNumber[8]
#define BuffMinA       BuffNumber[9]
#define BuffHourA      BuffNumber[10]
#define BuffDayA       BuffNumber[11]
#define BuffMonthA     BuffNumber[12]

#define RegisterMemoryHi 0xff
#define BuffNumber    BuffNumberA
#define BuffString    BuffNumber[7+1+5] + RegisterMemoryHi*0x100
#define BuffKateg     BuffNumber[8]     + RegisterMemoryHi*0x100
#define NumbParametrs BuffNumber[8]     + RegisterMemoryHi*0x100
#define BuffMin       BuffNumber[9]     + RegisterMemoryHi*0x100
#define BuffHour      BuffNumber[10]    + RegisterMemoryHi*0x100
#define BuffDay       BuffNumber[11]    + RegisterMemoryHi*0x100
#define BuffMonth     BuffNumber[12]    + RegisterMemoryHi*0x100
