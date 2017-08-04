#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define endl printf("\n")

int numrev(int n);

int main(int argc,char **argv){
	int n;
	scanf("%d",&n);
	n=numrev(n);
	printf("%d\n",n);
	return 0;
}

int numrev(int A){
	int k=0;
	int z=A;
	if(A<0){
		A*=-1;
		k=1;
	}
	long l=0;
	int r;
	while(A>0){
		r=A%10;
		l=l*10+r;
		A/=10;
	}
	if(z==(int)l)
		printf("Palinfrome");
	if(k==1)
		l*=-1;
	if(l<INT_MIN||l>INT_MAX)
		return 0;
	else
		return (int)l;
}