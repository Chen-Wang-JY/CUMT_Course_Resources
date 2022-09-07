/*word count*/
%{
    #include<string.h>

    enum tokenType{
        NUMBER,
        ADD,
        SUB,
        MUL,
        DIV,
        ABS,
        EOL,
    };
    char* tokenString[] = {"NUMBER", "ADD", "SUB", "MUL", "DIV", "ABS", "EOL"};
    int tempVal;
%}
%%
"+"     {return ADD;}
"-"     {return SUB;}
"*"     {return MUL;}
"/"     {return DIV;}
"|"     {return ABS;}
[0-9]+  {tempVal = atoi(yytext); return NUMBER; printf("match a number: %d\n", tempVal);}
\n      {return EOL;}
[ \t]   {/*忽略空白字符*/}
.       {printf("Mystery character %c\n", *yytext);}
%%
int main(int argc, char **argv){
    printf("begin\n");
    int tok;
    while(tok = yylex()){
        tok = yylex();
        printf("in\n");
        printf("now is: %s\n", tokenString[tok]);
        if(tok == NUMBER) printf(" = %d\n", tempVal);
        else printf("\n");
    }
    printf("out\n");
    return 0;
}

int yywrap(){
    return 1;
}