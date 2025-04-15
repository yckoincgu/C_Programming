#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char xstr[] = "This is a sample string with the word 'sample'.";
    char word[] = "sample";

    
    int xstrLength=strlen(xstr);
    char *dynamicStr=malloc((xstrLength+1) * sizeof(char));
    int i=0;

    for(i=0; i<xstrLength; i++)
        dynamicStr[i]=xstr[i];
    dynamicStr[xstrLength]='\0';
    char *ptr = strstr(dynamicStr, word);


    printf("strLength = %d\n", xstrLength);
    printf("dynamic string : %s\n",dynamicStr);
    if (ptr != NULL) {
        printf("Word '%s' found at position: %d\n", word, (int)(ptr-dynamicStr));
        printf("String from that position: %s\n", ptr);
    } else {
        printf("Word '%s' not found.\n", word);
    }

    return 0;
}