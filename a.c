/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

#include "io51.h"
#pragma language=extended
#define TheBeginNumber 0xB
#define PovtorByte 0xc
#define MutViewByte 0xb

 char OpN(void);
 bit Bigger(char H2,char M2,char H1,char M1);
/* const char BN[37]={1,2,0xc,7,2,3,9,4,0xb,1,2, 0xf,0xf,0xf,0xf,1,
                    0xf,0xf,0xf,0xf,0xf,2,0xf,1, 0xf,0xf,0xf,0xf,0xf,0xf,2,
                    0xf,2,0xf,1,0xf,0xf}; */
/* const char BN[37]={2,0xc,7,2,3,9,4,0xb,1,2, 0xf,0xf,0xf,0xf,0xf,
                    0xf,0xf,0xf,0xf,0xf,0xf,0xA,0xA, 0xf,0xf,0xf,0xf,0xf,0xf,0xf,
                    0xf,0xf,0xf,0xf,0xf,0xf}; */
 const char BN[37]={0xB,1,2,0xC,7,2,3,4,9,0xB, 0x1,0x2,0xf,0xf,0xf,
                    0xf,0xf,0xf,0xf,0xf,0xf,0xA,0xA, 0xf,0xf,0xf,0xf,0xf,0xf,0xf,
                    0xf,0xf,0xf,0xf,0xf,0xf};
 const char xx[9]={4,9,3,2,7,PovtorByte,2,0xff,1};
 bit ViewIt;
 bit NoCall;
 data int StartNumbIn;

 idata char BuffNumber[7];
 idata char ValueData[5];
 idata char OverNArray[1];

 bit OldEqual0,OldEqual1;


enum ec {
         False,
         True
        };

 data unsigned int M0,M1,M2;
 void main(void)
 {
   char xH2,xM2,xH1,xM1,xH,xM;
   bit A,B;


   IE=0;


   OpN();


   xH1=1,xM1=2;
   xH2=3,xM2=0;
   xH=3,xM=0;


   /* H1=23:00 H=1:20 H2=09:00 */
   /* B=0 A=0 */
   /* C=0 */

   B=Bigger(xH,xM,xH2,xM2); /* If (H>H2) B=1 else B=0 */
   A=Bigger(xH,xM,xH1,xM1); /* If (H>H1) A=1 else A=0 */

   if (Bigger(xH2,xM2,xH1,xM1)) /*C*/ /* If (H2>H1) C=1 else C=0
      NoCall=A&!B;
   else
      NoCall=(A&B)|(!A&!B);
              /* 00 0 1 1*/
              /* 01 0 0 0*/
              /* 10 0 0 0*/
              /* 11 1 0 1*/
   xH=2;

/*  TestOnSendAnswer(12); */
/*  if (M0==0xffff|M0<M1)
     M0=M2;

  if (M0>M2)
     M0=M1; */
 }

#define Ok   0
#define NoOk 1
#define MaxDoubleCx 2-1
#define MutByte 0xF

 bit Bigger(char H2,char M2,char H1,char M1)
   {
/*    signed char Hx=H2-H1,Mx=M2-M1;
    if (Hx!=0)
      if (Hx>=0)
       return(True);
      else
       return(False);
    else
      if (Mx>=0)
       return(True);
      else
       return(False); */

/* H2:M2 H1:M1 */
/* C=1 H2:M2>=H1:M1 */
    if (H2!=H1)
      if (H2>=H1)
       return(True);
      else
       return(False);
    else
      if (M2>=M1)
       return(True);
      else
       return(False);
   }
/*
xx12c7394b
x12ffff1f
xffff2f1f
xfffff2f2

x12ff2f1f
*/

 const char OprCode[66]={0xf,0xb,0xb,0x1,0x1,0x1,0x2,0x2,0x2,0x2,0xc,0xc,0xc,
 0xc,0x7,0x7,0x7,0x2,0x2,0x2,0x2,0x3,0x3,0x3,0x3,0x9,0x9,0x9,0x4,0x4,0x4,
 0x4,0xb,0xb,0xb,0x3,0x1,0x1,0x1,0x2,0x2,0x2,0x2,0x1,0xf,0xf,0xf,
 0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf};

/* f1f-2ff2 f 1 | 12c7394b 12ffff1f ffff2f1f fffff2f2 f1ff */
/* fbb1112222cccc777222233339994444bbb311122221fff */
/* fffffffffff131fffffffff9ff2ff1f2f2f1ff11fff232fff3ffffff2ff2fff2ff1ff11 */
/* fffffffffffffffffffffffffffffffffffffff4fffffff1fffffffffffff */

