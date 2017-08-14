#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define endl printf("\n")

int powmod(int x,int n,int d);

int main(int argc,char **argv){
	int x,n,d;
	scanf("%d%d%d",&x,&d,&d);
	printf("%d\n",powmod(x,n,d));
	return 0;
}

int powmod(int x,int n,int d){
	int res=1;
	while(n>0){
		if(n&1)
			res=(res*x)%d;
		n=n/2;
		x=(x*x)%d;
	}
	// if(res<0)
	// 	return d+res;
	return res;
}