/*
 * @Author: Chen
 * @Date: 2022-03-04 13:59:04
 * @LastEditTime: 2022-03-28 19:18:15
 * @FilePath: \codeByMyself\main.c
 */

#include "main.h"
#include "parser.h"


extern int yyparse();

extern FILE *yyin;

extern char * term_symb[];

extern void init_parser(int, int);
extern void   printast		();
extern int   init_out_file (char* fn);
extern void  term_out_file (char * );

/*================coding by myself=======================*/
/*======================begin============================*/
void getFourvarcode(char* file_name){
	char *filename = file_name;
	char * outfilename = "./output/AST.txt";

	//指向文件
	if(!(yyin = fopen(filename,"r"))) {
		printf("the file not exist\n");
		exit(0);
	}

	//初始化
	init_parser(100, 1000);

	if(yyparse())exit(1);

	//得到四元式
	tac();
    
	//打开输出文件
	init_out_file(outfilename);
	print_symtab (term_symb);  // Print the symbol table contents.
	//遍历ast树
	printast();	   // Print the AST, if ast option indicates.
	//关闭输出文件
	term_out_file(outfilename);
}
/*======================end==========================*/
/*================coding by myself===================*/

void  main (int na, char *arg[])
{
	getFourvarcode("./input/test.c");
}


void  quit ()
{
		#ifdef WAIT_ON_KEY
   // Wait until key is pressed ...
	  	printf( "Press any key to continue ...\n");
	  	while( !_kbhit() );
		#endif
		exit (0);
}

















