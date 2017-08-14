#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define endl printf("\n")

int powmod(int x,int n,int d);

int main(int argc,char **argv){
	int x,n,d;
	scanf("%d%d%d",&x,&n,&d);
	printf("%d\n",powmod(x,n,d));
	return 0;
}

int powmod(int x,int n,int d){
	if(n==1)
		return x;
	int t=powmod(x,n/2,d);
	if(n%2==0)
		return (t*t)%d;
	else
		return (((t*t)%d)*x)%d;
}