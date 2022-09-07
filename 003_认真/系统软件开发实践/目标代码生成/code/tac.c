#include "parser.h"
#include <string.h>

extern int root;
extern Node*   node;
extern char * node_name[140];
extern struct Symbol*  symbol;

char *op_string(int op);
static void start_tac(int n);
static char *deal_expk(int n);   //处理算术表达式
static void MAIN_K(int n);       //处理main
static void DEFINEPARA_K(int n); //处理定义结点
static void ASSIGN_K(int n);     //处理赋值结点
static fourvarcode* get_tac(int op,char a[],char b[],char c[]);  //产生四元式
static char * newtemp();    //申请临时寄存器
fourvarcode *tac_temp;      //四元式链表的一个变量指针
fourvarcode *tac_head;      //四元式链表头指针

static void EXP_K(int n);
static void IF_K(int n);
static void WHILE_K(int n);
static char* GO_EXP_TAC(int op, int n);

int line = 100;	//行号
int labelNum = 1; //标签号

/**
 * 记录当前四元式中的临时变量的标号
 * 
 * 如t#0, t#1, t#2等
*/
static int newtemp_no=0;

static char adr[10]= {'\0'};
static char empty[10]= "\0";
void print_tac();

void  tac()
{
    tac_head=(fourvarcode*)malloc(sizeof(fourvarcode));
    tac_temp=tac_head;
    start_tac(root);
	print_tac("./output/tac_before_optimization.txt");
	start_optimize(tac_head);
	print_tac("./output/tac_after_optimization.txt");
	start_asm(tac_head);
	printf("\nOK_11\n");
}

void start_tac(int n)
{
	/**
	 * 匹配到某一已知节点，则去处理它以及其兄弟节点（广度优先）
	 * 否则
	 * 对其孩子节点递归处理（深度优先）
	 * 太 妙 了
	*/
    while(n!=0)
    {
		char *start=node_name[node[n].id];  //取出结点name
		printf("now parser node: %s\n", start);
        if(strcmp(start,"funcdecl_")==0)    //main方法体
        {
            MAIN_K(n);
			break;
        }
        if(strcmp(start,"declarations_")==0)  //变量定义
        {
            DEFINEPARA_K(n);

			/**
			 * 这里会使n的类型从declarations_变为statements_
			 * 
			 * 其实也不一定，如果声明后并没有紧跟着赋值语句，则会由于不识别而跳过
			*/
			n = node[n].next;    //下一个兄弟结点
			continue;
        }
        if(strcmp(start,"statements_")==0)  //算术表达式
        {
            ASSIGN_K(n);
			n = node[n].next;  //下一个兄弟结点
			continue;
        }
		if(strcmp(start, "block_") == 0){
			start_tac(node[n].child);
			break;
		}

		/**
		 * 由于只做了部分节点，因此当处理到不识别的节点时，跳过它
		 * 
		 * 直接进入其子节点的处理 
		 * 
		 * BFS
		*/ 
		n = node[n].child;  //下一个子结点
    }
}

//处理main结点
void MAIN_K(int n)
{
    char a[10];
    a[0]='0';
    a[1]='\0';
    get_tac(6,adr,adr,adr);   //main函数开始
    start_tac(node[n].next);  //递归的处理main节点的兄弟节点，其实就是funcbody_
    get_tac(7,adr,adr,adr);   //main函数结束
}

//处理变量定义结点
void DEFINEPARA_K(int n)
{
	/**
	 * 最终这里存储的变量类型
	*/
	char a[10];
	/**
	 * 最终这里存储了变量名
	*/
	char b[10]; 


	n = node[n].child;//decl_init_
	while(n!=0)
	{
		int i=node[n].child;//decl_spec_
		char *d1=node_name[node[node[i].child].id];//type
		strcpy(a,d1);
		i=node[i].next; //init_declarators_
		i=node[i].child; //declarator_
		while(i!=0)
		{
			int j=node[i].child;//direct_decl_
			j=node[j].child; //ident
			j=node[j].child; //name
			int sti = node[j].sti;
			char* d2= symbol[sti].name;
			strcpy(b,d2);
			get_tac(8,a,b,adr);  //生成变量定义四元式

			/**
			 * 这行语句用于处理int a, b; 这种类型的定义。
			 * 
			 * 如果是int a; 那么到这里i = 0从而结束掉循环。
			*/
			i=node[i].next;//next declarator_
		}
		n=node[n].next;//next decl_init_
	}
}

