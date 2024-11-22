#include <stdio.h>

void HW5_1(){
  int i, j, space;

  printf("    j=0 j=1 j=2 j=3\n");

    for(i =0 ; i <= 3; i++){
      printf("i= %d ",i);

      for (j = 0; j < i; j++) {
            printf("   ");
        }

        for (space = 0; space < 4 - i; space++){
            printf(" X ");
        }
        
        printf("\n");  
    }

    }

void HW5_2(){
  int i, j, space;

  printf("    j=0 j=1 j=2 j=3\n");

       for (i = 1; i <= 4; i++) {

        printf("i= %d ",i);
        for (space = 0; space < 4 - i; space++) {
            printf("   ");
        }
        
        for (j = 0; j < i; j++) {
            printf("  X");
        }

        printf("\n");  
    }

    }

int main() {
    printf("\n");
    HW5_1();
    HW5_2();
    

    return 0;
}
