#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

typedef struct I{
	int x,y;
}I;

typedef struct node{
	I d;
	struct node *l;
}node;

node *s=NULL,*e;

int compCustom(const void *p1,const void *p2){
	I *i1=(I *)p1;
	I *i2=(I *)p2;
	if(i1->x-i2->x==0)
		return i1->y-i2->y;
	return i1->x-i2->x;
}

int mergerInterval();
void addNode(I in);
void delNode(node *n);
void traverse();

int main(int argc,char **argv){
	system("clear");
	int n,k=1,t;
	scanf("%d",&t);
	int i=0;
	char **ch;
	ch=(char **)malloc(sizeof(char *)*t);
	for(i=0;i<t;i++){
		int a,b;
		k=1;
		scanf("%d",&n);
		I *in;
		in=(I *)malloc(sizeof(I)*n);
		int j;
		for(j=0;j<n;j++){
			scanf("%d%d",&a,&b);
			(in+j)->x=a;
			(in+j)->y=b;
		}
		qsort(in,n,sizeof(I),compCustom);
		s=NULL;
		j=0;
		for(j=0;j<n;j++)
			addNode(*(in+j));
		free(in);
		while(k==1)
			k=mergerInterval();
		*(ch+i)=(char *)malloc(100);
		traverse(*(ch+i));
	}
	for(i=0;i<t;i++)
		puts(*(ch+i));	
	return 0;
}

int mergerInterval(){
	node *t=s;
	int k=0;
	while(t->l!=NULL){
		if(t->d.y>=t->l->d.x&&t->d.y<t->l->d.y){
			t->d.y=t->l->d.y;
			delNode(t);
			k=1;
		}
		else if(t->d.y>=t->l->d.y){
			delNode(t);	
			k=1;
		}
		else
			t=t->l;
	}
	return k;
}

void addNode(I in){
	if(s==NULL){
		s=(node *)malloc(sizeof(node));
		s->d=in;
		s->l=NULL;
		e=s;
	}
	else{
		node *t=(node *)malloc(sizeof(node));
		t->d=in;
		t->l=NULL;
		e->l=t;
		e=t;
	}
}

void traverse(char *ch){
	node *t=s;
	char *ch1;
	ch1=(char *)malloc(7);
	*(ch+0)='\0';
	while(t!=NULL){
		sprintf(ch1,"%d %d ",t->d.x,t->d.y);
		strcat(ch,ch1);
		t=t->l;
	}
}

void delNode(node *n){
	n->l=n->l->l;
}