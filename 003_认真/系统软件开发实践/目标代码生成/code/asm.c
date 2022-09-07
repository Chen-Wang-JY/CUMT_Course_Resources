#include "parser.h"
#include "stdio.h"
#include "stdlib.h"

void flocal_table(char type[],char name[],char num[],int n);
static void build_asm(fourvarcode* t);
static void build_define(fourvarcode* t);
static void build_assign(fourvarcode* t);
static void build_return(fourvarcode* t);

static void build_mainfuns(fourvarcode* t);
static void build_mainfuns_end(fourvarcode* t); 
static void build_jmp(fourvarcode* t);

/**
 * 学姐丢了几个方法的声明
*/
static char *registerGet();
int searchlocal(char a[20]);


/**
 * 向fp指向的文件写入，并打印
*/
static void doPrint(char* text);
static void doPrintWithOneTab(char* text);
static void doPrintWithNoEndl(char* text);

/**
 * 初始化全局变量
*/
static void initGlobalVariable();
/**
 * 写入通用的前部语句
*/
static void writeHeadStatement();   

/**
 * 遍历所有的声明语句，将每一个声明的变量添加到符号表链表尾部
 * 
 * 同时更新全局变量num的值
*/
static void initSymbolTable(fourvarcode* tac_head);

/**
 * 写入ALLOC标签下的内容
*/
static void writeAllocStatement();

/**
 * 从main遍历至main_end，产生目标代码
*/
static void writeMainStatement(fourvarcode* tac_head);

/**
 * 取出对应的值，如果是临时变量，则释放响应寄存器
 * 同时将变量位于内存中地址通过loc返回
*/
static void getVal(addr* p, char* reg, int* isTemp);
static void getVal_MULorDIV_Version(addr* p, char* reg, int* isTempAL, int* isTEmpAH, int flag);

/**
 * 得到一个待赋值的对象，通过reg返回
 * 如果reg返回的是
*/
static void get_copy_object(addr* p, char* reg);

static void build_if(fourvarcode* t);
static void build_label(fourvarcode* t);
static int labelNum = 1;
static void build_greater_than(fourvarcode* t);
static void build_greater_equal(fourvarcode* t);
static void build_less_than(fourvarcode* t);
static void build_less_equal(fourvarcode* t);

static void build_muls(fourvarcode* t); 
static void build_divs(fourvarcode* t);  
static void build_adds(fourvarcode* t);
static void build_minu(fourvarcode* t);

static void push_AX_reg();
static void pop_AX_reg();




void fglocal_table(char type[],char name[],char num[],int n);
fourvarcode* ltag;
char empty[]="\0";
int AX_FLAG=0,BX_FLAG=0,CX_FLAG=0,DX_FLAG=0,SI_FLAG=0;///通用寄存器
char assign_table[20][20];
char temp_val_table[20][20];
int num=0;

int AL_FLAG = 0, AH_FLAG = 0;
int BL_FLAG = 0, BH_FLAG = 0;
int CL_FLAG = 0, CH_FLAG = 0;
int DL_FLAG = 0, DH_FLAG = 0;

int AL_TEMP = 0, AH_TMEP = 0;


symboltable *local_table;
symboltable *lsptempg,*lsptempl;///用于构造符号表的临时变量

int stackn=0;
char function_table[20][20]; ///函数名
int function_num = 0; ///函数个数
FILE *fp;

/**
 * 8086的汇编程序开头、结尾是固定的。
 * 其中，开头部分没有label标记，在start_asm中产生。
 * 结尾部分使用over标记，over及其之后的部分在start_asm中产生。
 * 
 * 其余部分可以分为两部分————main、alloc
*/
void start_asm(fourvarcode* tac_head)
{
    //初始化全局变量
    initGlobalVariable();
    //初始化符号表
    initSymbolTable(tac_head);
    //写入头部固定的目标代码
    writeHeadStatement();
    //写入内存分配的目标代码
    writeAllocStatement();
    //写入主函数的目标代码
    writeMainStatement(tac_head);
    //写入最后的目标代码
    doPrint("");
    doPrint("CODE ENDS");
    doPrint("END START");
    fclose(fp);
}

