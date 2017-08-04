#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define endl printf("\n")

bool linSearch(int a[],int k,int n);
void setZero(int **a,int i,int j,int r,int c,bool keyr,bool keyc);
bool colValid(int **a,int i,int j,int r);
bool rowValid(int **a,int i,int j,int c);

int main(int argc,char **argv){
	int **a,r,c,*col,l,m;
	puts("Enter rows and column density");
	scanf("%d%d",&r,&c);
	a=(int **)malloc(sizeof(int)*r);
	col=(int *)malloc(sizeof(int)*c);
	int ctr=0;
	int i;
	for(i=0;i<r;i++){
		*(a+i)=(int *)malloc(sizeof(int)*c);
		*(col+i)=-1;
	}
	puts("Enter Element");
	int j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&*(*(a+i)+j));
	bool breaker,keyrv;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++){
			breaker=true;
			if(*(*(a+i)+j)==0){
				// endl;
				// printf("i=%d j=%d",i,j);
				// endl;
				// for(l=0;l<c;l++)
				// 	printf("%d ",*(col+l));
				// endl;
				if(linSearch(col,j,ctr)==true&&keyrv==false)
					continue;
				if(rowValid(a,i,j,c)==true){
					breaker=false;
					keyrv=true;
				}
				else
					keyrv=false;
				if(colValid(a,i,j,r)==false){
					setZero(a,i,j,r,c,breaker,true);
					*(col+ctr++)=j;
				}
				else
					setZero(a,i,j,r,c,breaker,false);
				// endl;
				// for(l=0;l<r;l++){
				// 	for(m=0;m<c;m++)
				// 		printf("%d ",*(*(a+l)+m));
				// 	endl;
				// }
				if(breaker==true)
					break;
			}
		}

	endl;
	for(l=0;l<r;l++){
		for(m=0;m<c;m++)
			printf("%d ",*(*(a+l)+m));
		endl;
	}
	return 0;
}

void setZero(int **a,int i,int j,int r,int c,bool keyr,bool keyc){
	int k;
	if(keyr==true)
		for(k=0;k<c;k++)
			*(*(a+i)+k)=0;
	if(keyc==true)
		for(k=0;k<r;k++)
			*(*(a+k)+j)=0;
}

bool linSearch(int a[],int k,int n){
	if(n==0)
		return false;
	int i=0;
	for(i=0;i<n;i++)
		if(a[i]==k)
			return true;
	return false;
}

bool colValid(int **a,int i,int j,int r){
	int k;
	for(k=i+1;k<r;k++)
		if(*(*(a+k)+j)==0)
			return true;
	return false;
}

bool rowValid(int **a,int i,int j,int c){
	int k;
	for(k=j+1;k<c;k++)
		if(*(*(a+i)+k)==0)
			return true;
	return false;
}