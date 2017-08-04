#include<stdio.h>

int main(){
	int n,sum=0,m;
	scanf("%d",&n);
	if(n%2==0)
		m=n/2;
	else
		m=n/2+1;
	sum=(m*(m-1))/2;
	for(int i=1;i<=n/2;i++)
		sum+=n%i;
	int res=n*n-sum;
	return 0;
}