#include<stdio.h>
int main(){
int size;
printf("Enter Array size:");
scanf("%d",&size);
int arr[size];
printf("Enter numbers in array:");
for(int i=0;i<size;i++){
	scanf("%d",&arr[i]);
}
printf("Elements after left shift are:\n");
for(int i=1;i<size;i++){
	printf("%d ",arr[i]);
}
printf("%d",arr[0]);
  return 0;
}