//
//  pat.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 15..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

int N;
int K;
char store[31];
void bitPattern(int bitCnt,int length){
    if(bitCnt>K)
        return;
    
    if(length==N){
        if(bitCnt==K){
            store[length]='\0';
            printf("%s\n",store);
        }
        return;
    }
    store[length]='1';
    bitPattern(bitCnt+1,length+1);
    
    store[length]='0';
    bitPattern(bitCnt,length+1);
    
}

int main(void){
    scanf("%d %d",&N,&K);
    bitPattern(0,0);
    return 0;
}