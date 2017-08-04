#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

void swap(int *p,int *q){
	int t=*p;
	*p=*q;
	*q=t;
}

int compare(const void *p1,const void *q1){
	int *p=(int *)p1;
	int *q=(int *)q1;
	return *p-*q;
}

int * wave(int *A,int n1,int *len1);

int main(int argc,char **argv){
	int *a,n,i,*b,n1;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&*(a+i));
	b=wave(a,n,&n1);
	for(i=0;i<n1;i++)
		printf("%d ",*(b+i));
	endl;
	return 0;
}

int * wave(int *A,int n1,int *len1){
	int i;
	*len1=n1;
	int *a;
	a=(int *)malloc(sizeof(int)*n1);
	a=A;
	qsort(a,*len1,sizeof(int),compare);
	for(i=0;i<*len1-1;i+=2)
		swap(&a[i],&a[i+1]);
	return a;
}