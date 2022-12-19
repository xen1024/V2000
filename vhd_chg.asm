/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

           NAME HD_CHG
           RSEG CODE
  public HexToDec,DecToHex
  public XchDP_VA,AddDPTR_BA,AddDPTR_A,SubDPTR_BA,rrcA_B,DecDPTR
  public GetMemDataaR0,MulaR1_AtoaR1,AddwaR0_aR1toaR1,IncwaR0
  public LoadByteFromAdrInRamaR0,AddwaR0_A,DecwaR0,CompaR0_aR1
  public SubwaR1_aR0toaR1,SaveByteFromAdrInRamaR0P,LoadByteFromAdrInRamaR0P
  public SubwaR0_A,stack_begin,ABTabelAHTDW_A,rlcA_B
  public shrA_B,shlA_B,shlBA_ParamXL,shrBA_ParamXL
  public Append2Bytes,GetByteFromWord
  public LoadByteFromAdrInRamP,SaveByteFromAdrInRamP
  public SaveByteFromAdrInRamF,SaveByteFromAdrInRamFP
  public DecToHexData,HexToDecData,GetDPTR_BA,HexTo5DecWord

  $DEFFN DecToHexData(0,0,0,0,0,0,0,0)
  $DEFFN HexToDecData(0,0,0,0,0,0,0,0)
  public stack_malloc
  $DEFFN stack_malloc(0,0,0,0,0,0,0,0)
  public stack_mfreelast
  $DEFFN stack_mfreelast(0,0,0,0,0,0,0,0)
  public LoadOpt
  $DEFFN LoadOpt(0,0,0,0,0,0,0,0)
  public SaveOpt
  $DEFFN SaveOpt(0,0,0,0,0,0,0,0)
  public AbsC
  $DEFFN AbsC(0,0,0,0,0,0,0,0)

#define __HD_CHG
$vdef.inc
;------------------------------------------------------------
;Hex to Dec word
;in: ParamL - word to convert
;out: ParamL - converted
;------------------------------------------------------------
HexToDecData:
             mov A,ParamLL
             mov B,ParamLH
             call HexToDecWord
             mov ParamLL,A
             mov ParamLH,B
             ret
;------------------------------------------------------------
HexTo5DecWord:
              mov ParamLL,#0
AgainHexTo5DecWord:
              mov ParamXH,A
              clr C
              subb A,#Low(10000)
              mov ParamHL,A
              mov A,B
              subb A,#High(10000)
              mov ParamHH,A
              jc ContinueHexTo5DecWord
               mov A,ParamHL
               mov B,ParamHH
               inc ParamLL
               jmp AgainHexTo5DecWord
ContinueHexTo5DecWord:
              mov A,ParamXH
              push ParamLLd
              call HexToDecWord
              pop ParamLLd
              ret
;------------------------------------------------------------
;Dec to Hex word
;in: ParamL - word to convert
;out: ParamL - converted
;------------------------------------------------------------
DecToHexData:
             mov A,ParamLL
             mov B,ParamLH
             call DecToHexWord
             mov ParamLL,A
             mov ParamLH,B
             ret
;----------------------------преобразование HEX в DEC start
HexToDec:
             mov B,#64h
             div AB
             push ACC
             mov A,#0Ah
             xch A,B
             div AB
             swap A
             orl A,B
             pop B
             ret
;----------------------------преобразование HEX в DEC end
;----------------------------преобразование DEC в HEX start
DecToHex:
             push ACC
             swap A
             anl A,#0Fh
             mov B,#0Ah
             mul AB
             mov B,A
             pop ACC
             anl A,#0Fh
             add A,B
             ret
;----------------------------преобразование DEC в HEX end
DecToHexWord: setb F0
              jmp HDToDHWord
HexToDecWord: clr F0
              anl B,#3fh
HDToDHWord:   mov R2,#0
              mov R3,#0
              mov R6,B
              mov R7,A
              mov R0,#0
AgainHexToDecWord:
              mov A,R0
              call ABTabelAHTDW_Aa
              call SubR67_BA
              jnc NextHexToDecWord
               inc R0
               inc R0
               call AddR67_BA
               mov A,R6
               orl A,R7
               jz ExitHexToDecWord
               sjmp AgainHexToDecWord
NextHexToDecWord:
              mov A,R0
              add A,#8
              call ABTabelAHTDW_Aa
              call AddR23_BA
              sjmp AgainHexToDecWord
ExitHexToDecWord:
              mov A,R3
              mov B,R2
              ret
ABTabelAHTDW_Aa:
              jnb F0,ABTabelAHTDW_A
               xrl A,#0x8
