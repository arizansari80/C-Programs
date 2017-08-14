#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define endl printf("\n")

void revString(char *A);

int main(int argc,char **argv){
	char A[30]="j";
	revString(A);
	puts(A);
	return 0;
}

void revString(char *A){
	int l=strlen(A);
	char *r=(char *)malloc(l);
	int i=--l,j,k=0;
	while(i>=0){
		while(*(A+i)!=' '&&i>=0){i--;}
		for(j=i+1;j<=l;j++)
			*(r+k++)=*(A+j);
		while(*(A+i)==' '&&i>=0){i--;}
		l=i;
		*(r+k++)=' ';
	}
	*(r+--k)='\0';
	for(i=0;i<k;i++)
		*(A+i)=*(r+i);
	*(A+i)='\0';
	free(r);
	// return r;
}