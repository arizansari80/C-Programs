#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

typedef struct node{
	int n;
	struct node *r,*l;
}node;

node *s=NULL;

void enterData(int z);
void traverse(node *k);

int main(int argc,char **argv){
	system("clear");
	int n,i=0;
	int a[10]={3,1,2,5,4,6,8,9,7,10};
	while(i<10)
		enterData(a[i++]);
	traverse(s);
	return 0;
}

void enterData(int z){
	if(s==NULL){
		s=(node *)malloc(sizeof(node));
		s->n=z;
		s->r=NULL;
		s->l=NULL;
	}
	else{
		node *t=s;
		node *j=(node *)malloc(sizeof(node));
		j->n=z;
		j->r=NULL;
		j->l=NULL;
		while(t!=NULL)
			if(j->n<t->n)
				if(t->l!=NULL)
					t=t->l;
				else{
					t->l=j;
					break;
				}
			else
				if(t->r!=NULL)
					t=t->r;
				else{
					t->r=j;
					break;	
				}
	}
}

void traverse(node *k){
	if(k==NULL)
		return;
	traverse(k->l);
	printf("%d ",k->n);
	traverse(k->r);	
}