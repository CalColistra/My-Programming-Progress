;----------------------------------------------------------------------------
; file:		    moreMath.asm
; author:	    <Cal Colistra>
; date:		    12/06/2021
; description:
;   This file adds up values by using registers, then finds the average of 
;   those values and stores the average in eax
;----------------------------------------------------------------------------
		option	casemap:none    ;case sensitive
;----------------------------------------------------------------------------
;symbol definitions
;----------------------------------------------------------------------------
		.data					;variables definitions
sum     SDWORD  ?				;32 bit variablefor storing the sum
avg     SDWORD  ?               ;32 bit variable for sotring the average
min     SDWORD  ?               ;32 bit variable for storing the minimum value
max     SDWORD  ?               ;32 bit variable for storing the maximum value
cnt     DWORD   0               ;32 bit variable for counting # of variables that are less than avg
num     DWORD   0               ;32 bit variable to count number of values
X0      SDWORD  5               ;32 bit variable
X1      SDWORD  1               ;32 bit variable
X2      SDWORD  100             ;32 bit variable
X3      SDWORD  90              ;32 bit variable
X4      SDWORD  -10             ;32 bit variable
;----------------------------------------------------------------------------
		.code					;executable instructions (procedures/functions)
calc	proc

;this block of code adds up the 5 values then stores the result in sum
;and it divides the sum by the number of values and stoes the result in avg
        mov	    eax,  X0	    ;get X0
        inc     num             ;increment counter
        mov     ebx,  X1	    ;get X1
        add     eax,  ebx       ;add X0 and X1 and store it in eax
        inc     num             ;increment counter
        mov     ebx,  X2        ;get X2
        add     eax,  ebx       ;add X2 and store in eax
        inc     num             ;increment counter
        mov     ebx,  X3        ;get X3
        add     eax,  ebx       ;add X3 and store in eax
        inc     num             ;increment counter
        mov     ebx,  X4        ;get X4
        add     eax,  ebx       ;add X4 and store in eax
        inc     num             ;increment counter
        mov     sum,  eax       ;put eax in to sum
        mov     edx,  0         ;set edx to 0 for div
        idiv    num             ;divide sum by counter
        mov     avg,  eax       ;put the average in avg
        mov     eax,  X0        ;get X0

;this block of code compares each value and stores the lowest value in min
;it also compares again and stoes the greatest value in max

        cmp     eax,  X1        ;compare X0 with X1
        jl      if11            ;if X0 is less than X1 then jump  to next cmp
        mov     eax,  X1        ;else mov X1 into eax
if11:
        cmp     eax,  X2        ;compare X2 with eax
        jl      if22            ;if value in eax is less than X2 then jump to next cmp
        mov     eax,  X2        ;else mov X2 into eax
if22:
        cmp     eax,  X3        ;compare X3 with eax
        jl      if3             ;if value in eax is less than X3 then jump to next cmp
        mov     eax,  X3        ;else mov X3 into eax
if3:    
        cmp     eax,  X4        ;compare X4 with eax
        jl      done            ;if value in eax is less than X4 then jump to next cmp
        mov     eax,  X4        ;else mov X4 into eax
done:
        mov     min, eax        ;put the minimum value into min

        mov     eax,  X0        ;get X0
        cmp     eax,  X1        ;compare X0 with X1
        jg      iff1            ;if X0 is greater than X1 then jump  to next cmp
        mov     eax,  X1        ;else mov X1 into eax
iff1:
        cmp     eax,  X2        ;compare X2 with eax
        jg      iff2            ;if value in eax is greater than X2 then jump to next cmp
        mov     eax,  X2        ;else mov X2 into eax
iff2:
        cmp     eax,  X3        ;compare X3 with eax
        jg      iff3            ;if value in eax is greater than X3 then jump to next cmp
        mov     eax,  X3        ;else mov X3 into eax
iff3:    
        cmp     eax,  X4        ;compare X4 with eax
        jg      done2           ;if value in eax is greater than X4 then jump to next cmp
        mov     eax,  X4        ;else mov X4 into eax
done2:
        mov     max,  eax       ;put the maximum value into max

;this block of code compares each value with the avg and counts 
;how many values are less than the average

        mov     eax,  X0        ;get X0
        cmp     eax,  avg       ;compare X0 with avg
        jg      l1              ;if X0 is greater than avg then jump
        inc     cnt             ;else incrememnt counter
l1:
        mov     eax,  X1        ;get X1
        cmp     eax,  avg       ;compare X1 with avg
        jg      l2              ;if X1 is greater than avg then jump
        inc     cnt             ;else incrememnt counter
l2:
        mov     eax,  X2        ;get X2
        cmp     eax,  avg       ;compare X2 with avg
        jg      l3              ;if X2 is greater than avg then jump
        inc     cnt             ;else incrememnt counter
l3:
        mov     eax,  X3        ;get X3
        cmp     eax,  avg       ;compare X3 with avg
        jg      l4              ;if X3 is greater than avg then jump
        inc     cnt             ;else incrememnt counter
l4:
        mov     eax,  X4        ;get X4
        cmp     eax,  avg       ;compare X4 with avg
        jg      l5              ;if X4 is greater than avg then jump
        inc     cnt             ;else incrememnt counter
l5:     
        ret	
calc    endp

getSum  proc                        
        mov     eax,  sum       ;commincate sum variable to c++
        ret
getSum  endp

getMax  proc
        mov     eax,  max       ;commincate max variable to c++
        ret
getMax  endp

getMin  proc
        mov     eax,  min       ;commincate min variable to c++
        ret
getMin  endp

getAvg  proc
        mov     eax,  avg       ;commincate sum avg to c++
        ret
getAvg  endp

getCnt  proc
        mov     eax,  cnt
        ret
getCnt  endp
		end						;required by Mr. Gates!
;----------------------------------------------------------------------------
