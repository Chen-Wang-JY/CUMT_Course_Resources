#include "fb3-2.h"
#include <stdio.h>
int main(){
    char* ans = do_cal("let avg(a, b){(a + b) / 2;}\n");

    printf("The ans is %s\n", ans);
    ans = do_cal("avg(1, 4);\n");
    printf("The ans is %s\n", ans);
    
}




