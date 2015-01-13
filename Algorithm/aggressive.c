//
//  aggressive.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 12..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

/*
 첫 줄에는 두 정수 N , C 가 주어진다.
 다음 N 줄에는 xi 가 주어진다.
 1 이되면 싸움.
 
 */
#include <stdio.h>

#define abs(value) value>0?value:value*-1


int N,C;
int cage[100001];
int min;
int visit[100001];

void swap(int *x,int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}

int getPivot(int x,int y){
    return ((x+y)/2);
}

void quick_sort(int left,int right,int mid){
    
}

int main(void)
{
    int i,j,k=0;
    int index;
    int x,y,z;
    scanf("%d %d",&N,&C);
    for(i=1;i<=N;i++){
        scanf("%d",&index);
        cage[i]=index;
    }
    quick_sort(1,N);
    for (i=1;i<=N; i++) {
        printf("%d ",cage[i]);
    }

//    for(i=1;i<=N;i++){
//        x=cage[i];
//        for (j=1;j<=N;j++)
//        {
//            if(cage[j]>x+1){
//                y=cage[j];
//                for(k=1;k<=N;k++){
//                    if(cage[k]>y&&cage[k]>x){
//                        int temp;
//                        z=cage[k];
//                        if(y-x==1||z-y==1)
//                            continue;
//                        
//                        temp = y-x<z-y?y-x:z-y;
//                        
//                        if(temp>min)
//                            printf("%d %d %d\n",x,y,z);
//                        min=temp;
//                    }
//                }
//            }
//        }
//    }
    //printf("%d",min);
    return 0;
}
