#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int GCD(int A,int B);

int main(int argc,char **argv){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",GCD(n,m));
	return 0;
}

int GCD(int A,int B){
	if(A==B)
		return B;
	if(A==0)
		return B;
	else if(B>A)
		return GCD(B,A);
	else
		return GCD(A%B,B);
}