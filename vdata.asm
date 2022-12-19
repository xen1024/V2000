/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */


 public FormatOptionsTBL,StartVideoTbl,SoundUnPackTbl
StartVideoRom:
                dw ViewMainMode           ;vMain
                dw SelectMode             ;vMode
                dw ViewSetup              ;vSetup
                dw ViewEditNumber         ;vViewEditNumber
                dw ViewCalling            ;vCalling
                dw ViewRequestOut         ;vRequestOut
                dw ViewEditNumberO        ;vViewEditNumberO
                dw ViewBookSelect         ;vViewBookSelect
                dw VClearNumber           ;vClearNumber
                dw VClearNumber1          ;vClearNumber1
                dw VBusy                  ;vBusy
                dw VKateg                 ;vKateg
                dw VTimeCall              ;vTimeCall
                dw VTimeSay               ;vTimeSay
                dw VDateCall              ;vDateCall
                dw VCallsPerTime          ;vCallsPerTime
                dw VAllTimeSay            ;vAllTimeSay
                dw VShowIndificated       ;vShowIndificated
                dw VShowTimeSayingNow     ;vShowTimeSayingNow
                dw VResetMode             ;vResetMode
                dw VTimeOutReset          ;vTimeOutReset
                dw VBCalling              ;vBCalling
                dw VSoundMode             ;vSoundMode
                dw VParallelDetect        ;vParallelDetect
                dw VLockingNumber         ;vLockingNumber
                dw VHold                  ;vHold
                dw VGetLine               ;vGetLine
                dw VSearchNumber          ;vSearchNumber
                dw VShowNotFound          ;vShowNotFound
                dw VFlash                 ;vFlash
                dw VAntiAON               ;vAntiAON
                dw VShowLabelFilterStatus ;vShowLabelFilterStatus
                dw VStoreCustomBook       ;vStoreCustomBook
                dw VStoreCustomNumber     ;vStoreCustomNumber
                dw VTestPassword          ;vTestPassword
                dw VShowTestPassword      ;vShowTestPassword
                dw VSecondsSet            ;vSecondsSet
                dw VAlarmPlay             ;vAlarmPlay
                dw VAlarmDial             ;vAlarmDial
                dw VAutoDial              ;vAutoDial
                dw VConfidenceShow        ;vConfidenceShow
                dw VRemoteAccessKey       ;vRemoteAccessKey
                dw VAutoDialCustomNumber  ;vAutoDialCustomNumber

                dw VShowError             ;vShowError
                dw VShowLogo              ;vShowLogo
                dw VShowVersionInfo       ;vShowVersionInfo
                dw VDebugBeep             ;vDebugBeep

                dw VExtFunc               ;vExtFunc

                dw Test_vdViewHexMemI     ;vTestHexI
                dw Test_ViewHexStringMemX ;vTestHexString
                dw ViewRAMdata            ;vTestRAMdata
                dw Debug_KeyView          ;vDebugKeyView
                dw TestEdit0              ;vTestEdit0

                dw VOpt0A                 ;vOpt0A
                dw VOpt1A                 ;vOpt1A
                dw VOpt2A                 ;vOpt2A
                dw VOpt3A                 ;vOpt3A
                dw VOpt4A                 ;vOpt4A
                dw VOpt5A                 ;vOpt5A
                dw VOpt6A                 ;vOpt6A
                dw VOpt7A                 ;vOpt7A
                dw VOpt8A                 ;vOpt8A

                dw VOpt0B                 ;vOpt0B
                dw VOpt1B                 ;vOpt1B
                dw VOpt2B                 ;vOpt2B
                dw VOpt3B                 ;vOpt3B
                dw VOpt4B                 ;vOpt4B
                dw VOpt5B                 ;vOpt5B
                dw VOpt6B                 ;vOpt6B
                dw VOpt7B                 ;vOpt7B
                dw VOpt8B                 ;vOpt8B
                dw VOpt9B                 ;vOpt9B

                dw VOpt0X                 ;vOpt0X
                dw VOpt1X                 ;vOpt1X
                dw VOpt2X                 ;vOpt2X
                dw VOpt3X                 ;vOpt3X
                dw VOpt4X                 ;vOpt4X

                dw VOpt0C                 ;vOpt0C
                dw VOpt1C                 ;vOpt1C
                dw VOpt2C                 ;vOpt2C
                dw VOpt3C                 ;vOpt3C
                dw VOpt4C                 ;vOpt4C
                dw VOpt5C                 ;vOpt5C

                dw VAlarm0                ;vAlarm0
                dw VAlarm1                ;vAlarm1
                dw VAlarm2                ;vAlarm2
                dw VAlarm3                ;vAlarm3
                dw VAlarm4                ;vAlarm4

                dw VNightOn               ;vNightOn
                dw VNightFrom             ;vNightFrom
                dw VNightTo               ;vNightTo
                dw VNightBells            ;vNightBells

                dw VOpt0D                 ;vOpt0D
                dw VOpt1D                 ;vOpt1D
                dw VOpt2D                 ;vOpt2D
                dw VOpt3D                 ;vOpt3D
                dw VOpt4D                 ;vOpt4D
                dw VOpt5D                 ;vOpt5D
                dw VOpt6D                 ;vOpt6D
                dw VOpt7D                 ;vOpt7D
                dw VOpt8D                 ;vOpt8D
                dw VOpt9D                 ;vOpt9D

                dw VBookShowSpecical      ;vBookShowSpecical
                dw VBookShow              ;vBookShowWhite
                dw VBookShow              ;vBookShowBlack
                dw VBookShow              ;vBookShowBlackLock
                dw VBookShowInOut         ;vBookShowIn
                dw VBookShowInOut         ;vBookShowOut
                dw VBookShow              ;vBookShowZK

                dw VAONModeSelect         ;vAONModeSelect
                dw VBCall                 ;vBCall
                dw VBCallNumber           ;vBCallNumber
                dw VReaddressNumber       ;vReaddressNumber
                dw VReaddressTime         ;vReaddressTime
                dw VPagerNumber           ;vPagerNumber
                dw VPagerAbonent          ;vPagerAbonent

                dw VFilter                ;vFilter

                dw VPassword0             ;vPassword0
                dw VPassword1             ;vPassword1
                dw VAONLock               ;vAONLock
                dw VLockArea              ;vLockArea
                dw VLockAllCalls          ;vLockAllCalls
                dw VLockNumber            ;vLockNumber
                dw VLockCountry           ;vLockCountry

                dw VTimeSet               ;vTimeSet
                dw VDateSet               ;vDateSet
VExtFunc:
 db zSP,vdChangeTM,MigType2,zE|zpixel,zF,zu,zn,zc,zt,vdExit

VDebugBeep:
 db vdViewDeccv,vdPixel,vdViewDeccv,vdPixel,vdViewDeccv,vdPixel,vdViewDeccv,vdPixel,vdViewHalfDeccv,vdExit

VAutoDialCustomNumber:
 db zC,zA,zL,zL|zpixel,zn,zo,zSP,vdViewDeccv,vdExit
VShowVersionInfo:
 db vdViewOffsetDatacv
 db zU,zA,zMNS,zA,zL,zP,zH,zA,zMNS,zt,zE,zS,zt
 db zSP,zd,zA,zt,zE,zMNS
 db z0+((DATE 4)/10),(z0+((DATE 4)%10))|zpixel
 db z0+((DATE 5)/10),(z0+((DATE 5)%10))|zpixel
 db z2,z0,z0+((DATE 6)/10),(z0+((DATE 6)%10))|zpixel
 db zSP,zt,zI,zMl,zMr,zE,zMNS
 db z0+((DATE 3)/10),(z0+((DATE 3)%10)),vdVwChTM,MigType1,zMNS
 db z0+((DATE 2)/10),(z0+((DATE 2)%10)),vdVwChTM,MigType1,zMNS
 db z0+((DATE 1)/10),(z0+((DATE 1)%10))
 ;db zSP,zb,zu,zi,zll,zd,zMNS,z0,z6,z6
 db zSP|zpixel,zSP|zpixel,zSP|zpixel,zSP|zpixel,zSP|zpixel,zSP|zpixel,zSP|zpixel,vdVwChTM,MigType1,zSP|zpixel,vdVwChTM,MigType2,zSP|zpixel
 db vdVwChTM,MigType1,zSP|zpixel,vdVwChTM,MigType2,zSP|zpixel
 db vdExit

VRemoteAccessKey:
 db zSP,zSP,zSP,zd,zU,vdExit
VConfidenceShow:
 db zSP,zC,zO,zPr,zF|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)

VShowLogo:
 db vdJumpcv,High(LogoA),Low(LogoA)
LogoA:
; db zSP,zA,zL,zP,zH,zA,zMNS,zU,zA,vdExit
 db zSP,zSP,zSP,zU,zA,vdExit
 db zSP,z3,z8,zMNS,z0,z4,z4,vdExit
 db z2,z4,z2,zMNS,z9,z8,zMNS,z4,z8,vdExit

; db zA,zL,zP,zH,zA|zpixel,z2,z0,z0,z0,vdExit
VAlarmDial:
 db zE|zpixel,zC|zpixel,vdViewNumber,vdExit
VAlarmPlay:
 db zE,vdViewHalfDeccv,vdPixel,vdViewNumber,vdExit

VShowError:
 db zE,zr,zr|zpixel,vdCallcv,High(VErrors),Low(VErrors),vdExit
VErrors:
 db z2,z4,zL,zC,z1,z6,vdExit
 db zSP,zPr,z3,zY,vdExit
 db zSP,zChr,zA,zC,zb,zIl,vdExit

VTestPassword:
 db zP,zA,zS,zS|zpixel,zMNS,vdShowPWDcv,4,vdExit
VShowTestPassword:
 db zP,zA,zS,zS|zpixel,zMNS,vdChangeTM,MigType2,zC,zO,zd,zE,vdExit

VTimeSet:
 db zt|zpixel,zSP,vdViewDeccv,zMNS,vdViewDeccv,vdExit
VDateSet:
 db vdViewDeccv,zMNS,vdViewDeccv,zMNS,vdViewDeccv,vdExit

VStoreCustomBook:
 db zS,zt,zo,zr,zE|zpixel,zSP,vdChangeTM,MigType2,z_,vdExit ;zMNS,vdViewHalfDeccv,
VStoreCustomNumber:
 db zNr,zO,zMl,zMr,zE,zP|zpixel,zMNS,vdViewDeccv,vdExit

VFilter:
 db zF,zI,zL,zt,zE,zr|zpixel,vdShowFiltercv,MaxAONLabelType,vdExit
VShowLabelFilterStatus:
 db vdChangeSMT,NoMig,zSP,vdCallcv,High(VAONLabelFilter),Low(VAONLabelFilter),zMNS,vdChangeTM,MigType2,vdJumpcv,High(VOnOff),Low(VOnOff)
VAONLabelFilter:
 db zBr|zpixel,zC|zpixel,vdExit
 db zC|zpixel,zC|zpixel,vdExit
 db zChr|zpixel,zC|zpixel,vdExit

VPassword0: ;Password on/off
 db zP,zA,zS,zS,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)
VPassword1: ;Password xxxx                  {if (PasswordOn)}
 db zP,zA,zS,zS,zMNS,vdShowPWDcv,4,vdExit
