%{
    int wordCount = 0;
%}
chars [A-za-z\_\'\.\"]
numbers ([0-9])+
delim [" "\n\t]
whitespace {delim}+
words {chars}+
%%
{words} {wordCount++;}
{whitespace} {/*donothing*/}
{numbers} {/*one may want to add some processing here*/}
. {/*donothing*/}
%%
void main(){
    yylex();
    printf("%d\n", wordCount);
}
int yywrap(){
    return 1;
}