#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char stack[402],exprn[100][402],test[402];
int top=-1,j=0,ctr=0,k=0;

void converter();
void push(char ch);
char pop();
void expr(char ach);
int precedence(char pch);

int main()
{
	int t;
	printf("Enter the number of expression ");
	scanf("%d",&t);
	getchar();
	for(k=0;k<t;k++)
	{
    	printf("Enter the Expression ");
    	gets(test);
		j=0;
		converter();
		top=-1;
		if(exprn[k][j-1]=='(')
     		exprn[k][j-1]='\0';
    	else
     		exprn[k][j]='\0';
	}
	for(k=0;k<t;k++)
		puts(exprn[k]);
    return 0;
}

void converter()
{	
    int i=0,poe,pos;
    char chr;
    push('(');
    for(i=0;test[i]!='\0';i++)
    {
        if(isalnum(test[i]))
         expr(test[i]);
        else if(test[i]=='(')
         push('(');
        else if(test[i]==')')
        {
            chr=pop();
            while(chr!='(')
            {
                expr(chr);
                chr=pop();
            }
        }
        else
        {
            poe=precedence(test[i]);
            chr=pop();
            pos=precedence(chr);
            if(pos<poe)
                push(chr);
            else
            {
                while(pos>=poe)
                {
                    expr(chr);
                    chr=pop();
                    pos=precedence(chr);
                }
                push(chr);
            }
            push(test[i]);
        }
    }
}

void push(char ch)
{
    if(top==-1)
     stack[++top]=ch;
    else if(top==20)
     printf("\nOverFlow \n");
    else
     stack[++top]=ch;
}

char pop()
{
    char rch;
    ctr++;
    if(top==-1)
    {
     if(exprn[k][j-1]=='(')
         exprn[k][j-1]='\0';
     else
         exprn[k][j]='\0';
    }
    if(top==0)
     rch=stack[top--];
    else
     rch=stack[top--];
    return rch;
}

void expr(char ach)
{
    exprn[k][j++]=ach;
}

int precedence(char pch)
{
    switch(pch)
    {
        case '^':return 5;
        case '/':return 4;
        case '*':return 4;
        case '%':return 4;
        case '+':return 2;
        case '-':return 2;
        default:return 0;
    }
}
