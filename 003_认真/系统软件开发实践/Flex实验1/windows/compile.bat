cd ./%1
flex lex.l
gcc lex.yy.c -o lex.exe