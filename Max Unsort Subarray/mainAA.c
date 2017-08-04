#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define endl printf("\n")

int min(int a[],int s,int e);
int max(int a[],int s,int e);
int maxUnsortSubArray(int *A,int s,int e,int *s1,int *e1); 

int main(int argc,char **argv){
	int *a,s=-1,e=-1,n,i,j;
	int t;
	int *ans=(int *)malloc(sizeof(int)*(2*t));
	scanf("%d",&t);
	for(j=0;j<t;j++){
		int k;
		scanf("%d",&n);
		a=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&*(a+i));
		s=-1,e=-1;
		k=maxUnsortSubArray(a,0,n-1,&s,&e);
		*(ans+2*j)=s;
		*(ans+2*j+1)=e;
	}
	for(j=0;j<t;j++)
		printf("%d %d\n",*(ans+2*j),*(ans+2*j+1));
	return 0;
}

int maxUnsortSubArray(int *A,int s,int e,int *s1,int *e1){
	if(s>=e)
		return -1;
	int mn=min(A,s,e);
	int mx=max(A,s,e);
	if(mn!=*(A+s)&&mx!=*(A+e)){
		*s1=s;
		*e1=e;
		return 1;
	}
	else if(mn==*(A+s)&&mx==*(A+e))
		maxUnsortSubArray(A,s+1,e-1,s1,e1);
	else if(mn==*(A+s)&&mx!=*(A+e))
		maxUnsortSubArray(A,s+1,e,s1,e1);
	else if(mn!=*(A+s)&&mx==*(A+e))
		maxUnsortSubArray(A,s,e-1,s1,e1);
}

int min(int a[],int s,int e){
	int mn=a[s];
	int i;
	for(i=s+1;i<=e;i++)
		if(a[i]<=mn)
			mn=a[i];
	return mn;
}

int max(int a[],int s,int e){
	int mx=a[s];
	int i;
	for(i=s+1;i<=e;i++)
		if(a[i]>=mx)
			mx=a[i];
	return mx;
}