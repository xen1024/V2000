/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

   Name OptionsWork
   rseg CODE

   public LoadValue,SaveValue,GetVideoDataOnOption
   public GetKeyEditOnTypeEdit,LoadValueN,SaveValueN,CustomMinMax
   public TestMinMaxValue,OptConst
   $DEFFN GetKeyEditOnTypeEdit(0,0,0,0,0,0,0,0)
   $DEFFN LoadValue(0,0,0,0,0,0,0,0),LoadNumber
   $DEFFN SaveValue(0,0,0,0,0,0,0,0),LoadNumber,SaveNumber
   $DEFFN SaveValueN(0,0,0,0,0,0,0,0),LoadNumber,SaveNumber
   $DEFFN LoadValueN(0,0,0,0,0,0,0,0),LoadNumber
;   public SaveNumberOpt
;   $DEFFN SaveNumberOpt(0,0,0,0,0,0,0,0),SaveNumber
   public GetNumberNumber
   $DEFFN GetNumberNumber(0,0,0,0,0,0,0,0)
   public GetNumberBook
   $DEFFN GetNumberBook(0,0,0,0,0,0,0,0)
   $DEFFN GetVideoDataOnOption(2,0,0,0,1,0,0,0),LoadValue
   public ResetOptions
   $DEFFN ResetOptions(2,0,0,0,0,0,0,0)

   public BookOpt

#define __OptWork
$vdef.inc

#define WorkBook $PRMBD LoadNumber

;------------------------------------------------------------
;------------------------------------------------------------
;OptionsWork
;------------------------------------------------------------
;------------------------------------------------------------

;------------------------------------------------------------
;LoadValue(uchar)
;in: ParamLL - number of option
;out: Paramxx     ___- Data
;------------------------------------------------------------
LoadValueN:setb NoChangeOpt
           jmp LoadValueA
LoadValue: clr NoChangeOpt
LoadValueA:
           clr BookOpt
           clr OptConst
           call GetAddressOfOption
           jb NoChangeOpt,NoChgOpt3
            mov LenEdit,A
NoChgOpt3:
           jb OptConst,DontLoadMemPack
           push ParamHLd
           push ParamHHd
           call GetWordFromConstBit

          jb NoChangeOpt,NoChgOpt4
           call GetMinOptionValue
           mov MinValue,ParamHL
           call GetMaxOptionValue
           mov MaxValue,ParamHL

           mov ParamLH,#3
AgainGetLenEdit:
            mov A,ParamLH
            rl A
            call ABTabelAHTDW_A
            mov ParamYH,A
            mov A,ParamHL
            clr C
            subb A,ParamYH
            mov A,ParamHH
            subb A,B
            jc NoIncLenEdit
             inc LenEdit
             mov A,ParamLH
             jz NoIncLenEdit
             dec ParamLH
             jnz AgainGetLenEdit
NoIncLenEdit:
NoChgOpt4:
           pop ParamHHd
           pop ParamHLd
           call XchDP_VA
           call GetWordFromMemPack
           jb NoChangeOpt,NoChgOpt5
            call TestMinMaxValue
            clr CustomMinMax
NoChgOpt5: clr NoChangeOpt
DontLoadMemPack:
           jnb BookOpt,NoLoadNumber
            jb SaveNumberNow,NoLoadNumber
             mov ParamHL,WorkBook
             jmp LoadNumber
NoLoadNumber:
           ret
;------------------------------------------------------------
;SaveValue(uchar,uint)
;in: ParamLL - number of option
;    ParamH  - data for save
;out: C = 1 - Saved
;         0 - Error
;------------------------------------------------------------
SaveValueN:setb NoChangeOpt
           jmp SaveValueA