/**
 * 查询当前变量名是否在局部变量表中
*/
int searchlocal(char a[20])
{
    symboltable *t=local_table->next;
 
    while(t!=NULL)
    {
        if(strcmp(t->name,a)==0)
        {
            return t->location;
            break;
        }
        t=t->next;
    }
    return -1;
}

/***********************************************************
* 功能:用于申请寄存器 为0则可以用
**********************************************************/
char *registerGet()
{
    if(AL_FLAG == 0){
        AL_FLAG = 1;
        return "AL";
    } else if(AH_FLAG == 0){
        AH_FLAG = 1;
        return "AH";
    } else if(BL_FLAG == 0){
        BL_FLAG = 1;
        return "BL";
    } else if(BH_FLAG == 0){
        BH_FLAG = 1;
        return "BH";
    } else if(CL_FLAG == 0){
        CL_FLAG = 1;
        return "CL";
    } else if(CH_FLAG == 0){
        CH_FLAG = 1;
        return "CH";
    } else if(DL_FLAG == 0){
        DL_FLAG = 1;
        return "DL";
    } else if(DH_FLAG == 0){
        DH_FLAG = 1;
        return "DH";
    }
    return "-1";
}
/***********************************************************
* 功能:释放寄存器
**********************************************************/
void registerFree(char b[10])
{
    // if(strcmp(b,"AX")==0||strcmp(b,"EAX")==0)
    // {
    //     AX_FLAG=0;
    // }
    // else if(strcmp(b,"BX")==0||strcmp(b,"EBX")==0)
    // {
    //     BX_FLAG=0;
    // }
    // else if(strcmp(b,"CX")==0||strcmp(b,"ECX")==0)
    // {
    //     CX_FLAG=0;
    // }
    // else if(strcmp(b, "DX") == 0){
    //     DX_FLAG = 0;
    // }
    if(strcmp(b, "AL") == 0)
        AL_FLAG = 0;
    else if(strcmp(b, "AH") == 0)
        AH_FLAG = 0;
    else if(strcmp(b, "BL") == 0)
        BL_FLAG = 0;
    else if(strcmp(b, "BH") == 0)
        BH_FLAG = 0;
    else if(strcmp(b, "CL") == 0)
        CL_FLAG = 0;
    else if(strcmp(b, "CH") == 0)
        CH_FLAG = 0;
    else if(strcmp(b, "DL") == 0)
        DL_FLAG = 0;
    else if(strcmp(b, "DH") == 0)
        DH_FLAG = 0;
}

/***********************************************************
* 功能:开始根据op来生成汇编代码
**********************************************************/
void build_asm(fourvarcode* t)
{
    if(t->op == DEFINE_VARIABLE)
    {
        build_define(t);
        return;
    }
    else if(t->op == EQUAL)
    {
        build_assign(t);
        return ;
    }
    else if(t->op == SUB)
    {
        build_minu(t);
        return ;
    }
    else if(t->op == DIV)
    {
        build_divs(t);
        return ;
    }
    else if(t->op == ADD)
    {
        build_adds(t);
        return ;
    }   
    else if(t->op == MUL)
    {
        build_muls(t);
        return ;
    }
    else if(t->op == MAIN)
    {
        build_mainfuns(t);
        return ;
    }
    else if(t->op == MAIN_END)
    {
        build_mainfuns_end(t);
        return ;
    }
    else if(t->op == IF_IF){
        build_if(t);
        return ;
    }
    else if(t->op == LABEL){
        build_label(t);
        return ;
    }
    else if(t->op == GREATER_THAN){
        build_greater_than(t);
        return ;
    }
    else if(t->op == GREATER_EQUAL){
        build_greater_equal(t);
        return ;
    }
    else if(t->op == LESS_THAN){
        build_less_than(t);
        return ;
    }
    else if(t->op == LESS_EQUAL){
        build_less_equal(t);
        return ;
    }
    else if(t->op == JMP){
        build_jmp(t);
        return ;
    }
}

