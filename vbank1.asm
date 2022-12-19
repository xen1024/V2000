/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

 name V_BANK1
;#define BankDebuging

#ifdef BankDebuging
 rseg RCODE
#endif
#ifndef BankDebuging
 RSEG BSEG1
#endif


$vdef.inc
 org 0
StartBank1:
StartVec:
          mov IE,#0
          jmp ResetBank0
;------------------------------------------------------------
;Bank switch functions !!!!!!
          ORG    StartVec + OffsetBankFunctions
ResetBank0:
           clr BankB0
           jmp 0
;------------------------------------------------------------
b1_LoadByteBankCDPTR:  clr A
b1_LoadByteBankCDPTRA: clr IE
                    mov BankB0,C
                    movc A,@A+DPTR
                    inc DPTR
                    clr BankB0
                    setb IE
                    ret
;------------------------------------------------------------
TimerVoice:
                jnb BankPlay,NoPlayingBank1
                 setb BankB0
NoPlayingBank1: push PSW
                push    B                   ;
                xch     A,SamplePosLo       ;
                xch     A,DPL               ;
                xch     A,SamplePosHi       ;
                xch     A,DPH               ;
                xch     A,OutByte           ;
                anl     P4,#3               ;
                orl     A,P4                ;
                mov     P4,A                ;
                movx    @R0,A               ;hP4=OutA|(P4&3);
                clr     A                   ;
                movc    A,@A+DPTR           ;
                mov     B,A                 ;XADR=XMEM[ADDR];
                mov     A,XTone1Lo          ;if (R1!=0)
                jz      X065d               ;
                 add     A,#FastShl1-$-3-1  ;{
                 movc    A,@A+PC            ; XADR=XADRt=High(X6c4[R1]*XMEM[ADDR+1])
                 mov     StepTone2,A        ;        |Low(X6c4[R1]*XMEM[ADDR]);
                 mul     AB                 ;
                 mov     StepTone2+1,A      ;
                 mov     A,#1               ;
                 movc    A,@A+DPTR          ;
                 mov     B,StepTone2        ;
                 mul     AB                 ;
                 mov     A,StepTone2+1      ;}
X065d:          clr BankB0
                orl     A,B                 ;
                mov     StepTone2,DPL       ;
                mov     StepTone2+1,DPH     ;
                mov     DPTR,#SoundUnPackTbl ;
                movc    A,@A+DPTR           ;;//X6c4[XMEM[ADDR]] or X6c4[XADRt]
                mov     DPL,StepTone2       ;
                mov     DPH,StepTone2+1     ;
                mov     B,A                 ;
                anl     A,#7                ;
                inc     A                   ;
                add     A,XTone1Lo          ;R1=X6c4[XADR]&7+R1+1;
                jnb     ACC.3,X0677         ;if (R1&8)
                 anl     A,#7               ;{ R1&=7;                 // R1=00000xxx;
                 inc     DPTR               ;  ADDR++;
X0677:          mov     XTone1Lo,A          ;}
                mov     A,B                 ;
                swap    A                   ;
                anl     A,#0fh              ;A=X6c4[XADR]>>4;     //A=0..7..0xA
                jnb     ACC.3,X0689         ;                     //A=0..7,FF,FE,FD
                                            ;                      +0..7/-1..-3
                 clr     ACC.3              ;if (A&8) A~=A&7;     //A=11111xxx;
                 cpl     A                  ;
X0689:          add     A,XrlByte           ;A=x3eh=x3eh+A;      //
                mov     XrlByte,A           ;
                swap    A                   ;
                rr      A                   ;
                xch     A,OutByte           ;OutA=A.43210765;     //OutA=xXXXXXxx=xxxxxx000
                xch     A,DPH               ;
                xch     A,SamplePosHi       ;
                xch     A,DPL               ;
                xch     A,SamplePosLo       ;
                djnz    WawLenLo,X0680      ;if (LEN--) tr0=fAlse; //end loop
                 djnz    WawLenHi,X0680     ;
                  clr     TR1               ;}
                  setb    EndWavPlay
X0680:                                      ;
                pop     B                   ;while(tr0);
                pop PSW
                reti
FastShl1: db 0x02,0x04,0x08,0x10,0x20,0x40,0x80
;------------------------------------------------------------
 END