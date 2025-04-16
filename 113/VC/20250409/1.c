#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s = "This program makes a string \"hello world\"";
    char x = '\"';

    printf("%x%s%x\n", s);

    return 0;
}
