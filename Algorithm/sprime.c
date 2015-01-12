//
//  sprime.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 12..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

int N;
int degree=0;
int checkPrime(int number){
    int i=0;
    degree++;
    if(degree==N)
        printf("%d",number);
    
    if(number%2==0&&number%5==0)return 0;
    
    for(i=3;i*i<number;i++){
        if(number%i==0)return 0;
    }
    
    return 1;
}
int main(void){
    int j,i=0;
    int max=1;
    scanf("%d",&N); // 자리수 입력
    checkPrime(2);
    checkPrime(3);
    checkPrime(5);
    checkPrime(7);
}