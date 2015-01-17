//
//  coci_intersect.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 16..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

/*
 조합에대한 문제이다.
 nC4
 */
#include <stdio.h>
int N;

int main(void){
    scanf("%d",&N);
    int result = N*(N-1)*(N-2)*(N-3)/24; // 다른 기법 없이 그져 공식 대입처리.
    printf("%d",result);
    
    return 0;
}