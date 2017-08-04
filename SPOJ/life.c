#include<stdio.h>
int main(){
	int a[100],i;
	for(i=0;i<100;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<100;i++){
		if(a[i]!=42)
			printf("%d\n",a[i]);
		else
			break;
	}
	return 0;
}
