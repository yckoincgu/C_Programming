#include<stdio.h> 

int main(){
	int a,p;
	printf("Input a:");
	scanf("%d",&a);
	if(a<=230){
	p=a*3.2;
	}
	else if(a<=450){
	p=230*3.2+(a-230)*4.8;
	}
	else{
	p=230*3.2+(450-230)*4.8+(a-450)*6.0;
	}
	printf("%d",p);
}

