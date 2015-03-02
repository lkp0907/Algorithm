//
//  dam.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 11..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

// BFS 를 이용하여 해결해보자. Queue 구현
/*
 입력
 
 첫 줄에는 배열의 크기인 T(1 ≤ T ≤100)가 주어지고
 다음 줄부터 배열의 값이 주어진다. 0은 텅 빈 길, 1은 건물이다. (물은 건물을 뒤덮지 못한다고 가정한다.)
 그리고 그 다음 줄에는 호수의 좌표 x, y가 주어지고,
 다음 줄에는 댐이 지어지는 시간인 K가 주어진다.
 */
#include <stdio.h>

int T; // 배열 크기
int dam[101][101]; //댐
int startPoint,endPoint;
int K;
int count;

int front;
int tail;
int queue[101*101][2];

void enqueue(int a,int b){
    queue[tail][0]=a;
    queue[tail][1]=b;
    tail++; // 큐 추가
}

void dequeue(int &a,int &b){
    a = queue[front][0];
    b = queue[front][1]; // 큐빼내기
    front++;
}

void checkDam(){
    int x,y,i;
    int direction[4][2] = {{ 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 }};
    dam[startPoint][endPoint]=1;
    enqueue(startPoint,endPoint);
    while(front<=tail){
        dequeue(x, y);
        
        for (i=0; i<4; i++) {
            int newX =x+direction[i][0];
            int newY =y+direction[i][1];
            if(newX>=1 && newY>=1 && newX<=T && newY<=T){
                if(dam[newX][newY]==0){
                    dam[newX][newY] = dam[x][y]+1;
                    enqueue(newX, newY);
                }
            }
        }
    }
    
    for (int i=1; i<=T; i++) {
        for (int j=1; j<=T; j++) {
            if(dam[i][j]==K+1){
                count++;
            }
        }
      
    }
}

int main(void){
    int i,j;
    scanf("%d",&T);
    for (i=1; i<=T; i++) {
        for (j=1; j<=T; j++) {
            scanf("%d",&dam[j][i]);
            dam[j][i] = dam[j][i]==1?-1:dam[j][i];
        }
    }
    scanf("%d %d",&startPoint,&endPoint);
    scanf("%d",&K);
    count= 0;
    checkDam();
   
    if(count==0)
        printf("OH, MY GOD");
    else{
        
        printf("%d",count);
    }
    
    return 0;
}