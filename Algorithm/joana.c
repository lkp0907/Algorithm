//
//  joana.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 17..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

void sumX(int x,double *sum)
{
    if(x<1)
        return;
    *sum+=x;
    sumX((x-2),sum);
}

int main(void)
{
    int N;
    double basicNumber=0;
    double lastNumber=0;
    double result=0;
    scanf("%d",&N);
    sumX(N,&basicNumber);
    lastNumber = basicNumber*2-1;
    result =3*lastNumber-6;
    printf("%.0lf",result);
    return 0;
}