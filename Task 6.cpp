#include <stdio.h>
int main(){
	int num1,num2;
	printf("Enter First Number ");
	scanf("%d", &num1);
	printf("Enter Second Number ");
	scanf("%d", &num2);
	if (num1>num2){
		if(num1>100){
		printf("First Number is Significantly larger");
		}
		else printf("First Number is larger");
	}
	else if(num1<num2){
		if(num1<0)
		printf("First Number is Negative and smaller");
		else
	printf("First number is smaller");
	}
	if (num1==num2)
	printf("Both number are equal");
	return 0;
}