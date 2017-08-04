#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
	char ch[55];
	int sum,tc,i=0,*arr,j;
	scanf("%d",&tc);
	getchar();
	arr=(int *)malloc(sizeof(int)*tc);
	while(i<tc){
		j=0;
		sum=0;
		gets(ch);
		while(ch[j]!='\0')
			sum+=ch[j++]-48;
		*(arr+i++)=sum;
	}
	i=0;
	while(i<tc)
		printf("%d\n",*(arr+i++));
	free(arr);
	return 0;
}
