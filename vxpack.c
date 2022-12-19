/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

//******************
//BookWork
//******************
#include <V2000.h>

#pragma memory=data


code const uint
 StartAddrC[] ={StartAddrIn,StartAddrOut,StartAddrZKall},
 LenC[]       ={LenIn,LenOut,LenZKall},
 EndAddrC[]   ={EndAddrIn,EndAddrOut,EndAddrZKall},
 MaxNumbersC[]={MaxNumbersIn,MaxNumbersOut,MaxNumbersZKall},
// ZK W B BL SPC
 OffsetNumberX[]={
 MaxNumbersSpecical+MaxNumbersWhite+MaxNumbersBlack+MaxNumbersBlackLock,
 MaxNumbersSpecical,
 MaxNumbersSpecical+MaxNumbersWhite,
 MaxNumbersSpecical+MaxNumbersWhite+MaxNumbersBlack,
 0},
 LenBookX[]={MaxNumbersZK,MaxNumbersWhite,MaxNumbersBlack,
 MaxNumbersBlackLock,MaxNumbersSpecical};

code const uchar MinLenC[]={MinLenIn,MinLenOut,MinLenZK,MinLenZK,MinLenZK,MinLenZK,MinLenZK};

bit NumberPresent;

uchar MinLen;
uchar Book;
data uint idata *BookDataI;
data uint NNumber;


// *****************************************************
//In: Number - no changed
//Out: no space=1
bit InsertNumberBook(void)
{
 uint addr;
 bit NoSpace;
 if (LenNumber==0)
   return true;
AgainTestInsert:
 NoSpace=GetLenPackOfLenNumberMinLen()>Len-UseLen||UseNumbers>=MaxNumbers;
 addr=GetAddress(NNumber);
 if (NNumber==0||Book==bBookZK)
 {
  switch(Book)
  {
   case bBookIn:
        if (NoSpace)
          OffsetAddr=GetOffsetNextNumber(addr);
        else
          UseNumbers++;
        addr=GetAddress(GetNumberBack(NNumber));
        break;
   case bBookOut:
        if (NoSpace)
        {
          OffsetAddr=GetOffsetNextNumber(addr);
          UseLen-=GetLenNumber(addr);
          UseNumbers--;
          goto AgainTestInsert;
        }
        UseNumbers++;
        addr=GetAddress(GetNumberBack(NNumber));
        {
          uchar xlen=0;
          if (LenNumber>15)
            xlen++;
          xlen=((LenNumber+xlen)>>1)+1+MinLen;
          UseLen+=xlen;
        }
        break;
   case bBookZK:
        if (NoSpace)
          return false;
//        UseNumbers++;
        {
          uint tmp;
          uchar xlen=GetLenPackOfLenNumberMinLen();
//          if (LenNumber>15)
//            xlen++;
//          xlen=((LenNumber+xlen)>>1)+1+MinLen;
          UseLen+=xlen;
          tmp=StartAddr+UseLen;
          CopyMemMOD(tmp-xlen-1,
                     tmp-1,
                     tmp-xlen-addr,//LEN
                     dBackward);
        }
        SetNAT(NNumber,nPresent);
  }
  BuffWork(addr,tcbPack);
  SaveBookData();
  return true;
 }
 return false;
}
//Delete number
//in: Number - not changed

