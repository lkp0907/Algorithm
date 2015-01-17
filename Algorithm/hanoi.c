//
//  hanoi.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 15..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

int N;
int T[4][11];

int harnoi(int T[4][N]){
    
    return 0;
}

int main(void){
    int i;
    scanf("%d",&N); // N 개의 접시를 받습니다.
    
    for (i=1; i<=N; i++) {
        T[1][i]=i;
    }
    
    printf("%d",harnoi(T));
    
    return 0;
}