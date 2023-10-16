#include<stdio.h> 

int main(){
	int qty,money;
	
	printf("Input qty:");
	scanf("%d",&qty);
	if(qty<=230){
		money=qty*3.2;	}
	else if(qty<=450){
			money=qty*4.8;}
	else{
		money=qty*6;		}
		
	printf("%d",money);
	return 0;
}

