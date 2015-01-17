//
//  athletic.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 15..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int N;
int count;
char str[15];
void athletic(int win,int lose){

    if(lose >= N)
        return;
    
    if(win >= N)
    {
        count++;
        str[win+lose] = '\0'; // 문자열의 마지막 알려주기 위해서
        printf("%s\n", str);
        return;
    }
    str[win+lose] = 'o';
    athletic(win+1,lose);
    
    str[win+lose] = 'x';
    athletic(win,lose+1);
    
}

int main(void){
    scanf("%d",&N);
    
    athletic(0,0);
    printf("total %d case(s)",count);
    
}