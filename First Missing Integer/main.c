#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define endl printf("\n")

int firstMissingPositive(int *A,int n1);
bool lSearch(int *a,int n,int key);

int main(int argc,char **argv){
	int *a,n;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&*(a+i));
	int f=firstMissingPositive(a,n);
	printf("First Missing Integer is %d",f);
	endl;
	return 0;
}

 
int firstMissingPositive(int* A, int n1) {
    if(n1==1){
		if(*(A+0)<=0)
			return 1;
		else if(*(A+0)==1)
			return 2;
		else if(*(A+0)>1)
			return 1;
	}
	int key=0,mn=32000,mx=0;
	int i;
	for(i=0;i<n1;i++)
		if(*(A+i)>0){
			key=1;
			if(*(A+i)<=mn)
				mn=*(A+i);
			if(*(A+i)>=mx)
				mx=*(A+i);
		}
	if(key==0)
		return 1;
	if(mn>1)
		return 1;
	else
		while(mn<=mx)
			if(lSearch(A,n1,mn++)==false)
				return mn-1;
}

bool lSearch(int *A,int n1,int key){
	int i;
	for(i=0;i<n1;i++)
		if(*(A+i)==key)
			return true;
	return false;
}