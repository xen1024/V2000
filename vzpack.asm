/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

; IAR 3.11A
  name BookWork
  rseg RCODE
  public GetLenNumber
  $DEFFN GetLenNumber(0,0,0,0,0,0,0,0)
  public GetNextNAT
  $DEFFN GetNextNAT(0,0,0,0,0,0,0,0)
  public SetStartNAT
  $DEFFN SetStartNAT(0,0,0,0,0,0,0,0)
  public TestOutOfBook
  $DEFFN TestOutOfBook(0,0,0,0,0,0,0,0)
  public TestOutOfBookA
  $DEFFN TestOutOfBookA(0,0,0,0,0,0,0,0)
  public SetNAT
  $DEFFN SetNAT(0,0,0,0,0,1,0,0)
  public BuffWork
  $DEFFN BuffWork(4,0,0,0,1,0,0,0)
  public NextNumberAddr
  $DEFFN NextNumberAddr(0,0,0,0,0,0,0,0)



  extern MinLen,NumberPresent
  extern BookDataI,Book

;#define LenNumber 1

$vdef.inc
#define tpNumberPack 0x80
#define tpLenNumber  0x84
#define EndByteTablePack 0xFF
#define LenNumberPack4Bit 16

;uchar GetLenNumber(uint addr)
;{
; if (NumberPresent)
;    return(LoadMem(addr)+MinLen);
; else
;    return(0);
;}
GetLenNumber:
        JNB     NumberPresent,?0070
?0069:
         mov DPL,ParamLL
         mov DPH,ParamLH
         call LoadByteFromAdrInRam
         mov B,A
         anl A,#0xF
         cjne A,#0xF,NoBiggestNumber
          mov A,B
          swap A
          anl A,#0xF
          add A,#LenNumberPack4Bit
NoBiggestNumber:
         inc A
         clr C
         rrc A
         inc A
         ADD A,MinLen
         MOV R4,A
         RET
?0070:
         MOV     R4,#0
         RET

;------------------------------------------------------------
;bit GetNextNAT(void)
;{
;  NATbyte>>=1;
;  if((8-StartAddrNAT)&7==0)
;    NATbyte=LoadMem(AddrNAT++);
;  return(NATbyte&1);
;}
GetNextNAT:
;        %GetDirectWord DPH,DPL,BookDataI,oAddrNAT
;        mov A,DPL
;        add A,#8-StartAddrNAT
;        anl A,#7
        mov A,ParamHL
        anl A,#7
        jnz NoNextByteInNAT
SetStartBitNAT:
         %GetDirectWord DPH,DPL,BookDataI,oAddrNAT
         call LoadByteFromAdrInRam
         mov NATbyte,A
         inc DPTR
         %SetDirectWord DPH,DPL,BookDataI,oAddrNAT
NoNextByteInNAT:
        mov A,NATbyte
        rlc A
        mov NATbyte,A
        ret

SetStartNAT:
           %SetDirectWord #High(StartAddrNAT),#Low(StartAddrNAT),BookDataI,oAddrNAT
           mov DPTR,#StartAddrNAT
           jmp SetStartBitNAT
;------------------------------------------------------------
;uint TestOutOfBook(uint addr)
;{
; while (addr>EndAddr)
;   addr-=Len;
; return(addr);
;}
TestOutOfBook:
?0067:
; 249.   while (addr>=EndAddr)
        %Y_XPlusC R0,BookDataI,oEndAddr*2+1,1
        MOV     A,R4
        clr    C
        SUBB    A,@R0
        dec     R0
        MOV     A,R5
        SUBB    A,@R0
        JC      ?0066
?0068:
; 250.     addr-=Len;
         %Y_XPlusC R0,BookDataI,oLen*2+1,1
         CLR     C
         MOV     A,R4
         SUBB    A,@R0
         dec     R0
         MOV     R4,A
         MOV     A,R5
         SUBB    A,@R0
         MOV     R5,A
        SJMP    ?0067
?0066:
        ret
;------------------------------------------------------------
;uint TestOutOfBookA(uint);
;in: addr
;out: addr
;if (addr>max) addr=min+addr-max
;if (addr<min) addr=max+min-addr
TestOutOfBookA:
;  if (addr<BookDataI[oStartAddr])
              %Y_XPlusC R0,BookDataI,oStartAddr*2+1,1
              setb C
              mov     A,@R0
              subb    A,ParamLL
              dec     R0
              MOV     A,@R0
              subb    A,ParamLH
              JC     NoBiggerLimitTestOutOfBookA
