//
//  dfs.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 12..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//
/*
 입력의 첫째 줄에는 정점의 수와 시작정점의 번호가 입력되고, 다음 부터는 정점의 쌍으로 간선(edge)을 표현한다.
 
 정점 수는 최대 10 개이고 , 1 부터 순차적으로 번호가 부여되어 있다.
 
 입력의 끝은 EOF 이다.
 
 */

#include <stdio.h>

int N,S; // 정점의 갯수, 시작점
int edge[11][11];
int visitStack[11];
int x,y;

void dfs(int startPoint){
    int i;
    for (i=1;i<=N;i++)
    {
        if(edge[startPoint][i]==1&&visitStack[i]!=1){
            visitStack[i] = 1;
            printf("%d ",i);
            edge[startPoint][i]=edge[i][startPoint]=0;
            dfs(i);
        }
    }
}

int main(void){
    scanf("%d %d",&N,&S);
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        edge[x][y]=edge[y][x]=1;
    }
    printf("%d ",S);
    visitStack[S]=1;
    dfs(S);
    
    return 0;
}
