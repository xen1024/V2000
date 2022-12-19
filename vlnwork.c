/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

#include <v2000.h>
//#define VAx Ncifra1
//#define VAy Mut
//#define OverNArrayVAxNcifra Cifra
//#define OverNArray Number+4
#define LenBuffIndCode 33
void GetAnswerAndDecode(char FirstByteSet)
{
  data char Nloop=0,Ax=0,Ncifra=0,Mut=0,Ncifra1,
  Ay,Cifra,PriorityNumb[4],OldCifra,
  VAx,VAy,OverNArrayVAxNcifra;
  bit OldEqual0,OldEqual1;

  Ncifra1=0;

  if (FirstByteSet!=opnMutByte)
  {
    SetNumberBuffA(Ncifra1,FirstByteSet);
    OldCifra=FirstByteSet;
//    VideoBuffer[0][1]=FirstByteSet;
    Ncifra1++;
  }

 /* generation opr code end*/
 /* 0-сырой код */
 /* 1-полученый */
/* ********************* */
   do
   {
     OldEqual0=0;
     OldEqual1=0;
/* 28 20 21 c0 c0 c1 70 70 71 20 20 21 30 30 31 90 90 91 40 40 41 b0 b1 b0 */
/* 10 10 11 */
/* 222ccc777222333999444bbb111 */
/* 010010010010010010010100010 */
    Cifra=NumeralDetect();
/*    OverNArray[Ncifra+30-7]=Cifra; */
/*
    if ((Cifra&0xF0)<=MinQuality)
       Cifra=MutByte;
    Cifra&=0xF;
*/
     if (OldCifra==Cifra) OldEqual0=1;
     if (GetNumberBuff(Ncifra1-1)==Cifra)
       OldEqual1=1;
     if (Cifra==opnMutByte)
       Mut++;
     else
     {
       if (Cifra==opnBegin||OldEqual0)
       {
         if (!OldEqual1)
         {
           if (GetNumberBuff(Ncifra1-1)==opnMutByte&&Mut==2)
             Ncifra1--;
           SetNumberBuffA(Ncifra1,Cifra);
           Ncifra1++;
         }
         Mut=0;
       }
       else
       {
         if (OldEqual1)
           Mut=0;
         else
           Mut++;
         OldCifra=Cifra;
       }
     }
     if (Mut==2)
     {
       SetNumberBuffA(Ncifra1,opnMutByte);
       Ncifra1++;
     }
     if (Mut==3)
       Mut=0;
   }
   while (Ncifra1<LenBuffIndCode);

   Ncifra=0;
   do
   {
     Cifra=GetNumberBuff(Ncifra);
     if (Cifra==opnBegin||Nloop==8)
     {
//    if (BuffNumber[5]==0xFF)
//       BuffNumber[5]=Cifra; /*DEBUG*/
       ValueData[Ax]=Ncifra-8;
       if (Cifra!=opnBegin)
         Ncifra--;
       Ax++;
       Nloop=0xFF;
     }
   }
   while (Nloop++,Ncifra++,Ax!=4); /*Ncifra!=36&& */
//  BuffNumber[0]=ValueData[0];
//  BuffNumber[1]=ValueData[1];
//  BuffNumber[2]=ValueData[2];
//  BuffNumber[3]=ValueData[3];
//  BuffNumber[4]=OverNArray[0];

   OldCifra=opnMutByte;
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
       VAx=ValueData[Ax]+Ncifra;
       OverNArrayVAxNcifra=GetNumberBuff(VAx);
       if (!(VAx&0x80))
       if (OverNArrayVAxNcifra!=opnMutByte)
       {
         do
         {
           VAy=ValueData[Ay];
           if (OverNArrayVAxNcifra==GetNumberBuff(VAy+Ncifra))
           {
             PriorityNumb[Ax]++;
             if (GetNumberBuff(VAy+8)==opnBegin)
               PriorityNumb[Ax]++;
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
         Cifra=GetNumberBuff(ValueData[Ax]+Ncifra);
         if (Cifra==opnRepeat)
           Cifra=OldCifra;
         if (Cifra>9)
           Cifra=numUndefined;
        SetNumberBuffA(Ncifra1+LenBuffIndCode,Cifra);
       }
     }
     OldCifra=Cifra;
   }
   while (Ncifra!=0);

  Mut=0;
  for (Ncifra=0;Ncifra<8;Ncifra++)
  {
    Cifra=GetNumberBuff(Ncifra+LenBuffIndCode);
    if (Cifra==numUndefined)
      Mut++;
    SetNumberBuffA(Ncifra,Cifra);
  }

  if (Mut>5)
    for (Ncifra=0;Ncifra<8;Ncifra++)
    {
      Cifra=numUndefined;
      SetNumberBuffA(Ncifra,Cifra);
    }

  Kateg=Cifra;
}

uchar TestOnSendAnswer(uchar NLoops)
{
       data uchar ByteGet,OldByteGet=opnMutByte,DoubleCxTOSA=0;
       bit ByteFirstTOSA;
       ByteFirstTOSA=1;
       do
       {
         ByteGet=NumeralDetect();
/*
         if ((ByteGet&0xF0)<=MinQuality)
            ByteGet=MutByte;
         ByteGet&=0xF;
*/
         if (ByteGet==OldByteGet&&ByteGet!=opnMutByte)
         {
           if (DoubleCxTOSA++==MaxDoubleCx)
             return ByteGet;
         }
         else
           DoubleCxTOSA=0;

         if (ByteFirstTOSA)
         {
           ByteFirstTOSA=0;
           DoubleCxTOSA++;
         }

         OldByteGet=ByteGet;
       }
       while (NLoops--!=0);
       return opnMutByte;
}