/**
 * 创建符号表链表的一个新节点
*/
void flocal_table(char type[],char name[],char num[],int n)
{
    symboltable *t;
    t = (symboltable *)malloc(sizeof(symboltable));
    t->next = NULL;
    strcpy(t->type, type);
    strcpy(t->name, name);
    t->location=n;
    lsptempl->next=t;
    lsptempl=t;

    strcpy(assign_table[n], "0");
}



/***********************************************************
* 以下是将各种不同的四元式生成目标代码的方法。
**********************************************************/
void build_mainfuns(fourvarcode* t)
{
    return;
}

void build_mainfuns_end(fourvarcode* t)
{
    return;
}

void build_define(fourvarcode* t)  ///跟符号表有关了！！
{
    flocal_table(t->addr1.name,t->addr2.name,t->addr3.name,num+1);
    if(strcmp(t->addr3.name,empty)==0)////这一定不是数组定义了
    {
        num++;
    }
}

/**
 * 赋值语句的四元式处理方法
*/
void build_assign(fourvarcode* t)
{
    char b[20], a1[20], a2[20];  ///a1 a2分别用来存储 赋值四元式的 值和变量名
    strcpy(a1, t->addr1.name);
    strcpy(a2, t->addr2.name);

    /**
     * 将数值赋值给变量
    */
    if (a1[0] >= '0' && a1[0] <= '9')///数字赋给局部变量或者中间变量
    {
        /**
         * 赋值给a b c等局部变量
        **/
        if (((a2[0] >= 'a' && a2[0] <= 'z') || (a2[0] >= 'A' && a2[0] <= 'Z')) && a2[1] != '#')///局部变量 形如这样的四元式= ,1,a,___
        {
            //变量一定存在于符号链表中
            int location = searchlocal(t->addr2.name);
            //更新assign_table值
            strcpy(assign_table[location], t->addr1.name);
            //产生语句：
            //MOV AX, num
            //MOV [location], AX
            char curRegister[8], text[64];
            sprintf(curRegister, "%s", registerGet());
            sprintf(text, "MOV %s, %s", curRegister, assign_table[location]);
            doPrintWithOneTab(text);
            sprintf(text, "MOV [%d], %s", location, curRegister);
            doPrintWithOneTab(text);
            registerFree(curRegister);
        } 
        /**
         * 数字赋值给t#n等中间变量，这里申请的寄存器不能释放
        */
        else {  ///if(a2[1]=='#'形如 =，1，t#1
            char curRegister[8], text[64];
            sprintf(curRegister, "%s", registerGet());
            int location = t->addr2.name[2] - '0';  //t#n
            sprintf(temp_val_table[location], "%s", curRegister);
            
            //MOV AX, num
            sprintf(text, "MOV %s, %s", curRegister, t->addr1.name);
            doPrintWithOneTab(text);
        }
    }
    /**
     * 将变量赋值给变量
    */
    else if (((a1[0] >= 'a' && a1[0] <= 'z') || (a1[0] >= 'A' && a1[0] <= 'Z')) && a1[1] != '#')  ///形如这样的四元式 =,a,t#1,___ 主要翻译if while for (a<b)
    {
        int isTemp = 0;
        char reg_1[8], text[64];
        getVal(&(t->addr1), reg_1, &isTemp);

        int location = searchlocal(t->addr2.name);
        if(location != -1){
            // reg_1 赋值给 变量
            sprintf(text, "MOV [%d], %s", location, reg_1);
            doPrintWithOneTab(text);
            registerFree(reg_1);
        } else {
            // reg_1 赋值给 t#n
            location = t->addr2.name[2] - '0';
            
            char reg_2[8];
            sprintf(reg_2, "%s", registerGet());
            sprintf(temp_val_table[location], "%s", reg_2);

            sprintf(text, "MOV %s, %s", reg_2, reg_1);
            doPrintWithOneTab(text);

            registerFree(reg_1);
        }
    }
}

