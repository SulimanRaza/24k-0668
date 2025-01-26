#include<stdio.h>
#include<string.h>
void perc(int tnum, int per){
    if (per<=100)
    {
        float num=(tnum*per)/100;
        printf("\n%d percent = %0.2f",per,num);
        perc(tnum,per+1);
    }
}
int main(){
    int tnum,per = 1;
    printf("Enter a number: ");
    scanf("%d", &tnum);
    perc(tnum,per);
    return 0;
}