CalcNewAddrTestOutOfBookA:
;     addr=BookDataI[oEndAddr]+(addr-BookDataI[oStartAddr]);
               %Y_XPlusC R1,BookDataI,oEndAddr*2+1,1
               mov A,@R1
               add A,ParamLL
               mov ParamLL,A
               dec R1
               mov A,@R1
               add A,ParamLH
               mov ParamLH,A
               clr C
               dec R0
               mov A,ParamLL
               subb A,@R0
               mov ParamLL,A
               dec R0
               mov A,ParamLH
               subb A,@R0
               mov ParamLH,A
ExitTestOutOfBookA:
; return addr
               RET
NoBiggerLimitTestOutOfBookA:
;  if (addr>BookDataI[oEndAddr])
              %Y_XPlusC R0,BookDataI,oEndAddr*2+1,1
              setb C
              mov     A,@R0
              subb    A,ParamLL
              dec     R0
              MOV     A,@R0
              subb    A,ParamLH
              JNC      ExitTestOutOfBookA
;     addr=BookDataI[oStartAddr]+addr-BookDataI[oEndAddr];
               %Y_XPlusC R1,BookDataI,oStartAddr*2+1,1
               jmp CalcNewAddrTestOutOfBookA

;bit SetNAT(uint Number,bit value)
;{
; uint addr=StartAddrNAT+Number>>3;
; uchar c=value<<(Number&7);
; SaveMem((LoadMem(addr)&(~c))|c);
; return(0);
;}
SetNAT:
        mov A,ParamLL
        anl A,#7
        mov ParamHL,A
        call GetDPTR_NAT
        call LoadByteFromAdrInRam
        mov ParamLL,A
        mov A,#0x80
        mov B,ParamHL
        call shrA_B
        mov ParamHL,A
        cpl A
        anl A,ParamLL
        jnb $LOCBB SetNAT,NoSetBitNAT
         orl A,ParamHL
NoSetBitNAT:
        call SaveByteFromAdrInRam
        ret
;------------------------------------------------------------
;Data pack number
;in: uchar ParamL=addr
;    Book
;out: none

#define TypeCompare    $PRMBD BuffWork
#define BookTypeBit    $LOCBB BuffWork
#define TypeDataOffset $LOCBB BuffWork+1
#define LenNumberX     $LOCBB BuffWork+2
#define LenNumberY     $LOCBB BuffWork+3
#define LenNumberZ     TypeDataOffset
#define TmpParamLL     BookTypeBit

BuffWork:
        setb UnPacking
        clr CompareNumber
        cjne ParamHL,#tcbPack,NoModeBuffWork1
         clr UnPacking
NoModeBuffWork1:
        mov A,ParamHL
        setb C
        subb A,#tcbUnPack
        jc NoModeBuffWork2
         setb CompareNumber
NoModeBuffWork2:
        mov TypeCompare,ParamHL

        mov DPL,ParamLL
        mov DPH,ParamLH

        clr A
        mov ByteLo,A
        mov ByteHi,A
        mov BitShift,A
        mov TypeDataOffset,A

        mov B,Book
        inc A
        call shlA_B
        mov BookTypeBit,A           ;BookBit

        jnb UnPacking,NoUnpackLoad
         call LoadByteFromAdrInRamP
         mov ByteLo,A
         call LoadByteFromAdrInRamP ;SLOW!!! WARNING
         mov ByteHi,A
         mov LenNumberY,#MaxLenNumberIn      ;OnlyIn
NoUnpackLoad:

AgainDataPackBook:
         mov A,TypeDataOffset
         call GetTableBookPack
         inc TypeDataOffset
         cjne A,#EndByteTablePack,NoExitDataPackBook
          jmp ExitDataPackBook
NoExitDataPackBook:
         anl A,BookTypeBit
         jz AgainDataPackBookA

         mov A,TypeDataOffset
         inc A
         call GetTableBookPack
         mov R0,A

         mov A,TypeDataOffset
         call GetTableBookPack
         mov BitLen,A

         jb UnPacking,UnpackMethod

         cjne A,#tpNumberPack,NoNumberPackNow
          mov LenNumberX,#0
          mov LenNumberY,LenNumber
