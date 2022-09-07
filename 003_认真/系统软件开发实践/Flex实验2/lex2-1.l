%{
    int currentLine = 1;
%}
letter [a-zA-Z\_]
digit [0-9]
ID {letter}({letter}|{digit})*
NUMBER [1-9]{digit}*
KEYWORD ("else"|"if"|"switch"|"for"|"int"|"float"|"return"|"void"|"while")
SYMBOL ("+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"=="|"!="|"="|";"|","|"("|")"|"["|"]"|"{"|"}")
%%
\n {
    currentLine++;
}
{NUMBER} {
    printf("line %d:\tnumber\t%s\n", currentLine, yytext);
}
{KEYWORD} {
    printf("line %d:\tKeyWord\t%s\n", currentLine, yytext);
}
{ID} {
    printf("line %d:\tID\t%s\n", currentLine, yytext);
}
{SYMBOL} {
    printf("line %d:\tSymbol\t%s\n", currentLine, yytext);
}

. {

}
%%
int main(){
    yylex();
    printf("end\n");
    return 0;
}

int yywrap(){
    return 1;
}