ABTabelAHTDW_A:
              mov B,A
              add A,#TabelAHTDW-$-3
              movc A,@A+PC
              xch A,B
              add A,#TabelAHTDW-$-3+1
              movc A,@A+PC
              ret
TabelAHTDW    dw 1000,100,10,1,1000h,100h,10h,1
SubR67_BA:
             clr C
SubR67_BA_C: xch A,R7
             subb A,R7
             xch A,R7
             xch A,R6
             subb A,B
             xch A,R6
             ret
AddR67_BA:
             xch A,R7
             add A,R7
             xch A,R7
             xch A,R6
             addc A,B
             xch A,R6
             ret
AddR23_BA:
             xch A,R3
             add A,R3
             xch A,R3
             xch A,R2
             addc A,B
             xch A,R2
             ret

;умножение: w@R1=w@R1*A
MulaR1_AtoaR1: push ACC
               inc R1
               mov B,@R1;R7
               mul AB
               mov @R1,A;R7,A
               mov A,B
               dec R1
               xch A,@R1;R6
               mov B,A
               pop ACC
               mul AB
               add A,@R1;R6
               mov @R1,A
;               mov B,A
;               mov A,R7
               ret

;сравнение: C=w@R1-w@R0
CompaR0_aR1:
                clr C
                mov A,@R1
                subb A,@R0
                inc R0
                inc R1
                mov A,@R1
                subb A,@R0
                dec R0
                dec R1
                ret

;Вычитание: w@R1=w@R1-w@R0
SubwaR1_aR0toaR1:clr C
SbbwaR1_aR0toaR1:mov A,@R1
                 subb A,@R0
                 mov @R1,A
                 inc R0
                 inc R1
                 mov A,@R1
                 subb A,@R0
                 mov @R1,A
                 dec R0
                 dec R1
                 ret
;Сложение: w@R1=w@R1+w@R0
AddwaR0_aR1toaR1:mov A,@R1
                 add A,@R0
                 mov @R1,A
                 inc R0
                 inc R1
                 mov A,@R1
                 addc A,@R0
                 mov @R1,A
                 dec R0
                 dec R1
                 ret


;;умножение: BA=R6R7*A
;MulR6R7_AtoBA: push ACC
;               mov B,R7
;               mul AB
;               mov R7,A
;               mov A,B
;               xch A,R6
;               mov B,A
;               pop ACC
;               mul AB
;               add A,R6
;               mov B,A
;               mov A,R7
;               ret
;;сравнение: C=R6R7-R2R3
;CompR67_R23:
;                clr C
;                mov A,R7
;                subb A,R3
;                mov A,R6
;                subb A,R2
;                ret
rrcA_B:
        inc B
AgainRRC:
         rrc A
        djnz B,AgainRRC
        ret
rlcA_B:
        inc B
AgainRLC:
         rlc A
        djnz B,AgainRLC
        ret

; w@R0+=A
AddwaR0_A:inc R0
          add A,@R0
          mov @R0,A
          dec R0
          mov A,@R0
          addc A,@R0
          mov @R0,A
          ret

; w@R0-=A
SubwaR0_A:clr C
          inc R0
          subb A,@R0
          mov @R0,A
          dec R0
          mov A,@R0
          subb A,@R0
          mov @R0,A
          ret


;Dec @R0
; w@R0-- if (@R0=0) A=0
DecwaR0:inc R0
        mov A,@R0
        dec @R0
        dec R0
        jnz NoDecHiaR0
         dec @R0
NoDecHiaR0:
        orl A,@R0
        ret
;Inc @R0
; w@R0++
IncwaR0:inc R0
        inc @R0
        mov A,@R0
        dec R0
        jnz NoIncHiaR0
         inc @R0
NoIncHiaR0:
        ret
; A=RAM[w@R0]
MovxAaaR0:
         call MovDPTR_aR0
         jmp LoadByteFromAdrInRam
; RAM[w@R0]=A
MovxaaR0A:
         call MovDPTR_aR0
         jmp SaveByteFromAdrInRam
; DPTR=w@R0
MovDPTR_aR0:
         mov DPL,A
         mov A,@R0
         mov DPH,A
         inc R0
         mov A,@R0
         xch A,DPL
         dec R0
         ret


; A=RAM[w@R0]
LoadByteFromAdrInRamaR0: call MovDPTR_waR0
                         jmp LoadByteFromAdrInRam
; RAM[w@R0]=A
SaveByteFromAdrInRamaR0: call MovDPTR_waR0
                         jmp SaveByteFromAdrInRam
; RAM[w@R0++]=A
SaveByteFromAdrInRamaR0P:
                          call SaveByteFromAdrInRamaR0P
                          call IncwaR0
                          ret
