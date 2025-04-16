#include <stdio.h>

char x[2] = "\"\"";
char *s = "hello world";
int main(){ 
    printf("%c%s%c\n",x[0],s,x[1]);
    return 0;
}