VAONLock:  ;AON lock Off/MainModes/All
 db zA,zO,zNr|zpixel,zb,zll|zpixel,zMNS,vdJumpcv,High(AONlock),Low(AONlock)
AONlock:
 db zO,zF,zF,vdExit
 db zO|zpixel,zP|zpixel,vdExit
 db zA,zL,zL,vdExit
VLockArea: ;Lock Area Parallel/Parallel+AON
 db zNr,zA,zBr,zO,zP|zpixel,zMNS,vdJumpcv,High(LockArea),Low(LockArea)
LockArea:
 db zt,zE,zL,vdExit
 db zA,zL,zL,vdExit
VLockAllCalls: ;Lock All numbers On/Off
 db zVr,zC,zE|zpixel,zSP,zn,zo|zpixel,vdJumpcv,High(VOnOff),Low(VOnOff)
VLockNumber: ;Lock LockNumber On/Off        {if (!LockAllCalls)}
 db zb,zll,zSP,zn,zo|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)
VLockCountry: ;Lock LockCountryCode On/Off  {if (!LockAllCalls)}
 db zL|zpixel,zC,zO,zd,zE|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)

VAntiAON:
 db zSP,zSP,vdChangeTM,MigType2,zA,zMNS,zA,zO,zNr,vdExit
VFlash:
 db zSP,zSP,vdChangeTM,MigType2,zF,zL,zA,zS,zH|zpixel,vdExit
 ;vdChangeTM,NoMig,vdViewNumber,
VShowNotFound:
 db zn,zo,zt,zSP,zF,zo,zu,zn,zd,vdExit
VSearchNumber:
 db vdChangeTM,MigType2,vdCallcv,High(BookTypes),Low(BookTypes),vdChangeTM,NoMig,vdViewNumberType,vdViewNumber,vdExit
BookTypes:
 db z7,vdExit
 db z8,vdExit
 db z9,vdExit
 db zBr|zpixel,vdExit
 db zChr|zpixel,vdExit
 db zC|zpixel,vdExit

VGetLine:
 db zSP,vdChangeTM,MigType2,zL,zn|zpixel,zSP,zS,zA,zV,zE,vdExit
VHold:
 db zSP,zSP,vdChangeTM,MigType2,zH,zo,zll,zd,vdExit
VLockingNumber:
 db vdVwChTM,MigType2,zL|zpixel,vdViewNumberType,vdViewNumber,vdExit
VParallelDetect:
 db zP,vdViewNumberType,vdPixel,vdViewNumber,vdExit
VSoundMode:
 db zSP,zSP,zS,zo,zu,zn,zd,vdExit
VBCalling:
 db zb,zc|zpixel,vdViewNumber,vdExit
VAONModeSelect:
 db zSP,zP|zpixel,zMNS,vdViewHalfDeccv,zSP,zSP,vdDecCV,vdJumpcv,High(VAONMode),Low(VAONMode)
VBCall:
 db zb|zpixel,zC,zA,zL,zL,zMNS,vdCallcv,High(VOnOff),Low(VOnOff),vdExit
VBCallNumber:
 db zb,zc|zpixel,vdViewNumber,vdExit
VReaddressNumber:
 db zPr,zH|zpixel,vdViewNumber,vdExit
VReaddressTime:
 db zSP,zSP,zPr,zVr|zpixel,zMNS,vdViewDeccv,vdExit
VPagerNumber:
 db zP,zG|zpixel,vdViewNumber,vdExit
VPagerAbonent:
 db zA,zb|zpixel,vdViewNumber,vdExit

VTimeOutReset:
 db zPr,zE,zP,zE,zZr,zA,zPr|zpixel,zMNS,vdChangeTM,MigType1,vdViewHalfDeccv,vdExit
VResetMode:
 db zO,zChr,zC|zpixel,zMNS,vdVwChTM,MigType2,z1,zMNS,vdVwChTM,MigType2,z2,zMNS,\
    vdVwChTM,MigType2,z3,vdExit


VShowTimeSayingNow:
 db zPr,zP|zpixel,zSP,vdViewHalfDecMemI,HourSay,0,zMNS,vdViewDecMemI,MinSay,0,vdExit

VShowIndificated:
 db vdChangeTM,MigType2,vdViewHalfDecMemI,Kateg,0,vdChangeTM,NoMig,vdViewNumberType,vdViewNumberMig,vdExit

VAllTimeSay:
 db zPr,zP|zpixel,zSP,vdJumpcv,High(VAllTimeSayHM),Low(VAllTimeSayHM)

VAllTimeSayHM:
 db vdViewDeccv,zMNS,vdViewDeccv,vdExit
 db vdViewDec5cv,vdExit

VCallsPerTime:
 db vdViewDec5cv,zSP,vdViewDeccv,vdExit

VKateg:
 db vdChangeSMT,NoMig,vdViewDeccv,vdPixel,zSP,zA,zBr,zMNS,vdViewHalfDecMemI,Kateg,0,vdExit
VTimeCall:
 db vdChangeSMT,NoMig,vdViewDeccv,vdPixel,zSP,vdViewDecMemI,HourCall,0,zMNS,vdViewDecMemI,MinCall,0,vdExit
VTimeSay:
 db vdChangeSMT,NoMig,vdViewDeccv,vdPixel,zSP,vdViewHalfDecMemI,HourSay,0,zMNS,vdViewDecMemI,MinSay,0,vdExit
VDateCall:
 db vdChangeSMT,NoMig,vdViewDeccv,vdPixel,vdViewHalfDecMemI,DayOfWeekCall,1,z_,vdViewDecMemI,DayCall,1,zu,vdViewDecMemI,MonthCall,1,vdExit

VBusy:
 db vdChangeTM,MigType2,zB,zU,zS,zY,zSP|zpixel,zSP|zpixel,zSP|zpixel,vdExit
VClearNumber1:
 db zSP,zSP,zO,zChr,zC|zpixel,zMNS,vdVwChTM,MigType2,z1,vdExit
VClearNumber:
 db zO,zChr,zC|zpixel,zMNS,vdVwChTM,MigType2,z1,zMNS,vdVwChTM,MigType2,z2,vdExit
VBookShow:
 db vdChangeSMT,NoMig,vdViewDeccv,vdPixel,vdViewNumber,vdExit

VBookShowInOut:
 db vdTodaySeeSTM,vdViewDeccv,vdPixel,vdChangeTM,NoMig,vdViewNumber,vdExit
VBookShowSpecical:
 db vdChangeSMT,NoMig,vdCallcv,High(ShowSpecicalLabel),Low(ShowSpecicalLabel),vdPixel,vdViewNumber,vdExit
ShowSpecicalLabel:
 db zL,z0|zpixel,vdExit
 db zL,z1|zpixel,vdExit
 db zL,z2|zpixel,vdExit
 db zL,z3|zpixel,vdExit
 db zL,z4|zpixel,vdExit
 db zL,z5|zpixel,vdExit
 db zL,z6|zpixel,vdExit
 db zL,z7|zpixel,vdExit
 db zL,z8|zpixel,vdExit
 db zL,z9|zpixel,vdExit

 db zF,z0|zpixel,vdExit
 db zF,z1|zpixel,vdExit
 db zF,z2|zpixel,vdExit
 db zF,z3|zpixel,vdExit
 db zF,z4|zpixel,vdExit
 db zF,z5|zpixel,vdExit
 db zF,z6|zpixel,vdExit
 db zF,z7|zpixel,vdExit
 db zF,z8|zpixel,vdExit
 db zF,z9|zpixel,vdExit

 db zt,z0|zpixel,vdExit
 db zt,z1|zpixel,vdExit
 db zt,z2|zpixel,vdExit
 db zt,z3|zpixel,vdExit
 db zt,z4|zpixel,vdExit
 db zt,z5|zpixel,vdExit
 db zt,z6|zpixel,vdExit
 db zt,z7|zpixel,vdExit
 db zt,z8|zpixel,vdExit
 db zt,z9|zpixel,vdExit

 db zC,z1|zpixel,vdExit
 db zC,z2|zpixel,vdExit
 db zC,z3|zpixel,vdExit
 db zC,z4|zpixel,vdExit
 db zC,z5|zpixel,vdExit

 db zGr,zo|zpixel,vdExit
 db zPr,zNr|zpixel,vdExit
 db zb,zc|zpixel,vdExit
 db zP,zG|zpixel,vdExit
 db zA,zb|zpixel,vdExit

 db zE,z0|zpixel,vdExit
 db zE,z1|zpixel,vdExit
 db zE,z2|zpixel,vdExit
 db zE,z3|zpixel,vdExit
 db zE,z4|zpixel,vdExit
 db zE,z5|zpixel,vdExit
 db zE,z6|zpixel,vdExit
 db zE,z7|zpixel,vdExit
 db zE,z8|zpixel,vdExit
 db zE,z9|zpixel,vdExit

ViewBookSelect:
 db zBr,zC|zpixel,zSP,zC,zC|zpixel,zSP,zChr,zC|zpixel,vdExit
ViewEditNumberO:
 db vdSetTM,MigType2,vdSetTM,MigType2,vdViewNumber,vdExit

ViewEditNumber:
 db vdCallSpeaker,High(NumberShowModes),Low(NumberShowModes)
 db vdChangeTM,NoMig,vdViewNumber,vdExit
NumberShowModes:
 db zH,vdViewNumberType,vdExit
 db zH,zF|zpixel,vdExit

VAutoDial:
 db zA,vdHangUpTM,vdViewNumberType,vdChangeTM,NoMig,vdViewNumber,vdExit

ViewSetup:
 db zSP,zSP,vdChangeTM,MigType2,zS,zE,zt,zU,zP,vdExit
SelectMode:
 db vdVwChTM,MigType2,zF,vdViewNumberType,vdViewNumber,vdExit
ViewMainMode:
 db vdJumpcv,High(MainModesView),Low(MainModesView)
MainModesView:
 db vdViewDecMemI,Day,0,vdPixel,\
    vdViewHalfDecMemI,DayOfWeek,1,\
    vdCallcv,High(MainViewLine0),Low(MainViewLine0),\
    vdViewHoursDecMemI,Hours,\
    vdVwChTM,MigType1,zMNS,vdViewDecMemI,Minutes,0,\
    vdJumpcv,High(ViewNotViewedCalls),Low(ViewNotViewedCalls)
 db vdViewHoursDecMemI,Hours,vdVwChTM,MigType1,zMNS,vdViewDecMemI,Minutes,0,zSP,\
    vdCallcv,High(MainViewLine1),Low(MainViewLine1),\
    vdCallcv,High(NamesOfDays),Low(NamesOfDays),vdChangeTM,NoMig,zSP,\
    vdJumpcv,High(ViewNotViewedCalls),Low(ViewNotViewedCalls)
 db zh|zpixel,vdViewHoursDecMemI,Hours,zMNS,vdViewDecMemI,Minutes,0,zMNS,\
    vdViewDecMemI,Seconds,0,\
    vdJumpcv,High(ViewNotViewedCalls),Low(ViewNotViewedCalls)
 db vdViewHalfDeccv,vdVwChTM,MigType1,zMNS,vdViewDeccv,vdPixel,\
    vdViewHoursDecMemI,Hours,vdVwChTM,MigType1,zMNS,vdViewDecMemI,Minutes,0,vdExit
