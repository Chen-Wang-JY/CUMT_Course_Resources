letter [a-zA-Z\_]
digit [0-9]

ID {letter}({letter}|{digit})*
DEC_NUMBER [+-]?(0|([1-9]{digit}*))(\.{digit}+)?
SCI_NUMBER [-]?([1-9](\.{digit}+)?|(0.{digit}+))e[-]?{digit}+
BIN_NUMBER [-]?0[Bb][1][01]*
OCT_NUMBER [-]?0[1-7][0-7]*
HEX_NUMBER [-]?0[xX][1-9a-fA-F][0-9a-fA-F]*

KEYWORD1 "else"|"if"|"switch"|"for"|"int"|"float"|"return"|"void"|"while"|"string"
KEYWORD2 "include"|"iostream"|"using"|"namespace"|"std"|"main"|"cout"|"endl"
KEYWORD {KEYWORD1}|{KEYWORD2}
SYMBOL "+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"=="|"!="|"="|";"|","|"("|")"|"["|"]"|"{"|"}"|"<<"|"#"
STRING \".*\"
SINGLE_LINE_COMMENT "//"[^\n]*
MULTI_LINE_COMMENT "/*"

%{
    #include <stdio.h>
    #include <string.h>
    int currentLine = 1;
    int currentColumn = 1;
    void count(int* currentColumnP);
    void multi_line_comment();
%}

%%
\n {
    currentLine++;
    currentColumn = 1;
}
{DEC_NUMBER} {
    printf("line %d\tcolumn %d:\tDec_Number\t%s\n", currentLine, currentColumn, yytext);
    count(&currentColumn);
}
{SCI_NUMBER} {
    printf("line %d\tcolumn %d:\tSci_Number\t%s\n", currentLine, currentColumn, yytext);
    count(&currentColumn);
}
{BIN_NUMBER} {
    printf("line %d\tcolumn %d:\tBin_Number\t%s\n", currentLine, currentColumn, yytext);
    count(&currentColumn);
}
{OCT_NUMBER} {
    printf("line %d\tcolumn %d:\tOct_Number\t%s\n", currentLine, currentColumn, yytext);
    count(&currentColumn);
}
{HEX_NUMBER} {
    printf("line %d\tcolumn %d:\tHex_Number\t%s\n", currentLine, currentColumn, yytext);
    count(&currentColumn);
}
{KEYWORD} {
    printf("line %d\tcolumn %d:\tKeyWord\t%s\n", currentLine, currentColumn, yytext);
    count(&currentColumn);
}
{ID} {
    printf("line %d\tcolumn %d:\tID\t%s\n", currentLine, currentColumn, yytext);
    count(&currentColumn);
}
{STRING} {
    printf("line %d\tcolumn %d:\tString\t%s\n", currentLine, currentColumn, yytext);
    count(&currentColumn);
}
{SINGLE_LINE_COMMENT} {
    /*单行注释不需要做动作，因为接下来必定出现的换行符会被匹配，从而更新line与column*/
}
{MULTI_LINE_COMMENT} {
    multi_line_comment();
}
{SYMBOL} {
    printf("line %d\tcolumn %d:\tSymbol\t%s\n", currentLine, currentColumn, yytext);
    count(&currentColumn);
}


. {
    count(&currentColumn);
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

void count(int* currentColumnP){
    int len = strlen(yytext);
    for(int i = 0; i < len; i++){
        if(yytext[i] == '\t')
            *currentColumnP += 8;
        else if(yytext[i] == '\n')
            *currentColumnP = 1;
        else
            *currentColumnP += 1;
    }
}

void multi_line_comment(){
    char c;
    char prev = 0;
    while((c = input()) != 0){  //EOF 的Asci编码为0
        if(c == '/' && prev == '*')
            return;
        else if(c == '\t')
            currentColumn += 8;
        else if(c == '\n'){
            currentColumn = 1;
            currentLine += 1;
        }
        prev = c;
    }
}