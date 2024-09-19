#include<stdio.h> 

float CtoF(int C){
	float F=C*9/5+32;
	return F; 
}

float FtoC(int F){
	float C=(F-32)*5/9;
	return C;
}

int main(){
	float x=FtoC(100);
	printf("%f",x);
	return 0;
}

