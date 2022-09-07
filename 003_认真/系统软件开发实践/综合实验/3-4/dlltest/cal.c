/*
 * @Author: Chen
 * @Date: 2022-03-19 09:20:26
 * @LastEditTime: 2022-03-19 09:22:21
 * @FilePath: \dlltest\cal.c
 */
#include "cal.h"
#include <stdio.h>

int add(int x, int y){
    return x + y;
}

int sub(int x, int y){
    return x - y;
}

void myPrint(char* str){
    printf("The str is %s\n", str);
}