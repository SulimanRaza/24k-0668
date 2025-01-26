#include<stdio.h>
int main(){
	float p;
	printf("Enter percentage");
	scanf("%f",&p);
	(p>=90)?printf("Grade is A"):(p>=80&&p<=89)?printf("Grade is B"):(p>=70&&p<=79)?printf("Grade is C"):
	(p>=60&&p<=69)?printf("Grade is D"):printf("Fail");
}