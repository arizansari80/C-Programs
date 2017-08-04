#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
	char ch[50];
	int sum,tc,i=0,*arr,j;
	printf("Enter the number of test cases ");
	scanf("%d",&tc);
	getchar();
	arr=(int *)malloc(sizeof(int)*tc);
	while(i!=tc){
		j=0;
		sum=0;
		printf("Enter the number ");
		fgets(ch,50,stdin);
		printf("%d\n",strlen(ch));
		ch[strlen(ch)-1]='\0';
		while(ch[j]!='\0')
			sum+=ch[j++]-48;
		*(arr+i++)=sum;
	}
	i=0;
	while(i<tc)
		printf("%d\n",*(arr+i++));
	return 0;
}
