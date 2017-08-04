#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int maxDistance(int a[],int n);

int main(int argc,char **argv){
	system("clear");
	int n,*a,t,*ans,i,j;
	scanf("%d",&t);
	ans=(int *)malloc(sizeof(int)*t);
	for(j=0;j<t;j++){
		scanf("%d",&n);
		a=(int *)malloc(sizeof(int)*n);
		// puts("Enter the array Element");
		for(i=0;i<n;i++)
			scanf("%d",&*(a+i));
		*(ans+j)=maxDistance(a,n);
		free(a);
	}
	for(i=0;i<t;i++)
		printf("%d\n",*(ans+i));
	// printf("%d",*(ans+i));
	free(ans);
	return 0;
}

int maxDistance(int a[],int n){
	int max=-1,i,j,k,ii,jj;
	if(n==1)
		return 0;
	for(i=0;i<n-1;i++){
		j=n-1;
		k=0;
		while(a[j]<a[i])
			j--;
		k=j-i;
		if(k>=max&&k!=0){
			ii=i;
			jj=j;
			max=k;
		}
	}
	return max;
}