/* 12c7384b12 fffff */
/* 10 10 10 20 20 21 c1 c1 42 72 73 73 23 23 34 34 34 35 95 95 95 96 46 46 47 */
/* b7 b8 b8 18 */

/* 111222cc4777223339999444bbb11 */
/* 00001112233334445556667788889 */
/* 0000+00+0+000+00+00+00+0+000+ */
char OpN(void)
  {
   data char Nloop=0,Ax=0,Ncifra,Mut=0,Ncifra1;
   data char Ay,Cifra,OldCifra,xd=0;
   idata char PriorityNumb[4];
  Ncifra1=0;
  do
   {
    OldEqual0=0;
    OldEqual1=0;
    Cifra=OprCode[xd++];
/*    Cifra=OPRED_C();
/*    OverNArray[Ncifra+30-7]=Cifra; */
    if ((Cifra&0xF0)<=MinQuality)
       Cifra=MutByte;
    Cifra&=0xF;       */

    if (OldCifra==Cifra) OldEqual0=1;
    if (OverNArray[Ncifra1-1]==Cifra) OldEqual1=1;
    if (Cifra==MutByte)
       Mut++;
    else
      {
       if (Cifra==TheBeginNumber||OldEqual0)
         {
          if (!OldEqual1)
            {
             if (OverNArray[Ncifra1-1]==MutByte&&Mut==2)
               Ncifra1--;
             OverNArray[Ncifra1]=Cifra;
             Ncifra1++;
            }
          Mut=0;
         }
       else
         {
          if (OldEqual1) Mut=0;
          else Mut++;
          OldCifra=Cifra;
         }
      }
    if (Mut==2)
      {
       OverNArray[Ncifra1]=MutByte;
       Ncifra1++;
      }
    if (Mut==3) Mut=0;


   }
  while (Ncifra1<36); /* Ncifra++, */
  EA=1; /*!!!!!!!!!!*/

  Ncifra=0;
  do
   {
    OverNArray[Ncifra]=BN[Ncifra];
   }
  while (Ncifra++,Ncifra!=36);

  /*выбор адресов*/
  Ncifra=0;
    do
     {
      Cifra=OverNArray[Ncifra];
      if (Cifra==TheBeginNumber||Nloop==8)
       {
        ValueData[Ax]=Ncifra-8;
        if (Cifra!=TheBeginNumber) Ncifra--;
        Ax++;
        Nloop=0xFF;
       }
      Nloop++;
     }
    while (Ncifra++,Ncifra!=36&&Ax!=4);

  Ncifra=8;
  do
   {
    Ncifra--;
    for (Ax=0;Ax!=3;Ax++)
      PriorityNumb[Ax]=0;
    Ax=0;
    do
     {
      Ay=Ax;
#define VAx OldCifra
#define VAy Mut
#define OverNArrayVAxNcifra Cifra
      VAx=ValueData[Ax]+Ncifra;
      OverNArrayVAxNcifra=OverNArray[VAx]; /* +Ncifra */
      if (!(VAx&0x80))
      if (OverNArrayVAxNcifra!=MutByte)
       {
        do
         {
          VAy=ValueData[Ay];
          if (OverNArrayVAxNcifra==OverNArray[VAy+Ncifra])
           {
            PriorityNumb[Ax]++;
            if (OverNArray[VAy+8]==TheBeginNumber) PriorityNumb[Ax]++;
           }
         }
        while (Ay++,Ay!=4);
       }
     }
    while (Ax++,Ax!=4);

    Mut=0;
    for (Ax=0;Ax!=3;Ax++)
     {
      if (PriorityNumb[Ax]>=Mut)
       {
        Ay=Ax;
        Mut=PriorityNumb[Ax];
        Ncifra1=7-Ncifra;
        if (Ncifra1==7) Ncifra1++; /*!!!*/
        BuffNumber[Ncifra1]=OverNArray[ValueData[Ax]+Ncifra];
       }
     }
   }
  while (Ncifra!=0);

/*  Ncifra++; */
/*#define OldNcifra1 Mut */
  do
   {
    Ncifra1=BuffNumber[Ncifra];
    if (Ncifra1==PovtorByte) Ncifra1=OldCifra;
/*    if (Ncifra1==MutByte) Ncifra1=MutViewByte; */
    if (Ncifra1>9) Ncifra1=MutViewByte; /* =MutByte */
    OldCifra=Ncifra1;
    BuffNumber[Ncifra]=Ncifra1;
   }
  while (Ncifra++,Ncifra!=8);
 }