ViewNotViewedCalls:
 db vdExit
 db vdPixel,vdExit
VSecondsSet:
 db zh|zpixel,vdViewHoursDecMemI,Hours,zMNS,vdViewDecMemI,Minutes,0,zMNS,\
    vdViewDecMemI,Seconds,0,vdExit
MainViewLine0:
 db vdVwChTM,MigType2,zo,vdExit
 db zo,vdExit
MainViewLine1:
 db vdChangeTM,MigType2,vdExit
 db vdExit
NamesOfDays:
 db zPr,zNr|zpixel,vdExit
 db zVr,zNr|zpixel,vdExit
 db zC,zP|zpixel,vdExit
 db zChr,zGr|zpixel,vdExit
 db zPr,zA|zpixel,vdExit
 db zC,zBr|zpixel,vdExit
 db zVr,zC|zpixel,vdExit

ViewCalling:
 db zSP,zC,zA,zL,zL,zMNS,vdChangeTM,MigType2,vdViewDeccv,vdExit
ViewRequestOut:
 db zSP,zO,zPr,zP,zMNS,vdChangeTM,MigType2,vdViewDeccv,vdExit

ViewCallFromKey:
 db zt,zo,zn,zE,vdExit

Test_vdViewHexMemI:
 db zt,z0|zpixel,zSP,vdViewHexMemI,ValueData,vdExit
Test_ViewHexStringMemX:
 db zt,z1|zpixel,zSP,vdViewHexStringMemX,vdExit
ViewRAMdata:
 db vdView3HexMemI,vdDecCV,vdDecCV,vdViewHexStringMemX,vdExit

 extern KeyPresent,NowKey,LongPressKey,FirstKeyt,Key,FKey
Debug_KeyView:                  ;KeyUp
 db zd|zpixel,zSP,vdViewHexMemI,NowKey,vdViewHexMemI,Key,vdViewHexMemI,FKey,vdExit

TestEdit0:
 db z1|zpixel,vdViewDeccv,zSP,z2|zpixel,vdView3Deccv,vdExit

VOpt0A:
 db zd,zI,zA,zL|zpixel,zL|zpixel,vdViewHalfDeccv,zSP,zP|zpixel,vdViewHalfDeccv,vdExit
VOpt1A:
 db zA|zpixel,zd,zI,zA,zL|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)
VOpt2A:
 db zS,zP|zpixel,zd,zI,zA,zL|zpixel,zMNS,vdViewDeccv,vdExit
VOpt3A:
 db zC,zA,zL,zL,zS|zpixel,zMNS,vdViewDeccv,vdExit
VOpt4A:
 db zA|zpixel,zS,zr,zc,zh,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)
VOpt5A:
 db zChr,zA,zC,zb,zIl|zpixel,vdCallcv,High(V12h24h),Low(V12h24h),vdViewHalfDeccv,vdExit
VOpt6A:
 db zA,zu,zt,zo|zpixel,zA|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)
VOpt7A:
 db zC,zo,zr,zr|zpixel,vdCallcv,High(VCorrSign),Low(VCorrSign),vdViewHalfDeccv,zMNS,vdViewDeccv,zc|zpixel,vdExit
VOpt8A:
 db zNr,zE,zO,zPr,zRr,zMNS,vdJumpcv,High(V12OnOff),Low(V12OnOff)

VOpt0B:
 db zb,zu,zt,zt,zo,zn|zpixel,zMNS,vdViewHalfDeccv,vdExit
VOpt1B:
 db zH,zo,zu,zr|zpixel,zMNS,vdViewHalfDeccv,vdExit
VOpt2B:
 db zL,zn|zpixel,zH,zo,zl,zd|zpixel,zMNS,vdViewDeccv,vdExit
VOpt3B:
 db zb,zE,zL,zL|zpixel,zMNS,vdViewHalfDeccv,vdExit ;,vdViewHalfDeccv
VOpt4B:
 db zL,zI,zS,zt,zn|zpixel,zSP,vdViewHalfDeccv,zSP,vdViewHalfDeccv,vdExit
VOpt5B:
 db zS,zA,zY|zpixel,zSP,zA|zpixel,zPr|zpixel,zMNS,vdViewDeccv,vdExit
VOpt6B:
 db zS,zA,zY|zpixel,zSP,zH|zpixel,zRr|zpixel,zMNS,vdViewHalfDeccv,vdExit
VOpt7B:
 db zA,zt,zS|zpixel,zS,zn,zd|zpixel,vdJumpcv,High(VOnOff),Low(VOnOff)
VOpt8B:
 db zS,zA,zY|zpixel,zd,zr,zc,zt|zpixel,zMNS,vdJumpcv,High(VDirections),Low(VDirections)
VDirections:
 db zF|zpixel,vdExit
 db zb|zpixel,vdExit
VOpt9B:
 db zE|zpixel,zL,zi,zn,zE|zpixel,vdJumpcv,High(VNoneStop),Low(VNoneStop)
VNoneStop:
 db zN,zO,zN,zE|zpixel,vdExit
 db zS,zt,zO,zP|zpixel,vdExit

VOpt0X:
 db vdChangeTM,MigType2,zL,zi,zG,zh,zt|zpixel,vdChangeTM,NoMig,vdViewLinecv,vdExit
VOpt1X:
 db vdVwChTM,MigType2,zGr|zpixel,vdViewLinecv,vdExit
VOpt2X:
 db vdVwChTM,MigType2,zS|zpixel,vdViewLinecv,vdExit
VOpt3X:
 db vdChangeTM,MigType2,zb,zL,zi,zc|zpixel,vdChangeTM,NoMig,vdViewLinecv,vdExit
VOpt4X:
 db zV,zo,zl|zpixel,zSP,vdCallcv,High(VLoHi),Low(VLoHi),vdExit

VLoHi:
 db zL,zo,vdExit
 db zH,zi,vdExit

VOpt0C:
 db zA,zt,zS|zpixel,zC,zI,zF,zr|zpixel,zMNS,vdViewHalfDeccv,vdExit
VOpt1C:
 db zNr,zA,zBr|zpixel,zMNS,vdJumpcv,High(VPulseTone),Low(VPulseTone)
VOpt2C:
 db zP,zA,zMNS,vdCallcv,High(VSayOnOff),Low(VSayOnOff),zSP,zSP,vdJumpcv,High(VPulseTone),Low(VPulseTone)
VOpt3C:
 db zb,zE,zE,zP,zE,zr|zpixel,vdJumpcv,High(VOnOff),Low(VOnOff)
VOpt4C:
 db zP,zr,zE,zF|zpixel,zSP,vdViewHalfDeccv,zSP,vdViewHalfDeccv,vdExit
VOpt5C:
 db zL|zpixel,zC,zo,zd,zE|zpixel,zMNS,vdViewHalfDeccv,vdPixel,vdViewDeccv,vdPixel,vdExit

VOpt0D:
 db zZr,zA,zPr|zpixel,zSP,vdViewDeccv,zSP,vdJumpcv,High(VFormRequest),Low(VFormRequest)
VOpt1D:
 db zZr,zA,zPr|zpixel,zSP,zd|zpixel,zSP,vdViewDeccv,vdExit
VOpt2D:
 db zZr,zA,zPr|zpixel,zSP,zPr,z1|zpixel,zSP,vdViewDeccv,vdExit
VOpt3D:
 db zZr,zA,zPr|zpixel,zSP,zPr,z2|zpixel,zSP,vdViewDeccv,vdExit
VOpt4D:
 db zNr,zA,zBr|zpixel,zSP,zd|zpixel,zSP,vdViewDeccv,vdExit
VOpt5D:
 db zNr,zA,zBr|zpixel,zSP,zPr|zpixel,zSP,vdViewDeccv,vdExit
VOpt6D:
 db zNr,zA,zBr|zpixel,zSP,zGr|zpixel,zSP,vdJumpcv,High(VOnOff),Low(VOnOff)
VOpt7D:
 db zF,zSP,zMNS,zSP,vdViewDeccv,zMNS,vdViewDeccv,vdExit
VOpt8D:
 db zPr|zpixel,zMNS,vdViewDeccv,vdPixel,zA|zpixel,zPr|zpixel,zMNS,vdViewDeccv,vdExit
VOpt9D:
 db zF,zL,zA,zS,zH|zpixel,zMNS,vdViewDeccv,vdExit

VFormRequest:
 db zd,zd,vdExit
 db zA,zA,vdExit
 db zd,zA,vdExit
 db zA,zd,vdExit

VAlarm0:
 db zE,vdViewHalfDeccv,vdPixel,zSP,vdViewDeccv,zMNS,vdViewDeccv,vdPixel,vdJumpcv,High(VBudMode),Low(VBudMode)
VAlarm1:
 db vdJumpcv,High(VAlarm1A),Low(VAlarm1A)
VAlarm2:
 db vdJumpcv,High(VAlarm2A),Low(VAlarm2A)
VAlarm3:
 db zd|zpixel,zSP,vdViewDayscv,vdExit
VAlarm4:
 db zE,zHio|zpixel,vdViewNumber,vdExit

VPMode0:
 db zSP,zP,zMNS,vdViewHalfDeccv,zSP,vdDecCV,vdCallcv,High(VAONModeA),Low(VAONModeA),vdDecCV,vdJumpcv,High(VAONMode),Low(VAONMode)
VPMode1:
 db zb|zpixel,zC,zA,zL,zL|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)

VNightOn:
 db zH,zO,zChr,zb|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)
VNightFrom:
 db zc|zpixel,zSP,vdViewDeccv,zMNS,vdViewDeccv,vdExit
VNightTo:
 db zn,zo|zpixel,zSP,vdViewDeccv,zMNS,vdViewDeccv,vdExit
VNightBells:
 db zn|zpixel,zb,zE,zL,zL,zS,zMNS,vdViewDeccv,vdExit

VAONModeA:
 db vdNone
 db zo,vdExit
 db zn,vdExit
 db zEQ,vdExit
 db zu,vdExit
 db zAGEr,vdExit
 db zAGEl,vdExit
 db zcb,vdExit
 db zc,vdExit


VAlarm2A:
 db vdNone,vdNone,vdNone
 db zP,zL,zA,zY,zMNS,vdViewDeccv,zSP,vdJumpcv,High(VBudVol),Low(VBudVol)
 db zE|zpixel,zSP,zP,zMNS,vdViewHalfDeccv,zSP,vdDecCV,vdJumpcv,High(VAONMode),Low(VAONMode)

VAlarm1A:
 db vdNone,vdNone
 db zL|zpixel,zP,zL,zA,zY|zpixel,vdJumpcv,High(VAlarmLPlay),Low(VAlarmLPlay)
 db zA|zpixel,zC|zpixel,zS,zn,zd|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)
 db zP|zpixel,zMNS,vdJumpcv,High(VAlarmPMode),Low(VAlarmPMode)
 db zE|zpixel,zSP,zBr|zpixel,zC|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)
 db zE|zpixel,zSP,zChr|zpixel,zC|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)
 db zE|zpixel,zSP,zC|zpixel,zC|zpixel,zMNS,vdJumpcv,High(VOnOff),Low(VOnOff)

