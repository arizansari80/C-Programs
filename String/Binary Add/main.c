#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define endl printf("\n")

char * binAdd(char *A,char *B);

int main(int argc,char **argv){
	char A[200]="10001100010111000101100010100110001001101010000010011010",B[200]="101111000100100100111110010010101110101001100100101001111010011000000110";
	char *s=binAdd(A,B);
	puts(s);
	return 0;
}

char * binAdd(char *A,char *B){
	int l1=strlen(A);
	int l2=strlen(B);
	int l=l1>l2?l1:l2;
	char *r=(char *)malloc(l);
	char *orr;
	l1--,l2--;
	int c=0,s,i=l-1;
	while(l1>=0&&l2>=0){
		s=(*(A+l1--)-48)+(*(B+l2--)-48)+c;
		if(s>1){
			c=1;
			if(s==2)
				s=0;
			else
				s=1;
		}
		else
			c=0;
		*(r+i--)=s+48;
	}
	while(l1>=0){
		s=(*(A+l1--)-48)+c;
		if(s>1){
			c=1;
			if(s==2)
				s=0;
			else
				s=1;
		}
		else
			c=0;
		*(r+i--)=s+48;	
	}
	while(l2>=0){
		s=(*(B+l2--)-48)+c;
		if(s>1){
			c=1;
			if(s==2)
				s=0;
			else
				s=1;
		}
		else
			c=0;
		*(r+i--)=s+48;	
	}
	if(c==1){
		orr=(char *)malloc(l+1);
		*(orr+0)=c+48;
		strcat(orr,r);
		free(r);
		*(orr+l+1)='\0';
		return orr;
	}
	*(r+l)='\0';
	return r;
}