#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void calc(long h,long a);

int main()
{
    long **arr;
    int tc,i=0;
    printf("Enter the number of test cases: ");
    scanf("%d",&tc);
    arr=(long **)malloc(sizeof(long *)*tc);
    *(arr+0)=(long *)malloc(sizeof(long)*2);
    *(arr+1)=(long *)malloc(sizeof(long)*2);
    while(i<tc)
    {
        printf("Enter the hypotaneous and area: ");
        scanf("%ld%ld",&*(*(arr+i)+0),&*(*(arr+i)+1));
        i++;
    }
    i=0;
    while(i<tc)
    {
        calc(*(*(arr+i)+0),*(*(arr+i)+1));
        i++;
    }
    return 0;
}

void calc(long h,long a)
{
    long ar[3];
    float b1,p1,sq;
    ar[0]=pow(h,2);
    ar[1]=pow(ar[0],2);
    ar[2]=16*pow(a,2);
    if((ar[1]-ar[2])<0)
        printf("-1\n");
    else if((ar[1]-ar[2])==0)
    {
        b1=(2*ar[0])/2;
        b1=sqrt(b1);
        p1=(2*a)/b1;
        if(b1>=p1)
            printf("%0.6f %0.6f %0.6f\n",p1,b1,h);
        else
            printf("%0.6f %0.6f %0.6f\n",b1,p1,h);
    }
    else
    {
        sq=sqrt(ar[1]-ar[2]);
        if(sq<ar[0])
        {
            b1=(ar[0]+sq)/2;
            b1=sqrt(b1);
            p1=(2*a)/b1;
            if(b1>=p1)
                printf("%0.6f %0.6f %0.6f\n",p1,b1,h);
            else
                printf("%0.6f %0.6f %0.6f\n",b1,p1,h);
        }
        else if(sq==ar[0])
        {
            b1=(2*ar[0])/2;
            b1=sqrt(b1);
            p1=(2*a)/b1;
            if(b1>=p1)
                printf("%0.6f %0.6f %0.6f\n",p1,b1,h);
            else
                printf("%0.6f %0.6f %0.6f\n",b1,p1,h);
        }
    }
}
