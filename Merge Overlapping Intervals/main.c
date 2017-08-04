#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define endl printf("\n")

void mergeInterval(int X[],int Y[]);

int main(int argc,char **argv){
	int X[4],Y[4];
	for(int i=0;i<4;i++)
		scanf("%d%d",&X[i],&Y[i]);
	mergeInterval(X,Y);
	return 0;
}

void mergeInterval(int X[],int Y[]){
	int temp,i,k=0,t1,t2,mid;
	for(i=0;i<4;i++){
		temp=X[i];
		X[i]=(Y[i]*10)+X[i];
		Y[i]=(temp*10)+Y[i];
	}
	/*for(i=0;i<3;i++)
		if(X[i]>Y[i+1]){
			t1=Y[i]/10;
			t2=Y[i+1]%10;
			X[k]=t2*10+t1;
			Y[k++]=t1*10+t2;
		}*/
	for(i=0;i<6;i++){
		if(Y[i+1]>X[i])
			continue;
		mid=i+1;
		while(1){
			mid=mid+5/2;
			
		}
	}
	for(i=0;i<k;i++){
		X[i]=Y[i]/10;
		Y[i]=Y[i]%10;
	}
	for(i=0;i<k;i++)
		printf("%d %d\n",X[i],Y[i]);
}