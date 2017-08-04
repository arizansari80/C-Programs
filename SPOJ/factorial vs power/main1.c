#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned int calculator(unsigned int a,unsigned int n);
double calc(unsigned int a,unsigned int n);
unsigned int * range(unsigned int a,double res2,int n);

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
    double res1,res2,tempd;
    unsigned int m,*arr;
    res2=calc(a,n);
    arr=(unsigned int *)malloc(sizeof(unsigned int)*2);
    arr=range(a,res2,n);
    m=*(arr+0);
    n=*(arr+1);
    free(arr);
    res1=calc(a,m);
    res2=calc(a,n);
    while(n-m>1)
    {
        tempd=calc(a,(m+n)/2);
            if(tempd>0){
                n=(m+n)/2;
                continue;
            }
            m=(m+n)/2;
        /*else
            if(tempd>0)
            {
                m=(m+n)/2;
                res1=tempd;
            }
            else
            {
                n=(m+n)/2;
                res2=tempd;
            }*/
    }
    return n;
}

double calc(unsigned int a,unsigned int n)
{
    double d,c=0.91895385332;
    d=((n+0.5)*log(n))-(n*log(a))-n+c;
    return d;
}

unsigned int * range(unsigned int a,double res2,int n)
{
    unsigned int *m;
    m=(unsigned int *)malloc(sizeof(unsigned int)*2);
    *(m+0)=n/2;
    *(m+1)=n;
    while(res2<0)
    {
        *(m+0)=*(m+1);
        *(m+1)*=2;
        res2=calc(a,*(m+1));
    }
    return m;
}

