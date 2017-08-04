#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define endl printf("\n")

char str[1003];
int t;

void calc(int e,int s,char ch);
void sum(int e,int s);
void sub(int e,int s);
void mult(int e,int s);

int main(void){
	int i,e,s;
	printf("Enter the string ");
	fgets(str,1003,stdin);
	t=strlen(str);
	str[t--]='\0';
	t--;
	i=0;
	while(isdigit(str[i++]));
	e=i-2;
	s=i;
	i=0;
	while(i<=e)
		printf("%c",str[i]);
	endl;
	i=s;
	while(i<=t)
		printf("%c",str[i]);
	endl;
	calc(e,s,str[i]);
	//printf("%d %c",i-1,str1[i]);
	//endl;

	return 0;
}

void calc(int e,int s,char ch){
	switch(ch){
		case '+':sum(e,s);
				 break;
		//case '-':sub(int e,int s);
		//		 break;
		//case '*':mult(int e,int s);
		//		 break;
	}
}

void sum(int e,int s){
	char re[502],temp[3];
	int i=e,j=t,k=0,tem,sen;
	while(i>=0&&j>=s){
		tem=(str[i]-48)+(str[j]-48);
		sprintf(temp,"%d",tem);
		if(temp[1]=='\0')
			re[k++]=temp[0];
		else{
			re[k++]=temp[1];
			if((e+1)>(t+1-s))
				str[i-1]=((str[i-1]-48)+1)+48;
			else
				str[j-1]=((str[j-1]-48)+1)+48;
		}
		i--;
		j--;
	}
	while(i>=0)
		re[k++]=str[i--];
	while(j>=s)
		re[k++]=str[j--];
	re[k]='\0';
	i=strlen(re)-1;
	while(i>=0)
		printf("%c",re[i--]);
	endl;
}