SaveValue: clr NoChangeOpt
SaveValueA:
           clr BookOpt
           clr OptConst
           mov ParamXLd,ParamHL
           mov ParamXHd,ParamHH
           call GetAddressOfOption

           jb OptConst,SaveValueNumber
           clr OptChanged
           call GetWordFromConstBit

           jb NoChangeOpt,NormalCompare
           jnb CustomMinMax,NormalCompare
            push ParamLLd
            mov ParamLL,ParamXLd
            call TestMinMaxValue
            mov ParamXL,ParamLLd
            pop ParamLLd
            jc ErrorOptionSet
            jmp NormalValueLimit
NormalCompare:
SaveCurrValue:
           call GetMinOptionValue
           mov A,ParamHL
           setb C
           subb A,ParamXL
           mov A,ParamHH
           subb A,ParamXH
           jnc ErrorOptionSet
            call GetMaxOptionValue
            mov A,ParamHL
            clr C
            subb A,ParamXL
            mov A,ParamHH
            subb A,ParamXH
            jc ErrorOptionSet
NormalValueLimit:
             call GetAddressOfOption
             call XchDP_VA
             mov ParamLLd,ParamXL
             mov ParamLHd,ParamXH
;             mov ParamHLd,ParamLL
;             mov ParamHHd,ParamLH
             push ParamLLd
             push ParamLHd
             call SetWordToMemPack
             pop ParamLHd
             pop ParamLLd
SaveValueNumber:
             jbc SaveNumberNow,?SaveValueNumber
             setb C
             ret
ErrorOptionSet:
             clr C
             ret
?SaveValueNumber:
             setb OptChanged
             mov ParamHL,WorkBook
             jmp SaveNumber
;------------------------------------------------------------
GetNumberNumber:
           clr BookOpt
           clr OptConst
;           mov ParamXLd,ParamHL
;           mov ParamXHd,ParamHH
           call GetAddressOfOption
;           mov $PRMBD SaveNumber+2,WorkBook
;           jmp SaveNumber
           ret
GetNumberBook:
           clr BookOpt
           clr OptConst
;           mov ParamXLd,ParamHL
;           mov ParamXHd,ParamHH
           call GetAddressOfOption
           mov ParamLL,WorkBook
           ret

;------------------------------------------------------------
;GetAddressOfOption()
;in: ParamLL - number of option
;out: DPTR - Address of option TypeByte
;     VA   - Address of option in mem
;     BitShift - Bit offset in byte
;------------------------------------------------------------
EndFindOption:
         jmp GetParamOption
;        call GetParamOption
;        ret
GetAddressOfOption:
                mov BitShift,#0
                mov DPTR,#StartAddrOpt
                call XchDP_VA
                mov DPTR,#FormatOptionsTBL
                mov XOption,#0
AgainGetAddressOfOption:
                mov A,XOption
                cjne A,ParamLLd,$+3
                jnc EndFindOption
?AgainGetAddressOfOption:
                 call GetTypeByteOption
                 xch A,B
                 cjne A,#Array256,NoSpecicalData0
                  inc DPTR
                  clr A
                  movc A,@A+DPTR
                  inc DPTR
                  inc DPTR
                  inc DPTR
                  push A
                  call GetTypeByteOption
                  pop B
                  call ArrayGetVA_BitShiftOnBA
                  call GetTypeByteOption
                  jmp NextSpcOption
NoSpecicalData0:
                 cjne A,#DAChar,NoSpecicalData1
?SpecicalData1:   inc DPTR
                  inc DPTR
                  inc DPTR
                  call GetTypeByteOption
                  jmp NextSpcOption
NoSpecicalData1: cjne A,#NumberBookO,NoSpecicalData2
                  inc DPTR
;                  inc DPTR
;                  inc DPTR
;                  inc DPTR
;                  call GetTypeByteOption
;                  jmp NoSpecicalData
                  jmp ?SpecicalData1
NoSpecicalData2: cjne A,#NumberConstO,NoSpecicalData3
                  mov A,#7
                  jmp NextOptionAddress
