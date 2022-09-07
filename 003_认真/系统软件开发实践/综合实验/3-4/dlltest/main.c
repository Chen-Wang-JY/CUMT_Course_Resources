/*
 * @Author: Chen
 * @Date: 2022-03-19 09:24:29
 * @LastEditTime: 2022-03-19 09:24:29
 * @FilePath: \dlltest\main.c
 */
#include "cal.h"
int main(){
    int ans1 = add(1, 2);
    int ans2 = add(2, 3);
    printf("%d %d\n", ans1, ans2);
    myPrint("helloworld\n");
    return 0;
}