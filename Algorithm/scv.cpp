//
//  scv.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 14..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

int N;
int map[101][101];
int mineral[101][101];
int main(void)
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&map[i][j]);
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j]==0){
                map[i-1][j]>map[i][j-1]?map[i][j]=map[i-1][j]:map[i][j]=map[i][j-1];
            }
            else if(map[i][j]>=1){
                map[i-1][j]>map[i][j-1]?map[i][j]=map[i-1][j]:map[i][j]=map[i][j-1];
                map[i][j]+=1;
            }
            mineral[i][j] = map[i][j];
        }
    }

    printf("%d",mineral[N][N]);
    
    return 0;
}