AgainPackNumberX:
            push ParamLLd
            mov ParamLL,LenNumberX
            call GetNumberBuff
            mov A,ParamLL
            pop ParamLLd
SetEndNumberIn:
            mov BitLen,#4
            call Append2Bytes
            jc NoNextBytePackA
              mov A,ByteLo
              call SaveByteFromAdrInRamP
              mov ByteLo,ByteHi
NoNextBytePackA:
          inc LenNumberX
          mov A,LenNumberX
          cjne A,LenNumberY,AgainPackNumberX
          mov A,Book
          cjne A,#bBookIn,NoBookInPacking
           mov A,LenNumberY
           xrl A,#MaxLenNumberIn
           jz NoBookInPacking
            mov A,#numEndNumberIn
            mov LenNumberY,#MaxLenNumberIn
            mov LenNumberX,#MaxLenNumberIn-1
            jmp SetEndNumberIn
NoBookInPacking:
          jmp AgainDataPackBookA
NoNumberPackNow:

         cjne A,#tpLenNumber,NoLenNumberPack
          cjne @R0,#LenNumberPack4Bit,$+3
          jnc NoUse4bitPack
           mov BitLen,#4
           mov A,@R0
           dec A
           jmp Use8bitPack
NoUse4bitPack:
           mov BitLen,#8
           mov A,@R0
           add A,#-LenNumberPack4Bit
           swap A
           orl A,#0x0F
           jmp Use8bitPack
Use4bitPack:
NoLenNumberPack:
         mov A,@R0
Use8bitPack:
         call Append2Bytes
         jc NoNextBytePack
           mov A,ByteLo
           call SaveByteFromAdrInRamP
           mov ByteLo,ByteHi
NoNextBytePack:

AgainDataPackBookA:
         inc TypeDataOffset
         inc TypeDataOffset
        jmp AgainDataPackBook
;*************************************************************
UnpackMethod:
         cjne A,#tpLenNumber,NoLenNumberUnPack
          mov BitShift,#4
          mov A,ByteLo
          anl A,#0xF
          cjne A,#0xF,?NoLenNumberUnPack
           mov BitShift,#0
           mov A,ByteLo
           swap A
           anl A,#0xF
           add A,#LenNumberPack4Bit-1   ;must be C=0!!!
?NoLenNumberUnPack:                     ;must be C=1!!!
           jmp NextByteUnpack
NoLenNumberUnPack:

         xrl A,#tpNumberPack
         jz ?NumberUnPackNow
         jmp NoNumberUnPackNow
?NumberUnPackNow:
          mov ParamYH,ByteHi
          mov LenNumberX,#0
          jnb CompareNumber,AgainUnPackNumberX
            mov LenNumberZ,#Low(-1)
            mov A,TypeCompare
            cjne A,#tcbLen1Use,NoTypeCompare1  ;if (LenBook<LenNumber) exit
             mov A,LenNumberY
             clr C
             subb A,LenNumber
             jc CompareNoEQ
             mov LenNumberY,LenNumber
             jmp AgainUnPackNumberX
NoTypeCompare1:
            cjne A,#tcbUseLenPack,NoTypeCompare7 ;if (LenBook>=LenNumber) exit
             mov A,LenNumber
             setb C
             subb A,LenNumberY
             jc CompareNoEQ
             mov TypeCompare,#tcbLen1Use
             jmp AgainUnPackNumberX
NoTypeCompare7:
            cjne A,#tcbMaskBuff2,NoTypeCompare0
             mov A,LenNumberY
             xrl A,LenNumber
             jz AgainUnPackNumberX
CompareNoEQ:  clr C
              ret
NoTypeCompare0:
;            cjne A,#tcbSkipBigger9,NoTypeCompare2
;             mov A,LenNumber
;             setb C
;             subb A,LenNumberY
;             jnc CompareNoEQ
;NoTypeCompare2:
;<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>
AgainUnPackNumberX:
            mov ByteHi,ParamYH
            mov BitLen,#4
            call GetByteFromWord
            push A
            jc NoNextByteUnPackA
             mov ByteLo,ByteHi
             call LoadByteFromAdrInRamP
             mov ParamYH,A
