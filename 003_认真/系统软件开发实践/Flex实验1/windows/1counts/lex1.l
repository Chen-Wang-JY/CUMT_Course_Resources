/*word count*/
%{
    int chars = 0;
    int words = 0;
    int lines = 0;
%}
%%
[^ \t\n]+ {words++; chars += yyleng;printf("match a word: %s\n", yytext);}
\n {
    chars++;
    lines++;
}
. {
    chars++;
}
%%
int main(int argc, char **argv){
    yylex();
    printf("%d\t%d\t%d\n", chars, words, lines);
    return 0;
}

int yywrap(){
    return 1;
}