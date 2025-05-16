#include <stdio.h>
#include <string.h>

char* transfer(int x){
    if (x<0){
        x = x*-1;
    }
    int bin[32];
    int count = 0;
    if (x==0){
    return 0;
    }
    
    if (x==1){
        return 1;
    }

    while (x>1){
        bin[count] = x%2;
        x = x/2;
        count+=1;
    }

    static char result[100] = "1";
    for (int i = count-1; i>=0; i--) {
        char temp[10];
        sprintf(temp, "%d", bin[i]);
        strcat(result, temp);
    }
    //printf("here: %s\n",result);
    return result;

}