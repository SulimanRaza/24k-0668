#include<stdio.h>
int main(){
    int cost;
    float discount,total;
    printf("Enter total cost ");
    scanf("%d", &cost);
    if(cost<1500){
        discount=cost*0.07;
        total=cost-discount;
     }
    else if(cost>=1500 && cost<3000){
        discount=cost*0.12;
        total=cost-discount;
    }    
    else if(cost>=300 && cost<5000){
        discount=cost*0.22;
        total=cost-discount;
    }
    else {
        discount=cost*0.3;
        total=cost-discount;
    }
    printf("Your original amount is %d", cost);
    printf("\nAmount saved due to the discount %f", discount);
    printf("\nYour total amount is %f", total);
    return 0;
}