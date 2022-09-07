/*
 * @Author: Chen
 * @Date: 2022-03-04 13:59:04
 * @LastEditTime: 2022-03-29 10:43:40
 * @FilePath: \codeByMyself2\parser.h
 */

#ifndef PARSER_H
#define PARSER_H

#include "main.h"

#include "nconst.h"

//#pragma once

typedef struct Symbol             
{
	char*  name;	 // Pointer to symbol name.														4		
	short  length;	 // Length  of symbol name.														2
	//short  level;	 // Level number for scope.                                        	2
	unsigned short term;	 // Terminal number (e.g. <identifier>, <string>, {typedef}, ...)		2
	unsigned short type;	 // Type (e.g. integer, float, double, char, ...)							2
	int    cell;	 // Hash vector cell number for deleting this symbol.						4  16 bytes
}Symbol;

/*==================新增加的code============================*/
/*=======================begin==============================*/
/**
 * 四元式(op, addr1, addr2, addr3)
 * 项的结构
*/
typedef struct addr  //数值 或 局部变量 或 中间变量 或 类型 或 空
{
	char kind[20];
	char name[20];
}addr;
/**
 * 四元式链表
*/
typedef struct fourvarcode  //(op ,addr1 ,addr2 ,addr3 ,)
{
	int op;
	struct addr addr1;
	struct addr addr2;
	struct addr addr3;
	struct fourvarcode *next;
	int line;		// 行号
}fourvarcode;
/**
 * 符号表链表
*/
typedef struct symboltable
{
    char type[20];
    char name[20];
    struct symboltable* next;
    int location;
}symboltable;
/*=======================end================================*/
/*==================新增加的code=============================*/

typedef struct Node                
{
	unsigned short id;		 // Node id number    (65535 max).					2	 2	  //id与node_name数组关联, 各个类型的node与node_name数组的第i个串相同，则id就为i //需要修改范围
	unsigned short prod;	 // Production number (65535 max).					2	 4
	int node_index;   //node 在node数组中的索引
	int    sti;     // Symbol-table index (perm or temp var).		4	 8        //sti与symbol数组关联
	int    prev;	 // Previous node.			   						4  12
	int    next;	 // Next node.												4  16   //node的数组下标与id 和sti关联
	int    line;    // Line number.                                4  20 
	int    child;   // Child node.                                	4  24 
	int    parent;  // Parent node.                             	4  28 bytes per node
	unsigned short layer;	//节点所在的层(与block有关，设计到变量的作用域，使用的范围,用uchar型也可以，一般不会达到255层)
	unsigned char  bsource;  //表示是否是被分析的程序的节点(源程序包含头文件，预处理之后，被包含的头文件与源程序会放在同一个中间文件中进行处理，用uchar(unsigned char)也可以)
}Node;


int yyerror(char *str);


void init_parser(int, int);
void term_parser();

// Symtab functions
void   init_symtab  (int);	// Initialize the symbol table.
void   term_symtab  ();

char * symbol_name  (short, FILE * );
void  print_symtab (char**);

int   add_symbol (short, char*);
int   get_symbol (char*); 

// AST functions
void   init_ast		(int);   //初始ast树

Node*  new_node();

void addchild( Node * node1, Node * node2 );

void adjust_term( Node * node1, int term );

//AST
void   printast		();  //打印ast树信息, 入口函数
void   print_ast		(int n);  //递归
void   print_node	(char *indent, int n);  //打印节点，对于node[]            
void   traverse		(char *indent, int n);

//打开输出文件
int   init_out_file (char* fn);
void  term_out_file (char * );


/*==================新增加的code============================*/
/*=======================begin==============================*/


/*通过查看parser.c，发现并没有在.c中实现下述任一方法*/


/**
 * 在asm.c中实现
 * 与目标代码生成有关的方法
*/
void start_asm(fourvarcode* );
/**
 * 在optimizetac.c中实现
 * 与中间代码优化有关的方法
*/
void start_optimize(fourvarcode* tac_head);
void optimer_tac(fourvarcode* tac_head);
void print_optimize_tac(fourvarcode* tac_head);
/**
 * 在tac.c中实现
 * 与产生中间代码有关的方法
*/
char *op_string(int op);
void tac();
static void start_tac(int n);
static char *deal_expk(int n);
static void MAIN_K(int n);
static void DEFINEPARA_K(int n);
static void ASSIGN_K(int n);
static fourvarcode* get_tac(int op,char a[],char b[],char c[]);
static char * newtemp();

/**
 * 自己新增加的东西
*/
static void EXP_K(int n);
static void IF_K(int n);
static void WHILE_K(int n);
static char* GO_EXP_TAC(int op, int n);

enum OP{
	EQUAL = 1,
	MUL,
	ADD,
	SUB,
	DIV,
	MAIN,
	MAIN_END,
	DEFINE_VARIABLE,
	LESS_THAN,
	GREATER_THAN,
	LESS_EQUAL,
	GREATER_EQUAL,
	IF_IF,
	JMP,
	LABEL,

};

/*=======================end================================*/
/*==================新增加的code=============================*/
#endif









