@echo off
flex lexical.l
bison -d syntax.y
gcc -o mycompiler lex.yy.c syntax.tab.c -lfl -ly
type test.txt | mycompiler.exe
