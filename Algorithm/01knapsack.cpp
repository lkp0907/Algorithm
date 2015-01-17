//
//  01knapsack.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 14..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

/*
 첫 줄에는 도둑이 가져갈 수 있는 무게를,
 다음 줄에는 보석의 개수,
 다음 줄 부터는 각 보석의 무게와 값이 한 줄에 하나씩 입력된다.
 */

#include <stdio.h>
#define kMAX_WEIGHT 201
#define kMAX_PRODUCT 101
#define kMAX_TOTAL_WEIGHT 10001


int WEIGHT;
int N; // 도둑이 갖고가는 무게
int J[kMAX_TOTAL_WEIGHT]; // 무게 가치
int BAG[kMAX_PRODUCT][kMAX_TOTAL_WEIGHT];
int max(int x,int y){return x>y?x:y;}

int main(void){
    scanf("%d",&WEIGHT);
    scanf("%d",&N);
    for (int i=1; i<=N;i++) {
        int weight,value;
        scanf("%d %d",&weight,&value);
        // 뒤에서 부터 처리할 경우
        // for(int i=WEIGHT;i>=1;i--)
        // 0보다 작아질수도 있음 i 값이 그로인해 배열이 -1 인덱스를 참조해버리면 죽음
        // 참조이전에 >0 체크 
        
        for (int total_weight=0;total_weight<=WEIGHT;total_weight++) {
        // x 무게까지 보석들을 검색합니다.
            BAG[i][total_weight] = max(BAG[i][total_weight], BAG[i - 1][total_weight]);
        
            if(total_weight<weight) // j가 입력받은 무게보다 작으면 넘기기
                continue;
        
            // 예 : 새로운 15kg 의가치는 이전 10kg 의가치+ 현재 보석 5kg 의 가치와 (이전 15kg 의 가치의 최대값을 비교 하여 큰값으로 바꾸기.
            BAG[i][total_weight] = max(BAG[i][total_weight], BAG[i - 1][total_weight - weight] + value);
        }
        
       BAG[i][weight] = max(BAG[i][weight], value);
    }
    printf("%d",BAG[N][WEIGHT]);

    
}
