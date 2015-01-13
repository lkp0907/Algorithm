//
//  barn.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 13..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

enum ORDER {
    ASC=1,
    DES,
} ORDER;

int barn[202];
int between[202];
int cow[202];
int panel[202];
int M,S,C;

int front;


void order(int array[],int order){
    int i,j;
    if(order==ASC){
        for (i=1; i<=C; i++) {
            for(j=1;j<=C;j++){
                if(array[i]<array[j]){
                    int temp = array[i];
                    array[i]=array[j];
                    array[j]=temp;
                }
            }
        }
    }else if(order==DES){
        for (i=1; i<=C; i++) {
            for(j=1;j<=C;j++){
                if(array[i]>array[j]){
                    int temp = array[i];
                    array[i]=array[j];
                    array[j]=temp;
                }
            }
        }
    }
}

void getDistance(){
    int i;
    for(i=1;i<C;i++){
        int current = barn[i];
        int next = barn[i+1];
        int rightMin = next-current;
        between[i]=rightMin;
    }
}

int dequeue(){
    return between[front++];
}


int main(void){
    int i,sum=0;
    front =1;
    scanf("%d %d %d",&M,&S,&C);
    for(i=1;i<=C;i++){
        scanf("%d",&barn[i]);
    }
    order(barn,ASC); // 오름차순 정렬 ( 정렬되지 않은 수들이 들어올경우 )
    getDistance(); // 거리구하기 ( 각 소들간의 거리 측정 )
    order(between,DES); // 내림차순 정렬 // 거리를 내림차순으로 정렬 ( 가장 높은 거리가 인덱스가 0 )
    
    sum = barn[C]-barn[1]; // 정렬된 소들의 차는 = 총 거리
    if(M-1>C){
        printf("%d",C); // 널빤지수가 소의 수보다 같거나 많을때.
        return 0;
    }
    
    for(i=0;i<M-1;i++){
        sum -=dequeue(); // 가장 큰거리부터 하나씩 빼서 더함.
    }
    printf("%d",sum+M); // M 개의 널빤지를 넣기때문에 1*M 을 더해줘야함.
    
}
