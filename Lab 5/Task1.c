#include<stdio.h>
int main(){
	int age,city;
	printf("Enter your age");
	scanf("%d",&age);
	printf("Are you a citizen of pakistan (1 for yes, 2 for no)");
	scanf("%d",&city);
	if(city==1){
		if(age>=18){
		printf("You are eligible to vote");
        }
		else{
		printf("you are not eligible to vote");
	    }
    }    
	else{
	printf("you are not eligible to vote");
    }
    return 0;
}