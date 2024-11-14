#include<stdio.h>
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    for (int i = 1; i <= num; i++)
    {
        printf("\n");
        for (int j = 1; j <= i; j++)
        {
            printf("%d",j);
        }
        for (int k = i-1; k >= 1; k--)
        {
            printf("%d",k);
        }
        
    }
    return 0;
}