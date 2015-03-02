//
//  mt.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 27..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
int N;
int check=0;
void mt(int num){
    if(num==0){
        return;
    }
    printf("%d",num);
    if(num==N){
        check=1;
        mt(num-1);
        return;
    }
    if(check==0)
        mt(num+1);
    else{
        mt(num-1);
    }
    
}

int main(void)
{
    scanf("%d",&N);
    mt(1);
    return 0;
}