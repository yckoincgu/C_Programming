#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getstr() {
    char str[100];
    printf("please input a string: \n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    return str;
}
int main() {
    char *s;
    char x[2] = "\"\"";
    s = getstr();
    printf("%c%s%c\n",x[0],s,x[1]);

}