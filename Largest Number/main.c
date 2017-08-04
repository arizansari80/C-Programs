#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int main(int argc,char **argv){
	system("clear");
	int n,*a,i,*al;
	char ch[10];
	puts("Enter the size of the array");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	al=(int *)malloc(sizeof(int)*n);
	puts("Enter the array element");
	for(i=0;i<n;i++){
		scanf("%d",&*(a+i));
		sprintf(ch,"%d",*(a+i));
		*(al+i)=ch[0]-48;
	}
	for(i=0;i<n;i++)
		printf("%d",*(al+i));
	endl;
	return 0;
}