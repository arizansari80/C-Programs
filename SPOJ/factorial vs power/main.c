#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned int calculator(unsigned int a,unsigned int n);
double calc(unsigned int a,unsigned int n);

int main(void)
{
    unsigned int r,*arr;
    int tc,i=0;
    scanf("%d",&tc);
    arr=(unsigned int *)malloc(sizeof(unsigned int)*tc);
    while(i<tc)
        scanf("%d",&*(arr+i++));
    i=0;
    while(i<tc)
    {
        if(*(arr+i)==2)
            printf("4\n");
        else
        {
            r=calculator(*(arr+i),2*(*(arr+i)));
            printf("%d\n",r);
        }
        i++;
    }
    return 0;
}

unsigned int calculator(unsigned int a,unsigned int n)
{
    double tempd;
    unsigned int m;
    m=n;
    n=2*n;
    while(n-m>1)
    {
        tempd=calc(a,(m+n)/2);
            if(tempd>0){
                n=(m+n)/2;
                continue;
            }
            m=(m+n)/2;
    }
    return n;
}

double calc(unsigned int a,unsigned int n)
{
    double d,c=0.91895385332;
    d=((n+0.5)*log(n))-(n*log(a))-n+c;
    return d;
}
