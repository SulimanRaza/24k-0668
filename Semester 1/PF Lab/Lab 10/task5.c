#include <stdio.h>
int add(int num[], int i, int sum)
{
    if (i >= 0)
    {
        sum += num[i];
        return add(num, i - 1, sum);
    }
    else
    {
        return sum;
    }
}
int main(void){
    int num[50],total;
    printf("Enter total numbers: ");
    scanf("%d",&total);
    printf("Enter numbers: ");
    for (int i = 0; i < total; i++)
    {
        scanf("%d",&num[i]);
    }
    int sum=0;
    sum = add(num,total-1,sum);
    printf("Sum of numbers: %d\n", sum);
    
}