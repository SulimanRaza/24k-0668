#include<stdio.h>
void array_print(int num[],int n,int i){
    if (i>n)
    {
        return;
    }
    printf("\n Element %d = %d",i+1,num[i]);
    array_print(num,n,i+1);
}
int main(){
    int n,i=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int num[n];
    printf("Enter array elemnts: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }
    array_print(num,n-1,i);
}