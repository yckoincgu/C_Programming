#include<stdio.h> 
float CtoF(int C){
	float F=C*9/5+32;
	return F; 
}

int main(){
	float x;
	
	printf("Input C:");
	scanf("%f",&x);
	float a=CtoF(x);
	printf("%f",a);
	
}
