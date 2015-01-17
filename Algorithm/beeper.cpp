//
//  beeper.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 13..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

typedef struct Dot{
    int isExit;
    int weight;
    int isVisit;
}Dot;

Dot table[21][21];
int N;
int sizeX,sizeY;
int startPointX,startPointY;
int totalPath;
int ABS(int x,int y){
    return x-y>0?(x-y):(x-y)*-1;
}



// 경로찾기 - Back Tracking ????

void searchPath(int x,int y){

    for(int i=1;i<=sizeX;i++){
        for(int j=1;j<=sizeY;j++)
        {
            if(i==x&&j==y)
                continue;
            
            if(table[i][j].isExit==1&&table[i][j].isVisit!=1){
                // 점들 시작
                table[i][j].isVisit=1; // 되찾은 무전기 표시
                table[i][j].weight += (table[x][y].weight+ABS(x,i)+ABS(y,j));
                printf("%d",table[i][j].weight);
                searchPath(i, j);
                // 다음경로
            }
        }
    }

}

int main(void){
    // 좌표평면계 받기 알아내기
    scanf("%d %d",&sizeX,&sizeY);
    scanf("%d %d",&startPointX,&startPointY);
    table[startPointX][startPointY].isExit=1;
    // 점들 받기.
    scanf("%d",&N);
    for (int i=2;i<=N+1;i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        table[x][y].isExit=1;
    }

    table[startPointX][startPointY].isVisit=1; // 되찾은 무전기 표시
    table[startPointX][startPointY].weight =0;
    // 각점들에 대한 최단거리.
    searchPath(startPointX,startPointY);
    
    printf("finish");
}