NoSpecicalData3: xch A,B
NoSpecicalData:  add A,BitShift
                 push A
                 push B
                 rl A
                 swap A
                 anl A,#0x0F
                 call XchDP_VA
                 call AddDPTR_A
                 call XchDP_VA
                 pop B
                 pop A
                 anl A,#0x7
                 mov BitShift,A
NextSpcOption:

                 mov A,B
                 anl A,#0x70
                 swap A
                 rl A
                 mov AddrPlusO,#2
                 push DPH
                 push DPL
                 mov DPTR,#EJMP_TBL0
                 push DPL
                 push DPH
                 mov DPTR,#JMP_TBL0
                 jmp @A+DPTR
JMP_TBL0:
 sjmp Pmmo0_1N
 sjmp Pmmo0_9S
 sjmp Pmmo0_99S
 sjmp Pmmo0_ctmS
 sjmp Pmmo0_ctmN
 sjmp Pmmoctm_ctmS
 sjmp Pmmo0_0xFFC
 sjmp Pmmoctm_ctmC

Pmmo0_0xFFC:
                  inc AddrPlusO
                  ret
Pmmoctm_ctmC:
                  inc AddrPlusO
Pmmoctm_ctmS:
                  call AddByteLen_AddrPlusO
Pmmo0_ctmS:
Pmmo0_ctmN:
                  jmp AddByteLen_AddrPlusO
Pmmo0_1N:
Pmmo0_9S:
Pmmo0_99S:
                  ret

EJMP_TBL0:
                 pop DPL
                 pop DPH
                 mov A,ByteLen
                 add A,AddrPlusO
NextOptionAddress:
                 call AddDPTR_A
                 inc XOption
                jmp AgainGetAddressOfOption
AddByteLen_AddrPlusO:
         xch A,AddrPlusO
         add A,ByteLen
         xch A,AddrPlusO
         ret

;------------------------------------------------------------
;BitShift=(BitShift+(BitLen*Size))&0x7
;AddrMem+=(BitLen*Size)>>3
;in:A-bitlen
;   B-ElementOfArray
;out: VA-New VA
;     BitShift-new BitShift
;------------------------------------------------------------
ArrayGetVA_BitShiftOnBA:
                  mul AB
                  add A,BitShift
                  push A
                  anl A,#0x7
                  mov BitShift,A
                  pop A
                  rl A
                  swap A
                  anl A,#0x1F
                  xch A,B
                  rl A
                  swap A
                  anl A,#0x70
                  orl A,B
                  call XchDP_VA
                  call AddDPTR_A
                  call XchDP_VA
                  ret

;------------------------------------------------------------
;uchar GetKeyEditOnTypeEdit();
;out: ParamLL - keymap on current mode edit
;------------------------------------------------------------
GetKeyEditOnTypeEdit:
           mov A,TypeEdit
           mov TypeEdit,#teSerialEnter
           add A,#KeyTypeTBL-$-3
           movc A,@A+PC
           mov ParamLL,A
           ret
KeyTypeTBL: db kmEdIncDec,kmEdSerialPaste,kmNone
;------------------------------------------------------------
;uchar GetVideoDataOnOption(uchar);
;in: ParamLL - Selected Option
;out: ParamLL - Video Data Number
;------------------------------------------------------------
#define LowVD           $LOCBD GetVideoDataOnOption
#define HighVD          $LOCBD GetVideoDataOnOption+1
#define CurrVD          $PRMBD GetVideoDataOnOption
#define CurrentValue    LowVD
#define CurrVideoData   ParamHLd

GetVideoDataOnOption:
           mov C,SaveNumberNow
           push PSW
           setb SaveNumberNow
           clr A
           mov LowVD,A
           mov HighVD,A
           mov CurrVD,A
           mov CurrentValue,A
;           mov CurrVideoData,A
           mov DPTR,#StartVideoTbl
           mov CurrVideoData,#vStartVideoForOptions-1
           movc A,@A+DPTR
           mov HighVD,A
           inc DPTR
