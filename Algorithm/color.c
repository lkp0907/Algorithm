//
//  color.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 20..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//
// top,bottom,left,right 의 인덱스가 생김
//
#include <stdio.h>
#define kMAX_LENGTH 129
int T;
int map[kMAX_LENGTH][kMAX_LENGTH];
int bucket[2];
void detect(int left,int right,int bottom,int top){
    int i,j;
    int mcol,mrow;
    int sum=0;
    for (i=left; i<=right; i++) {
        for(j=bottom;j<=top;j++){
            if(map[i][j]==1)
                sum++;
        }
    }
    if(sum==(right-left+1)*(top-bottom+1)){
        bucket[1]=bucket[1]+1;
        return;
    }
    else if(sum==0){
        bucket[0]=bucket[0]+1;
        return;
    }
    if(left<right){

        mcol = (right+left)/2;
        mrow = (top+bottom)/2;

        detect(left, mcol, bottom, mrow); // 좌상
        detect(mcol+1, right, bottom, mrow); //우상
        detect(left, mcol, mrow+1, top);//좌하
        detect(mcol+1, right, mrow+1,top);//우하
        
    }
    
}
int main(void){
    int i,j,input;
    scanf("%d\n",&T);
    
    for(i=1;i<=T;i++){
        for(j=1;j<=T;j++){
            scanf("%d",&input);
            map[i][j] = input;
        }
    }
    detect(1,T,1,T);
    
    printf("%d\n",bucket[0]);
    printf("%d",bucket[1]);
    
    
    return 0;
}

