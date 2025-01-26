#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(void){
	FILE *source,*destination;
	source=fopen("source.txt","r");
	destination=fopen("destination.txt","w");
	if(source==NULL||destination==NULL){
		printf("Error in opening source file\n");
		return 1;
	}
	char c;
	while((c=fgetc(source))!= EOF){
	        fputc(islower(c) ? toupper(c) : c, destination);
	}
	fclose(source);
	fclose(destination);
}