AgainGetVideoDataOnOption:
            mov LowVD,HighVD
            clr A
            movc A,@A+DPTR
            mov HighVD,A
            inc DPTR
            mov A,HighVD
            setb C
            subb A,ParamLL
            inc CurrVideoData
           jc AgainGetVideoDataOnOption

           push CurrVideoData
           mov A,ParamLL
           clr C
           subb A,LowVD
           mov SelectedValue,A
           mov CurrVD,LowVD
           mov CurrentValue,#ValueData
AgainGetValueDataOnOption:
            mov ParamLL,CurrVD
            call LoadValue
            mov R0,CurrentValue
            mov @R0,ParamLLd
            inc R0
            mov A,LenEdit
            mov C,ACC.7
            jnc NoWordUse
             mov @R0,ParamLHd
             inc R0
NoWordUse:  mov CurrentValue,R0
            inc CurrVD
            mov A,CurrVD
            clr C
            subb A,HighVD
           jc AgainGetValueDataOnOption
           pop ParamLLd
           pop PSW
           mov SaveNumberNow,C
           ret
;------------------------------------------------------------
;GetParamOption();
;in: DPTR - Address of option TypeByte
;out: KeyTypeView
;     TypeEdit
;     TypeOfData
;     DPTR - Address of DefaultValue option
;------------------------------------------------------------
GetParamOption:
           call GetTypeByteOption
           xch A,B
           cjne A,#Array256,NoArrayOption
            inc DPTR
            clr A
            movc A,@A+DPTR
            push A
            inc DPTR
            call GetDPTR_BA
            push DPH
            push DPL
            mov DPL,A
            mov DPH,B
            call LoadByteFromAdrInRam
            pop DPL
            pop DPH
            pop B
            cjne A,B,$+3
            jc NoOutOfArray
             mov A,B
             dec A
NoOutOfArray:
            push A
            call GetTypeByteOption
            pop B
            call ArrayGetVA_BitShiftOnBA
            call GetTypeByteOption
            jmp NextGetParamOption
NoArrayOption:
           cjne A,#DAChar,NoDACharOption
?DACharOption:
            inc DPTR
            call GetDPTR_BA
            mov VideoAdrLo,A
            mov VideoAdrHi,B
            mov BitShift,#0
            call GetTypeByteOption
            jmp NextGetParamOption
NoDACharOption:
           cjne A,#NumberBookO,NoNumberBookOOption
            inc DPTR
            clr A
            movc A,@A+DPTR
            mov WorkBook,A
            setb BookOpt
;            inc DPTR
;            mov BitShift,#0
;            call GetTypeByteOption
;            jmp NextGetParamOption
            jmp ?DACharOption
NoNumberBookOOption:
           cjne A,#NumberConstO,NoNumberConstOOption
            inc DPTR
            clr A
            movc A,@A+DPTR
            mov KFunc,A
            inc DPTR
            clr A
            movc A,@A+DPTR
            mov WorkBook,A
            setb BookOpt
            setb OptConst
            inc DPTR
            call GetDPTR_BA
            mov ParamLL,A
            mov ParamLH,B
            call GetDPTR_BA
            mov DPL,A
            mov DPH,B
            cjne A,#Low(-1),NoSpecicalNumberConstO
             mov A,B
             cjne A,#High(-1),NoSpecicalNumberConstO
              ret
NoSpecicalNumberConstO:
            call LoadByteFromAdrInRam
            add A,ParamLL
            mov ParamLL,A
            jnc NoIncXXX
             inc ParamLH
NoIncXXX:   ret
NoNumberConstOOption:
           xch A,B
NextGetParamOption:
           inc DPTR
           clr A
           movc A,@A+DPTR
           inc DPTR
           jb NoChangeOpt,NoChgOpt0
            mov KFunc,A
NoChgOpt0: mov A,B
           mov C,ACC.7
           jb NoChangeOpt,NoChgOpt1
            mov TypeOfData,C
NoChgOpt1: call GetTypeEditOption
           jb NoChangeOpt,NoChgOpt2
            mov TypeEdit,A
