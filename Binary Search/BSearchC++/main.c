#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define endl printf("\n")

int bSearch(int *A,int n1,int B);

int main(int argc,char **argv){
	int a[4]={1,3,5,6};
	int n=4,B;
	printf("{1,3,5,6}");
	endl;
	printf("Enter B value ");
	scanf("%d",&B);
	printf("%d\n",bSearch(a,n,B));
	return 0;
}

int bSearch(int *A,int n1,int B){
	if(B<*A)
		return 0;
	if(B>*(A+n1-1))
		return n1;
	int mid;
	int s=0,e=n1-1;
	while(s<=e){
		mid=(s+e)/2;
		if(B==*(A+mid))
			return mid;
		if(B>*(A+mid))
			s=mid+1;
		else
			e=mid-1;
	}
	return s;
}