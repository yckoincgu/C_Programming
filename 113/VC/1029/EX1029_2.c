#include <stdio.h>

int FX_A() ;
int FX_B() ;

// 函數用來顯示圖形A Function to display pattern A
int FX_A(int n) {

    if (n==0)
        return 1;
    else
        return n*FX_A(n-1);
   
}


// 函數用來顯示圖形B Function to display pattern B
int FX_B(int n) {

    int x=0;
    if (n==0)
        x=1;
    else
        {
            printf("front FX_B(%d) \n", n);
            x= n*FX_B(n-1);
            printf("back FX_B(%d) = %d\n", n, x);
        }    
    return x;    
}


int main() {
    int n=10;

    printf("(A)\n");
    printf("FX_A = %d\n", FX_A(n));
    printf("\n");

   
    printf("(B)\n");
    printf("FX_B(%d) = %d\n", n, FX_B(n));


    return 0;
}