NoChgOpt2: mov A,B
;           rl A
           swap A
           anl A,#0xF0
           ret
;------------------------------------------------------------
;GetWordFromConstBit
;in: DPTR - Address of option load data
;out: uint ParamH - word
;     DPTR+=ByteLen
;------------------------------------------------------------
GetWordFromConstBit:
                clr A
                mov ParamHH,A
                movc A,@A+DPTR
                mov ParamHL,A
                inc DPTR
                mov A,ByteLen
                dec A
                jz NoByteUse
                 clr A
                 movc A,@A+DPTR
                 inc DPTR
                 xch A,ParamHL
                 mov ParamHH,A
NoByteUse:
                ret
;------------------------------------------------------------
;GetTypeEditOption();
;in: DPTR - Address of option TypeByte
;    A - TypeByte
;out: A - TypeEdit
;------------------------------------------------------------
GetTypeEditOption:
                  anl A,#0x70
                  swap A
                  add A,#KeyEditTBL-$-3
                  movc A,@A+PC
                  cjne A,#tectmV,NoCustomKeyMap
                   clr A
                   movc A,@A+DPTR
                   inc DPTR
NoCustomKeyMap:   ret
KeyEditTBL: db teIncDec,teSerialEnter,teSerialEnter,teSerialEnter,\
               teIncDec,teSerialEnter,tectmV,tectmV
;------------------------------------------------------------
;GetTypeByteOption()
;in:DPTR - Address of option TypeByte
;out: B       - TypeByte
;     ByteLen - Len of data in byte
;     BitLen  - Len of data in bit
;------------------------------------------------------------
GetTypeByteOption:
                 clr A
                 movc A,@A+DPTR
                 mov B,A
                 anl A,#0xF
                 mov ByteLen,#1
                 jnb ACC.3,No2ByteUsed
                  inc ByteLen
No2ByteUsed:     inc A
                 mov BitLen,A
                 ret
;------------------------------------------------------------
;GetWordFromMemPack()
;in: DPTR - Address in mem
;    BitShift - Bit offset in byte
;    BitLen - Len of data in bit
;out: uint ParamL - Data
;------------------------------------------------------------
GetWordFromMemPack:
                mov R0,#_R+1
                call LoadByteFromAdrInRamP
                mov ByteLo,A
AgainGetWordFromMemPackA:
                 call LoadByteFromAdrInRamP
                 mov ByteHi,A
AgainGetWordFromMemPack:
                 call GetByteFromWord
                 mov @R0,A
                 mov A,BitLen
                 jz ExitGetWordFromMemPack
                 inc R0
                 jc NoNextByteMem0
                  mov ByteLo,ByteHi
                  jmp AgainGetWordFromMemPackA
NoNextByteMem0:
                jmp AgainGetWordFromMemPack
ExitGetWordFromMemPack:
                mov ParamLL,_R+1
                mov ParamLH,_R+2
                ret
;------------------------------------------------------------
;SetWordToMemPack()
;in: DPTR - Address in mem
;    BitShift - Bit offset in byte
;    BitLen - Len of data in bit
;    uint ParamL - Data
;out:
;------------------------------------------------------------
SetWordToMemPack:
                mov _R+1,ParamLL
                mov _R+2,ParamLH
                mov R0,#_R+1
                call LoadByteFromAdrInRamP
                mov ByteLo,A
                call LoadByteFromAdrInRam
                mov ByteHi,A
                call DecDPTR
                jmp AgainSetWordToMemPack
AgainSetWordToMemPackA:
                 mov ByteLo,ByteHi
                 call LoadByteFromAdrInRam
                 mov ByteHi,A
                 call DecDPTR
AgainSetWordToMemPack:
                 mov A,@R0
                 push _R+2
                 call Append2Bytes
                 pop _R+2
                 mov A,ByteLo
                 call SaveByteFromAdrInRamFP
                 jc NoNextByteMem2
                  mov A,ByteHi
