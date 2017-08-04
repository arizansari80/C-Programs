#include<stdio.h>
#include<stdlib.h>

double square_root(double d);
double funct(double xn,double d);

int main()
{
    double d;
    printf("Enter any number: ");
    scanf("%lf",&d);
    printf("The Square Root of Number %f is %0.16lf",d,square_root(d));
    return 0;
}

double square_root(double d)
{
    double xn=d/2,xn1;
    xn1=funct(xn,d);
    //printf("xn=%f xn1=%f xn1-xn=%f\n",xn,xn1,xn1-xn);
    int i=0;
    while(xn-xn1>0.0000000000000001)
    {
        //printf("In While\n");
        xn=xn1;
        xn1=funct(xn,d);
        //printf("xn=%f xn1=%f xn1-xn=%f\n",xn,xn1,xn1-xn);
        i++;
    }
    printf("The Number of Iteration is %d\n",i);
    return xn1;
}

double funct(double xn,double d)
{
    return xn-(((xn*xn)-d)/(2*xn));
}
