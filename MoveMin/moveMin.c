#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")

typedef struct P{
	int x,y;
}P;

int dist(int y2,int y1,int x2,int x1);
void swap(int *p1,int *p2);

int coverPoints(int *X,int n1,int *Y,int n2);

int main(int argc,char **argv){
	struct P *p;
	int *X,*Y;
	int n,i;
	printf("Enter the number of points ");
	scanf("%d",&n);
	X=(int *)malloc(sizeof(int)*n);
	Y=(int *)malloc(sizeof(int)*n);
	printf("Enter points\n");
	for(i=0;i<n;i++)
		scanf("%d%d",&*(X+i),&*(Y+i));
	printf("Count = %d\n",coverPoints(X,n,Y,n));
	return 0;
}

int coverPoints(int* X,int n1,int* Y,int n2){
	int i;
	int sx,sy,dx,dy;
	int c=0,v=0,z;
	int min,j,k;
	i=0;
	while(i<n1-1){
		sx=*(X+i);
		sy=*(Y+i++);
		z=i;
		min=32767;
		j=i;
		for(;j<n1;j++){
			k=dist(*(Y+j),sy,*(X+j),sx);
			if(k<min){
				min=k;
				z=j;
			}
		}
		swap(X+i,X+z);
		swap(Y+i,Y+z);
		dx=*(X+i);
		dy=*(Y+i);
		while(1){
			if(sx==dx&&sy==dy)
				break;
			if(sx==dx){
				if(dy-sy>0)
					sy++;
				else
					sy--;
				c++;
			}
			else if(sy==dy){
				if(dx-sx>0)
					sx++;
				else
					sx--;
				c++;
			}
			else{
				if(dy-sy>0&&dx-sx>0){
					sx++;
					sy++;
				}
				else if(dy-sy<0&&dx-sx<0){
					sx--;
					sy--;
				}
				else if(dx-sx<0&&dy-sy>0){
					sx--;
					sy++;
				}
				else{
					sx++;
					sy--;
				}
				c++;
			}
		}
	}
	return c;
}

int dist(int y2,int y1,int x2,int x1){
	return (int)sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1)));
}

void swap(int *p1,int *p2){
	int t;
	t=*p1;
	*p1=*p2;
	*p2=t;
}