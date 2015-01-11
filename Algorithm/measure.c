//
//  measure.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 11..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
/*
 첫째 줄에 줄자의 길이가 입력된다. 줄자의 길이는 10 cm 이상 1,000 cm 이하이고 단위를 나타내는 cm은 입력되지 않는다.
 둘째 줄에는 두 빨간 점의 위치를 나타내는 정수가 빈칸을 사이에 두고 입력된다.
 셋째 줄에는 두 파란 점의 위치가,
 넷째 줄에는 두 노란 점의 위치를 나타내는 정수가 빈칸을 사이에 두고 입력된다.
 */
typedef struct Dot{
    float x;
    float y;
}Dot;
Dot dots[2000];
int measure[11];
float left=0;
float startPoint=0;
float endPoint;
float midPoint=0;
float distance=0;
void leftFolding(int index){
    int i=0;
    for (i = index; i < 3; i++)
    {
        Dot pin= dots[i];
        float pointX;
        float pointY;
        if(pin.x>midPoint)
            pointX=midPoint-(pin.x-midPoint);
        else
            pointX=pin.x;
        
        if(pin.y>midPoint)
            pointY=midPoint-(pin.y-midPoint);
        else
            pointY=pin.y;
        // 중간점 안쪽에 있던 녀석들은점 이동 시켜줘야함
        
        if(pointX>=pointY){
            pin.x= pointY;
            pin.y= pointX;
        }
        else{
            pin.x= pointX;
            pin.y= pointY;
        }
        
        dots[i]=pin;
    }
}
void rightFolding(int index){
    int i=0;
    for (i = index+1; i < 3; i++)
    {
        Dot pin= dots[i];
        float pointX;
        float pointY;
        if(pin.x<midPoint)
            pointX=midPoint+(midPoint-pin.x);
        else
            pointX=pin.x;
        
        if(pin.y<midPoint)
            pointY=midPoint+(midPoint-pin.y);
        else
            pointY=pin.y;
        // 중간점 안쪽에 있던 녀석들은점 이동 시켜줘야함
        
        if(pointX>=pointY){
            pin.x= pointY;
            pin.y= pointX;
        }
        else{
            pin.x= pointX;
            pin.y= pointY;
        }
        dots[i]=pin;
    }
}

float mid(float x,float y){
    return (x+y)/2;
}

void folding(int index){
    if(dots[index].x==dots[index].y)
        return;
    
    midPoint = mid(dots[index].x,dots[index].y); // 두 점사이의 중점
    
    if(endPoint-midPoint<midPoint-startPoint)
    {
        endPoint=midPoint; // 우측에서 좌측으로 접음
        leftFolding(index);
    }else if(endPoint-midPoint>=midPoint-startPoint){
        startPoint = midPoint; //좌측에서 우측으로 접음
        rightFolding(index);	
    }
    distance = endPoint-startPoint;
    
}

int main(void){
    int index;
    int i,j;
    
    scanf("%f",&endPoint);
    
    for(index=0;index<3;index++){
        Dot dot;
        float x,y;
        scanf("%f %f",&x,&y);
        if(x>y){
            dot.x=y;
            dot.y=x;
        }else{
            dot.x=x;
            dot.y=y;
        }
        dots[index]=dot;
    }
    //RED
    folding(0);
    folding(1);
    folding(2);
    
    printf("%.1f",distance);
    return 0;
}
