#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

void swap(int *p,int *q){
	int t=*p;
	*p=*q;
	*q=t;
}

void waveArrayBuild(int a[],int n);

int main(int argc,char **argv){
	int **a,*n,i,j,t;
	scanf("%d",&t);
	a=(int **)malloc(sizeof(int *)*t);
	n=(int *)malloc(sizeof(int)*t);
	for(j=0;j<t;j++){
		scanf("%d",&*(n+j));
		*(a+j)=(int *)malloc(sizeof(int)*(*(n+j)));
		for(i=0;i<*(n+j);i++)
			scanf("%d",&*(*(a+j)+i));
		waveArrayBuild(*(a+j),*(n+j));
	}
	for(i=0;i<t;i++){
		for(j=0;j<*(n+i);j++)
			printf("%d ",*(*(a+i)+j));
		free(*(a+i));
		endl;
	}
	free(n);
	return 0;
}

void waveArrayBuild(int a[],int n){
	int i;
	for(i=0;i<n-1;i++)
		if(i%2==0)
			if(a[i]>a[i+1])
				continue;
			else
				swap(&a[i],&a[i+1]);
		else
			if(a[i]<a[i+1])
				continue;
			else
				swap(&a[i],&a[i+1]);
}