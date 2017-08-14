#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int square_root(int d);
double funct(double xn,int d);

int main()
{
    int d;
    printf("Enter any number: ");
    scanf("%d",&d);
    printf("The Square Root of Number %d is %d",d,square_root(d));
    printf("\n");
    return 0;
}

int square_root(int d)
{
    double xn=d/2,xn1;
    xn1=funct(xn,d);
    while(xn-xn1>0.0000000000000001)
    {
        xn=xn1;
        xn1=funct(xn,d);
    }
    return floor(xn1);
}

double funct(double xn,int d)
{
    return xn-(((xn*xn)-d)/(2*xn));
}
