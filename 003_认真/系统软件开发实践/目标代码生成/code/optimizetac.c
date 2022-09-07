//optimizetac.c  优化四元式
#include"parser.h"

char emptys[]="\0";
 
void start_optimize(fourvarcode* tac_head)
{
    printf("\nstart_optimize\n");
    optimer_tac(tac_head);
    print_optimize_tac(tac_head);
}

void optimer_tac(fourvarcode* tac_head)
{
    /**
     * t p q指向四元式链表的三个连续节点
     * 即使用窗口大小为3的滑动窗口遍历整个链表
     * 遇到待优化四元式序列则优化
    */ 
    fourvarcode* t=tac_head->next;
    fourvarcode* p;
    fourvarcode* q;
    p=t->next;
    q=p->next;


    while(q!=NULL)
    {
        /**
         * 可优化情况1：
         *      前者是赋值的话
         *      后者也是赋值，则可以优化为一个四元式
         * 可优化情况2：
         *      前者是赋值
         *      后者不是赋值，则 这 里 真 的 没 看 懂 ！
        */
        if(p->op==1)
        {
            /**
             * 可优化情况1：
            */
            if(q->op==1)
            {
                char a[20];
                strcpy(a,p->addr2.name);
                if(strcmp(p->addr2.name,q->addr1.name)==0&&a[0]=='t'&&a[1]=='#')
                {
                    strcpy(p->addr2.name,q->addr2.name);
                    p->next=q->next;
                    /**
                     * 内存管理大师！ 
                    */
                    free(q);
                    q=p->next;
                }
                /**
                 * 两个紧邻的赋值语句不能优化，则窗口向后遍历
                 * 
                 * 如果可以优化，窗口向后移动的代码写在了上一个if语句中 
                */
                else
                {
                    t=t->next;
                    p=p->next;
                    q=q->next;
                }
            }
 
            /**
             * 可优化情况2：
            */
            else if(q->op!=1) ///p可能需要删掉  比如return 0 的多于
            {
                char a[10],b[20],c[20];
                strcpy(a,p->addr1.name);
                strcpy(b,p->addr2.name);
                strcpy(c,q->addr3.name);
                if(strcmp(p->addr2.name,q->addr1.name)==0&&b[0]=='t'&&b[1]=='#'&&(c[0]=='\0'||a[1]=='#'))
                {
                    strcpy(q->addr1.name,p->addr1.name);///将asn的值给下一句
                    t->next=p->next;
                    free(p);
                    p=t->next;
                    q=q->next;
                }
                else
                {
                    t=t->next;
                    p=p->next;
                    q=q->next;
                }
            }
        }
        /**
         * 可优化情况3：
         * 112 (/ , t#6 , 3 , t#7)
         * 113 (= , t#7 , t#2 , _ , )
         * 
         * 优化为：
         * 112 (/, t#6, 3, t#2)
        */
        else if(p->op!=1)  ///如果不是赋值语句，那么它的下一句是赋值语句的话，且有运算
        {
            if(q->op==1)
			{ 
                /**
                 * p的addr3不为空，代表这是个带运算的赋值吧 a = 1 + 2   →   (+, 1, 2, a);
                */
				if(p->addr3.kind!=emptys)
				{
					char a[20];
				    strcpy(a,p->addr3.name);
					if(strcmp(p->addr3.name, q->addr1.name)==0&&a[0]=='t'&&a[1]=='#')
					{
                        /**
                         * 将赋值提前，即省略了赋值的中间变量
                        */
						strcpy(p->addr3.name,q->addr2.name);//将赋值提前
						p->next=q->next;
						free(q);
						q=p->next;
					}
					else ///如果不是运算 --继续执行
					{
						t=t->next;
						p=p->next;
						q=q->next;
					}
				}
				else///如果不是运算 --继续遍历
				{
					t=t->next;
				    p=p->next;
					q=q->next;
				}
			}
			else  ///下一句也不是赋值语句，那么肯定继续搜索，没法简化
			{
				t=t->next;
				p=p->next;
				q=q->next;
			}
		}
 
    }
}

/**
 * 这个方法会把优化后的四元式打印在命令行中，
 * 其实只要调用print_tac()方法，就可以将修改后的四元式链表写入文件
*/
///输出简化后的四元式
void print_optimize_tac(fourvarcode* tac_head)
{
	fourvarcode* t=tac_head->next;
	while(t!=NULL)
	{
	    if(t->op==7||t->op==6||t->op==8)
        {
            t=t->next;
        }
        else
        {
	    printf("(");
		printf("%s ,",op_string(t->op));
		if(t->addr1.kind==emptys)
			printf("_ ,");
		else
			printf("%s ,",t->addr1.name);
 
		if(t->addr2.kind==emptys)
			printf("_ ,");
		else
			printf("%s ,",t->addr2.name);
 
		if(t->addr3.kind==emptys)
			printf("_ ,");
		else
			printf("%s ,",t->addr3.name);
 
		t=t->next;
		printf(")");
		printf("\n");
        }
	}
}


