#include<stdio.h>
int main(){
    int charge;
    float bill,Total,sur;
    printf("Enter total unit charges ");
    scanf("%d", &charge);
    if(charge<=30)
    bill=30*0.60;
    else if(charge<=110)
    bill=30*0.60+(charge-30)*0.85;
    else if(charge<=210)
    bill=30*0.60+80*0.85+(charge-110)*1.30;
    else
    bill=30*0.60+80*0.85+100*1.30+(charge-210)*1.60;
    sur=bill*0.15;
    Total=bill+sur;
    printf("Your total bill is %fRs",Total);
    return 0;
}