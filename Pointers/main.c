#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int main(int argc,char **argv){
	system("clear");
	char **ch;
	ch=(char **)malloc(sizeof(char *)*5);
	for(int i=1;i<=5;i++){
		*(ch+i)=(char *)malloc(sizeof(char)*(5*i));
		fgets(*(ch+i),10,stdin);
		puts("You Enter");
		puts(*(ch+i));
	}
	return 0;
}