//
//  euler.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 21..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//
// 문제가 별로 안좋음
// 오일러 공식을 알아야함 
//

#include <stdio.h>

#define kMAX_LENGTH 101

int N,E; // N : 노드 수, E : 간선 수
int total; // 이어야할 간선 수
int edge[kMAX_LENGTH][kMAX_LENGTH];
int edgeStack[kMAX_LENGTH*20];
int edgeCount[kMAX_LENGTH];
int beginPoint;

bool dfs_euler(int point){
    
    int k;
    edgeStack[total]=point;
    if(total==0){
        return true;
    }else{
        for (k=1;k<=N; k++) {
            
            if(edge[point][k]!=0){
                
                edge[point][k]=0;
                edge[k][point]=0;
                total--; // 간선을 지나서
                
                if(dfs_euler(k))
                    return true; // 다음 간선 체크

                // 간선 빠져나온후에는 원상복귀 시켜주자
                edge[point][k]=1;
                edge[k][point]=1;
                total++;
            }
        }
        
        
    }
    return false;
}

int main(void){
    int i=0;
    int x=0,y=0;
    scanf("%d %d",&N,&E);
    for (i=0; i<E; i++) {
        scanf("%d %d",&x,&y);
        edge[x][y]=edge[y][x]=1;
        edgeCount[x]++;
        edgeCount[y]++;
    }
    for (i=1; i<=N; i++) {
        total = E;
        beginPoint=i;
        if(N>3){
            if(edgeCount[i]%2==1){
                if(dfs_euler(i))
                    break;
            }
        }
        else{
            if(dfs_euler(i))
                break;
        }
    }
    for (i=E; i>=0; i--) {
        printf("%d ",edgeStack[i]);
    }
    return 0;
}