; A=RAM[w@R0++]
LoadByteFromAdrInRamaR0P:
                          call LoadByteFromAdrInRamaR0P
                          push ACC
                          call IncwaR0
                          pop ACC
                          ret
; DPTR=w@R0
MovDPTR_waR0:
                         mov DPH,@R0
                         inc R0
                         mov DPL,@R0
                         dec R0
                         ret
;w@R0=MemData[A]
GetMemDataaR0:
              call GetMemDataAtoBA
              mov @R0,B
              inc R0
              mov @R0,A
              dec R0
              ret

;BA=MemData[A]
GetMemDataAtoBA:
                 rl A
                 mov B,A
                 add A,#IntDataTbl-$-3
                 movc A,@A+PC
                 xch A,B
                 add A,#IntDataTbl-$-3+1
                 movc A,@A+PC
                 ret
IntDataTbl: dw 1,2,3,4,5,6,7


;IncR67:
;                inc R7
;                mov A,R7
;                jnz NoIncR7AFN
;                 inc R6
;NoIncR7AFN:
;        ret
;AddVA_A:    mov B,#0
;AddVA_BA:   add A,VideoAdrLo
;            xch A,VideoAdrLo
;            xch A,VideoAdrHi
;            addc A,B
;            xch A,VideoAdrHi
;            ret

;DPTR-=A; / DPTR-=BA;
SubDPTR_A:  mov B,#0
SubDPTR_BA: clr C
            xch A,DPL
            subb A,DPL
            xch A,DPL
            xch A,DPH
            subb A,B
            xch A,DPH
            ret
;DPTR+=A; / DPTR+=BA;
AddDPTR_A:  mov B,#0
AddDPTR_BA: add A,DPL
            xch A,DPL
            xch A,DPH
            addc A,B
            xch A,DPH
            ret
DecDPTR:mov A,DPL
        dec DPL
        jnz NoDPL_00
         dec DPH
NoDPL_00:
        ret
;++++++++++++++++++++++ DPTR <=> VideoAdr X1z
XchDP_VA:
                      xch A,VideoAdrLo
                      xch A,DPL
                      xch A,VideoAdrLo
                      xch A,VideoAdrHi
                      xch A,DPH
                      xch A,VideoAdrHi
                      ret
;=======================Модуль
AbsC:
        mov A,ParamLL
        jnb ACC.7,NoCplA
         cpl A
         inc A
NoCplA: mov ParamLL,A
        ret

;Allocate mem in stack
;in:  char ParamLL  - size
;Out: char ParamLL - pointer
stack_malloc:
        mov A,SP
        mov R0,A
        add A,ParamLL
        mov SP,A
        mov R1,A
AgainMoveStackDown:
         mov A,@R0
         mov @R1,A
         dec R1
         dec R0
        cjne R0,#stack_begin-1,AgainMoveStackDown
        mov ParamLL,#stack_begin
        ret

;Unallocate mem in stack
;in:  char ParamLL  - size
;Out: bit - 1-error
stack_mfreelast:
        mov A,#stack_begin;SP
        mov R1,A
        add A,ParamLL
        mov R0,A
AgainMoveStackUp:
         mov A,@R0
         mov @R1,A
         mov @R0,#0
         inc R1
         mov A,R0
         inc R0
        cjne A,SP,AgainMoveStackUp
        clr C
        mov A,SP
        subb A,ParamLL
        mov SP,A
        ret
;Load int from mem
;
LoadOpt:
        mov DPTR,#StartSpecOpt
        mov A,ParamLL
        rl A
        call AddDPTR_A
        call LoadByteFromAdrInRam
        mov ParamLH,A
        inc DPTR
        call LoadByteFromAdrInRam
        mov ParamLL,A
        ret
;Save int to mem
SaveOpt:
        mov DPTR,#StartSpecOpt
        mov A,ParamHL
        rl A
        call AddDPTR_A
        mov A,ParamLH
        call SaveByteFromAdrInRam
        inc DPTR
        mov A,ParamLL
        call SaveByteFromAdrInRam
        ret

shrA_B:
        xch A,B
        jz ExitshrA_B
         dec A
         xch A,B
         clr C
         rrc A
         jmp shrA_B
;ExitshlBA_ParamXL:
;        xch A,B
;        ret
shlA_B:
        xch A,B
        jz ExitshlA_B
         dec A
         xch A,B
         clr C
         rlc A
         jmp shlA_B
ExitshrA_B:
ExitshlA_B:
        xch A,B
        ret

shlBA_ParamXL:
         xch A,ParamXL
         jz ExitshlBA_ParamXL
          dec A
          xch A,ParamXL
          clr C
          rlc A
          xch A,B
          rlc A
          xch A,B
          jmp shlBA_ParamXL
