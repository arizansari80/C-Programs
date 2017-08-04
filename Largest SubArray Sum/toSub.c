#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int retSum(int a[],int n);
int max(int a,int b);

int main(int argc,char **argv){
	int *a,n,*ans,t,j,i;
	scanf("%d",&t);
	ans=(int *)malloc(sizeof(int)*t);
	for(j=0;j<t;j++){
		scanf("%d",&n);
		a=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&*(a+i));
		*(ans+j)=retSum(a,n);
		free(a);
	}
	for(j=0;j<t;j++)
		printf("%d\n",*(ans+j));
	return 0;
}

int retSum(int a[],int n){
	int *dp,k,ret,i,cret;
	cret=-1234;
	ret=-1234;
	for(i=0;i<n;i++){
		cret=max(a[i],cret+a[i]);
		ret=max(ret,cret);
	}
	// dp=(int *)malloc(sizeof(int)*n);
	// for(i=1;i<n;i++)
	// 	if(a[i]>=ret)
	// 		ret=a[i];
	// for(i=0;i<n;i++){
	// 	if(i==0)
	// 		for(j=i;j<n;j++)
	// 			*(dp+j)=a[j];
	// 	else
	// 		for(j=i,k=0;j<n;j++,k++){	
	// 			*(dp+k)=*(dp+k)+a[j];
	// 			if(*(dp+k)>=ret)
	// 				ret=*(dp+k);
	// 		}
	// }
	// free(dp);
	return ret;
}

int max(int a,int b){
	return a>b?a:b;
}