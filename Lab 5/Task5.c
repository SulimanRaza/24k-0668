#include<stdio.h>
int main(){
	int num;
	printf("Enter a number ");
	scanf("%d",&num);
	if(!(num&1)){
		printf("Number is even");
	}
	else 
	printf("Number is odd");
}