;ExitshlBA_ParamXL:
;         xch A,ParamXL
;         ret

shrBA_ParamXL:
         xch A,ParamXL
         jz ExitshrBA_ParamXL
          dec A
          xch A,ParamXL
          xch A,B
          clr C
          rrc A
          xch A,B
          rrc A
          jmp shrBA_ParamXL
ExitshlBA_ParamXL:
ExitshrBA_ParamXL:
         xch A,ParamXL
         ret
;-----------------------------------------------------------------
;byte SetByteFromBitWord(uint BB,uchar ByteAppend,uchar BitShift,uchar BitLen)
;{
; BB=ByteLo|((ByteHi&(~(0xFF<<BitLen)))<<BitShift);
; BitShift=(BitShift+BitLen)&7;
; if (BitLen>8)
;    BitLen-=8;
; else
;    BitLen=0;
;}
;in: uchar ByteLo      ParamLL
;    uchar ByteHi      ParamLH
;    uchar BitShift   ParamHL
;    uchar BitLen     ParamHH
;    uchar A          - ByteAppend
;out: uint BB           ParamL
;     uchar BitShift    ParamHL
;     uchar BitLen=A    ParamHH
;     bit C=1 - 00000000xxxxxxxx
;           0 - xxxxxxxxxxxxxxxx
;-----------------------------------------------------------------
Append2Bytes:
                 push A
                 mov B,BitLen
                 mov A,#0xFF
                 call shlA_B
                 cpl A
                 push A
                 mov B,#0
                 mov ParamXLd,BitShift
                 call shlBA_ParamXL
                 cpl A
                 anl ByteLo,A
                 mov A,B
                 cpl A
                 anl ByteHi,A
                 pop A
                 pop B
                 anl A,B
                 mov B,#0
                 mov ParamXLd,BitShift
                 call shlBA_ParamXL
                 orl ByteLo,A
                 mov A,B
                 orl ByteHi,A
                 call GetNextBitShift
                 ret

;-----------------------------------------------------------------
;byte GetByteFromBitWord(uint BB,uchar BitShift,uchar BitLen)
;{
; uchar Ch=(BB>>BitShift)&(~(0xFF<<BitLen));
; BitShift=(BitShift+BitLen)&7;
; if (BitLen>8)
;    BitLen-=8;
; else
;    BitLen=0;
; return (Ch);
;}
;in: uint BB          ParamL
;    uchar BitShift   ParamHL
;    uchar BitLen     ParamHH
;out: uint BB          ParamL
;     uchar BitShift   ParamHL
;     uchar BitLen     ParamHH
;     uchar A
;     bit C=1 - 00000000xxxxxxxx
;           0 - xxxxxxxxxxxxxxxx
;-----------------------------------------------------------------
GetByteFromWord:
                 mov B,BitLen
                 mov A,#0xFF
                 call shlA_B
                 cpl A
                 push A
                 mov A,ByteLo
                 mov B,ByteHi
                 mov ParamXLd,BitShift
                 call shrBA_ParamXL
                 pop B
                 anl A,B
                 push A
                 call GetNextBitShift
                 pop A
                 ret
;-----------------------------------------------------------------
;GetNextBitShift();
; BitShift=(BitShift+BitLen)&7;
; if (BitLen>8)
;    BitLen-=8;
; else
;    BitLen=0;
;-----------------------------------------------------------------
GetNextBitShift:
                 mov A,BitShift
                 add A,BitLen
                 cjne A,#8,$+3
                 push PSW
                 anl A,#7
                 mov B,A
;                 mov BitShift,A
                 mov A,BitLen
                 add A,#-8
                 jc NoBigger8AB
                  clr A
                  mov BitShift,B
NoBigger8AB:     mov BitLen,A
                 pop PSW
                 ret

LoadByteFromAdrInRamP:
        call LoadByteFromAdrInRam
        inc DPTR
        ret
SaveByteFromAdrInRamP:
        call SaveByteFromAdrInRam
        inc DPTR
        ret
SaveByteFromAdrInRamFP:
        call SaveByteFromAdrInRamF
        inc DPTR
        ret
SaveByteFromAdrInRamF:
        push B
        push A
        call LoadByteFromAdrInRam
        pop B
        xrl A,B
        jz NoMemByteEQ
         mov A,B
         call SaveByteFromAdrInRam
         setb OptChanged
NoMemByteEQ:
        mov A,B
        pop B
        ret
GetDPTR_BA:
           clr A
           movc A,@A+DPTR
           mov B,A
           inc DPTR
           clr A
           movc A,@A+DPTR
           inc DPTR
           ret

    RSEG CSTACK
    org 0
stack_begin:

     END