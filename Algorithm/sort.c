//
//  sort.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 12..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//
//

/*
 첫 라인은 정렬할 수의 개수 N (1 <= N <= 1000) 이 입력되고 ,
 다음 줄부터 N 개의 수가 한 줄에 하나씩 1 ,2 ,3 중 하나가 입력된다.
 221333231
 221333231
 */

#include <stdio.h>

int input[1001];
int medal[4];
int N;
int count=0;
void swap(int a,int b){
    int temp = input[a];
    input[a]=input[b];
    input[b]= temp;
}
void orderMedal(int startPoint,int nextPoint,int medalType,int nextMedalType){
    int i,j;
    for(i=startPoint;i<=startPoint+medal[medalType]-1;i++){ // 금,은,동
        if(input[i]==nextMedalType)
        {
            for(j=nextPoint;j<=nextPoint+medal[nextMedalType]-1;j++){ // 은,동,금
                if(input[j]==medalType){
                    swap(i,j);
                    count++;
                    break;
                }
            }
        }
        
    }
}

int main(void){
    //3,2,1,3
    int i;
    scanf("%d",&N); // 메달의 갯수를 받아들인다.
    
    for(i=1;i<=N;i++){
        scanf("%d",&input[i]); // 메달이 무엇인지 입력받음
        medal[input[i]]++; // 각 메달의 갯수
    }
    // 금<->은
    // medal[1] = 금메달 개수
    // 금메달 시작
    orderMedal(1,1+medal[1],1,2);
    
    // 은<->동
    // medal[2] = 은메달 개수
    orderMedal(1+medal[1],1+medal[1]+medal[2],2,3);
    // 금<->동
    // medal[3] = 동메달 개수
    orderMedal(1+medal[1]+medal[2],1,3,1);
    
    
    // 정렬확인 지워줄것
//    for(i=1;i<=N;i++){
//        printf("%d ",input[i]);
//    }
    for (i=1;i<=medal[1];i++)
    {
        if(input[i]!=1){
            count+=2;
        }
    }
    
    printf("\n%d",count);
    return 0;
}