/**
 * 
*/
void build_adds(fourvarcode* t)
{
    int isTemp1 = 0, isTemp2 = 0;
    char reg_1[64], reg_2[64];
    int location1, location2;
    getVal(&(t->addr1), reg_1, &isTemp1);
    getVal(&(t->addr2), reg_2, &isTemp2);

    //相加后， 赋值给变量
    char reg[8];
    get_copy_object(&(t->addr3), reg);
    //int location = searchlocal(t->addr3.name);
    char text[64];
    //写入
    sprintf(text, "ADD %s, %s", reg_1, reg_2);
    doPrintWithOneTab(text);
    sprintf(text, "MOV %s, %s", reg, reg_1);
    doPrintWithOneTab(text);

    registerFree(reg_1);
    registerFree(reg_2);
}
 
/**
 * (-, 1, 2, t#n)
*/
void build_minu(fourvarcode* t)
{
    int isTemp1 = 0, isTemp2 = 0;
    char reg_1[64], reg_2[64];
    int location1, location2;
    getVal(&(t->addr1), reg_1, &isTemp1);
    getVal(&(t->addr2), reg_2, &isTemp2);

    //相加后， 赋值给变量
    char reg[8];
    get_copy_object(&(t->addr3), reg);
    //int location = searchlocal(t->addr3.name);
    char text[64];
    //写入
    sprintf(text, "SUB %s, %s", reg_1, reg_2);
    doPrintWithOneTab(text);
    sprintf(text, "MOV %s, %s", reg, reg_1);
    doPrintWithOneTab(text);

    registerFree(reg_1);
    registerFree(reg_2);
}

void build_muls (fourvarcode* t)
{
    int isTemp1 = 0, isTemp2 = 0;
    char reg_1[64], reg_2[64];
    int location1, location2;

    //暂存AX及其相关状态
    push_AX_reg();

    //可以保证不会分配到AH AL
    AH_FLAG = 1;
    AL_FLAG = 1;
    getVal(&(t->addr1), reg_1, &isTemp1);
    getVal(&(t->addr2), reg_2, &isTemp2);

    char text[64];

    char reg[8];
    get_copy_object(&(t->addr3), reg);      
    //写入
    sprintf(text, "MOV AL, %s", reg_1);
    doPrintWithOneTab(text);
    sprintf(text, "MOV AH, %s", reg_2);
    doPrintWithOneTab(text);

    sprintf(text, "MUL AH");
    doPrintWithOneTab(text);
    sprintf(text, "MOV %s, AL", reg);
    doPrintWithOneTab(text);


    //回复AX寄存器及其相关状态
    pop_AX_reg();
    registerFree(reg_1);
    registerFree(reg_2);
}
void getVal_MULorDIV_Version_1(addr* p, char* reg, int* isTempAL, int* isTempAH, int flag){

}

void push_AX_reg(){
    AH_TMEP = AH_FLAG;
    AL_TEMP = AL_FLAG;
    doPrintWithOneTab("PUSH AX");
}

