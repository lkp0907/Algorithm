//
//  even.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 16..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main(void)
{
    double a,b;
    scanf("%lf %lf",&a,&b);
    double sqrtB=sqrt(b);
    double sqrtA=sqrt(a);
    sqrtA = sqrtA==(int)sqrtA?sqrtA:sqrtA+1;
    double result = b-(int)(sqrtB)-(a-(int)sqrtA);
    printf("%.0lf",result);
    
    return 0;
}