;           mov DPTR,#StartAddrOpt
;           mov A,#3
;           call SaveByteFromAdrInRam
;           mov DPTR,#StartAddrOpt+1
;           mov A,#7
;           call SaveByteFromAdrInRam
                  call SaveByteFromAdrInRamFP
NoNextByteMem2:
                 mov A,BitLen
                 jz ExitSetWordToMemPack
                 inc R0
                 jnc AgainSetWordToMemPackA
                jmp AgainSetWordToMemPack
ExitSetWordToMemPack:
                ret

;------------------------------------------------------------
;GetMinOptionValue()
;GetMaxOptionValue()
;in: B - type MinMax
;out: ParamH - uint min/max
;------------------------------------------------------------
GetMaxOptionValue:
           mov A,B
           add A,#MaxOptTBL-$-3
           movc A,@A+PC
           jmp TestCustomValue
MaxOptTBL: db 1,9,99,mmoctmV,mmoctmV,mmoctmV,0xFF,mmoctmV

GetMinOptionValue:
           mov A,B
           swap A
           anl A,#0x7
           mov B,A

;           mov A,B
           add A,#MinOptTBL-$-3
           movc A,@A+PC
           jmp TestCustomValue
MinOptTBL: db 0,0,0,0,0,mmoctmV,0,mmoctmV

TestCustomValue:
           cjne A,#mmoctmV,NoCustomValue
            call GetWordFromConstBit
            ret
NoCustomValue:
           mov ParamHL,A
           mov ParamHH,#0
           ret
;------------------------------------------------------------
;TestMinMaxValue();
;in:ParamLL
;------------------------------------------------------------
TestMinMaxValue:
               mov A,LenEdit
               jb ACC.7,NoMaxValue
                mov A,ParamLL
                cjne A,MinValue,$+3
                jnc NoMinValue
                 mov ParamLL,MinValue
                 ret
NoMinValue:     setb C
                subb A,MaxValue
                jc NoMaxValue
                 mov ParamLL,MaxValue
                 setb C
                 ret
NoMaxValue:     clr C
                ret

;TestOptionSaveLoad:
;                mov ParamLL,#oLastOption
;                call SaveValue
;
;                mov ParamLL,#0
;                mov ParamHL,#1
;                mov ParamHH,#0
;AgainTestOptionSaveLoad:
;                push ParamHHd
;                push ParamHLd
;                push ParamLLd
;                call SaveValue
;                pop ParamLLd
;                push ParamLLd
;                call LoadValue
;                pop ParamLLd
;                pop ParamHLd
;                pop ParamHHd
;                inc ParamLL
;                cjne ParamHL,#5,AgainTestOptionSaveLoad
;                ret
;StartOptionEdit:
;                jb TypeOfData,NoConvertHtoD
;                 mov R0,#EditBuff
;                 mov A,@R0
;                 call HexToDec
;NoConvertHtoD:
;                ret
;------------------------------------------------------------
;in: ParamLL - start option
;    ParamLH - end option
;------------------------------------------------------------
#define StartOptionReset $LOCBD ResetOptions
#define EndOptionReset   $LOCBD ResetOptions+1
ResetOptions:
             mov StartOptionReset,ParamLL
             mov EndOptionReset,ParamLH
AgainResetOptions:
              mov ParamLL,StartOptionReset
              clr BookOpt
              clr OptConst
;              mov ParamXLd,ParamHL
;              mov ParamXHd,ParamHH
              call GetAddressOfOption

              clr OptChanged
              call GetWordFromConstBit
              mov ParamXLd,ParamHL
              mov ParamXHd,ParamHH
              call SaveCurrValue

              inc StartOptionReset
              mov A,EndOptionReset
             cjne A,StartOptionReset,$+3
             jnc AgainResetOptions

             ret
 RSEG BITVARS
NoChangeOpt:  DS 1
CustomMinMax: DS 1
BookOpt:      DS 1
OptConst:     DS 1
 END