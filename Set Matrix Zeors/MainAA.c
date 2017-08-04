#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define endl printf("\n")

int main(int argc,char **argv){
	int **a,r,c,k=0,l=0,m=0;
	puts("Enter rows and column density");
	scanf("%d%d",&r,&c);
	int ra[r],ca[c];
	a=(int **)malloc(sizeof(int)*r);
	int i;
	for(i=0;i<r;i++)
		*(a+i)=(int *)malloc(sizeof(int)*c);
	puts("Enter Element");
	int j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&*(*(a+i)+j));

	for(i=0;i<r;i++){
		ra[i]=-1;
		k=0;
		for(j=0;j<c;j++){
			if(*(*(a+i)+j)==1)
				k++;
			ca[j]=-1;
		}
		if(k==c)
			ra[l++]=i;
	}
	for(i=0;i<c;i++){
		k=0;
		for(j=0;j<r;j++){
			if(*(*(a+j)+i)==1)
				k++;
			*(*(a+j)+i)=0;
		}
		if(k==r)
			ca[m++]=i;
	}
	i=0;
	while(i<l){
		j=0;
		while(j<m)
			*(*(a+ra[i])+ca[j++])=1;
		i++;
	}
	endl;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%d ",*(*(a+i)+j));
		endl;
	}
	endl;
	return 0;
}