VAlarmLPlay:
 db zS,zh,zr,zt|zpixel,vdExit
 db zL,zO,zn,zG|zpixel,vdExit

VAlarmPMode:
 db zA,zL,zWl,zWr,zA,zY,zS|zpixel,vdExit
 db zO,zN,zC,zE|zpixel,vdExit

VAONMode:
 db vdExit
 db zA|zpixel,zPr|zpixel,vdExit
 db zP|zpixel,zPr|zpixel,vdExit
 db zPr|zpixel,zPr|zpixel,vdExit
 db zPr|zpixel,zH|zpixel,vdExit
 db zPr|zpixel,zVr|zpixel,vdExit
 db zH|zpixel,zPr|zpixel,vdExit
 db zH|zpixel,zP|zpixel,vdExit

VBudMode:
 db zn,vdExit
 db zu,vdExit
 db zo,vdExit
 db zA,vdExit
 db zP,vdExit
 db zBr,vdExit
 db zChr,vdExit
 db zC,vdExit
VBudVol:
 db zH,vdExit
 db zPr,vdExit
VSayOnOff:
 db vdJump,High(VOff),Low(VOff)
 db vdJump,High(VOn),Low(VOn)
 db zS,zA,zY,vdExit
VPulseTone:
 db zP,zU,zL,zS,zE,vdExit
 db zt,zo,zn,zE,vdExit
VCorrSign:
 db zMNS,vdExit
 db zpixel|zSP,vdExit
V12OnOff:
 db vdJump,High(VOff),Low(VOff)
 db vdJump,High(VOn),Low(VOn)
V12h24h:
 db z2,z4,zh,vdExit
 db z1,z2,zh,vdExit
VOnOff:
VOff:
 db zO,zF,zF,vdExit
VOn:
 db zO,zn,zSP,vdExit


;------------------------------------------------------------
StartVideoTbl:
 db oACallLoopBeforeTimeOut,oAutoACall,oACallLoops,oWaitCalls
 db oAutoSearch,o12ClkView,oAnswerBackParallel,oSignCorr,oUnknownOper

 db oTypeKeyBeep,oTypeHourSnd,oMelodyHold,oBellTone,oParalListen
 db oRepNumberSay,oParalTypeNumberSay,oAnswerListen,oDirectionSay
 db oAlarmStopOnLineOff

 db oLightLevel,oBeepLineFreq,oSpeedOfVoice,oMigLevel,oVolume
; db oBeepLineTone+1
 db oATSLenNumber,oTypeLineCall,oParalOpr
 db oRemoteAccess,oPrefix,oCountryCode
; db oCountryBeepWait+1
 db oAlarmNumber,oLenPlayAlarm,oPlayAlarm,oDaysAlarm,oAlarmNumberCall
; db oDaysAlarm+1
 db oNightOn,oNightFromHour,oNightToHour,oNightBells
; db oNightBells+1
 db oRequests,oLenRequest,oPauseRequest0,oPauseRequest
 db oSpeedNumeralCall,oWaitNextNumeral,oEveryNumeralBeepTest
 db oFminCall,oKvantPipeUp,oFlashPause
; db oFlashPause+1
 db oShowSpecical,oShowWhite,oShowBlack,oShowBlackLock
 db oShowIn,oShowOut,oShowZK
; db oShowZK+1
 db oAONMode,oBCall
; db oBCall+1
 db oBCallNumber
; db oBCallNumber+1
 db oReaddressNumber,oReaddressTime
 db oPagerNumber,oPagerAbonent
; db oPagerAbonent+1
 db oFilter
; db oFilter+1
 db oPassOn,oPassword,oAONlock,oAreaLock,oLockAllCalls,oLockNumbers,oLockCode
; db oLockCode+1
 db oHours,oDay
 db oYear+1

;------------------------------------------------------------
;Video data on EFunc
TblVDKOnEFunc:
  db vMain,             kmMain,\
     vMode,             kmMode,\
     vSetup,            kmMode,\
     vViewEditNumber,   kmEdEditNumberMainPipeUp,\
     vViewEditNumber,   kmEdEditNumberMainPipeUpTn,\
     vViewEditNumber,   kmEdEditNumberMainPipeDown,\
     vNone,             kmShowNumber,\
     vViewEditNumber,   kmEdEditNumberMainPUpTone,\
     vViewEditNumber,   kmShowMainNumber,\
     vAutoDial,         kmAutoDial,\
     vCalling,          kmCalling,\
     vRequestOut,       kmCalling,\
     vViewEditNumberO,  kmEditNumberOpt,\
     vViewBookSelect,   kmMode,\
     vClearNumber,      kmClearNumber,\
     vClearNumber1,     kmClearPropAllNumber,\
     vKateg,            kmShowNumber,\
     vTimeCall,         kmShowNumber,\
     vTimeSay,          kmShowNumber,\
     vDateCall,         kmShowNumber,\
     vCallsPerTime,     kmShowNumberProperties,\
     vAllTimeSay,       kmShowNumberProperties,\
     vShowTimeSayingNow,kmShowNumber,\
     vShowIndificated,  kmBeepEmulation,\
     vResetMode,        kmResetMode,\
     vTimeOutReset,     kmResetMode,\
     vBCalling,         kmSound,\
     vSoundMode,        kmSound,\
     vParallelDetect,   kmSound,\
     vLockingNumber,    kmSound,\
     vHold,             kmSound,\
     vGetLine,          kmSound,\
     vSearchNumber,     kmSearchNumber,\
     vShowNotFound,     kmShowNumber,\
     vFlash,            kmShowNumber,\
     vAntiAON,          kmAntiAON,\
     vNone,             kmEditCharBuff,\
     vShowLabelFilterStatus, kmShowNumber,\
     vStoreCustomBook,  kmStoreCustomBook,\
     vStoreCustomNumber,kmStoreCustomNumber,\
     vTestPassword,     kmTestPassword,\
     vShowTestPassword, kmShowNumber,\
     vSecondsSet,       kmSecondsSet,\
     vAlarmPlay,        kmSound,\
     vAlarmDial,        kmSound,\
     vShowLogo,         kmSound,\
     vConfidenceShow,   kmShowNumber,\
     vRemoteAccessKey,  kmRemoteAccessKey,\
     vSoundMode,        kmSound,\
     vShowVersionInfo,  kmSound,\
     vAutoDialCustomNumber, kmAutoDialCustomNumber,\
     vDebugBeep,        kmSound,\
     vExtFunc,          kmExtFuncSubmit

;------------------------------------------------------------
; Table convertion from Key to FKey
KeyHwToSw: db kf1,kf2,kf3,kfBookIn
           db kf4,kf5,kf6,kfBookOut
           db kf7,kf8,kf9,kfBookZK
           db kfStar,kf0,kfPriston,kfMode
; xx y2 x3 x2
; y1 y0 xx x1
;           db kf0,kf1,kf2,kf3
;           db kf4,kf5,kf6,kf7 kfNone
           db kfRedial,kfVolume,kfStore,kfFlash
;           db kfRedial,kfHold,kfHold,kfSpkPhnOnOff
           db kfRedial,kfTone,kfHold,kfSpkPhnOnOff
           db kfBookWhite,kfBookBlack,kfBookBlackLock,kfBookSpecical

SpecicalKeyHwToSw:
           db 0x31,kfAntiAON,0xFF
;------------------------------------------------------------
;Options
;------------------------------------------------------------
;TypeByte KeyMapView [KeyMapEdit] DefaultValue [MinValue] [MaxValue]
;Array256:          TypeByte=mmo0_9S|olBit
;                   Size,AddressMem
;                   NormalParams
;DirectAddressByte: TypeByte=mmo0_99S|olBit
;                   AddressMem
;                   NormalParams
;NumberBookO:       TypeByte=mmo0_ctmS|olBit
;                   AddressMem
;                   KeyMapView,Book
;                   NormalParams
;NumberConstO:      TypeByte=mmoctm_ctmS|olBit
;                   KeyMapView,Book,StartNumber,AddressMem
;
FormatOptionsTBL:
 DB mmo0_9S|olMx9,        kmEdSerialPaste,5    ;dial.-x
 DB mmo0_9S|olMx9,        kmEdSerialPaste,1    ;dial.- x
 DB mmo0_1N|olBit,        kmEdMinMax,0         ;A.dial.-ooo
 DB mmo0_99S|olMx99,      kmEdSerialPaste,09   ;Sp.dial.-xx
 DB mmo0_99S|olMx99,      kmEdSerialPaste,01   ;Calls.-xx
 DB mmo0_1N|olBit,        kmEdMinMax,0         ;A.Srch.-oo
 DB mmo0_1N|olBit,        kmEdMinMax,0         ;Clock.ooo
 DB mmo0_ctmS|olMx3,      kmEdSerialPaste,1,2  ;Clock.   x
 DB mmo0_1N|olBit,        kmEdMinMax,1         ;AutoA.-ooo
 DB mmo0_1N|olBit,        kmEdMinMax,0         ;Cor.x -
 DB mmo0_9S|olMx9,        kmEdSerialPaste,0    ;Cor. x-
 DB mmo0_ctmS|olMx63,     kmEdSerialPaste,0,59 ;Cor.  -xx
 DB mmo0_ctmS|olMx3,      kmEdK0_2,1,2         ;NEOPR-ooo

 DB mmo0_ctmS|olMx7,      kmEdSerialPaste,4,6  ;button.-x
 DB mmo0_ctmS|olMx7,      kmEdSerialPasteMT,0,5  ;Hour.-x
 DB mmo0_ctmS|olMx31,     kmEdSerialPasteMT,0,MaxMelodyPlay+1 ;Ln.Hold.-xx
 DB mmo0_9S|olMx9,        kmEdSerialPasteMT,0    ;bell.-x
