#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#define endl printf("\n")

int custAtoi(char *A);

int main(int argc,char **argv){
	char A[30]="-54332872018247709407";
	int l=custAtoi(A);
	printf("%d\n",l);
	return 0;
}

int custAtoi(char *A){
	int l=strlen(A),i=0;
	long r=0;
	bool neg=false;
	bool neg1=false;
	while(*(A+i)==' ')
		i++;
	neg=(*(A+i)=='-')||(*(A+i)=='+');
	if(neg){
		neg1=*(A+i)=='-';
		if(*(A+i+1)==' ')
		return r;
		else
			i++;
	}
	int k=0;
	while(isdigit(*(A+i))){
		r=(r*10)+(*(A+i++)-48);
		k++;
	}
	if(neg1){
		r*=-1;
		if(r<INT_MIN||k>19)
			return INT_MIN;
	}
	if(r>INT_MAX)
		return INT_MAX;
	return r;
}