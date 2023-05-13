flex lexical.l
bison -d syntax.yy
gcc lex.yy.c  syntax.tab.c -lfl -ly -o ProjetSM.exe