NoNextByteUnPackA:
            pop ParamLHd
            cjne ParamLH,#numEndNumberIn,NoEndNumberInFoundUnpack
             mov A,Book
             cjne A,#bBookIn,NoEndNumberInFoundUnpack
              mov LenNumberY,LenNumberX
              jnb CompareNumber,NoComparingNow     ;if (EndIn&&CompareNumber) ExitNotEq
               mov A,TypeCompare
               cjne A,#tcbUndefinedSearch,CompareNoEQ
               jmp NextCompareType
NoComparingNow:
;              jb CompareNumber,CompareNoEQ
              jmp NextUnpackType
NoEndNumberInFoundUnpack:
            jnb CompareNumber,NoCompareNumberNow
             mov TmpParamLL,ParamLL
             mov A,TypeCompare
             cjne A,#tcbMaskBuff2,NoTypeCompareA0  ;Compare tcMaskBuff2
              cjne ParamLH,#numMask,NoMaskFound
               jmp NoTypeCompareA
NoMaskFound:  mov ParamLL,LenNumberX
              call GetNumberBuff
              mov A,ParamLL
              xrl A,ParamLH
              jz NoTypeCompareA
              jmp CompareNoEQ
NoTypeCompareA0:
            cjne A,#tcbLen1Use,NoTypeCompareA1     ;Compare tcLen1Use
             jmp NoMaskFound
NoTypeCompareA1:
            cjne A,#tcbSkipBigger9,NoTypeCompareA2 ;Compare tcSkipBigger9
TypeCompareA1:inc LenNumberZ
              mov ParamLL,LenNumberZ
              mov A,LenNumber
              xrl A,ParamLL
              jz CompareNoEQ
              call GetNumberBuff
              mov A,ParamLL
              xrl A,ParamLH
              jz NormalNumeralCompare    ;if (Book[i]==Buff[j]) {i++;j++;}
               cjne ParamLL,#10,$+3      ;  else if (Buff[i]>10) i--;
               jc CompareNoEQ
               jmp TypeCompareA1
NormalNumeralCompare:
NoTypeCompareA2:
;            cjne A,#tcbUseLenPack,NoTypeCompareA4
;             jmp NoMaskFound
;NoTypeCompareA4:
            cjne A,#tcbUndefinedSearch,NoTypeCompareA3
             cjne ParamLH,#10,$+3
             jc CompareNoEQ
NoTypeCompareA3:
NoTypeCompareA:
            mov ParamLL,TmpParamLL
            inc LenNumberX
            mov A,LenNumberX
          cjne A,LenNumberY,AgainUnPackNumberX
NextCompareType:
          jmp _NextCompareType
NoCompareNumberNow:
            push ParamLLd
            mov ParamLL,LenNumberX
            call SetNumberBuffA
            pop ParamLLd
ComparedNumberNow:
            inc LenNumberX
            mov A,LenNumberX
;          cjne A,LenNumberY,AgainUnPackNumberX
           xrl A,LenNumberY
           jz NextUnpackType
           jmp AgainUnPackNumberX
NextUnpackType:
          mov ByteHi,ParamYH
          jmp AgainDataPackBookA
NoNumberUnPackNow:

         call GetByteFromWord
NextByteUnpack:
         mov F0,C
         cjne R0,#LenNumber,NoLenNumberSet
          inc A
          mov LenNumberY,A
NoLenNumberSet:
         jb CompareNumber,?NoNextByteUnPack
          mov @R0,A
?NoNextByteUnPack:
         jb F0,NoNextByteUnPack
          mov ByteLo,ByteHi
          call LoadByteFromAdrInRamP
          mov ByteHi,A
NoNextByteUnPack:
        jmp AgainDataPackBookA

_NextCompareType:
;        mov A,TypeCompare
;        cjne A,#tcbSkipBigger9,NoTypeCompareX1
;AgainTypeCompareX1:
;          inc LenNumberZ
;          mov ParamLL,LenNumberZ
;          mov A,LenNumber
;          xrl A,ParamLL
;          jz NoTypeCompareX1
;          call GetNumberBuff
;          cjne ParamLL,#10,$+3      ;  else if (Buff[i]>10) i--;
;          jnc AgainTypeCompareX1
;           jmp CompareNoEQ
;NoTypeCompareX1:
        setb C
        ret