; DB mmo0_9S|olMx9,        kmEdSerialPaste,0    ;bell.- x
 DB mmo0_ctmS|olMx3,      kmEdSerialPaste,0,2  ;Listn.x
 DB mmo0_ctmS|olMx3,      kmEdSerialPaste,0,2  ;Listn. x
 DB mmo0_99S|olMx99,      kmEdSerialPaste,2    ;Say. A.P.-xx
 DB mmo0_ctmS|olMx3,      kmEdSerialPaste,0,3  ;Say. H.P.-x
 DB mmo0_1N|olBit,        kmEdMinMax,0         ;ATS.Snd.ooo
 DB mmo0_1N|olBit,        kmEdMinMax,0         ;SAY.drct.-o
 DB mmo0_1N|olBit,        kmEdMinMax,0         ;E.LinE.-oooo

 DB mmo0_ctmS|olMx7|ohHBD,  kmEdMinMaxLine,7,7     ;L.||||||||
 DB mmo0_ctmS|olMx31|ohHBD, kmTestOptionA,7,16     ;P.||||||||
 DB mmo0_ctmS|olMx31|ohHBD, kmTestOptionB,14,16    ;S.||||||||
 DB mmo0_ctmS|olMx7|ohHBD,  kmEdMinMaxLine,3,MaxMigLevel ;blic.|||||
 DB mmo0_1N|olBit,          kmEdMinMax,1           ;Uol. xx

 DB mmoctm_ctmS|olMx9,    kmEdSerialPaste,7,3,7   ; d-x
 DB mmo0_1N|olBit,        kmEdMinMax,0            ;NAB.-ooooo
 DB mmo0_ctmN|olMx3,      kmEdK0_2,0,2            ;PA-ooo
 DB mmo0_1N|olBit,        kmEdMinMax,0            ;PA-    o
 DB mmo0_1N|olBit,        kmEdMinMax,0            ;bEEPEr.ooo
 DB mmo0_9S|olMx9,        kmEdSerialPaste,9       ;PrEF. x
 DB mmo0_ctmS|olMx3,      kmEdSerialPaste,0,3     ;PrEF.   x
 DB mmo0_9S|olMx9,        kmEdSerialPaste,8       ;L.CodE.-x
 DB mmoctm_ctmS|olMx99,   kmEdSerialPaste,20,1,99 ;L.CodE.- xx


 DB DAChar
 DW NumberOfAlarm
 DB mmo0_9S|olMx255,      kmEdSerialPaste,0     ;Ex   -
 DB Array256,MaxAlarms
 DW NumberOfAlarm
 DB mmo0_ctmS|olMx31,     kmEdSerialPasteA,0,23 ;E  xx-
 DB Array256,MaxAlarms
 DW NumberOfAlarm
 DB mmo0_ctmS|olMx63,     kmEdSerialPasteA,0,59 ;E    -xx
 DB Array256,MaxAlarms
 DW NumberOfAlarm
 DB mmo0_ctmS|olMx7,      kmEdBudModeSel,0,7    ;E    -   x
 DB Array256,MaxAlarms
 DW NumberOfAlarm
 DB mmo0_1N|olBit,        kmEdMinMax,0          ;L.Play.ooo
                                                ;A.Snd. ooo
                                                ;P. ooooo
 DB Array256,MaxAlarms
 DW NumberOfAlarm
 DB mmo0_ctmS|olMx63,     kmEdSerialPasteMT,0,MaxMelodyPlay ;Play-xx
                                                 ;E. P-x x x
 DB Array256,MaxAlarms
 DW NumberOfAlarm
 DB mmo0_1N|olBit,        kmEdMinMax,0          ;Play-   o
 DB Array256,MaxAlarms
 DW NumberOfAlarm
 DB mmo0_ctmS|olMx127|ohHBD,kmEdBudEdit,0x7F,0x7F ;d.zzzzzzz
 DB NumberConstO,kmShowNumberOpt,bBookSpecical
 DW nbStartAlarm,NumberOfAlarm                    ;E. nnnnnnn

 DB mmo0_1N|olBit,        kmEdMinMaxNight,0        ;Night-ooo
 DB mmo0_ctmS|olMx31,     kmEdSerialPasteA,22,23   ;from xx-
 DB mmo0_ctmS|olMx63,     kmEdSerialPasteA,0,63    ;from   -xx
 DB mmo0_ctmS|olMx31,     kmEdSerialPasteA,6,23    ;to xx-
 DB mmo0_ctmS|olMx63,     kmEdSerialPasteA,0,63    ;to   -xx
 DB mmo0_99S|olMx99,      kmEdSerialPasteNBells,20 ;N.Bells-xx

 DB mmo0_99S|olMx99,      kmEdSerialPaste,7       ;3AP. xx
 DB mmo0_ctmN|olMx3,      kmEdK0_3,3,3            ;3AP.     oo
 DB mmo0_99S|olMx99,      kmEdSerialPaste,11      ;3AP. d. xx
 DB mmo0_99S|olMx99,      kmEdSerialPaste,20      ;3AP. P1. xx
 DB mmoctm_ctmS|olMx99,   kmEdSerialPaste,10,5,99 ;3AP. P2. xx
 DB mmoctm_ctmS|olMx99,   kmEdSerialPaste,10,1,99 ;NAB. d. xx
 DB mmoctm_ctmS|olMx99,   kmEdSerialPaste,50,1,99 ;NAB. P. xx
 DB mmo0_1N|olBit,        kmEdMinMax,0            ;NAB. G. ooo
 DB mmoctm_ctmS|olMx99,   kmEdSerialPaste,13,5,99 ;F - xx -
 DB mmoctm_ctmS|olMx99,   kmEdSerialPaste,75,5,99 ;F -    - xx
 DB mmo0_99S|olMx99,      kmEdSerialPaste,0       ;P.xx A.P.
 DB mmo0_99S|olMx99,      kmEdSerialPaste,10      ;P.   A.P.xx
; DB mmo0_ctmS|olMx63,     kmEdSerialPaste,0,40    ;P.xx A.P.
; DB mmo0_ctmS|olMx63,     kmEdSerialPaste,0,40    ;P.   A.P.xx
 DB mmoctm_ctmS|olMx99,   kmEdSerialPaste,80,1,99 ;FLASH.-xx

 DB NumberBookO,bBookSpecical                     ;Specical show/edit
 DW SelNumberBook                                 ;
 DB mmo0_ctmS|olMx63,     kmBookShowZK,0,49       ;
 DB NumberBookO,bBookWhite                        ;White show/edit
 DW SelNumberBook                                 ;
 DB mmo0_ctmS|olMx63,     kmBookShowZK,0,49       ;
 DB NumberBookO,bBookBlack                        ;Black show/edit
 DW SelNumberBook                                 ;
 DB mmo0_ctmS|olMx63,     kmBookShowZK,0,49       ;
 DB NumberBookO,bBookBlackLock                    ;BlackLock show/edit
 DW SelNumberBook                                 ;
 DB mmo0_ctmS|olMx63,     kmBookShowZK,0,49       ;

 DB NumberBookO,bBookIn                           ;In show/edit
 DW SelNumberBook                                 ;
 DB mmo0_99S|olMx99,      kmBookShowIn,0          ;
 DB NumberBookO,bBookOut                          ;Out show/edit
 DW SelNumberBook                                 ;
 DB mmo0_99S|olMx99,      kmBookShowOut,0         ;
 DB NumberBookO,bBookZK                           ;ZK show/edit
 DW SelNumberBook                                 ;
 DB mmo0_99S|olMx99,      kmBookShowZK,0          ;

 DB mmoctm_ctmS|olMx7,   kmEdSerialPasteAMode,1,1,MaxAONModes       ;P.-x xx
 DB mmo0_1N|olBit,       kmEdMinMaxBCall,0                          ;b.CALL-xxx
 DB NumberConstO,        kmShowNumberBCall,bBookSpecical            ;bC.nnnnnnn
 DW nbBCallNumber,-1                                                ;
 DB NumberConstO,        kmEditReaddressNumber,bBookSpecical        ;PH.nnnnnnn
 DW nbReaddressingNumber,-1                                         ;
 DB mmo0_ctmS|olMx31,    kmEditReaddressTime,00,23                  ;B.P.-xx
 DB NumberConstO,        kmEditReaddressPagerNumber,bBookSpecical   ;PG.nnnnnnn
 DW nbPagerNumber,-1                                                ;
 DB NumberConstO,        kmEditReaddressPagerAbonent,bBookSpecical  ;Ab.nnnnnnn
 DW nbPagerAbonent,-1                                               ;
 DB mmo0_ctmS|olMx255,   kmEdFilterEdit,0xFE,0xFF                   ;xxxxxxxxx(filter)

 DB mmo0_1N|olBit,        kmEdMinMaxPass,0                ;PASS.-ooo
 DB mmo0_ctmS|olMx9999,   kmEdSerialPasteA                ;PASS.-xxxx
 DW 0,9999                                                ;
 DB mmo0_ctmS|olMx3,      kmEdK0_2,0,2                    ;AON.bl.-ooo (AONlock)
 DB mmo0_1N|olBit,        kmEdMinMax,0                    ;NABOR.-ooo  (AreaLock)
 DB mmo0_1N|olBit,        kmEdMinMax,0                    ;BCE.3B.-ooo (LockAllCalls)
 DB mmo0_1N|olBit,        kmEdMinMax,0                    ;L_-ooo      (LockNumbers)
 DB mmo0_1N|olBit,        kmEdMinMax,0                    ;L.CODE-ooo  (LockCode)

 DB DAChar                                                ;t. xx-   (hours)
 DW Hours|0xFF00                                          ;
 DB mmo0_ctmS|olMx255,    kmEdSerialPasteHours,12,23      ;
 DB DAChar                                                ;t.   -xx (minutes)
 DW Minutes|0xFF00                                        ;
 DB mmo0_ctmS|olMx255,    kmEdSerialPasteMinutes,0,59     ;
 DB DAChar                                                ;xx-  -   (day)
 DW Day|0xFF00                                            ;
 DB mmoctm_ctmS|olMx255,  kmEdSerialPasteDate,DATE 4,1,31 ;
 DB DAChar                                                ;  -xx-   (month)
 DW Month|0xFF00                                          ;
 DB mmoctm_ctmS|olMx255,  kmEdSerialPasteDate,DATE 5,1,12 ;
 DB DAChar                                                ;  -  -xx (year)
 DW Year|0xFF00                                           ;
 DB mmo0_99S|olMx255,     kmEdSerialPasteDate,DATE 6      ;

 DB mmo0_1N|olBit,        0,0                             ;Up Readdress Time
 DB mmo0_99S|olMx15,      0,0                             ;PowerDownTimeOut
 DB mmo0_1N|olBit,        0,0                             ;NewNotSayCalls

 DB mmo0_ctmS|olMx9999,   0                               ;CheckReset
 DW CheckResetData,0xFFFF

 DB mmo0_1N|olBit,        kmEdMinMax,0                    ;ShowLogo

 DB mmo0_ctmS|olMx255,    0 ,0,255                        ;AllHourSay
 DB mmo0_ctmS|olMx63,     0 ,0,59                         ;AllMinSay

 DB mmo0_ctmS|olMx9999,   0                               ;CallsPerAllTime
 DW 0,MaxValueAllCalls                                    ;
 DB mmo0_ctmS|olMx255,    0 ,0,250                        ;TodayCalls
 DB mmo0_ctmN|olMx31,     0 ,0,31                         ;Old Day
; DB DAChar
; DW NumberOfAlarm
; DB mmo0_9S|olMx9,        kmEdSerialPaste,5
;
; DB Array256,5
; DW NumberOfAlarm
; DB mmo0_9S|olMx9,        kmEdSerialPaste,5
;
;
; DB mmo0_1N|olBit,        kmEdIncDec,001
; DB mmo0_9S|olMx9,        kmEdSerialPaste,005
; DB mmo0_ctmS|olMx9,      kmTest,003,004
; DB mmo0_99S|olMx99,      kmTest,005
; DB mmo0_0xFFC|olMxByte,  kmTest,kmTest,005
; DB mmo0_ctmS|olMx999,    kmTest,010,010, 100,001
; DB mmo0_ctmN|olMx999,    kmTest,011,011, 101,001
; DB mmoctm_ctmS|olMx9999, kmTest,020,020, 000,000, 200,200
; DB mmoctm_ctmC|olMx9999, kmTest,kmTest,021,021, 000,000, 201,201
; DB mmoctm_ctmC|olMx9999, kmTest,kmTest,021,021, 000,000, 201,201
;

