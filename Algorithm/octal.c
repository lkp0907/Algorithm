//
//  octal.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 11..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
char octal[102];
char octalTable[2][2][2];
void createOctalTable(){
    int i,j,k;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                octalTable[i][j][k]=48+i*2*2+j*2+k;
            }
        }
    }
}

int main(void){
    int addIndex;
    int index;
    int innerIndex;
    int tableIndex;
    createOctalTable();
    gets(octal);
    addIndex = 3-strlen(octal)%3;
    if(addIndex!=0){
        for (index=(int)strlen(octal); index>=0; index--) {
            octal[index+addIndex]=octal[index];
        }
        for (index=0;index<addIndex; index++) {
            octal[index]='0';
        }
    }
    
    for(index=0;index<strlen(octal);){
        printf("%c",octalTable[(int)octal[index]-48][(int)octal[index+1]-48][(int)octal[index+2]-48]);
        index= index+3;
    }
    return 0;
}