//处理赋值结点
void ASSIGN_K(int n)
{
	char t1[10],t2[10];
	n = node[n].child;
	while(n!=0)
	{
		char* currentNode = node_name[node[n].id];  //取出结点name

		if(strcmp(currentNode, "exp_")==0)
			EXP_K(n);
		else if(strcmp(currentNode, "if_") == 0)
			IF_K(n);
		else if(strcmp(currentNode, "while_") == 0)
			WHILE_K(n);

		n = node[n].next;
	}
}

/**
 * 处理AST中的exp_节点
 * 学姐原来的ASSIGN_K是用来处理statements_的全部子结点的，
 * 默认了全部子节点均为exp_类型。
 * 事实上，还可能是if_类型
 * 
 * 因此这里将原ASSIGN_K的主体抽取出来，形成处理exp_节点的新方法。
*/
void EXP_K(int n){
	char t1[10],t2[10];
	strcpy(t1, newtemp());
	int i=node[n].child;//assignment_
	i=node[i].child;//equals_
	i=node[i].child;//IDENT_

	/**
	 * 这里，node[i].next类型为div_
	 * 
	 * 用于处理使用表达式对变量赋值的语句
	 * 
	 * 例如 a = 1 + 2;
	*/
	strcpy(t2,deal_expk(node[i].next));
	get_tac(EQUAL ,t2 ,t1, adr);
	int sti = node[i].sti;
	char* q= symbol[sti].name;
	get_tac(EQUAL ,t1 ,q, adr);
}

/**
 * IF下通常有两个子结点——assignment_、block_(empty_stmt_)
*/
void IF_K(int n){
	char t1[10],t2[10];

	//处理assignment_
	n = node[n].child; //assignment_
	int i = node[n].child; 		// gt_
	strcpy(t1, deal_expk(i));
	fourvarcode* f =  get_tac(IF_IF, t1, adr, adr);
	
	//处理bolck_
	n = node[n].next;	//bolck_
	start_tac(n);
	//每一个块结束意味着前面有一个条件语句。
	//此处为条件语句的False出口
	char thisLabel[8];
	sprintf(thisLabel, "label%d", labelNum++);
	get_tac(LABEL, thisLabel, adr, adr);


	//sprintf(f->addr2.name, "%d", f->line + 1);
	sprintf(f->addr3.name, "%s", thisLabel);
}

void WHILE_K(int n){
	char t1[10],t2[10];

	char labelBegin[8], labelEnd[8];
	sprintf(labelBegin, "label%d", labelNum++);
	sprintf(labelEnd, "label%d", labelNum++);
	//先做一个标签，当循环体结束后无条件跳转
	get_tac(LABEL, labelBegin, adr, adr);
	//处理assignment_
	n = node[n].child; //assignment_
	int i = node[n].child; 		// gt_
	strcpy(t1, deal_expk(i));
	//用来存储(if, _, _, _)的行号，方便while结束后返回。
	fourvarcode* f =  get_tac(IF_IF, t1, adr, adr);
	
	//处理bolck_
	n = node[n].next;	//bolck_
	start_tac(n);


	//sprintf(f->addr2.name, "%d", f->line + 1);
	sprintf(f->addr3.name, "%s", labelEnd);

	get_tac(JMP, labelBegin, adr, adr);	
	get_tac(LABEL, labelEnd, adr, adr);
}

