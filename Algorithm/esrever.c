//
//  esrever.c
//  Dovelet
//
//  Created by GiPyeong Lee on 2015. 1. 10..
//  Copyright (c) 2015년 com.devsfolder.Dovelet. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(void)
{
    // ' ' 32
    // '.' 46
    // ' ' 일 경우 단어 분리됨
    // ' '
    // 01234567890123
    // I like spring.
    // I ekil .gnirps
    // 0,0 s=e
    // 0,1 e=s+
    // (1-1),0> e->i
    // 2,2 i = l
    // 2,6 e = l
    // (6-1),2 > e->i
    // 7,7 i=e
    // 7,len
    
    int n;

    char input[81];
    int startIndex=0;
    int endIndex=0;
    int firstIndex=0;
    int position=0;
    memcpy(input," ", 81);
    gets(input);
    n = (int)strlen(input);
    for (startIndex=0; startIndex<n;startIndex++) {
        if(input[startIndex]==' '||startIndex==n-1){
            firstIndex=position;
            endIndex = startIndex;
            for(;endIndex>=firstIndex;endIndex--){
                if(input[endIndex]!=' ')
                    printf("%c",input[endIndex]);
                position++;
            }
            printf(" ");
        }
        
        
    }
    return 0;
}
