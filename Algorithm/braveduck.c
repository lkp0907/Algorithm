//
//  braveduck.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 11..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define kMAX_LENGTH 100

typedef struct dot{
    int x;
    int y;
}Dot;
Dot dots[kMAX_LENGTH +2];
int visit[kMAX_LENGTH + 2];

void isExist(int node,int N,int J){
    int i;
    for (i=1; i<=N+1; i++) {
        if(visit[i]==0&&(dots[i].x-dots[node].x)*(dots[i].x-dots[node].x)+(dots[i].y-dots[node].y)*(dots[i].y-dots[node].y)<=J*J){
            visit[i]=1;
            isExist(i,N,J);
        }
    }
    
}

int main(void){
    int T,J,N;
    int i,j,k=0;
    
    scanf("%d",&T);
    
    for (i=0; i<T; i++) {
        // 시작점,끝점 받기
        scanf("%d",&J);
        scanf("%d%d%d%d",&dots[0].x,&dots[0].y,&dots[1].x,&dots[1].y);
        scanf("%d",&N);
        for (j=2; j<=N+1; j++) {
            scanf("%d %d",&dots[j].x,&dots[j].y);
        }
        visit[0]=1;
        isExist(0,N,J);
        for(k=1;k<N+2;k++){
            if(visit[k]!=1)
            {
                printf("NO\n");
                break;
            }
            else{
                printf("YES\n");
                break;
            }
        }
        memset(dots,0,sizeof(dots));
        memset(visit,0,sizeof(visit));
    }
    
    return 0;
}