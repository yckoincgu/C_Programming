#include<stdio.h> 

int main(){
	int qty,money;
	
	printf("Input qty:");
	scanf("%d",&qty);
	if(qty<=230){
		money=qty*3.2;
	}
	else if(qty<=450){
			money=230*3.2+(qty-230)*4.8;	}
	else{
		money=230*3.2+(450-230)*4.8+(qty-450)*6.0;
	}
	printf("%d",money);
	return 0;
}

