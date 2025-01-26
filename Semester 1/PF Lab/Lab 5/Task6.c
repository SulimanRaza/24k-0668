#include <stdio.h>
int main(){
    int number,n=0;
    printf("Enter a number till 15 : ");
    scanf("%d",&number);
    if(number&1)
    n ++;
    if(number&2)
    n ++;
    if(number&4)
    n ++;
    if(number&8)
    n ++;
    printf("Number of 1s in binary representation of -%d- is -%d-",number,n);
}