#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

void retIndex(int a[],int n);

int main(int argc,char **argv){
	system("clear");
	int *a,n;
	puts("Enter the size of array");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	puts("Enter the element");
	for(int i=0;i<n;i++)
		scanf("%d",&*(a+i));
	retIndex(a,n);
	free(a);
	// for(int i=0;i<*(ind+0)+1;i++)
	// 	printf("%d ",*(a+(*(ind+1)+i)));
	// printf("\nAnd Max Sum is %d\n",*(ind+2));
	return 0;
}

void retIndex(int a[],int n){
	int **dp,k,ret[3];
	ret[2]=a[0];
	ret[0]=0;
	ret[1]=0;
	dp=(int **)malloc(sizeof(int *)*n);
	for(int i=1;i<n;i++)
		if(a[i]>=ret[2]){
			ret[2]=a[i];
			ret[1]=i;
		}
	// printf("%d %d %d\n",ret[0],ret[1],ret[2]);
	// exit(0);
	for(int i=0;i<n;i++){
		// endl;
		*(dp+i)=(int *)malloc(sizeof(int)*(n-i));
		// puts("After Make");
		if(i==0)
			for(int j=i;j<n;j++){
				*(*(dp+i)+j)=a[j];
				// printf("%d ",*(*(dp+i)+j));
			}
		else
			for(int j=i,k=0;j<n;j++,k++){	
				*(*(dp+i)+k)=*(*(dp+i-1)+k)+a[j];
				// printf("%d ",*(*(dp+i)+k));	
			}
		if(i>0){
			for(int j=0;j<n-i;j++)
				if(*(*(dp+i)+j)>=ret[2]){
					ret[2]=*(*(dp+i)+j);
					ret[0]=i;
					ret[1]=j;
				}
		}
		// printf("\nMax I J %d %d %d\n",ret[2],ret[0],ret[1]);
		//getchar();
	}
	for(int i=0;i<n;i++)
		free(*(dp+i));
	// puts("Minal");
	printf("\nMax I J %d %d %d\n",ret[2],ret[0],ret[1]);
	puts("Result SubArray is");
	for(int i=0;i<=ret[0];i++)
		printf("%d ",a[ret[1]+i]);
	printf("\nMaxSum of SubArray is %d\n",ret[2]);
}