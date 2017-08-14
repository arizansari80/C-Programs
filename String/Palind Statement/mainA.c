#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#define endl printf("\n")

bool P(char *A);

int main(int argc,char **argv){
	char A[100]="A man, a plan, a canal: Panama";
	if(P(A))
		puts("Palindrome");
	return 0;
}

bool P(char *A){
	int k=strlen(A);
	k--;
	int i=0;
	while(i<=k){
		if(!isalnum(*(A+i))&&!isalnum(*(A+k))){
			i++;
			k--;
			continue;
		}
		if(!isalnum(*(A+i))){
			i++;
			continue;
		}
		if(!isalnum(*(A+k))){
			k--;
			continue;
		}
		if(!((*(A+i)==*(A+k))||(*(A+i)+32==*(A+k))||(*(A+i)-32==*(A+k))))
			return false;
		else
			i++,k--;
	}
	return true;
}