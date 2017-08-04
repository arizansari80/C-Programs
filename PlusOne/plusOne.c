#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define endl printf("\n")

int* plusOne(int *A,int n1,int *length_of_array){
    *length_of_array=n1;
	int e=0,i,f=0;
	for(i=0;i<n1;i++)
		if(*(A+i)!=0)
			break;
		else
			f++;
	if(f==n1){
		*length_of_array=1;
		int *result=(int *)malloc(*length_of_array*sizeof(int));
		*result=1;
	}
	for(i=f;i<n1;i++)
		if(*(A+i)==9)
			e++;
	if(e==n1-f){
		*length_of_array=n1-f+1;
		int *result=(int *)malloc(*length_of_array*sizeof(int));
		*result=1;
		for(i=1;i<*length_of_array;i++)
			*(result+i)=0;
		return result;
	}
	i=n1-1;
	int y,r;
	int z=1;
	while(z!=0&i>=f){
		y=*(A+i);
		y+=z;
		r=y%10;
		*(A+i--)=r;
		z=y/10;
	}
	*length_of_array-=f;
	int *result=(int *)malloc(*length_of_array*sizeof(int));
	result=A+f;
	return result;
}

int main(int argc,char **argv){
	int *a,n;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		scanf("%d",&*(a+i));
	int *b;
	b=plusOne(a,n,&n);
	for(int i=0;i<n;i++)
		printf("%d ",*(b+i));
	return 0;
}