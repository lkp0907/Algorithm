//
//  virus1.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 11..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

#define kMAX_LENGTH 100
int rear=0;
int tail=0;

int virusCount=0;

void enqueue(int queue[],int data){
    queue[tail++]=data;
}
int dequeue(int queue[kMAX_LENGTH]){
    return queue[rear++];
}

int main(void)
{
    int computers,connect;
    int index,j;
    int visitQueue[kMAX_LENGTH+1]={0};
    int virusQueue[kMAX_LENGTH+1]={0};
    int last;
    int table[kMAX_LENGTH+1][kMAX_LENGTH+1]={0};
    
    scanf("%d",&computers);
    scanf("%d",&connect);
    
    enqueue(virusQueue, 1);
    visitQueue[1]=1;
    last = 1;
    
    for (index=0;index<connect;index++){
        int x,y;
        scanf("%d %d",&x,&y);
        table[x][y]=table[y][x]=1;
    }
    while(rear<=tail){
        for (j=1; j<=computers; j++) {
            if(table[last][j]==1&&visitQueue[j]!=1){
                visitQueue[j]=1;
                enqueue(virusQueue, j);
            }
        }
        last = dequeue(virusQueue);
    }
    printf("%d",tail-1);
    return 0;
}