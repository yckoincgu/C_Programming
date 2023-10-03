#include<stdio.h> 

int main(){
	int a,p;
	printf("Input a:");
	scanf("%d",&a);
	if(a<=230){
	p=a*3.2;
	}
	else if(a<=450){
	p=a*4.8;
	}
	else{
	p=a*6;
	}
	printf("%d",p);
}

