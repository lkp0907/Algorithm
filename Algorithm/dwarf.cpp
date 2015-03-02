//
//  dwarf.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 20..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

int dwarf[10];
int nonA;
int nonB;
int main(void){
    int sum=0;
    int i,j;
    for (i=0; i<9; i++) {
        scanf("%d",&dwarf[i]);
        sum +=dwarf[i];
    }
    for (i=0; i<9; i++) {
        for(j=0;j<9;j++){
            if(i==j)
                continue;
            int tempSum=0;
            tempSum+=dwarf[j];
            tempSum+=dwarf[i];
            if(sum-tempSum==100){
                nonA = i;
                nonB = j;
                break;
            }
        }
    }
    for (i=0; i<9; i++) {
        if(i==nonA||i==nonB)
            continue;
        printf("%d\n",dwarf[i]);
    }
}