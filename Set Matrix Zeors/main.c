#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int binSearch(int a[],int k,int n);
void setZero(int **a,int i,int j,int r,int c);

int main(int argc,char **argv){
	int **a,r,c,*col;
	puts("Enter rows and column density");
	scanf("%d%d",&r,&c);
	a=(int **)malloc(sizeof(int)*r);
	col=(int *)malloc(sizeof(int)*c);
	int ctr=0;
	int i;
	for(i=0;i<r;i++){
		*(a+i)=(int *)malloc(sizeof(int)*c);
		*(col+i)=-1;
	}
	puts("Enter Element");
	int j,k;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&*(*(a+i)+j));
	// endl;
	// for(i=0;i<c;i++)
	// 	printf("%d ",*(col+i));
	// endl;
	//Operation Part

	for(i=0;i<r;i++)
		for(j=0;j<c;j++){
			if(*(*(a+i)+j)==0){
				k=binSearch(col,j,ctr);
				// printf("j= %d & k= %d\n",j,k);
				if(k!=-1)
					continue;
				setZero(a,i,j,r,c);
				*(col+ctr++)=j;
				// puts("Col array is");
				// for(k=0;k<ctr;k++)
				// 	printf("%d ",*(col+k));
				// endl;
				break;
			}
		}

	endl;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%d ",*(*(a+i)+j));
		endl;
	}
	// endl;
	// for(i=0;i<ctr;i++)
	// 	printf("%d ",*(col+i));
	// endl;
	return 0;
}

void setZero(int **a,int i,int j,int r,int c){
	int k;
	// puts("In Set Zero\n");
	// printf("i= %d j= %d\n",i,j);
	for(k=0;k<c;k++)
		*(*(a+i)+k)=0;
	for(k=0;k<r;k++)
		*(*(a+k)+j)=0;
}

int binSearch(int a[],int k,int n){
	// puts("In BSearch");
	// printf("n= %d\n",n);
	if(n==0)
		return -1;
	int s=0,e=n-1,mid;
	while(s<=e){
		mid=(s+e)/2;
		if(a[mid]==k)
			return mid;
		else if(a[mid]>k)
			e=mid-1;
		else
			s=mid+1;
	}
	return -1;
}