void pop_AX_reg(){
    AH_FLAG = AH_TMEP;
    AL_FLAG = AL_TEMP;
    doPrintWithOneTab("POP AX");
}

 
void build_divs(fourvarcode* t)
{
    char text[64];
    int isTemp1 = 0, isTemp2 = 0;
    char reg_1[64], reg_2[64];
    int location1, location2;

    //暂存AX及其相关状态
    push_AX_reg();


    AH_FLAG = 1;
    AL_FLAG = 1;
    getVal(&(t->addr1), reg_1, &isTemp1);
    // reg_2一定不在AX中
    getVal(&(t->addr2), reg_2, &isTemp2);


    char reg[8];

    get_copy_object(&(t->addr3), reg);      //可以保证不会分配到AX
    //写入
    sprintf(text, "MOV AL, %s", reg_1);
    doPrintWithOneTab(text);
    sprintf(text, "MOV AH, 0");
    doPrintWithOneTab(text);

    sprintf(text, "DIV %s", reg_2);
    doPrintWithOneTab(text);
    sprintf(text, "MOV %s, AL", reg);
    doPrintWithOneTab(text);

    //回复AX寄存器及其相关状态
    pop_AX_reg();
    registerFree(reg_1);


    // int isTemp1 = 0, isTemp2 = 0;
    // char reg_1[64], reg_2[64];
    // int location1, location2;

    // //这里保证reg_1为AL，因此可以确保调用getVal获取第二个值不会分配到AL寄存器
    // int isTempAL = 0, isTempAH = 0;
    // getVal_MULorDIV_Version(&(t->addr1), reg_1, &isTempAL, &isTempAH, 1);
    // getVal(&(t->addr2), reg_2, &isTemp2);

    // //相加后， 赋值给变量
    // char reg[8];
    // get_copy_object(&(t->addr3), reg);      //可以保证不会分配到AH AL
    // char text[64];
    // //写入
    // sprintf(text, "DIV %s", reg_2);
    // doPrintWithOneTab(text);

    // sprintf(text, "MOV %s, %s", reg, reg_1);
    // doPrintWithOneTab(text);

    // //registerFree(reg_1);
    // registerFree(reg_2);

    // if(strcmp(reg_2, "AH") == 0) isTempAH = 0;
    // if(isTempAL || isTempAH){
    //     doPrintWithOneTab("POP AX");
    // }
    // if(isTempAL) AL_FLAG = 1; else AL_FLAG = 0;
    // if(isTempAH) AH_FLAG = 1; else AH_FLAG = 0;
}


/********************************************************************
 * 自己添加的
********************************************************************/

void doPrint(char* text){
    printf("%s\n", text);
    fprintf(fp, "%s\n", text);
}
void doPrintWithOneTab(char* text){
    printf("\t%s\n", text);
    fprintf(fp, "\t%s\n", text);
}

void doPrintWithNoEndl(char* text){
    printf("%s", text);
    fprintf(fp, "%s", text);
}

void initGlobalVariable(){
    fp = fopen("./output/x86.asm","w+");
    local_table=(symboltable *)malloc(sizeof(symboltable));
    lsptempl=local_table;
    local_table->next=NULL;
}

void writeHeadStatement(){
    doPrint("DATA SEGMENT");
    doPrint("");
    doPrint("DATA ENDS");
    doPrint("");
    doPrint("CODE SEGMENT");
    doPrintWithOneTab("ASSUME CS: CODE, DS: DATA");
    doPrint("");
    doPrint("START:");
    doPrintWithOneTab("MOV AX, DATA");
    doPrintWithOneTab("MOV DS, AX");
    doPrint("");
    doPrint("ALLOC:");
}

void initSymbolTable(fourvarcode* tac_head){
    fourvarcode* p=tac_head->next;
    while(p->op != MAIN_END)
    {
        if(p->op == DEFINE_VARIABLE)
        {
            build_asm(p);
        }
        p = p->next;
    }
}

void writeAllocStatement(){
    symboltable* p = local_table->next;
    int base = 0;
    while(p != NULL){
        char* type = p->type;
        char* name = p->name;
        int location = p->location;   

        // 写入如下格式：
        // MOV AX, num
        // MOV [location], AX
        char text[64];           // 缓冲区
        sprintf(text, "MOV AL, %s", "0");       //这里暂时写入0吧，有点没搞懂为什么要设置一个ALLOC标记
        doPrintWithOneTab(text);
        sprintf(text, "MOV [%d], AL", location);
        doPrintWithOneTab(text);

        p = p->next;
    }
    doPrint("");
    doPrint("MAIN:");
}

