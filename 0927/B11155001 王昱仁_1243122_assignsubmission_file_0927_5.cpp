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
	float f=CtoF(-40);
	float c=FtoC(-40);
	printf("%f\n",f);
	printf("%f\n",c);
	return 0;
}

