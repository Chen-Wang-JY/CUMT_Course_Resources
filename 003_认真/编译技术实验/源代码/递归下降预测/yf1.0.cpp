#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

const char* keyWord[8] = {"if", "for", "else", "while", "do", "float", "int", "break"};
char keyWordTable[20][20], reKeywordTable[20][20];  //存放保留字
char digitTable[20][20], reDigitTable[20][20];      //存放数字
char otherCharTable[20][20], reOtherCharTable[20][20];  //存放其他字符
char idTable[20][20], reIdTable[20][20];            //存放标识符
char noteTable[20][20];                             //存放注释
char finalTable[100][20];                           //存放终结符
int finalTableInt[100];
char word[20];
void initialize();
void alpha();
void digit();
void error();
void otherChar();
void note();
void print();

void program();
void block();
void stmts();
void stmt();
void myBool();
void expr();
void expr1();
void term();
void term1();
void factor();
void match(char *t);

int digitNum = 0, keywordNum = 0, otherCharNum = 0, idNum = 0, noteNum = 0;
int redigitNum = 1, reKeyWordNum = 1, reOtherCharNum = 1, reIdNum = 1;
int finalNum = 0, _finalNum = 0;
int flagError = 0, _flagError = 0;
char lookAhead;

int main()
{
    printf("请输入要分析的语句:\n");
    initialize();   
    //词法分析
    while(true){
        lookAhead = getchar();
        if(isalpha(lookAhead)){
            alpha();
            initialize();
        }
        else if(isdigit(lookAhead)){
            digit();
            initialize();
        }
        else if(lookAhead == '\t' || lookAhead == ' ')
            continue;
        else if(lookAhead == '\n')
            break;
        else if(lookAhead == '/'){
            lookAhead = getchar();
            if(lookAhead == '*'){
                note();
                initialize();
            }
            else{
                ungetc(lookAhead, stdin);
                strcpy(finalTable[finalNum] , "/");
                strcpy(finalTable[otherCharNum++], "/");
                finalTableInt[finalNum++] = 2;
                initialize();
            }
        }
        else{
            otherChar();
            initialize();
        }
    }
    //如果词法分析无错误，进入语法分析
    if(flagError == 0){
        print();
        program();
        if(_finalNum == finalNum)
            printf("语法分析完成！\n");
    }
}

void initialize(){
    for(int i = 0; i < 20; i++)
        word[i] = '\0';
}

void alpha(){
    //读入完整标识符
    int i = 1, flag;
    char ch;
    ch = lookAhead;
    word[0] = ch;
    ch = getchar();
    while(isalpha(ch) || isdigit(ch)){
        word[i++] = ch;
        ch = getchar();
    }
    ungetc(ch, stdin);
    flag = 0;
    //判断是否是保留字
    for(i = 0; i < 8; i++){
        if(strcmp(word, keyWord[i]) == 0)
            flag = 1;
    }
    //如果是保留字
    if(flag == 1){
        strcpy(keyWordTable[keywordNum++], word);   //将保留字复制到保留字表中
        strcpy(finalTable[finalNum], word);         //将保留字复制到终结符表中
        //分别判断是哪个保留字
        for(int k = 1; k <= 8; k++){
            if(strcmp(word, keyWord[k - 1]) == 0){
                finalTableInt[finalNum++] = k * 100;    //对应保留字终结符的序号为100~800
                break;
            }
        }
    }
    //如果是标识符
    else{
        strcpy(idTable[idNum++], word);         //将标识符复制到标识符表中
        strcpy(finalTable[finalNum], "id");     //终结符表中存放ID
        finalTableInt[finalNum++] = 1;          //标识符的序号为1
    }
}

void digit(){
    int i = 1, flag;
    char ch = lookAhead;
    word[0] = ch;
    ch = getchar();
    while (isalpha(ch) || isdigit(ch)){
        word[i++] = ch;
        ch = getchar();
    }
    ungetc(ch, stdin);
    //判断word是否是数字
    flag = 0;
    for(int i = 0; word[i] != '\0'; i++){
        //有一个字符不是数字
        if(word[i] < '0' || word[i] > '9'){
            flag = 1;
        }
    }
    //如果word有一个字符不是数字，则将该字符串放到标识符数组中
    if(flag == 1){
        strcpy(idTable[idNum++], word);
        strcpy(finalTable[finalNum], "id");
        finalTableInt[finalNum++] = 1;      //标识符的序号是1
        
    }
    //如果都是数字，则将它放到数字数组中
    else{
        strcpy(digitTable[digitNum++], word);
        strcpy(finalTable[finalNum], "num");
        finalTableInt[finalNum++] = 99;     //数字的序号是99
    }
}

