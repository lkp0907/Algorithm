//
//  maze.cpp
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 21..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//
// maze by DFS
// DFS 로 문제 풀기

#include <stdio.h>

#define kMAX_LENGTH 21

int X, Y;
int Min = 999;
char MAP[kMAX_LENGTH][kMAX_LENGTH];
int VISIT[kMAX_LENGTH][kMAX_LENGTH];
int direct[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
void searchPath(int x, int y, int depth){
    int i;
    if (x<0 || y<0 || x >= X || y >= Y) // 맵 벗어날때.
        return;
    
    if (y == 0 && x == X-1){
        if (depth < Min){
            Min = depth;
            return;
        }
    }
    for (i = 0; i < 4; i++)
    {
        int dX = x + direct[i][0];
        int dY = y + direct[i][1];
        
        if (VISIT[dX][dY] == 0 &&MAP[dX][dY] == '0'){
            
            VISIT[dX][dY] = 1;
            searchPath(dX, dY, depth+1);
            VISIT[dX][dY] = 0;
        }
    }
}

void input(){
    int i;
    scanf("%d %d", &X, &Y);
    for (i = 0; i<Y; i++) {
        scanf("%s", MAP[i]);
    }
}

int main(void)
{
    input();
    searchPath(0, Y-1, 1);
    printf("%d", Min);
    return 0;
    
}