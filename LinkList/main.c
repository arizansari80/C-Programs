#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

typedef struct node{
	int n;
	struct node *link;
}node;

node *s=NULL,*e;

void addS();
void addL();
void removeS();
void removeL();
void display();

int main(int argc,char **argv){
	system("clear");
	int ch;
	char ch1;
	do{
		printf("1.Add Start\n2.Remove Start\n3.Add Last\n4.Remove Last\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:addS();
				   break;
			case 2:removeS();
				   break;
			case 3:addL();
				   break;
			//case 4:removeL();
			//	   break;				   
		}
		getchar();
		printf("\nWant to do more ");
		scanf("%c",&ch1);
	}while(ch1=='Y'||ch1=='y');
	return 0;
}

void addS(){
	node *t;
	t=(node *)malloc(sizeof(node));
	printf("Enter the data ");
	scanf("%d",&t->n);
	if(s==NULL){
		s=(node *)malloc(sizeof(node));
		e=(node *)malloc(sizeof(node));
		s->n=t->n;
		s->link=NULL;
		e=s;
	}
	else{
		t->link=s;
		s=t;
	}
	display();
}

void addL(){
	node *t;
	t=(node *)malloc(sizeof(node));
	printf("Enter the data ");
	scanf("%d",&t->n);
	t->link=NULL;
	if(s==NULL){
		s=(node *)malloc(sizeof(node));
		e=(node *)malloc(sizeof(node));
		s->n=t->n;
		s->link=NULL;
		e=s;
	}
	else{
		e->link=t;
		e=e->link;
	}
	display();
}

void removeS(){
	if(s==NULL)
		printf("OverFlow\n");
	else
		s=s->link;
	display();
}

void display(){
	node *t;
	t=s;
	while(t!=NULL){
		printf("%d ",t->n);
		t=t->link;
	}
}