;------------------------------------------------------------
EventOnKeyAddrTable:
 dw MainK                    ;kmMain
 dw ModeK                    ;kmMode
 dw CallFromKeyK             ;kmCallFromKey
 dw ModeSubmitK              ;kmModeSubmit
 dw SetupSubmitK             ;kmSetupSubmit
 dw EdMinMaxK                ;kmEdMinMax
 dw EdIncDecK                ;kmEdIncDec
 dw EdSerialPasteK           ;kmEdSerialPaste
 dw EdMinMaxLine             ;kmEdMinMaxLine
 dw EdBudEdit                ;kmEdBudEdit
 dw EdBudModeSel             ;kmEdBudModeSel
 dw EdEditNumber             ;kmEdEditNumber
 dw EdEditNumberMainPipeUp   ;kmEdEditNumberMainPipeUp
 dw EdEditNumberMainPipeDown ;kmEdEditNumberMainPipeDown
 dw EdEditNumberMainPUpTone  ;kmEdEditNumberMainPUpTone
 dw EdEditNumberMainPipeUpTn ;kmEdEditNumberMainPipeUpTn
 dw ShowNumberK              ;kmShowNumber
 dw ShowMainNumberK          ;kmShowMainNumber
 dw AutoDialK                ;kmAutoDial
 dw CallingK                 ;kmCalling
 dw ShowNumberOptK           ;kmShowNumberOpt
 dw EditNumberOptK           ;kmEditNumberOpt
 dw EdSerialPasteAK          ;kmEdSerialPasteA
 dw BookSelectK              ;kmBookSelect
 dw BookShowInK              ;kmBookShowIn
 dw BookShowOutK             ;kmBookShowOut
 dw BookShowZKK              ;kmBookShowZK
 dw ClearNumberK             ;kmClearNumber
 dw ShowNumberPropertiesK    ;kmShowNumberProperties
 dw ClearPropAllNumberK      ;kmClearPropAllNumber
 dw BeepEmulationK           ;kmBeepEmulation
 dw TestOptionAK             ;kmTestOptionA
 dw TestOptionBK             ;kmTestOptionB
 dw BeepEmulationSubmitK     ;kmBeepEmulationSubmit
 dw ResetModeK               ;kmResetMode
 dw EdMinMaxNightK           ;kmEdMinMaxNight
 dw EdSerialPasteNBellsK     ;kmEdSerialPasteNBells
 dw EdSerialPasteAModeK      ;kmEdSerialPasteAMode
 dw EdMinMaxBCallK           ;kmEdMinMaxBCall
 dw ShowNumberBCallK         ;kmShowNumberBCall
 dw EditReaddressNumberK       ;kmEditReaddressNumber
 dw EditReaddressTimeK         ;kmEditReaddressTime
 dw EditReaddressPagerNumberK  ;kmEditReaddressPagerNumber
 dw EditReaddressPagerAbonentK ;kmEditReaddressPagerAbonent
 dw SoundK                     ;kmSound
 dw EdSerialPasteMT            ;kmEdSerialPasteMT
 dw SearchNumberK              ;kmSearchNumber
 dw AntiAONK                   ;kmAntiAON
 dw EditCharBuffK              ;kmEditCharBuff
 dw EdFilterEditK              ;kmEdFilterEdit
 dw StoreCustomBookK           ;kmStoreCustomBook
 dw StoreCustomNumberK         ;kmStoreCustomNumber
 dw EdMinMaxPassK              ;kmEdMinMaxPass
 dw TestPasswordK              ;kmTestPassword
 dw EdSerialPasteHoursK        ;kmEdSerialPasteHours
 dw EdSerialPasteMinutesK      ;kmEdSerialPasteMinutes
 dw EdSerialPasteDateK         ;kmEdSerialPasteDate
 dw SecondsSetK                ;kmSecondsSet
 dw RemoteAccessKeyK           ;kmRemoteAccessKey
 dw AutoDialCustomNumberK      ;kmAutoDialCustomNumber
 dw ExtFuncSubmitK             ;kmExtFuncSubmit
 dw EdK0_2K                    ;kmEdK0_2
 dw EdK0_3K                    ;kmEdK0_3

ProcEventOnKeyAddrTable:
 dw DefaultFKey                  ;kmDefault
 dw Set0_BtoBeepKey              ;kmSet0_BtoBeepKey
 dw DisableRepeat0_B             ;kmDisableRepeat0_B
 dw Set0_AtoSubmitMode           ;kmSet0_AtoSubmitMode
 dw ProcModeSubmitFKey           ;kmProcModeSubmit
 dw ProcSetupSubmitFKey          ;kmProcSetupSubmit
 dw ProcEdMinMaxFKey             ;kmProcEdMinMax
 dw ProcEdIncDecFKey             ;kmProcEdIncDec
 dw ProcEdSerialPasteFKey        ;kmProcEdSerialPaste
 dw ProcEdMinMaxLine             ;kmProcEdMinMaxLine
 dw ProcStarPriston_NextPrev     ;kmProcStarPriston_NextPrev
 dw ProcEdBudEdit                ;kmProcEdBudEdit
 dw ProcEdBudModeSel             ;kmProcEdBudModeSel
 dw SetL0_LBNone                 ;kmSetL0_LBNone
 dw ProcEdEditNumber             ;kmProcEdEditNumber
 dw ProcEdEditNumberMainPipeUp   ;kmProcEdEditNumberMainPipeUp
 dw ProcEdEditNumberMainPipeDown ;kmProcEdEditNumberMainPipeDown
 dw ProcMainKey                  ;kmProcMainKey
 dw ProcEdEditNumberMainPUpTone  ;kmProcEdEditNumberMainPUpTone
 dw ProcSetL0NoRepeat            ;kmProcSetL0NoRepeat
 dw ProcSetL1_6PipeUp            ;kmProcSetL1_6PipeUp
 dw ProcShowNumber               ;kmProcShowNumber
 dw ProcShowMainNumber           ;kmProcShowMainNumber
 dw ProcAutoDial                 ;kmProcAutoDial
 dw ProcCalling                  ;kmProcCalling
 dw ProcEditNumberStar           ;kmProcEditNumberStar
 dw ShowNumber0_9                ;kmShowNumber0_9
 dw ProcAutoNextOption           ;kmProcAutoNextOption
 dw ProcBookSelect               ;kmProcBookSelect
 dw ShowAllBookKeys              ;kmShowAllBookKeys
 dw ProcShowIn                   ;kmProcShowIn
 dw ProcShowOut                  ;kmProcShowOut
 dw ProcShowZK                   ;kmProcShowZK
 dw ProcClearBook                ;kmProcClearBook
 dw ProcShowNumberProperties     ;kmProcShowNumberProperties
 dw ProcClearPropAllNumber       ;kmProcClearPropAllNumber
 dw ProcBeepEmulation            ;kmProcBeepEmulation
 dw ProcTestOptionA              ;kmProcTestOptionA
 dw ProcTestOptionB              ;kmProcTestOptionB
 dw ProcBeepEmulationSubmit      ;kmProcBeepEmulationSubmit
 dw ProcResetMode                ;kmProcResetMode
 dw ProcEdMinMaxNight            ;kmProcEdMinMaxNight
 dw ProcEdSerialPasteAMode       ;kmProcEdSerialPasteAMode
 dw ProcEdMinMaxBCall            ;kmProcEdMinMaxBCall
 dw ProcNxtANxt_EditAONMode      ;kmProcNxtANxt_EditAONMode
 dw ProcPrvAPrv_EditAONMode      ;kmProcPrvAPrv_EditAONMode
 dw ProcReaddressNumber          ;kmProcReaddressNumber
 dw ProcReaddressTime            ;kmProcReaddressTime
 dw ProcSound                    ;kmProcSound
 dw ProcEdSerialPasteMT          ;kmProcEdSerialPasteMT
 dw ProcSearchNumber             ;kmProcSearchNumber
 dw ProcAntiAON                  ;kmProcAntiAON
 dw ProcEdFilterEdit             ;kmProcEdFilterEdit
 dw ProcStoreCustomNumber        ;kmProcStoreCustomNumber
 dw ProcStoreCustomBook          ;kmProcStoreCustomBook
 dw ProcEdMinMaxPass             ;kmProcEdMinMaxPass
 dw ProcTestPassword             ;kmProcTestPassword
 dw ProcEdSerialPasteHours       ;kmProcEdSerialPasteHours
 dw ProcEdSerialPasteMinutes     ;kmProcEdSerialPasteMinutes
 dw ProcEdSerialPasteDate        ;kmProcEdSerialPasteDate
 dw ProcSecondsSet               ;kmProcSecondsSet
 dw ProcRemoteAccessKey          ;kmProcRemoteAccessKey
 dw ProcAutoDialCustomNumber     ;kmProcAutoDialCustomNumber
 dw ProcExtFuncSubmit            ;kmProcExtFuncSubmit
 dw ProcEdK0_2                   ;kmProcEdK0_2
 dw ProcEdK3                     ;kmProcEdK3

MainK:   db kmProcMainKey,kfExit
ModeK:   db kmSet0_AtoSubmitMode,kfExit
CallFromKeyK: db kmSet0_BtoBeepKey,kfExit
ModeSubmitK: db kmSetL0_LBNone,kmProcModeSubmit,kfExit
SetupSubmitK: db kmSetL0_LBNone,kmProcSetupSubmit,kfExit
EdMinMaxK: db kmProcEdIncDec,kmProcEdMinMax,kmProcStarPriston_NextPrev,kfExit
EdIncDecK: db kmProcEdIncDec,kmProcStarPriston_NextPrev,kfExit
EdSerialPasteK: db kmProcEdSerialPaste,kmProcStarPriston_NextPrev,kfExit
EdSerialPasteAK: db kmProcEdSerialPaste,kmProcStarPriston_NextPrev,kfExit ;kmProcAutoNextOption,
EdMinMaxLine: db kmProcStarPriston_NextPrev,kmProcEdMinMaxLine,kfExit
EdBudEdit: db kmProcEdBudEdit,kmProcStarPriston_NextPrev,kfExit
EdBudModeSel: db kmProcEdIncDec,kmProcEdBudModeSel,kmProcStarPriston_NextPrev,kfExit
EdEditNumber: db kmProcEdEditNumber,kfExit
EdEditNumberMainPipeDown:
  db kmProcEdEditNumber,\
     kmProcEdEditNumberMainPipeDown,\
     kfExit
EdEditNumberMainPipeUp:    ; *-mode  L0..6 - Specical Tone-eSetToneKey
  db kmProcEdEditNumber,\
     kmProcEdEditNumberMainPipeUp,\
     kmProcSetL1_6PipeUp,\
     kfExit
EdEditNumberMainPipeUpTn:  ; *-mode  L0..6 - none Tone-eSetToneKey
  db kmProcSetL0NoRepeat,\
     kmProcEdEditNumber,\
     kmProcEdEditNumberMainPipeUp,\
     kfExit
EdEditNumberMainPUpTone:   ; *-tone* L0..6 - none Tone-eNone
  db kmProcEdEditNumber,\
     kmProcEdEditNumberMainPipeUp,\
     kmProcEdEditNumberMainPUpTone,\
     kmProcSetL0NoRepeat,\
     kfExit
ShowNumberK:
  db kmProcShowNumber,kfExit
ShowMainNumberK:
  db kmProcShowNumber,kmProcShowMainNumber,kfExit
