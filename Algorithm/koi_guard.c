//
//  koi_guard.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 20..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>

int map[101][101];

int X,Y;
int N;
int myX,myY;
int ABS(int x)
{
    return x>0?x:-1*x;
}
int minX(int x,int x2){
    int left = (ABS(0-x)+ABS(0-x2));
    int right =(ABS(X-x)+ABS(X-x2));
    
    return left<right?left:right;
}
int minY(int y,int y2){
    int left = (ABS(0-y)+ABS(0-y2));
    int right =(ABS(Y-y)+ABS(Y-y2));
    
    return left<right?left:right;
}
void realPosition(int *x,int *y){
    switch (*x) {
        case 1: //북쪽
            *x=0;
            break;
        case 2: // 남쪽
            *x=Y;
            break;
        case 3: // 서쪽
            *x=*y;
            *y=0;
            break;
        case 4: // 동쪽
            *x=*y;
            *y=X;
            break;
        default:
            break;
    }
}
int main(void)
{
    scanf("%d %d",&X,&Y);
    scanf("%d",&N);
    for (int i=0;i<=N; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        realPosition(&x, &y);
        if(i<N)
            map[y][x]=1;
        else{
            myX=y;
            myY=x;
        }

    }
    int sum=0;
    for(int i=0;i<=Y;i++){
        for(int j=0;j<=X;j++){
            if(map[j][i]==1){
                if(ABS(myY-i)==Y){
                    //  남북으로 나와 마주보는 상점
                    sum+=minX(myX, j);
                    sum+=Y;
                }
                else if(ABS(myX-j)==X){
                    //동서로 나와 마주보는 상점
                    sum+=minY(myY, i);
                    sum+=X;
                }
                else{
                    //내쪽, 동,서 쪽에 있는 모든 상점들.
                    sum+=(ABS(j-myX)+ABS(myY-i));
                }
            }
           
        }
    }
    printf("%d\n",sum);
    return 0;
}