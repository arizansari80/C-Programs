#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define endl printf("\n")

int *subUnsort(int *A,int n1,int *len1);
int min(int a[],int s,int e);
int max(int a[],int s,int e);
int * maxUnsortSubArray(int *A,int s,int e); 

int main(int argc,char **argv){
	int *a,s=-1,e=-1,n,i,*ans,len1;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&*(a+i));
	ans=subUnsort(a,n,&len1);
	if(ans==(int *)-1)
		printf("The Array is already sorted\n");
	else{
		for(i=0;i<len1;i++)
			printf("%d ",*(ans+i));
	}
	return 0;
}

int* subUnsort(int* A, int n1, int *len1){
    int *ans;
    *len1=2;
    ans=maxUnsortSubArray(A,0,n1-1);
    if(ans==(int *)-1)
        return (int *)-1;
    return ans;
}

int * maxUnsortSubArray(int *A,int s,int e){
	if(s>=e)
		return (int *)-1;
	int mn=min(A,s,e);
	int mx=max(A,s,e);
	if(mn!=*(A+s)&&mx!=*(A+e)){
		int *ans=(int *)malloc(sizeof(int)*2);
		*(ans+0)=s;
		*(ans+1)=e;
		return ans;
	}
	else if(mn==*(A+s)&&mx==*(A+e))
		maxUnsortSubArray(A,s+1,e-1);
	else if(mn==*(A+s)&&mx!=*(A+e))
		maxUnsortSubArray(A,s+1,e);
	else if(mn!=*(A+s)&&mx==*(A+e))
		maxUnsortSubArray(A,s,e-1);
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