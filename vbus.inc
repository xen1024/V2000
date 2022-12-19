/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

// Commands
#define clcmdGetTime            0
#define clcmdGetDate            1
#define clcmdSetTime            2
#define clcmdSetDate            3
#define clcmdSetPowerDownMode   4
#define clcmdClearPowerDownMode 5

//#define GetTime                0
//#define GetDate                1
//#define SetTime                2
//#define SetDate                3
//#define SetPowerDownMode       4
//#define ClearPowerDownMode     5

#define GetTimeLen                4
#define GetDateLen                6
#define SetTimeLen                4
#define SetDateLen                5
#define SetPowerDownModeLen       2
#define ClearPowerDownModeLen     2

#define CalltoPIC           0
#define WaitCallFromPIC     1
#define Wait1ms             2
#define StartBitWait        3
#define NextBitWait         4
#define SecondBitSendWait   5
#define StopBitGetWait      6
#define StopBitSendWait     7
#define FirstBitSendWait    8
#define FirstBitGetWait     9

#define ModeNone            0ffh


#define LoopReinitBeforeError 250