void note(){
    char ch;
    int i = 0;
    ch = getchar();
    while(1){
        if(ch == '*'){
            //出现了第二个 *，注释结束
            ch = getchar();
            if(ch == '/')
                break;
            //此时第二个 * 也属于注释
            else{
                /*这里和课本不一样！！！！！！！！！！*/
                /*我觉得不要写下面这句话*/
                //ungetc(ch, stdin);
                word[i++] = '*';
                word[i++] = ch;
            }
        }
        else{
            //未出现第二个 * ,所以仍为注释
            word[i++] = ch;
        }
        ch = getchar();
    }
    strcpy(noteTable[noteNum++], word);
}

void otherChar(){
    char ch;
    ch = lookAhead;
    switch(ch){
    case '!':{
        ch = getchar();
        // !=
        if(ch == '='){
            strcpy(otherCharTable[otherCharNum++], "!=");
            strcpy(finalTable[finalNum], "!=");
            finalTableInt[finalNum++] = 3;          // != 的序号是3；
        }
        else{
            ungetc(ch, stdin);
            error();
        }
        break;
    }
    case '=':{
        ch = getchar();
        // ==
        if(ch == '='){
            strcpy(otherCharTable[otherCharNum++], "==");
            strcpy(finalTable[finalNum], "==");
            finalTableInt[finalNum++] = 4;          // == 的序号是4；
        }
        // =
        else{
            strcpy(otherCharTable[otherCharNum++], "=");
            strcpy(finalTable[finalNum], "=");
            finalTableInt[finalNum++] = 5;          // = 的序号是5；
            ungetc(ch, stdin);
        }
        break;
    }

    case '(':{
        strcpy(otherCharTable[otherCharNum++], "(");
        strcpy(finalTable[finalNum], "(");
        finalTableInt[finalNum++] = 6;          // ( 的序号是6；  
        break;     
    }

    case ')':{
        strcpy(otherCharTable[otherCharNum++], ")");
        strcpy(finalTable[finalNum], ")");
        finalTableInt[finalNum++] = 7;          
        break;     
    }

    case ';':{
        strcpy(otherCharTable[otherCharNum++], ";");
        strcpy(finalTable[finalNum], ";");
        finalTableInt[finalNum++] = 8;          
        break;     
    }

    case '{':{
        strcpy(otherCharTable[otherCharNum++], "{");
        strcpy(finalTable[finalNum], "{");
        finalTableInt[finalNum++] = 9;          
        break;     
    }

    case '}':{
        strcpy(otherCharTable[otherCharNum++], "}");
        strcpy(finalTable[finalNum], "}");
        finalTableInt[finalNum++] = 10;          
        break;     
    }

    case '||':{
        strcpy(otherCharTable[otherCharNum++], "||");
        strcpy(finalTable[finalNum], ";");
        finalTableInt[finalNum++] = 11;          
        break;     
    }
    
    case '&&':{
        strcpy(otherCharTable[otherCharNum++], "&&");
        strcpy(finalTable[finalNum], "&&");
        finalTableInt[finalNum++] = 12;          
        break;     
    }

    case '+':{
        strcpy(otherCharTable[otherCharNum++], "+");
        strcpy(finalTable[finalNum], "+");
        finalTableInt[finalNum++] = 13;          
        break;     
    }

    case '-':{
        strcpy(otherCharTable[otherCharNum++], "-");
        strcpy(finalTable[finalNum], "-");
        finalTableInt[finalNum++] = 19;          
        break;     
    }

    case '>':{
        ch = getchar();
        if(ch == '='){
            strcpy(otherCharTable[otherCharNum++], ">=");
            strcpy(finalTable[finalNum], ">=");
            finalTableInt[finalNum++] = 14;  
        }
        else{
            strcpy(otherCharTable[otherCharNum++], ">");
            strcpy(finalTable[finalNum], ">");
            finalTableInt[finalNum++] = 15; 
            ungetc(ch, stdin); 
        }
        break;
    }

    case '<':{
        ch = getchar();
        if(ch == '='){
            strcpy(otherCharTable[otherCharNum++], "<=");
            strcpy(finalTable[finalNum], "<=");
            finalTableInt[finalNum++] = 16;  
        }
        else{
            strcpy(otherCharTable[otherCharNum++], "<");
            strcpy(finalTable[finalNum], "<");
            finalTableInt[finalNum++] = 17; 
            ungetc(ch, stdin); 
        }
        break;
    }

    case '*':{
        /*这里为啥少一句？？？？？*/
        strcpy(finalTable[finalNum], "*");
        finalTableInt[finalNum++] = 18;
        break;
    }

    default:{
        error();
        break;
    }
    }
}

