#include<stdio.h>
#include<stdlib.h>

void quicksort(unsigned int *a,int s,int e);
int pivot(unsigned int *a,int s,int e);
void swap(unsigned int *p,unsigned int *q);
int binary(unsigned int ele,unsigned int *a,int s,int e);

int main()
{
	unsigned int *arr,f,d;
	int size,i=0,br,ctr=0;
	scanf("%d%d",&size,&d);
	arr=(unsigned int *)malloc(sizeof(unsigned int)*size);
	for(;i<size;i++)
		scanf("%u",&*(arr+i));
	quicksort(arr,0,size-1);
	for(i=0;i<size-1;i++)
	{
		f=*(arr+i)+d;
		br=binary(f,arr,i+1,size-1);
		if(br!=-1)
			ctr++;
	}
	printf("%d",ctr);
	free(arr);
	return 0;
}

void quicksort(unsigned int *a,int s,int e)
{
	int p;
	if(s>=e)
		return;
	p=pivot(a,s,e);
	quicksort(a,s,p-1);
	quicksort(a,p+1,e);	
}

int pivot(unsigned int *a,int s,int e)
{
	int i=s,j=s;
	for(;i<e;i++)
		if(*(a+i)<*(a+e))
			swap(a+i,a+j++);
	swap(a+j,a+e);
	return j;
}

void swap(unsigned int *p,unsigned int *q)
{
	unsigned int temp=*p;
	*p=*q;
	*q=temp;
}

int binary(unsigned int ele,unsigned int *a,int s,int e)
{
	unsigned int r,mid;
	mid=(e+s)/2;
	while(s<=e)
	{
		if(ele==*(a+mid))
			return mid;
		else if(ele>*(a+mid))
			s=mid+1;
		else
			e=mid-1;
		mid=(e+s)/2;
	}
	return -1;
}
