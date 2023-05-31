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
etiquette0: 
MOV BX, 1.000000 
MOV SI, 1 
MOV temp[SI], BX
etiquette1: 
MOV BX, 2.000000
MOV AX, 1.000000
MOV SI, tmporaire>
ADD BX, AX 
MOV temp[SI], BX
FIN:
MOV AH,4CH
INT 21h
CODE ends
END MAIN
