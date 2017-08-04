#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int main(int argc,char **argv){
	system("clear");
	int n,i,j;
	puts("Enter the number of rows to be printed");
	scanf("%d",&n);
	int arr[n];
	arr[0]=1;arr[1]=0;arr[2]=0;
	int t1,t2,t3;
	for(i=0;i<n;i++){
		t1=arr[0];
		t2=arr[1];
		t3=arr[2];
		arr[0]=1;arr[i]=1;
		for(j=1;j<i;j++){
			arr[j]=t1+t2;
			t1=t2;
			t2=t3;
			t3=arr[j+2];
		}
		for(j=0;j<i;j++)
			printf("%d ",arr[j]);
		printf("%d\n",arr[j]);
	}
	return 0;
}