AutoDialK:
  db kmProcAutoDial,kfExit
CallingK:
  db kmProcCalling,kfExit
ShowNumberOptK:
  db kmProcStarPriston_NextPrev,kmShowNumber0_9,kfExit
EditNumberOptK:
  db kmProcEdEditNumber,kmProcEditNumberStar,kfExit
BookSelectK:
  db kmSetL0_LBNone,kmProcBookSelect,kfExit

BookShowInK:
  db kmProcShowIn,kmShowAllBookKeys,kfExit
BookShowOutK:
  db kmProcShowOut,kmShowAllBookKeys,kfExit
BookShowZKK:
  db kmProcShowZK,kmShowAllBookKeys,kfExit
ClearNumberK:
  db kmProcClearBook,kfExit
ShowNumberPropertiesK:
  db kmProcShowNumberProperties,kfExit
ClearPropAllNumberK:
  db kmProcClearPropAllNumber,kfExit
BeepEmulationK:
  db kmProcBeepEmulation,kfExit
BeepEmulationSubmitK:
  db kmProcBeepEmulationSubmit,kfExit
TestOptionAK:
  db kmProcStarPriston_NextPrev,kmProcEdMinMaxLine,kmProcTestOptionA,kfExit
TestOptionBK:
  db kmProcStarPriston_NextPrev,kmProcEdMinMaxLine,kmProcTestOptionB,kfExit
ResetModeK:
  db kmProcResetMode,kfExit
EdMinMaxNightK:
  db kmProcEdIncDec,kmProcEdMinMax,kmProcStarPriston_NextPrev,\
     kmProcEdMinMaxNight,kfExit
EdSerialPasteNBellsK:
  db kmProcEdSerialPaste,kmProcStarPriston_NextPrev,\
     kmProcNxtANxt_EditAONMode,kfExit
EdSerialPasteAModeK:
  db kmProcEdSerialPaste,kmProcStarPriston_NextPrev,\
     kmProcEdSerialPasteAMode,kfExit
EdMinMaxBCallK:
  db kmProcEdIncDec,kmProcEdMinMax,kmProcStarPriston_NextPrev,\
     kmProcEdMinMaxBCall,kfExit
ShowNumberBCallK:
  db kmProcStarPriston_NextPrev,kmShowNumber0_9,\
     kmProcNxtANxt_EditAONMode,kmProcPrvAPrv_EditAONMode,kfExit
EditReaddressNumberK:
  db kmProcStarPriston_NextPrev,kmShowNumber0_9,\
     kmProcPrvAPrv_EditAONMode,kmProcReaddressNumber,kfExit
EditReaddressTimeK:
  db kmProcEdSerialPaste,kmProcStarPriston_NextPrev,\
     kmProcReaddressTime,kmProcNxtANxt_EditAONMode,kfExit
EditReaddressPagerNumberK:
  db kmProcStarPriston_NextPrev,kmShowNumber0_9,\
     kmProcPrvAPrv_EditAONMode,kfExit
EditReaddressPagerAbonentK:
  db kmProcStarPriston_NextPrev,kmShowNumber0_9,\
     kmProcNxtANxt_EditAONMode,kfExit
SoundK: db kmProcSound,kfExit
EdSerialPasteMT:
  db kmProcEdSerialPaste,kmProcStarPriston_NextPrev,\
     kmProcEdSerialPasteMT,kfExit
SearchNumberK:
  db kmProcSearchNumber,kfExit
AntiAONK:
  db kmProcAntiAON,kfExit
EditCharBuffK:
  db kmProcShowNumber,kmProcEdSerialPaste,kfExit
EdFilterEditK:
  db kmProcPrvAPrv_EditAONMode,kmProcNxtANxt_EditAONMode,\
     kmProcEdFilterEdit,kfExit
StoreCustomBookK:
  db kmProcStoreCustomBook,kfExit
StoreCustomNumberK:
  db kmProcStoreCustomNumber,kfExit
EdMinMaxPassK:
  db kmProcEdIncDec,kmProcEdMinMax,kmProcStarPriston_NextPrev,\
     kmProcEdMinMaxPass,kfExit
TestPasswordK:
  db kmProcTestPassword,kfExit

EdSerialPasteHoursK:
  db kmProcEdSerialPaste,kmProcStarPriston_NextPrev,\
     kmProcEdSerialPasteHours,kfExit
EdSerialPasteMinutesK:
  db kmProcEdSerialPaste,kmProcStarPriston_NextPrev,\
     kmProcEdSerialPasteMinutes,kfExit
EdSerialPasteDateK:
  db kmProcEdSerialPaste,kmProcStarPriston_NextPrev,\
     kmProcEdSerialPasteDate,kfExit
SecondsSetK:
  db kmProcSecondsSet,\
     kfExit
RemoteAccessKeyK:
  db kmProcRemoteAccessKey,kfExit
AutoDialCustomNumberK:
  db kmProcAutoDialCustomNumber,kfExit
ExtFuncSubmitK:
  db kmProcExtFuncSubmit,kfExit
EdK0_2K: db kmProcEdIncDec,kmProcEdK0_2,kmProcStarPriston_NextPrev,kfExit
EdK0_3K: db kmProcEdIncDec,kmProcEdK0_2,kmProcEdK3,kmProcStarPriston_NextPrev,kfExit
;------------------------------------------------------------
ProcAutoDialCustomNumber:
 db kfAutoNext,eSubmitCustomDialNumber,\
    kfStar,eReturn,\
    kfPriston,eReturn,\
    kfAutoPrevious,eReturn,\
    kfExit
ProcRemoteAccessKey:
 db kfStar,eMode,\
    kf1,eStartNumberSay,\
    kf2,eStartNumberSay,\
    kf3,eSoundMode,\
    kfPriston,eExitToMainTime,\
    kfExit
ProcSecondsSet:
 db kfSetKeysTo,kf1,kf9,eNone,\
    kf0,eSetSecondsZero,\
    kfL0,eNone,\
    kfPriston,eExitToMain,\
    kfExit
ProcEdSerialPasteDate:
 db kfAutoNext,eSetDate,\
    kfExit
ProcEdSerialPasteMinutes:
 db kfAutoNext,eMinutesSet,\
    kfExit
ProcEdSerialPasteHours:
 db kfAutoNext,eHoursSet,\
    kfExit

ProcTestPassword:
 db kfAnyKey,eExitToMain,\
    kfLAnyKey,eNone,\
    kfAutoNext,ePasswordSubmit,\
    kfAutoPrevious,eExitToMainTime,\
    kfSetKeysTo,kf0,kf9,eSetCharEditBuff,\
    kfPriston,eExitToMainTime,\
    kfExit
ProcEdMinMaxPass:
 db kfAutoNext  ,eAutoNext2ByOn,\
    kfAutoNext2,eNewPasswordEnter,\
    kfExit
ProcStoreCustomNumber:
 db kfAutoNext,eStoreCustomNumber,\
    kfStar,eReturn,\
    kfPriston,eReturn,\
    kfAutoPrevious,eReturn,\
    kfExit
ProcStoreCustomBook:
 db kfSetKeysTo,kfBookWhite,kfBookBlackLock,eStoreCustomBook,\
    kfBookZK,eStoreCustomBook,\
    kfSetKeysTo,kf0,kf9,eStoreCustomBook,\
    kfStore,eStoreFirstFree,\
    kfPriston,eReturn,\
    kf0,eEnterStoreCustomNumber,\
    kfExit
;    kfStar,eReturn,
ProcEdFilterEdit:
 db kfSetKeysTo,kf1,kf0+MaxAONLabelType,eSetFilter,\
    kfExit
ProcAntiAON:
 db kfSetKeysTo,kf0,kf9,eNone,\
    kfPriston,eExitToMain,\
    kfLAntiAON,eAntiAONStart,\
    kfExit
ProcSearchNumber:
 db kfPriston,eReturnSearch,\
    kfSetKeysTo,kf0,kf9,eReturnSearch,\
    kfSetKeysTo,kfBookSpecical,kfBookZK,eEnterFoundBook,\
    kfLStar,eEnterFoundBook,\
    kfL0,eNone,\
    kfExit
ProcEdSerialPasteMT:
 db kfLStar,eTestMelody,\
    kfExit
ProcSound:
 db kfPriston,eExitToMain,\
    kfExit
ProcPrvAPrv_EditAONMode:
 db kfPriston      ,eEditAONMode,\
    kfAutoPrevious ,eEditAONMode,\
    kfExit
ProcNxtANxt_EditAONMode:
 db kfStar     ,eExitToMain,\
    kfAutoNext ,eExitToMain,\
    kfExit

ProcReaddressTime:
 db kfAutoPrevious ,eAModeSet,\
    kfPriston      ,eAModeSet,\
    kfExit
ProcReaddressNumber:
 db kfAutoNext     ,eEditReaddressingTime,\
    kfStar         ,eEditReaddressingTime,\
    kfExit

ProcEdMinMaxBCall:
 db kfAutoNext  ,eAutoNext2ByOn,\
    kfAutoNext2 ,eEditBCallNumber,kfExit
ProcEdSerialPasteAMode:
 db kfAutoNext ,eAModeSet,\
    kf0        ,eEditNight,\
    kf9        ,eEditFilter,\
    kfExit
ProcEdMinMaxNight:
 db kfPriston   ,eEditAONMode,\
    kfAutoNext  ,eAutoNext2ByOn,\
    kfAutoNext2 ,eNextOption,kfExit
Set0_BtoBeepKey:
 db kfSetKeysTo,kf0,kfPriston,eTakeNumeralKey,\
    kfDJump,kmDisableRepeat0_B
Set0_AtoSubmitMode:
 db kfSetKeysTo,kf0,kfPriston,eSubmitMode,\
    kfExit

DisableRepeat0_B:
 db kfSetKeysTo,kfL0,kfLPriston,eNoRepeat,\
    kfExit
SetL0_LBNone:
 db kfSetKeysTo,kfL0,kfLPriston,eNone,\
    kfExit


DefaultFKey:
 db kfStar          ,eMode,\
    kfL0            ,eExitToMain,\
    kfMode          ,eMode,\
    kfFlash         ,eExitToMain,\
    kfTone          ,eExitToMain,\
    kfRedial        ,eAutoDialKey,\
    kfSpkPhnOnOff   ,eSpeakerPhoneChange,\
    kfLMode         ,eNoRepeat,\
    kfLFlash        ,eNoRepeat,\
    kfLTone         ,eNoRepeat,\
    kfLSpkPhnOnOff  ,eNoRepeat,\
    kfLRedial       ,eAutoDialCustomNumber,\
    kfHold          ,eHold_LineGet,\
    kfLHold         ,eNoRepeat,\
    kfSetKeysTo,kfBookSpecical,kfBookZK,eShowBook,\
    kfAntiAON       ,eAntiAONStart,\
    kfStore         ,eEnterStore,\
    kfVolume        ,eVolumeChange,\
    kfLVolume       ,eNoRepeat,\
    kfExit

ProcExtFuncSubmit:
 db kf0,eEnterSearch,\
    kf1,eHold_LineGet,\
    kf2,eFlashStart,\
    kf3,eConfidenceOnOff,\
    kfPriston,eExitToMain,\
    kfExit
