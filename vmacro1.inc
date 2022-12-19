/* 
 * V2000 UA phone firmware for x51
 * made in 3 month by 19yo student in Ukraine at early 2000
 * Victor Kozub (C) Copyright 2000
 * https://github.com/xen1024
 */

; ENUM EMULATION FOR ASM
; %defenum X - start
; %enum s0,s1...s9
; %endenum   - end
 macro %redefenum
 ; \O \L0
 if \0 BINAND 0x01
 ; \T \L1 \+
 endif
 if \0 BINAND 0x02
 ; \T \L2 \+
 endif
 if \0 BINAND 0x04
 ; \T \L4 \+
 endif
 if \0 BINAND 0x08
 ; \T \L8 \+
 endif
 if \0 BINAND 0x10
 ; \T \L16 \+
 endif
 if \0 BINAND 0x20
 ; \T \L32 \+
 endif
 if \0 BINAND 0x40
 ; \T \L64 \+
 endif
 if \0 BINAND 0x80
 ; \T \L128 \+
 endif
 if \0 BINAND 0x0100
 ; \T \L256 \+
 endif
 if \0 BINAND 0x0200
 ; \T \L512 \+
 endif
 if \0 BINAND 0x0400
 ; \T \L1024 \+
 endif
 if \0 BINAND 0x0800
 ; \T \L2048 \+
 endif
 if \0 BINAND 0x1000
 ; \T \L4096 \+
 endif
 if \0 BINAND 0x2000
 ; \T \L8192 \+
 endif
 if \0 BINAND 0x4000
 ; \T \L8192 \+ \L8192 \+
 endif
 endmac

 macro %defenum
 ; \L0
  %redefenum \0
 endmac

 macro %endenum
; \O
 endmac

 macro %enum
; \?
 if \.>0
 ;\A
\0 = \. ;\I \A
 endif
 if \.>1
 ;\A
\1 = \. ;\I \A
 endif
 if \.>2
 ;\A
\2 = \. ;\I \A
 endif
 if \.>3
 ;\A
\3 = \. ;\I \A
 endif
 if \.>4
 ;\A
\4 = \. ;\I \A
 endif
 if \.>5
 ;\A
\5 = \. ;\I \A
 endif
 if \.>6
 ;\A
\6 = \. ;\I \A
 endif
 if \.>7
 ;\A
\7 = \. ;\I \A
 endif
 if \.>8
 ;\A
\8 = \. ;\I \A
 endif
 if \.>9
 ;\A
\9 = \. ;\I \A
 endif
; \L9
; \-
; \A
; \-
; \D
 endmac

 macro %subC
 if \1=1
  dec \0
 else
  xch A,\0
  add A,#-\1
  xch A,\0
 endif
 endmac
