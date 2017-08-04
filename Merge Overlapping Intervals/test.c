#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

struct Interval{
	int start,end;
};

typedef struct Interval interval;

typedef struct node{
	interval d;
	struct node *l;
}node;

node *s=NULL,*e;

int compCustom(const void *p1,const void *p2){
	interval *i1=(interval *)p1;
	interval *i2=(interval *)p2;
	if(i1->start-i2->start==0)
		return i1->end-i2->end;
	return i1->start-i2->start;
}

int mergerInterval();
void addNode(interval in);
void delNode(node *n);
interval * merge(interval *intervals,int sz,int *len);

int main(int argc,char **argv){
	system("clear");
	int n,nsz;
	// int t;
	// scanf("%d",&t);
	// char **ch;
	// ch=(char **)malloc(sizeof(char *)*t);
	// for(interval=0;interval<t;interval++){
	int a,b;
	scanf("%d",&n);
	interval *in,*r;
	in=(interval *)malloc(sizeof(interval)*n);
	int j;
	for(j=0;j<n;j++){
		scanf("%d%d",&a,&b);
		(in+j)->start=a;
		(in+j)->end=b;
	}
	r=merge(in,n,&nsz);
	int i=0;
	for(i=0;i<nsz;i++)
		printf("%d %d",(r+i)->start,(r+i)->end);
	// for(interval=0;interval<t;interval++)
	// 	puts(*(ch+interval));	
	return 0;
}

interval * merge(interval *intervals,int sz,int *len){
	int k=1;
	qsort(intervals,sz,sizeof(interval),compCustom);
	int j=0;
	for(j=0;j<sz;j++)
		addNode(*(intervals+j));
	free(intervals);
	while(k==1)
		k=mergerInterval();
	// *(ch+interval)=(char *)malloc(100);
	//traverse(&len);
	node *t=s;
	int k2=0;
	// char *ch1;
	// ch1=(char *)malloc(7);
	// *(ch+0)='\0';
	while(t!=NULL){
		// printf("%d %d ",t->d.start,t->d.end);
		// strcat(ch,ch1);
		t=t->l;
		k2++;
	}
	interval *ret;
	// exit(0);
	*len=k2;
	ret=(interval *)malloc(sizeof(interval)*k2);
	node *t1=s;
	k2=0;
	while(t1!=NULL){
		// strcat(ch,ch1);
		(ret+k2)->start=t1->d.start;
		//printf("ret+k2->start=%d\n",*(ret+k2)->start);
		(ret+k2)->end=t1->d.end;
		//printf("ret+k2->end=%d\n",*(ret+k2)->end);
		t1=t1->l;
		k2++;
	}
	return ret;
}

int mergerInterval(){
	node *t=s;
	int k=0;
	while(t->l!=NULL){
		if(t->d.end>=t->l->d.start&&t->d.end<t->l->d.end){
			t->d.end=t->l->d.end;
			delNode(t);
			k=1;
		}
		else if(t->d.end>=t->l->d.end){
			delNode(t);	
			k=1;
		}
		else
			t=t->l;
	}
	return k;
}

void addNode(interval in){
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

void delNode(node *n){
	n->l=n->l->l;
}