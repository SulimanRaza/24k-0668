#include<stdio.h>
int main() {
int arr[12],sum[6];
printf("Enter numbers in array:");
for(int i=0;i<12;i++){
	scanf("%d",&arr[i]);
}

printf("Summed array = [");
for(int i=0;i<6;i++){
	sum[i]=arr[2*i]+arr[2*i+1];
	printf(" %d ",sum[i]);
}
printf("]");
  return 0;
}