#include<stdio.h>
int main() {
int arr[]={1,2,3,4,5,6,7,8},number,flag=0;
printf("Array:{1,2,3,4,5,6,7,8}\n");
printf("Enter integer to search:");
scanf("%d",&number);
for(int i=0;i<8;i++){
if(arr[i] == number){
	printf("%d fount at %d\n",number,i);
	flag=1;
	break;
}
}
if(!flag){
    printf("Number not found");
}
  return 0;
}
