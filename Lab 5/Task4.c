#include<stdio.h>
int main(){
	int amount,member;
	printf("Enter total amount ");
	scanf("%d",&amount);
	printf("Do you have membership(1 for yes, 2 for no) ");
	scanf("%d",&member);
	(amount>100&&member==1)?printf("you are eligible for discount"):printf("you are not eligible for discount");
}