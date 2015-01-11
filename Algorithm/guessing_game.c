//
//  guessing_game.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 11..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
const char* high = "too high";
const char* low = "too low";
const char* right = "right on";
char stanTalk[9];
int max = 0;
int min = 0;
int flag =0;
void outputFlag(char talk[],int input){
    int length = strlen(talk);
    int last = length;
    int highFlag=0;
    int lowFlag=0;
    int rightFlag=0;
    while(length--){
        if(talk[length]==high[length])
        {
            highFlag++;
        }
        if(talk[length]==low[length])
        {
            lowFlag++;
        }
        if(talk[length]==right[length])
        {
            rightFlag++;
        }
    }
    if(highFlag==last){
        max = input;
    }else if(lowFlag==last){
        min = input;
    }else if(rightFlag==last){
        flag=-1;
        if(input<max||input>min)
        {
                        printf("Stan may be honest");
        }
        else{
            printf("Stan is dishonest");
        }

        
    }
}
int main(void){
    
    while(flag>-1){
        int input;
        scanf("%d",&input);
        scanf("%s",stanTalk);
        outputFlag(stanTalk, input);
    }
}