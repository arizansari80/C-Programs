#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

typedef struct stack{
	int top;
	int arr[];
}stack;

void push(int n,stack *s);
int pop(stack *s);
void display(stack *s);

int main(int argc,char **argv){
	stack *s1;
	int k;
	s1=(stack *)malloc(sizeof(stack)+5*sizeof(int));
	s1->top=-1;
	for(int i=0;i<5;i++){
		scanf("%d",&k);
		push(k,s1);
	}
	display(s1);
	for(int i=0;i<5;i++)
		printf("%d\n",pop(s1));
	return 0;
}

void push(int n,stack *s){
	if(s->top==-1)
		s->arr[++s->top]=n;
	else
		s->arr[++s->top]=n;
}

int pop(stack *s){
	if(s->top==-1)
		return -1;
	else
		return s->arr[s->top--];
}

void display(stack *s){
	for(int i=s->top;i>=0;i--)
		printf("%d ",s->arr[i]);
	endl;
}