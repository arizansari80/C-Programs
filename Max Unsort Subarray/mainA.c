#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define endl printf("\n")

int minmax(int a[],int s,int e,int *mx);
int maxUnsortSubArray(int *A,int s,int e,int *s1,int *e1); 

int main(int argc,char **argv){
	int *a,s=-1,e=-1,n,i;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&*(a+i));
	if(maxUnsortSubArray(a,0,n-1,&s,&e)==1)
		printf("The unsorted Sub Array is from index %d to %d\n",s,e);
	else
		printf("The Array is already sorted\n");
	return 0;
}

int maxUnsortSubArray(int *A,int s,int e,int *s1,int *e1){
	int mx;
	if(s>=e)
		return -1;
	int mn=minmax(A,s,e,&mx);
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

int minmax(int a[],int s,int e,int *mx){
	int mn=a[s];
	*mx=a[s];
	int i;
	for(i=s+1;i<=e;i++){
		if(a[i]<=mn)
			mn=a[i];
		if(a[i]>=*mx)
			*mx=a[i];
	}
	return mn;
}