uint DeleteNumberBook(void)
{
  uint addr;
  switch(Book)
  {
    case bBookIn:
//         addr1=UseNumbers*MinLen;
//         LenMove=UseNumbers*MinLen;
         addr=GetAddress(GetNumberBack(NNumber));
         break;
    case bBookZK:
         addr=GetAddress(NNumber);
         UseLen-=GetLenNumber(addr);
//         VideoBuffer[7][1]=GetLenNumber(addr);
//         VideoBuffer[8][1]=NumberPresent;
         SetNAT(NNumber,nNotPresent);
         break;
    case bBookOut:
         addr=GetAddress(GetNumberBack(NNumber));
         UseLen-=GetLenNumber(addr);
         break;
  }

  if (NumberPresent)
  {
    if (UseNumbers>0)
      UseNumbers--;
    if (NNumber==UseNumbers&&Book!=bBookZK)
      OffsetAddr=GetOffsetNextNumber(addr);
    else
      if (NNumber!=0||Book==bBookZK)
      {
        uint addr1,LenMove;
        addr1=NextNumberAddr(addr,0);
        if (Book!=bBookIn)
          LenMove=StartAddr+UseLen-addr;
        else
          LenMove=MinLen*(UseNumbers-GetNumberBack(NNumber));
        CopyMemMOD(addr1,addr,LenMove,dForward);
      }
  }
//  SaveBookData();
  return NNumber;
}


//------------------------------------------------------------
//in: Number
//out: addr
//     NumberPresent
//addr=x(Number)
//NumberPresent=x(Number);
uint GetAddress(uint number)
{
  uint addr=ResetNumberAddr(number);
  idata uint CurrNumber=0;
  if (number&0x8000)
  {
    NumberPresent=false;
    return StartAddr;
  }
  switch(Book)
  {
   case bBookIn:
     return TestOutOfBook(addr+number*MinLen);
   case bBookOut:
//     if (!NumberPresent)
//       break;
   case bBookZK:
     while(number--!=0)
       addr=NextNumberAddr(addr,CurrNumber++);
  }
  return addr;
}

//------------------------------------------------------------
//in:  Number - not changed
//out: Address
// addr=x(Number0)
uint ResetNumberAddr(uint number)
{
  switch(Book)
  {
    case bBookIn:
    case bBookOut:
         if (number<UseNumbers)
           NumberPresent=true;
         else
           NumberPresent=false;
         return StartAddr+OffsetAddr;
    case bBookZK:
         NumberPresent=SetStartNAT();
  }
  return StartAddr;
}

//------------------------------------------------------------
//in: addr
//out: addr
// addr=addr+x
//uint NextNumberAddr(uint addr,uint number)
//{
//  switch(Book)
//  {
//    case bBookIn:
//         return TestOutOfBook(addr+MinLen);
//    case bBookOut:
//         if (NNumber<UseNumbers)
//           NumberPresent=true;
//         else
//           NumberPresent=false;
//         return TestOutOfBook(addr+GetLenNumber(addr));
//    case bBookZK:
//         if (NumberPresent=GetNextNAT())
//           return addr+GetLenNumber(addr);
//  }
//  return addr;
//}

//------------------------------------------------------------
//CopyMemMOD
//in: FromAddr
//    ToAddr
//    LenCopy
//    Direction
//out:
uint TestOutOfBookA(uint addr);
void CopyMemMOD(uint FromAddr,uint ToAddr,uint LenCopy,bit Direction)
{
 if (FromAddr==ToAddr)
   return;
 while(LenCopy-->0)
 {
  FromAddr=TestOutOfBookA(FromAddr);
  ToAddr=TestOutOfBookA(ToAddr);
  SaveByteFromAdrInRamC(ToAddr,LoadByteFromAdrInRamC(FromAddr));
  if (Direction==dForward)
  {
    FromAddr++;
    ToAddr++;
  }
  else
  {
    FromAddr--;
    ToAddr--;
  }

 }
}

uint GetNumberBack(uint number)
{
 if (number>=UseNumbers&&number!=0)
   return -1;
 return UseNumbers-number-1;
}


uint GetOffsetNextNumber(uint addr)
{
 return NextNumberAddr(addr,0)-StartAddr;
}

