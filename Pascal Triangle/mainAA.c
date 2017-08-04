#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define endl printf("\n")

int ** generate(int A, int *number_of_rows);

int main(int argc,char **argv){
	system("clear");
	int n,i,j,m;
	int **a;
	scanf("%d",&n);
	a=generate(n,&m);
	for(i=0;i<m;i++){
		printf("[");
		for(j=0;j<i;j++)
			printf("%d ",*(*(a+i)+j));
		printf("%d] ",*(*(a+i)+j));
	}
	return 0;
}

int ** generate(int A, int *number_of_rows){
	*number_of_rows=A;
	int **result,i,j;
	result=(int **)malloc(sizeof(int *)*A);
	for(i=0;i<A;i++){
		*(result+i)=(int *)malloc(sizeof(int)*(i+1));
		if(i==0)
			*(*(result+i)+0)=1;
		if(i==1){
			*(*(result+i)+0)=1;
			*(*(result+i)+1)=1;
		}
		if(i==2){
			*(*(result+i)+0)=1;
			*(*(result+i)+1)=2;
			*(*(result+i)+2)=1;
		}
		if(i>2){
			int t1,t2,t3;
			t1=*(*(result+i-1)+0);
			t2=*(*(result+i-1)+1);
			t3=*(*(result+i-1)+2);
			*(*(result+i)+0)=1;*(*(result+i)+i)=1;
			for(j=1;j<i;j++){
				*(*(result+i)+j)=t1+t2;
				t1=t2;
				t2=t3;
				t3=*(*(result+i-1)+(j+2));
			}
		}
	}
	return result;
}