ExitDataPackBook:
        jb UnPacking,ExitDataUnPackBook
         mov A,BitShift
         jz NoSavePackLastByte
           mov A,ByteLo
           call SaveByteFromAdrInRamP
NoSavePackLastByte:
         ret
ExitDataUnPackBook:
         mov LenNumber,LenNumberY
         ret

;    LenNumber     ZK,Out
;    Kateg         In
;    DayCall       In,Out
;    MonthCall     In,Out
;    HourCall      In,Out
;    MinCall       In,Out
;    HourSay       In,Out
;    MinSay        In,Out

GetTableBookPack:
                add A,#TableBookPack-$-3
                movc A,@A+PC
                ret
TableBookPack:
;   BookEnable,LenBit,AddressIDATA
 db bBZK|bBOut,tpLenNumber,LenNumber
 db bBZK|bBOut|bBIn,tpNumberPack,Number
 db bBIn,4,Kateg
 db bBIn|bBOut,5,DayCall
 db bBIn|bBOut,4,MonthCall
 db bBIn|bBOut,3,DayOfWeekCall
 db bBIn|bBOut,5,HourCall
 db bBIn|bBOut,6,MinCall
 db bBIn|bBOut,3,HourSay
 db bBIn|bBOut,6,MinSay
 db EndByteTablePack

;------------------------------------------------------------

GetDPTR_NAT:
         mov DPL,#Low(StartAddrNAT)
         mov DPH,#High(StartAddrNAT)
         mov A,ParamLH
         rr A
         rr A
         rr A
         mov B,A
         anl A,#0xE0
         xch A,ParamLL
         rr A
         rr A
         rr A
         anl A,#0x1F
         orl A,ParamLL
         anl B,#0x1F
         jmp AddDPTR_BA
;         ret

;uint NextNumberAddr(uint addr,uint number)
;{
;  switch(Book)
;  {
;    case bBookIn:
;         return TestOutOfBook(addr+MinLen);
;    case bBookOut:
;         if (NNumber<UseNumbers)
;           NumberPresent=true;
;         else
;           NumberPresent=false;
;         return TestOutOfBook(addr+GetLenNumber(addr));
;    case bBookZK:
;         if (NumberPresent=GetNextNAT())
;           return addr+GetLenNumber(addr);
;  }
;  return addr;
;}
NextNumberAddr:
         mov A,Book
         cjne A,#bBookIn,NoNextNumberAddrBookIn
          mov A,ParamLL
          add A,MinLen
          mov ParamLL,A
          jnc NoIncH
           inc ParamLH
NoIncH:   jmp TestOutOfBook
NoNextNumberAddrBookIn:
         cjne A,#bBookOut,NoNextNumberAddrBookOut
          setb NumberPresent
          %Y_XPlusC R0,BookDataI,oUseNumbers*2+1,1
          mov A,ParamHL
          clr C
          subb A,@R0
          mov A,ParamHH
          subb A,@R0
          jc NoClearNumberPresent
           clr NumberPresent
NoClearNumberPresent:
          mov ParamHL,ParamLLd
          mov ParamHH,ParamLHd
          call GetLenNumber
          mov A,ParamLL
          add A,ParamHL
          mov ParamLL,A
          jnc NoIncH1
           inc ParamHH
NoIncH1:  mov ParamLH,ParamHHd
          jmp TestOutOfBook
NoNextNumberAddrBookOut:
         cjne A,#bBookZK,NoNextNumberAddrBookZK
          jnb NumberPresent,?NoNextNumberAddrBookZK
           mov ParamXL,ParamLLd
           mov ParamXH,ParamLHd
           call GetLenNumber
           mov A,ParamLL
           add A,ParamXL
           mov ParamLL,A
           jnc NoIncH2
            inc ParamXH
NoIncH2:   mov ParamLH,ParamXHd
?NoNextNumberAddrBookZK:
          inc ParamHL
          call GetNextNAT
          mov NumberPresent,C
NoNextNumberAddrBookZK:
         ret

    RSEG D_UDATA
NATbyte: DS 1
    RSEG BITVARS
UnPacking:      DS 1
CompareNumber:  DS 1
  END