#include<stdio.h>
int main(){
    int bolt,nut,washer,total=0;
    printf("Enter number of bolts: ");
    scanf("%d",&bolt);
    printf("Enter number of nut: ");
    scanf("%d",&nut);
    printf("Enter number of washers: ");
    scanf("%d",&washer);
    total=bolt*5;
    total+=nut*3;
    total+=washer;
    printf("Number of bolts: %d\n",bolt);
    printf("Number of nuts: %d\n",nut);
    printf("Number of washers: %d\n",washer);
    if (nut<bolt && washer<bolt*2)
    {
        printf("Check the order : too few nut, too few washers\n");
    }else if(nut<bolt)
    {
        printf("Check the order : too few nut\n");
    }else if (washer<bolt*2)
    {
        printf("Check the order : too few washers\n");
    }
    else
    {
         printf("Order is OK\n");
    }
    printf("Total cost: %d\n", total);
    return 0;
}