void error(){
    flagError = 1;
    printf("出现错误，中止分析！\n");
}

void print(){
    int i;
    finalTableInt[finalNum] = '\0';
    printf("词法分析结果如下：\n");
    for(int i = 0; i < finalNum; i++)
        printf("%s", finalTable[i]);
    finalNum = 0;

    printf("\n语法分析过程如下：\n");
}
void program(){
    printf("program-->block\n");
    block();
    if(flagError == 1){
        error();
        return;
    }
}

void block(){
    if(flagError == 1){
        return;
    }
    printf("block-->{stmts}\n");
    match("{");
    stmts();
    match("}");
}

void stmts(){
    if(flagError == 1){
        return;
    }
    //右括号
    if(finalTableInt[finalNum] == 10){
        printf("stmts-->null\n");
        return;
    }
    printf("stmts-->stmt stmts\n");
    stmt();
    stmts();
}

void stmt(){
    if(flagError == 1){
        return;
    }
    switch(finalTableInt[finalNum]){
    //标识符
    case 1:
        printf("stmt-->id = expr;\n");
        match("id");
        match("=");
        expr();
        match(";");
        break;
    //if
    case 100:
        match("if");
        match("(");
        myBool();
        match(")");
        stmt();
        if(strcmp(finalTable[finalNum], "else") == 0){
            printf("stmt-->if(bool) stmt else stmt\n");
            match("else");
            stmt();
            break;
        }
        else{
            printf("stmt-->{if(bool) stmt\n");
            break;
        }
    //while
    case 400:
        printf("stmt-->while(bool) stmt\n");
        match("while");
        match("(");
        myBool();
        match(")");
        stmt();
        break;
    //do
    case 500:
        printf("stmt-->do stmt while(bool)\n");
        match("do");
        stmt();
        match("while");
        match("(");
        myBool();
        match(")");
        break;
    //break
    case 800:
        printf("stmt->break\n");
        match("break");
        break;
    default:
        printf("stmt-->block\n");
        block();
        break;
    }      
}

void myBool(){
    if(flagError == 1)
        return;
    expr();
    switch(finalTableInt[finalNum]){
    //<
    case 17:
        printf("bool-->expr<expr\n");
        match("<");
        expr();
        break;
    //<=
    case 16:
        printf("bool-->expr <= expr\n");
        match("<=");
        expr();
        break;
    // >
    case 15:
        printf("bool-->expr>expr\n");
        match(">");
        expr();
        break;
    // >=
    case 14:
        printf("bool-->expr>=expr\n");
        match(">=");
        expr();
        break;
    default:
        printf("bool-->expr\n");
        expr();
        break;
    }
}

void expr(){
    if(flagError == 1)
        return;
    
    printf("expr-->term expr1\n");
    term();
    expr1();
}

void expr1(){
    if(flagError == 1)
        return;
    switch (finalTableInt[finalNum]){
    //+
    case 13:
        printf("expr1-->+ term expr1\n");
        match("+");
        term();
        expr1();
        break;
    //-
    case 19:
        printf("expr1-->- term expr1\n");
        match("-");
        term();
        expr1();
        break;
    default:
        printf("expr1-->null\n");
        break;
    }
}

void term(){
    if(flagError == 1) 
        return;
    printf("term-->factor term1\n");
    factor();
    term1();
}

void term1(){
    if(flagError == 1)
        return;
    switch(finalTableInt[finalNum]){
    //*
    case 18:
        printf("term1-->* factor term1\n");
        match("*");
        factor();
        term1();
        break;
    // /
    case 2:
        printf("term1--> /factor term1\n");
        match("/");
        factor();
        term1();
        break;
    default:
        printf("term1--> null\n");
        break;
    }
}

void factor(){
    if(flagError == 1)
        return;
    switch (finalTableInt[finalNum])
    {
    // (
    case 6:
        printf("factor--> (expr)\n");
        match("(");
        expr();
        match(")");
        break;
    // id
    case 1:
        printf("factor-->id\n");
        match("id");
        break;
    //num
    case 99:
        printf("factor-->num\n");
        match("num");
        break;
    default:
        flagError = 1;
        break;
    }
}

void match(char* t){
    if(strcmp(finalTable[finalNum], t) == 0){
        ;
    }
    else{
        flagError = 1;
        return;
    }
    finalNum++;
}