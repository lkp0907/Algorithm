//
//  knapsack.c
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

typedef struct Jewl{
    int weight;
    int left;
    double value; // 가치
    
}Jewl;
Jewl jewl[1001];
int WEIGHT;
int N;
int maxWeight;
double maxValue;

void order(Jewl array[],int order){
    int i,j;
    if(order==ASC){
        for (i=1; i<=N; i++) {
            for(j=1;j<=N;j++){
                
                if(array[i].value*array[j].weight<array[j].value*array[i].weight){
                    Jewl temp = array[i];
                    array[i]=array[j];
                    array[j]=temp;
                }
            }
        }
    }else if(order==DES){
        for (i=1; i<=N; i++) {
            for(j=1;j<=N;j++){
                if(array[i].value*array[j].weight>array[j].value*array[i].weight){
                    Jewl temp = array[i];
                    array[i]=array[j];
                    array[j]=temp;
                }
            }
        }
    }
}


double getJewValue(){
    int i;
    int temp = maxWeight;
    for (i=1; i<=N; i++) {
        if(jewl[i].left==0)
            continue;
        int left = WEIGHT-temp;
        if(jewl[i].weight%left==0){
            if(temp+jewl[i].weight<=WEIGHT)
            {
                maxWeight+=jewl[i].weight;
                jewl[i].left-=jewl[i].weight;
                return jewl[i].value;
            }else{
                maxWeight+=left;
                jewl[i].left-=left;
                return jewl[i].value/left;
            }
        }else{
            if(temp+jewl[i].weight<=WEIGHT)
            {
                maxWeight+=jewl[i].weight;
                jewl[i].left-=jewl[i].weight;
                return jewl[i].value;
            }else{
                break;
            }
        }
    }
    return jewl[N].value;
    //    return jewl[N].value;
}
double getValue(int value,int weight){
    return value%weight==0?value/weight:value;
}

int main(void)
{
    int i=0;
    
    scanf("%d",&WEIGHT);
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        int weight;
        double value;
        scanf("%d %lf",&weight,&value);
        jewl[i].weight = weight;
        jewl[i].left = weight;
        jewl[i].value= value;
    }
    order(jewl, DES);

    for(i=1;i<=N;i++){
        int jewlCnt = jewl[i].weight;
        
        if(jewlCnt+maxWeight>WEIGHT)
            jewlCnt=WEIGHT-maxWeight;
        
        maxValue +=(jewl[i].value/jewl[i].weight)*jewlCnt;
        maxWeight +=jewlCnt;

    }
    printf("%.2f",maxValue);
}