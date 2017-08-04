#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int main(int argc,char **argv){
	char ch[40]="for(i=0;i<n;i++){sum+=i;}";
	char *t;
	t=strtok(ch,", =+;(){}<>");
	printf("The tokens are as follows");
	endl;
	while(t!=NULL){
		printf("%s\n",t);
		t=strtok('\0',", =+;(){}<>");
	}
	endl;
	return 0;
}