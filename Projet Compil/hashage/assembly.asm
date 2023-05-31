TITLE prg.asm : 
Pile segment stack ; 
dw 100 dup(?) 
Pile ends 
DATA segment 
temp DD 2000 ?
DATA ends
CODE segment
ASSUME CS:CODE, DS:DATA
MAIN :
MOV AX,DATA
MOV DS,AX
FIN:
MOV AH,4CH
INT 21h
CODE ends
END MAIN
