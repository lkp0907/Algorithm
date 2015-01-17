//
//  lake.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 15..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define kMAX_LENGTH 101

int directList[3] = {0,-1,+1};
int N,M;

char lake[kMAX_LENGTH][kMAX_LENGTH];
int stack[kMAX_LENGTH];
int lakeCount;

void dfs(int x,int y){
    lake[x][y]='.';
    int dx[] = {-1,0,1,-1,1,-1,0,1};
    int dy[] = {1,1,1,0,0,-1,-1,-1};
    for (int i=0; i<8; i++) {
        if(lake[x+dx[i]][y+dy[i]]=='W')
            dfs(x+dx[i],y+dy[i]);
        
    }
}

int main(void){
    int count=0;
    scanf("%d %d",&N,&M);
    for (int i=1; i<=N; i++) {
        char string[kMAX_LENGTH+1];
        scanf("%s",string);
        for (int j=0; j<strlen(string); j++) {
            lake[i][j+1]=string[j];
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            
            if(lake[i][j]=='W'){
                count++;
                dfs(i,j);
            }
        }
    }
    
    printf("%d",count);

}