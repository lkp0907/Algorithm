//
//  ENCRYPT.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 3. 2..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int T; // 테스트 케이스 개수
char originalString[101]; // 100개의 문자열
char cryptString[101];
// HelloWorld = 10 / 5
void initString(){

}
int main(){
    int index;
    int strIndex,maxLength;
    int midIndex;
    scanf("%d",&T);
    for(index=0;index<T;index++){
        int cryptIndex=0;
        memset(originalString,0, strlen(originalString));
        memset(cryptString,0, strlen(cryptString));
        scanf("%s",originalString);
        maxLength = (int)strlen(originalString);
        
        if(maxLength%2==0)
            midIndex = maxLength/2;
        else
            midIndex = maxLength/2+1;
        
        for (strIndex=0; strIndex<maxLength; strIndex++) {
            if(strIndex%2==0){
                cryptString[cryptIndex++]=originalString[strIndex];
            }else{
                // 1
                cryptString[midIndex+cryptIndex-1] = originalString[strIndex];
            }
        }
        printf("%s\n",cryptString);
    }
    
    return 0;
}