#include <stdio.h>

int main() {
    char *x = "\"\"";
    char str[100];
    printf("please input a string: \n");
    scanf(" %[^\n]", str);
    printf("%c%s%c\n",x[0],str,x[1]);
    return 0;
}
