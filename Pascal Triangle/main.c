#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int main(int argc,char **argv){
	system("clear");
	int n,i;
	int arr[n],k=n-1;
	puts("Enter the number of rows to be printed");
	scanf("%d",&n);
	if(n>2){
		arr[n-1]=0;
		for(i=0;i<k;i++){
			arr[i]=0;
			printf(" ");
		}
		k--;
		arr[0]=1;
		arr[1]=1;
		printf("%d\n",arr[0]);
		for(i=0;i<k;i++)
			printf(" ");
		printf("%d %d\n",arr[0],arr[1]);
		k--;
		for(int j=2;j<n;j++){
			int t1,t2,t3;
			for(i=0;i<k;i++)
				printf(" ");
			k--;
			t1=arr[0];
			t2=arr[1];
			t3=arr[2];
			for(i=1;i<j;i++){
				arr[i]=t1+t2;
				t1=t2;
				t2=t3;
				t3=arr[i+2];
			}
			arr[i]=1;
			for(i=0;i<j;i++)
				printf("%d ",arr[i]);
			printf("%d",arr[i]);
			endl;
		}
	}
	return 0;
}