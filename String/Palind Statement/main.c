#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#define endl printf("\n")

int Palindr(char ch[],int k);

int main(int argc,char **argv){
	char ch[100]="radar";
	// printf("Enter the string: ");
	// gets(ch);
	int res=Palindr(ch,strlen(ch));
	// if()
	// 	puts("The above string is Palindrome");
	// else
	// 	puts("The above string is not a Palindrome");
	return 0;
}

int Palindr(char ch[],int k){
	printf("In Palind");
	k--;
	printf("K=%d",k);
	int i=0;
	while(i<=k){
		if(!isalpha(ch[i])&&!isalpha(ch[k])){
			i++;
			k--;
			continue;
		}
		if(!isalpha(ch[i])){
			i++;
			continue;
		}
		if(!isalpha(ch[k])){
			k--;
			continue;
		}
		if(!((ch[i]==ch[k])||(ch[i]+32==ch[k])||(ch[i]-32==ch[k])))
			return 0;
	}
	return 1;
}