ProcModeSubmitFKey:
 db kf3,eSetupMode,\
    kf5,eEditBud,\
    kf1,eEditAONMode,\
    kf6,eBookSelectMode,\
    kfSetKeysTo,kf7,kf9,eShowBook,\
    kf2,eSoundMode,\
    kf4,eEditTimeDate,\
    kfPriston,eAutoDialKey,\
    kf0,eEnterExtFunct,\
    kfExit
;    kf0,eConfidenceOnOff,
;    kfPriston,eEnterSearch,
;    kfStar,eAutoDialKey,
ProcSetupSubmitFKey:
 db kf7,eEditOpt0,\
    kf8,eEditOpt1,\
    kf3,eEditOpt2,\
    kf9,eEditOpt3,\
    kf4,eEditOpt4,\
    kf2,eSayCurrentTime,\
    kf5,eEnterReset,\
    kfStar,eEditLock,\
    kf1,eEnterSetSecondsZeroMode,\
    kf6,eShowVersionInfo,\
    kfExit
ProcEdBudEdit:
 db kfSetKeysTo,kf0,kf9,eBitDaySet,\
    kfExit
ProcEdMinMaxFKey:
 db kf0,eSetMin,\
    kf1,eSetMax,\
    kfExit
ProcEdIncDecFKey:
 db kfSetKeysTo,kf0,kf9,eIncOption,\
    kfExit
ProcEdSerialPasteFKey:
 db kfSetKeysTo,kf0,kf9,eSetCharEditBuff,\
    kfPriston,eDeleteCharEditBuff,\
    kfExit
ProcEdK0_2:
 db kfSetKeysTo,kf0,kf2,eSetCharEditBuff,\
    kfExit
ProcEdK3:
 db kf3,eSetCharEditBuff,\
    kfExit
ProcEdMinMaxLine:
 db kf0,eSetMin,\
    kf8,eSetMax,\
    kf7,eDecOptionA,\
    kf9,eIncOptionA,\
    kfExit
ProcEdBudModeSel:
 db kfSetKeysTo,kf0,kf0+MaxAlarmModes-1,eSetCharEditBuff,\
    kfExit
ProcStarPriston_NextPrev:
 db kfStar,eNextOption,\
    kfPriston,ePreviousOption,\
    kfExit

ProcEdEditNumber:
 db kfSetKeysTo,kf0,kf9,eAddNumeralBuff,\
    kfSetKeysTo,kfL1,kfL6,eAddNumeralBuff,\
    kfSetKeysTo,kfL7,kfL9,eNoRepeat,\
    kfPriston,eDeleteNumeralBuff,\
    kfTone,eToneSet,\
    kfLPriston,eNoRepeat,\
    kfExit
ProcMainKey:
 db kfSetKeysTo,kf0,kf9,eMainEditNumber,\
    kfTone,eMainEditNumber,\
    kfPriston,eShowNumber,\
    kfL0,eNone,\
    kfExit
ProcEdEditNumberMainPipeDown:
 db kfStar,eMode,\
    kfAutoPrevious,eReturn,\
    kfExit
ProcEdEditNumberMainPipeUp:
 db kfSetKeysTo,kf0,kf9,eAdd_CallNumeralBuff,\
    kfSetKeysTo,kfL1,kfL9,eNoRepeat,\
    kfTone,eToneSetKey,\
    kfExit
ProcEdEditNumberMainPUpTone:
 db kfStar,eAdd_CallNumeralBuff,kfPriston,eAdd_CallNumeralBuff,\
    kfLStar,eNoRepeat,kfLPriston,eNoRepeat,\
    kfTone,eNone,\
    kfExit
ProcSetL0NoRepeat:
 db kfL0,eNoRepeat,\
    kfExit
ProcSetL1_6PipeUp:
 db kfSetKeysTo,kfL1,kfL4,eAdd_CallNumeralBuff,\
    kfL3,eToneSetKey,\
    kfExit
ProcShowNumber:
 db kfAnyKey,eReturnKeyEvent,\
    kfLAnyKey,eNone,\
    kfVolume        ,eVolumeChange,\
    kfLVolume       ,eNoRepeat,\
    kfExit
ProcShowMainNumber:
 db kfPriston,eExitToMain,\
    kfExit
ProcAutoDial:
 db kfSetKeysTo,kf0,kf9,eNone,\
    kfPriston,eExitToMain,\
    kfRedial,eRedialA,\
    kfExit
ProcCalling:
 db kfPriston,eExitToMain,\
    kf0,eIndification,\
    kfExit
ProcEditNumberStar:
 db kfStar,eSubmitEditNumber,\
    kfExit
ShowNumber0_9:
 db kfSetKeysTo,kf0,kf9,eStartEditNumberAddNumeral,\
    kfAutoNext,eNextOption,\
    kfAutoPrevious,ePreviousOption,\
    kfExit
ProcAutoNextOption:
 db kfAutoNext,eNextOption,\
    kfAutoPrevious,ePreviousOption,\
    kfExit
ProcBookSelect:
 db kfSetKeysTo,kf0,kf3,eShowBook,\
    kfExit
ShowAllBookKeys:
 db kfStar,eIncOptionA,\
    kfPriston,eDecOptionA,\
    kf9,eAutoDialKey,\
    kf8,eSet8Book,\
    kf1,eEnterClearNumber,\
    kfExit
ProcShowIn:
 db kf2,eShowKateg,\
    kf3,eShowCallsPerTime,\
    kf4,eShowTimeCall,\
    kf5,eShowTimeSay,\
    kf6,eShowDateCall,\
    kf0,eStartNumberSay,\
    kfLBookIn,eStartNumberSay,\
    kfBookIn,eIncOptionA,\
    kfExit
; kf7,eStartEditNumber,
ProcShowOut:
 db kf3,eShowAllTimeSay,\
    kf4,eShowTimeCall,\
    kf5,eShowTimeSay,\
    kf6,eShowDateCall,\
    kf0,eStartNumberSay,\
    kfLBookOut,eStartNumberSay,\
    kfBookOut,eIncOptionA,\
    kfExit
; kf7,eStartEditNumber,
ProcShowZK:
 db kf5,eStartEditNumber,\
    kf4,eSetUndefinedNumber,\
    kf0,eEditCharBuff,\
    kfExit
ProcClearBook:
 db kf2,eClearBook,\
    kf1,eDeleteNumber,\
    kfPriston,eReturn,\
    kfExit
ProcShowNumberProperties:
 db kf1,eEnterClearPropAllNumber,\
    kf3,eChangeShowAllTimeSay,\
    kfPriston,eReturn,\
    kfExit
ProcClearPropAllNumber:
 db kf1,eSubmitClearPropAllNumber,\
    kfPriston,eReturn,\
    kfExit
ProcBeepEmulation:
 db kf0,eSetNoSoundPlay,\
    kf1,eSetSoundPlay,\
    kf2,eSetListenLine,\
    kfSetKeysTo,kf6,kf9,eSayLineCurrPhrase,\
    kfPriston,eExitToMain,kfExit
ProcTestOptionA:
 db kf1,eTestCurrBeepTone,\
    kfL1,eNoRepeat,kfExit
ProcTestOptionB:
 db kf1,eSayCurrentTime,\
    kfL1,eNoRepeat,kfExit
ProcBeepEmulationSubmit:
 db kf6,eRecallLater,\
    kf7,eRecallTomorrow,\
    kf8,eRecallInTimeLater,\
    kf9,eNumberUndefined,\
    kfExit
ProcResetMode:
 db kfSetKeysTo,kf1,kf3,eResetAll,\
    kfPriston,eExitToMain,\
    kf0,eCall,\
    kf9,eDebugBeep,\
    kfExit
;------------------------------------------------------------
BeepEvents:
;  NoBeep,Short,Long,VeryLong
 db eNextNumeralCallN,eRedialA,eRedialA,eRedialA
 db eRedialA,eRedialA,eRedialA,eNextNumeralCallN
 db eNextNumeralCallN,eNextNumeralCallN,eNextNumeralCallN,eNextNumeralCallN
 db eBeepTestCallA,eRedial,eBeepTestCallA,eRedial

;bmBeepEmulation
 db eStartBeepLine,eExitToMainTime,eExitToMainTime,eExitToMainTime
;bmToneBeepEmulation
 db ePlayBellInRoom,eExitToMainTime,eExitToMainTime,eExitToMainTime

 db eRepeatPhraseN,eExitToMainTime,eExitToMainTime,eExitToMainTime

;BCallStartBT
 db eAutoDial,eAutoDial,eBCallSay,eAutoDial
;BCallSayingBT
 db eBCallSay,eExitToMainTime,eBCallSay,eExitToMainTime
;Hold
 db eStartMelodyHold,eExitToMain,eExitToMain,eExitToMain
;SayingNumber
 db eNextNumberSay,eExitToMain,eExitToMain,eExitToMain
;TestBeepToPipeDown
 db eTestBeepToPipeDown,eTestPipeDownNow,eTestBeepToPipeDown,eTestPipeDownNow
;RemoteAccessKey
 db eContinueTestBeepRemoteAccess,eExitToMainTime,eContinueTestBeepRemoteAccess,eExitToMainTime
;Debug Beep
 db eDebugBeep,eDebugBeep,eDebugBeep,eDebugBeep
;------------------------------------------------------------
SoundUnPackTbl:
 db 0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,\
 0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,\
 0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,\
 0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,\
 0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,\
 0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,0xA3,\
 0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0xC5,0xC5,0xC5,0xC5,0x55,0x55,0x55,0x55,\
 0x75,0x75,0x75,0x75,0xF7,0xD7,0x66,0x66,0xE5,0xE5,0xE5,0xE5,0xB5,0xB5,0xB5,0xB5,\
 0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,\
 0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,\
 0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,\
 0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,\
 0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23,\
 0x93,0x93,0x93,0x93,0x93,0x93,0x93,0x93,0x93,0x93,0x93,0x93,0x93,0x93,0x93,0x93,\
 0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,\
 0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12

 public SSayKateg,SSayTimeCall,SSayDateCall,SSayTimeSay,SSaySetTime,SSaySetInTime
SSayKateg:
 db tsSetWavData0MemI,Kateg,0,tsSayKey,tsEndPhrase
SSayTimeCall:
 db tsSetWavData0MemI,HourCall,0,tsSetWavData1MemI,MinCall,0,\
  tsIn,tsSayChar,tsSayH,tsSetPause,5,tsSayMinutes,tsSayM,\
  tsEndPhrase
SSayDateCall:
 db tsSetWavData0MemI,DayOfWeekCall,1,tsSayChar,\
  tsSetWavData0MemI,Day,0,tsSayChar,\
  tsSetWavData0MemI,Month,0,tsSayChar,\
  tsEndPhrase
SSayTimeSay:
 db tsSetWavData0MemI,HourSay,0,\
  tsSetWavData1MemI,MinSay,0,\
  tsSayChar,tsSayH,tsSetPause,5,tsSayMinutes,tsSayM,\
  tsEndPhrase
SSaySetInTime:
 db tsIn
SSaySetTime:
 db tsSetWavData0cv,tsSetWavData1cv,\
  tsSayChar,tsSayH,tsSetPause,5,tsSayMinutes,tsSayM,\
  tsEndPhrase