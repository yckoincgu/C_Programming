#include <stdio.h>
int main() {
    char s1[] = "programming ", s2[] = "is awesome";
    int length_1, length_2, j;

    // store length of s1 in the length variable
    length_1 = 0;
    while (s1[length_1] != '\0')   ++length_1;
  
    printf("sizeof(s1)= %d \n", (int)sizeof(s1)); 
    printf("length_1= %d \n", length_1);

    length_2 = 0;
    while (s2[length_2] != '\0')   ++length_2;
    printf("length_2= %d \n", length_2);
    
    
    char s3[length_1+length_2+1];
    int k=0;
    printf("sizeof(s3)= %d \n", (int)sizeof(s3));
    // concatenate s2 and s1
    for (j = 0; j< (int)sizeof(s3); j++) {
    printf("j = %d ==>   ", j);
    if(j <  length_1) {s3[j] = s1[j];  printf("s3[%d]= %c\n", k, s1[j]); }
    if(j == length_1) {s3[j] = s2[k];  printf("s3[%d]= %c\n", k, s2[k++]);}
    if(j >  length_1) {s3[j] = s2[k];  printf("s3[%d]= %c\n", k, s2[k++]);}

  }

  // terminating the s3 string
  s3[length_1+length_2] = '\0';

  printf("After concatenation: ");
  puts(s3);

  return 0;
}