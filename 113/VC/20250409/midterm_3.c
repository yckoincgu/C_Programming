#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    char x[2] = "\"\"";
    printf("please input a string: \n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("%c%s%c\n",x[0],str,x[1]);
    return 0;
}
