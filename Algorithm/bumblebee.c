//
//  bumblebee.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 17..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int a,b,x,l;
    float time,distance;
    scanf("%d %d %d %d",&a,&b,&x,&l);
    time = (float)l/(a+b);
    distance= time*x;
    printf("%.6f",distance);
    return 0;
}