static void writeMainStatement(fourvarcode* tac_head){
    fourvarcode* t = tac_head->next; 
    // 忽略main方法外的语句，此时t指向main四元式
    while(t->op != MAIN)
    {
        t=t->next;
    }
    // tac_main目标代码，其实没有作用
    build_asm(t);
    t = t->next;
    // main中除声明语句外的目标代码
    while (t->op != MAIN_END)
    {
        if (t->op != DEFINE_VARIABLE)
        {
            build_asm(t);
        }
        t = t->next;
    }
    // main_end的目标代码
    build_asm(t);
}

/**
 * 根据addr，取出对应的值
 * 调用后，reg寄存器中保存了取出的值，即后续想要访问得到的值，只需要通过reg即可
 *  - addr是变量：MOV reg, [location]
 *  - addr是数值：MOV reg, num
 *  - addr是临时变量：将临时变量所在的寄存器名称存入reg
 * 
 * PS：isTemp应该没有用了
*/
void getVal(addr* p, char* reg, int* isTemp){
    char text[64];

    int location = searchlocal(p->name);
    if(location != -1){
        // 变量      
        sprintf(reg, "%s", registerGet());
        sprintf(text, "MOV %s, [%d]", reg, location);
        doPrintWithOneTab(text);
    } else if(p->name[0] >= '0' && p->name[0] <= '9'){  
        // 数值
        sprintf(reg, "%s", registerGet());
        sprintf(text, "MOV %s, %s", reg, p->name);
        doPrintWithOneTab(text);
    } else {
        // 临时变量
        int tempLocation = p->name[2] - '0';
        sprintf(reg, "%s", temp_val_table[tempLocation]);
        *isTemp = 1;    //表示需要释放
    }
}

void getVal_MULorDIV_Version(addr* p, char* reg, int* isTempAL, int* isTempAH, int flag){
    char text[64];

    if(AL_FLAG == 1)
        *isTempAL = 1;
    if(AH_FLAG == 1)
        *isTempAH = 1;
    if(*isTempAH || *isTempAL)
        doPrintWithOneTab("PUSH AX");
    AL_FLAG = 1;
    AH_FLAG = 1;
    sprintf(reg, "%s", "AL");
    if(flag == 1) 
        doPrintWithOneTab("MOV AH, 0");

    int location = searchlocal(p->name);
    if(location != -1){
        // 变量      
        sprintf(text, "MOV %s, [%d]", reg, location);
        doPrintWithOneTab(text);
    } else if(p->name[0] >= '0' && p->name[0] <= '9'){  
        // 数值
        sprintf(text, "MOV %s, %s", reg, p->name);
        doPrintWithOneTab(text);
    } else {
        // 临时变量
        int tempLocation = p->name[2] - '0';
        sprintf(text, "MOV %s, %s", reg, temp_val_table[tempLocation]);
        doPrintWithOneTab(text);
        sprintf(temp_val_table[tempLocation], "%s", "AL");
    }
    
}

/**
 * 根据addr，将reg中更新即将被赋值的变量。
 * 调用后，reg将更新为：
 *  - addr是变量：[location]
 *  - addr是临时变量：临时变量分配到的寄存器名称AL等
*/
void get_copy_object(addr* p, char* reg){
    char text[64];
    int location = searchlocal(p->name);

    if(location != -1){
        //变量
        sprintf(reg, "[%d]", location);
    } else {
        //临时变量
        sprintf(reg, "%s", registerGet());
        location = p->name[2] - '0';
        sprintf(temp_val_table[location], "%s", reg);
    }
}

void ALL_REGISTER_STATE(){
    char text[64];
    sprintf(text,
        "AL: %d\nAH: %d\nBL: %d\nBH: %d\n",
        AL_FLAG,
        AH_FLAG,
        BL_FLAG,
        BH_FLAG);
    doPrint(text);
}

