#include<stdio.h>
int main(){
	int a1,a2,a3,sum;
	printf("Enter 3 angles ");
	scanf("%d %d %d",&a1,&a2,&a3);
	sum=a1+a2+a3;
	if(a1>0||a2>0||a3>0){
		if(sum=180)
		printf("Triangle is valid");
		else
		printf("triangle is not valid");
	}
	else 
	printf("Triangle is not valid");
	return 0;
}