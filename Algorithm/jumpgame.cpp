//
//  jumpgame.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 23..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

#define kMAX_LENGTH 101
#define kMAX_ANSWER 51
int map[kMAX_LENGTH][kMAX_LENGTH];
int visit[kMAX_LENGTH][kMAX_LENGTH]; // 거쳤던 노드
int N;
int answer[kMAX_ANSWER];
void clearVisit(){
    for (int i=1; i<=N; i++) {
        for (int j=1 ; j<=N; j++) {
            visit[i][j]=0;
            map[i][j]=0;
        }
    }
}
void findGoal(int x,int y){
    
    if(visit[x][y]==1) // 방문했던 노드면 리턴
        return;
    
    if(x>N||y>N||x<1||y<1) // 판 밖으로 빠져나가면 리턴
        return;
    visit[x][y]=1;
    if(x==N&&y==N){
        return;
    }
    
 
    findGoal(x,y+map[x][y]);
    findGoal(x+map[x][y],y);
}

int main(void){

    int C;
    scanf("%d",&C);
    for (int i=0; i<C; i++) {
        clearVisit();
        scanf("%d",&N);
        for (int j=1; j<=N; j++) {
            for (int k=1; k<=N; k++) {
                scanf("%d",&map[j][k]);
            }
        }
        findGoal(1,1);
        if(visit[N][N]==1)
            answer[i]=1;
        else
            answer[i]=0;
    }

    for (int i=0; i<C; i++) {
        if(answer[i]==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    

}