void build_if(fourvarcode* t){
    int isTemp = 0;
    char reg[64];
    int location;
    getVal(&(t->addr1), reg, &isTemp);

    //相加后， 赋值给变量
    //get_copy_object(&(t->addr3), reg);
    //int location = searchlocal(t->addr3.name);
    char text[64];
    //写入
    sprintf(text, "CMP %s, 0", reg);
    doPrintWithOneTab(text);
    /**
     * 这里注意，if的跳转逻辑强行设置为：
     * 如果CMP cmp_ans, 0为正，则继续执行
     * 否则跳转至label
     * 
     * 也就意味着必须在比较符号串处做特殊处理。
    */
    sprintf(text, "JNG %s", t->addr3.name);
    doPrintWithOneTab(text);
    registerFree(reg);
}

void build_label(fourvarcode* t){
    char text[64];
    sprintf(text, "%s:", t->addr1.name);
    doPrint(text);
}

void build_greater_than(fourvarcode* t){
    int isTemp1 = 0, isTemp2 = 0;
    char reg_1[64], reg_2[64];
    int location1, location2;
    getVal(&(t->addr1), reg_1, &isTemp1);
    getVal(&(t->addr2), reg_2, &isTemp2);

    char reg[8];
    get_copy_object(&(t->addr3), reg);
    //int location = searchlocal(t->addr3.name);
    char text[64];
    //写入
    sprintf(text, "SUB %s, %s", reg_1, reg_2);
    doPrintWithOneTab(text);
    sprintf(text, "MOV %s, %s", reg, reg_1);
    doPrintWithOneTab(text);

    registerFree(reg_1);
    registerFree(reg_2);
}
void build_greater_equal(fourvarcode* t){
    int isTemp1 = 0, isTemp2 = 0;
    char reg_1[64], reg_2[64];
    int location1, location2;
    getVal(&(t->addr1), reg_1, &isTemp1);
    getVal(&(t->addr2), reg_2, &isTemp2);

    char reg[8];
    get_copy_object(&(t->addr3), reg);
    //int location = searchlocal(t->addr3.name);
    char text[64];
    //写入
    sprintf(text, "SUB %s, %s", reg_1, reg_2);
    doPrintWithOneTab(text);
    sprintf(text, "MOV %s, %s", reg, reg_1);
    doPrintWithOneTab(text);
    sprintf(text, "INC %s", reg);
    doPrintWithOneTab(text);

    registerFree(reg_1);
    registerFree(reg_2);
} 

void build_less_than(fourvarcode* t){
    // a < b 等价于 b > a
    int isTemp1 = 0, isTemp2 = 0;
    char reg_1[64], reg_2[64];
    int location1, location2;
    //这里修改了，先取addr2, 再取addr1
    getVal(&(t->addr2), reg_1, &isTemp1);
    getVal(&(t->addr1), reg_2, &isTemp2);

    char reg[8];
    get_copy_object(&(t->addr3), reg);
    //int location = searchlocal(t->addr3.name);
    char text[64];
    //写入
    sprintf(text, "SUB %s, %s", reg_1, reg_2);
    doPrintWithOneTab(text);
    sprintf(text, "MOV %s, %s", reg, reg_1);
    doPrintWithOneTab(text);

    registerFree(reg_1);
    registerFree(reg_2);
}
void build_less_equal(fourvarcode* t){
    // a <= b 等价于 b >= a
    int isTemp1 = 0, isTemp2 = 0;
    char reg_1[64], reg_2[64];
    int location1, location2;
    getVal(&(t->addr2), reg_1, &isTemp1);
    getVal(&(t->addr1), reg_2, &isTemp2);

    char reg[8];
    get_copy_object(&(t->addr3), reg);
    //int location = searchlocal(t->addr3.name);
    char text[64];
    //写入
    sprintf(text, "SUB %s, %s", reg_1, reg_2);
    doPrintWithOneTab(text);
    sprintf(text, "MOV %s, %s", reg, reg_1);
    doPrintWithOneTab(text);
    sprintf(text, "INC %s", reg);
    doPrintWithOneTab(text);

    registerFree(reg_1);
    registerFree(reg_2);
}

void build_jmp(fourvarcode* t){
    char text[64];
    sprintf(text, "JMP %s", t->addr1.name);
    doPrintWithOneTab(text);
}
