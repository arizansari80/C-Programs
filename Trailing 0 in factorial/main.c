#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int sumZeroFact(int A);

int main(int argc,char **argv){
	int n,s;
	scanf("%d",&n);
	s=sumZeroFact(n);
	printf("%d\n",s);
	return 0;
}

int sumZeroFact(int A){
	int m=A,sum=0,r=5;;
	while(A>0){
		A=m;
		A/=r;
		r*=5;
		sum+=A;
	}
	return sum;
}