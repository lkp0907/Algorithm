//
//  bsearch.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 11..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

int numbers[500000];

int main(void){
    int input;
    int index;
    int searchNumber;
    int isExist=0;
    scanf("%d",&input);
    for (index = 0; index < input; index++)
    {
        scanf("%d",&numbers[index]);
    }
    scanf("%d",&searchNumber);
    for (index=0;index<input;index++){
        if(numbers[index]==searchNumber)
        {
            isExist=1;
            printf("%d",index+1);
            break;
        }
    }
    
    if(!isExist)printf("not found");
    
    return 0;
}