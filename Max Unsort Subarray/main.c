#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define endl printf("\n")

int maxUnsortSubarray(int *A,int n1,int *s,int *e);

int main(int argc,char **argv){
	int *a,s=-1,e=-1,n,i;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&*(a+i));
	if(maxUnsortSubarray(a,n,&s,&e)==1)
		printf("The unsorted Sub Array is from index %d to %d\n",s,e);
	else
		printf("The Array is already sorted\n");
	return 0;
}

int maxUnsortSubarray(int *A,int n1,int *s,int *e){
	int i=0,j=n1-1,key=0,si=0,ei=n1-1;
	// while(key<2&&i<n1-1&&j>0){
	// 	if((*(A+i)>*(A+i+1))||(*(A+i)>*(A+j))){
	// 		if(key<2)
	// 			*s=i;
	// 		key++;
	// 	}
	// 	if(*(A+j)<*(A+j-1)||(*(A+i)<*(A+j))){
	// 		if(key<2)
	// 			*e=j;
	// 		key++;
	// 	}
	// 	i++;
	// 	j--;
	// }
	// printf("i=%d j=%d\n",i,j);
	// if(i==n1-1&&j==0){
	// 	*s=-1;
	// 	*e=-1;
	// 	return -1;
	// }
	// else
	// 	return 1;
	for(i=0;i<n1-1;i++){
		if(*(A+i)>*(A+i+1)){
			if(!(*(A+i+1)<*(A+si)))
				si=i;
			break;
		}
		si=i;
	}
	for(j=n1-1;j>0;j--){
		if(*(A+j)<*(A+j-1)){
			if(!(*(A+j-1)>*(A+ei)))
				ei=j;
			break;	
		}
		ei=j;
	}
	if(i==n1-1||j==0)
		return -1;
	else{
		*s=si;
		*e=ei;
		return 1;
	}
}