uint LoadNumber(uint number,uchar book)
{
  Book=book;
  NNumber=LoadBookData(number);
  if (Book==bBookIn||Book==bBookOut)
    NNumber=GetNumberBack(NNumber);
  NNumber=GetAddress(NNumber);
  if (NumberPresent)
    BuffWork(NNumber,tcbUnPack);
  else
  {
    LenNumber=0;
    DayOfWeekCall=Kateg=MinSay=HourSay=DayCall=MonthCall=HourCall=MinCall=0;
  }
  stack_mfreelast(LenTmpBookData);
  TypeNumber=false;
  return number;
}

bit SaveNumber(uint Number,uchar book)
{
  bit BitSave;
  ShowBusy();
  if (LenNumber==MaxLenNumber)
    LenNumber--;
  Book=book;
  NNumber=LoadBookData(Number);
  switch(Book)
  {
    case bBookIn:
    case bBookOut:
         BitSave=InsertNumberBook();
         stack_mfreelast(LenTmpBookData);
         return BitSave;
    case bBookZK:
         NNumber=DeleteNumberBook();
         BitSave=InsertNumberBook();
         SaveBookData();
         stack_mfreelast(LenTmpBookData);
         return BitSave;
  }
  return false;
}

uint DeleteNumber(uint number,uchar book)
{
  bit BitSave;
  ShowBusy();
  Book=book;
  NNumber=LoadBookData(number);
//  VideoBuffer[0][1]=Book;
//  VideoBuffer[1][1]=book;
//  VideoBuffer[2][1]=NNumber>>8;
//  VideoBuffer[3][1]=NNumber;
//  Halt;
  BitSave=DeleteNumberBook();
  SaveBookData();
  stack_mfreelast(LenTmpBookData);
  return BitSave;
}

void SaveBookData(void)
{
  if (Book!=bBookZK)
  {
    SaveOpt(BookDataI[oOffsetAddr],optOffsetAddrIn+Book);
    SaveOpt(BookDataI[oUseNumbers],optUseNumbersIn+Book);
  }
  if (Book!=bBookIn)
    SaveOpt(BookDataI[oUseLen],optUseLenOut+Book-1);
//  stack_mfreelast(LenTmpBookData);
}

uint LoadBookData(uint Number)
{
  uchar book=Book;
  BookDataI=stack_malloc(LenTmpBookData);

  if (Book>=bBookZK)
  {
    Number+=OffsetNumberX[Book-bBookZK];
    MaxNumbers=LenBookX[Book-bBookZK]+OffsetNumberX[Book-bBookZK];
    book=bBookZK;
  }
  StartAddr=StartAddrC[book];
  Len=LenC[book];
  EndAddr=EndAddrC[book];
  MinLen=MinLenC[Book];
  if (book==bBookZK)
    UseNumbers=0;
  else
  {
    UseNumbers=LoadOpt(optUseNumbersIn+book);
    MaxNumbers=MaxNumbersC[book];
    OffsetAddr=LoadOpt(optOffsetAddrIn+book);
  }
  if (book==bBookIn)
    UseLen=0;
  else
    UseLen=LoadOpt(optUseLenOut+book-bBookOut);
  Book=book;
  return Number;
}

uint GetNumberBackBook(uint number,uchar book)
{
  uint usenumbers;
  if (book!=bBookIn&&book!=bBookOut)
    return number;
  usenumbers=LoadOpt(optUseNumbersIn+book);
  if (number>=usenumbers&&number!=0)
    return -1;
  return usenumbers-number-1;
}

