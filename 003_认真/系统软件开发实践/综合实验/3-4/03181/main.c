/*
 * @Author: Chen
 * @Date: 2022-03-18 14:55:05
 * @LastEditTime: 2022-03-18 19:50:53
 * @FilePath: \makeso\main.c
 */
#include "fb3-2.h"
#include <stdio.h>

int main()
{
    char* text = "let avg(a, b){(a + b) / 2;}\n";
    char* text1 = "avg(1, 2);";
    char* ans = do_parser(text);
    printf("%s\n", ans);
    ans = do_parser(text1);
    printf("%s\n", ans);
    // calculate();
    return 0;
}