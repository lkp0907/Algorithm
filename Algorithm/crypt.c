//
//  crypt.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 11..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char bigKey[124];
char smallKey[124];
char text[80];
// 97~ 122 : 26
//
int main(void)
{
    int i=0;
    for (i=0; i<26; i++) {
        char letter;
        scanf("%c",&letter);
        smallKey[97+i]=letter;
        bigKey[65+i]=(char)((int)letter-32);
    }
    getchar();
    gets(text);
    
    for (i=0; i<strlen(text); i++) {
        if(text[i]==' ')
        {
            printf(" ");
            continue;
        }
        if((int)text[i]<97){
            // 대문자
            printf("%c",bigKey[(int)text[i]]);
        }
        else{
            // 소문자
             printf("%c",smallKey[(int)text[i]]);
            
        }
        
    }
}