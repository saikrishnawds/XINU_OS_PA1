#include<stdio.h>
#include "math.h"
#define RANDMAX 32767
double pow(double base, int rad)
{
    int i;
    double power = 1;
    if(rad < 0)
    {
        rad = -1*rad;
        for(i=0; i<rad; i++)
        {
            power = base*power;
        }
        power = 1/power;
    }
    else
    {
        for(i=0; i<rad; i++)
        {
            power = base*power;
        }
    }
    return power;
}

double log(double x)
{
    int i;
    double sum = 0;
    double power;
    for(i=1;i<20;i++)
    {
        power = pow(-1,(i+1));
        sum = sum + (power)*(pow((x-1),i)/i);
    }
    return sum;
}

double expdev(double lambda)
{
    double dummy;
    do
    {
        dummy = (double) rand() /RANDMAX ;
    }
    while(dummy == 0.0);
    return (-log(dummy)/lambda);
}
