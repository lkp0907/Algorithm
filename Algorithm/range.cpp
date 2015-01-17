//
//  range.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 14..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
#include<string.h>
int N;
char string[251];
int range[251][251];
int square[251][251];
int result[251];
int min(int x,int y){
    return x>y?y:x;
}
int main(void)
{
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++){
        scanf("%s",string);
        for (int j = 1; j <=strlen(string); j++)
        {
            range[i][j]=string[j-1]-48;
        }
    }


    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(range[i][j]==0)
                continue;

            int length = min(square[i-1][j],square[i][j-1]); // 최소값
            if(range[i-length][j-length]==1)
                length++;
            
            square[i][j]=length;
            
            for(int k=2;k<=square[i][j];k++){
                result[k]++;
            }
            
            
        }
    }

    int isZero=true;
    for (int i=2;i<=N; i++) {
        if(result[i]!=0){
            printf("%d %d\n",i,result[i]);
            isZero = false;
        }
    }
    if(isZero)
        printf("0");

    return 0;
}