uint SearchNumber(uint StartNumber,uint LenSearch,uchar book,uchar ModeSearch)
{
  uint addr;
  Book=book;
  NNumber=LoadBookData(StartNumber);
  if (LenSearch==-1)
    LenSearch=MaxNumbers-NNumber;
  if (Book==bBookIn||Book==bBookOut)
  {
    LenSearch=UseNumbers-NNumber;
//    NNumber=GetNumberBack(NNumber);
//    StartNumber=GetNumberBack(StartNumber);
  }
  addr=GetAddress(NNumber);
  while(LenSearch-->0)
  {
    if (NumberPresent)
    {
      if (ModeSearch!=tcbFreeSearch)
        if (BuffWork(addr,ModeSearch))
        {
//          if (Book==bBookIn||Book==bBookOut)
//            StartNumber=GetNumberBack(StartNumber);
          stack_mfreelast(LenTmpBookData);
          return StartNumber;
        }
    }
    else
      if (ModeSearch==tcbFreeSearch)
      {
        stack_mfreelast(LenTmpBookData);
        return StartNumber;
      }
    addr=NextNumberAddr(addr,NNumber);
    StartNumber++;
    NNumber++;
  }
  stack_mfreelast(LenTmpBookData);
  return -1;
}

void ClearBook(uchar book)
{
  ShowBusy();
  Book=book;
  NNumber=LoadBookData(0);
  if (Book>=bBookZK)
  {
    int i=NNumber,addr1,addr2;
    addr1=GetAddress(NNumber);
    addr2=GetAddress(MaxNumbers);
    if ((i=StartAddr+UseLen)>addr2)
      CopyMemMOD(addr2,addr1,i-addr2,dForward);

    for (i=NNumber;i<MaxNumbers;i++)
      SetNAT(i,nNotPresent);
  }
  UseNumbers=UseLen=OffsetAddr=0;
  SaveBookData();
  stack_mfreelast(LenTmpBookData);
}

/*
void BT(void)
{
//  char i;
  SaveOpt(0,optOffsetAddrIn);
  SaveOpt(0,optUseNumbersIn);
  SaveOpt(0,optOffsetAddrOut);
  SaveOpt(0,optUseNumbersOut);
//  SaveOpt(0,optUseNumbersZK);
  SaveOpt(0,optUseLenZK);
  SaveOpt(0,optUseLenOut);
  Kateg=9;
  DayCall=30;
  MonthCall=11;
  HourCall=23;
  MinCall=59;
  HourSay=23;
  MinSay=59;

#define i Number[14]
  for (i=0;i<100;i++)
  {
    for(LenNumber=0;LenNumber<7;LenNumber++)
      SetNumberBuffA(LenNumber,LenNumber+i);
    SaveNumber(0,bBookIn);
    SaveNumber(0,bBookOut);
    SaveNumber(i,bBookZK);
  }
  LoadNumber(100,bBookZK);

  SaveNumber(0,bBookIn);
  LoadNumber(0,bBookIn);

  SearchNumber(0,10,bBookIn,tcbMaskBuff2);
  SearchNumber(0,10,bBookIn,tcbLen1Use);
  SearchNumber(0,10,bBookIn,tcbSkipBigger9);

  DeleteNumber(0,bBookIn);

}
*/

void ResetBooks(void)
{
  int i;
  ShowBusy();
  for (i=0;i<MaxBooks;i++)
  {
    Book=i;
    LoadBookData(0);
    UseNumbers=UseLen=OffsetAddr=0;
    SaveBookData();
    stack_mfreelast(LenTmpBookData);
  }
  for (i=0;i<MaxNumbersZKall;i++)
    SetNAT(i,nNotPresent);
}

uint FindTodayCall(uint StartNumber,uchar book,bit Direction)
{
  if (StartNumber==-1)
  {
    if (Direction==dForward)
    {
      StartNumber=0;
      goto FindStartNumber;
    }
    else
    {
      StartNumber=LoadOpt(optUseNumbersIn+book);
      goto FindStartNumberA;
    }
  }
  while(1)
  {
    if (Direction==dForward)
    {
      if (++StartNumber>=LoadOpt(optUseNumbersIn+Book))
        break;
    }
    else
FindStartNumberA:
      if (StartNumber--==0)
        break;
FindStartNumber:
    LoadNumber(StartNumber,book);
    if (DayCall==Day-1&&MonthCall==Month-1)
      return StartNumber;
  }
  return -1;
}