/**
 * 
 * 建立一个四元式，后移四元式链表指针
 * 
 * 存在大量冗余代码，可以重构
 * 
*/
fourvarcode* get_tac(int op,char a[],char b[],char c[])
{
    fourvarcode* t=NULL;
    t=(fourvarcode*)malloc(sizeof(fourvarcode));
    t->op=op;
	t->line = line++;

    if(a[0]=='\0')
    {
		strcpy(t->addr1.kind,"emptys");
        strcpy(t->addr1.name,"\0");
    }
    else if((a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z'))
    {
        strcpy(t->addr2.kind,"strings");
        strcpy(t->addr1.name,a);
    }
    else
    {
        strcpy(t->addr2.kind,"consts");
        strcpy(t->addr1.name,a);
    }


    if(b[0]=='\0')
    {
		strcpy(t->addr2.kind,"emptys");
        strcpy(t->addr2.name,"\0");
    }
    else if((b[0]>='a'&&b[0]<='z')||(b[0]>='A'&&b[0]<='Z'))
    {
        strcpy(t->addr2.kind,"strings");
        strcpy(t->addr2.name,b);
    }
    else
    {
		strcpy(t->addr2.kind,"consts");
        strcpy(t->addr2.name,b);
    }


    if(c[0]=='\0')
    {
        strcpy(t->addr3.kind,"emptys");
        strcpy(t->addr3.name,"\0");
    }
    else if((c[0]>='a'&&c[0]<='z')||(c[0]>='A'&&c[0]<='Z'))
    {
        strcpy(t->addr3.kind,"strings");
        strcpy(t->addr3.name,c);
    }
    else
    {
        strcpy(t->addr3.kind,"consts");
        strcpy(t->addr3.name,c);
    }

    t->next=NULL;
    tac_temp->next=t;
    tac_temp=t;
	return t;
}

char *newtemp()
{
    static char s[10];
    sprintf(s,"t#%d",newtemp_no);
    newtemp_no++;
    return s;
}

/**
 * node[n]为div_
*/ 
char* deal_expk(int n) //处理expk式子
{
	char empty[10];
    empty[0]='\0';
	char *e=node_name[node[n].id];

	char t1[10], t2[10];
	static char t3[10];
	static char temp[10];

	
    if(strcmp(e,"IDENT_")==0)
	{
		int sti = node[n].sti;
		char* e1= symbol[sti].name;
		strcpy(temp, newtemp());
		get_tac(EQUAL, e1, temp, adr);
		return temp;
	}
	else if(strcmp(e,"CONST_")==0)
	{
		int sti = node[n].sti;
		char* e1= symbol[sti].name;
		return e1;
	}
	else if(strcmp(e,"add_")==0)
	{
		int i=node[n].child;
		int j=node[i].next;
		/**
		 * 记录一下，这里这个静态变量的小bug真难找......
		*/
		strcpy(temp,deal_expk(i));
		strcpy(t1, temp);
		strcpy(temp,deal_expk(j));
		strcpy(t2, temp);
		strcpy(temp,newtemp());
		strcpy(t3, temp);
        get_tac(ADD, t1, t2, t3);
        return t3;
	}
	else if(strcmp(e,"sub_")==0)
	{
		int i=node[n].child;
		int j=node[i].next;
		char temp1[10], temp2[10], temp3[10];
		strcpy(temp,deal_expk(i));
		strcpy(t1, temp);
		strcpy(temp,deal_expk(j));
		strcpy(t2, temp);
		strcpy(temp,newtemp());
		strcpy(t3, temp);
        get_tac(4,t1,t2,t3);
        return t3;
	}
	else if(strcmp(e,"mul_")==0)
	{
		int i=node[n].child;
		int j=node[i].next;
		strcpy(temp,deal_expk(i));
		strcpy(t1, temp);
		strcpy(temp,deal_expk(j));
		strcpy(t2, temp);
		strcpy(temp,newtemp());
		strcpy(t3, temp);
        get_tac(2,t1,t2,t3);
        return t3;
	}
	else if(strcmp(e,"div_")==0)
	{
		/**
		 * 某个运算符吧 mul_ 
		*/ 
		int i=node[n].child;
		/**
		 * 运算符后的值CONST_(num)
		*/ 
		int j=node[i].next;
		strcpy(temp,deal_expk(i));
		strcpy(t1, temp);
		strcpy(temp,deal_expk(j));
		strcpy(t2, temp);
		strcpy(temp,newtemp());
		strcpy(t3, temp);
        get_tac(5,t1,t2,t3);
        return t3;
	}
	else if(strcmp(e,"exp_")==0)
	{
		/**
		 * 似乎所有的exp_都有子节点assignment_
		 * assignment_的子节点才是真正有运算意义的节点
		*/
		n=node[n].child;//assignment_
		n=node[n].child; 

		/**
		 * 学姐忘记写返回语句了，因此处理exp_时返回的是"error at dealing expk!"
		 * 
		 * 所以报告中的截图才会有错误
		*/
		return deal_expk(n);
	}
	else if(strcmp(e, "ge_") == 0){
		return GO_EXP_TAC(GREATER_EQUAL, n);
	}
	else if(strcmp(e, "le_") == 0){
		return GO_EXP_TAC(LESS_EQUAL, n);
	}
	else if(strcmp(e, "gt_") == 0){
		return GO_EXP_TAC(GREATER_THAN, n);
	}
	else if(strcmp(e, "lt_") == 0){
		return GO_EXP_TAC(LESS_THAN, n);
	}
	printf("%s\t", e);
	return "error at dealing expk!";
}

char* GO_EXP_TAC(int op, int n){
	static char t1[10], t2[10], t3[10];
	static char temp[10];
	int i=node[n].child;
	int j=node[i].next;
	printf("%s %s\n\n", node_name[node[i].id], node_name[node[j].id]);

	strcpy(temp,deal_expk(i));
	strcpy(t1, temp);
	strcpy(temp,deal_expk(j));
	strcpy(t2, temp);
	strcpy(temp,newtemp());
	strcpy(t3, temp);
	get_tac(op, t1, t2, t3);
	return t3;
}

/*void print_tac()
{
	fourvarcode* t=tac_head->next;
	while(t!=NULL)
	{
	    printf("(");
		printf("%s ,",op_string(t->op));
		if(t->addr1.kind=="emptys")
			printf("_ ,");
		else
			printf("%s ,",t->addr1.name);

		if(t->addr2.kind=="emptys")
			printf("_ ,");
		else
			printf("%s ,",t->addr2.name);

		if(t->addr3.kind=="emptys")
			printf("_ ,");
		else
			printf("%s ,",t->addr3.name);

		t=t->next;
		printf(")");
		printf("\n");
	}
}*/

void print_tac(char* file_name)
{
	char s[10] = { 0 };
	//int line = 100;
	FILE* fp = fopen(file_name, "w");
	fourvarcode* t = tac_head->next;
	while (t != NULL)
	{
		sprintf(s, "%d ", t->line);
		fprintf(fp, s);
		//line++;
		fprintf(fp, "(");
		fprintf(fp, op_string(t->op));
		fprintf(fp, " , ");
		// 处理addr1

		/**
		 * 要这样改，才会正确判断是不是与"\0"相等。
		 * if (t->addr1.name == "\0")
		 * 			↓
		 * if (strcmp(t->addr1.name, "\0") == 0)
		*/
		//if (t->addr1.name == "\0")
		if (strcmp(t->addr1.name, "\0") == 0)
			fprintf(fp, "_ , ");
		else {
			fprintf(fp, t->addr1.name);
			fprintf(fp, " , ");
		}
		// 处理addr2
		// if (t->addr2.name == "\0")
		if (strcmp(t->addr2.name, "\0") == 0)
			fprintf(fp, "_ , ");
		else {
			fprintf(fp, t->addr2.name);
			fprintf(fp, " , ");
		}
		// 处理addr3
		// if (t->addr1.name == "\0")
		if (strcmp(t->addr3.name, "\0") == 0)
			fprintf(fp, "_ , ");
		else {
			fprintf(fp, t->addr3.name);
		}
		t = t->next;
		fprintf(fp, ")");
		fprintf(fp, "\n");
	}
	fclose(fp);
}

/**
 * 	将四元式链表中的op转换成对应的符号
*/
char *op_string(int op)
{
    switch (op)
    {
    case (1):
        return "=";
    case (2):
        return "*";
    case (3):
        return "+";
    case (4):
        return "-";
	case (5):
        return "/";
    case (6):
        return "main";
    case(7):
        return "main_end";
    case(8):
        return "define_variable";
	case(LESS_THAN):
		return "<";
	case(GREATER_THAN):
		return ">";
	case(LESS_EQUAL):
		return "<=";
	case(GREATER_EQUAL):
		return ">=";
	case(IF_IF):
		return "if";
	case(JMP):
		return "jmp";
	case(LABEL):
		return "label";
    default:
        printf("匹配有误");
		return 0;
    }
}



/**
 * 以下为自己新增加的方法
*/


/**
 * 遍历四元式链表，打印每一个节点类型
*/

