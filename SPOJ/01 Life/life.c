#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	srand(time(NULL));
	int a[100],i;
	for(i=0;i<100;i++)
		a[i]=rand()%100;
	i=0;
	while(a[i]!=42&&i<100)
		printf("%d\n",a[i++]);
	return 0;
}
