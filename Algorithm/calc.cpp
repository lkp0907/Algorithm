//
//  calc.c
//  Algorithm
//
//  Created by GiPyeong Lee on 2015. 1. 18..
//  Copyright (c) 2015년 com.devsfolder.Algorithm. All rights reserved.
//

/*
 스택은 연산자스택, 숫자 스택 두개가 있음.
 연산자 우선순위가 갖거나 높은것의 경우 스택의 것을 빼고 해당 연산자를 넣는다.
 스택에 연산자 넣을때 연산자 체크할 것.
 숫자들 빈공간 넣어주면서 스택에 쌓아줌.
 여는 괄호를 넣고 닫는 괄호는 넣지 않음. 닫는괄호가 나올경우 여는 괄호까지 팝해서 계산함
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define kMAX_LENGTH 256

char infix[kMAX_LENGTH];
double dStack[kMAX_LENGTH];
int dTop=-1;
char operation[5]={'+','-','/','*','^'};

char cStack[kMAX_LENGTH];
int cTop=-1;


void cPush(char data){
    cStack[++cTop] = data;
}
char cPop(){
    if(cTop>=0)
        return cStack[cTop--];
        
    return -1;
}

void dPush(double data){
    dStack[++dTop]=data;
}
double dPop(){
    if(dTop>=0){
        return dStack[dTop--];
    }
    return -1;
}
bool isDigit(char data){
    int i=0;
    for (i=0; i<5; i++) {
        if(operation[i]==data)
        {
            return false;
        }
    }
    return true;
}

int getPriority(int op){
    switch (op) {
        case '(':
            return 0;
            break;
        case '+':
        case'-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 100;
}

void makePostfix(char *post,const char *mid){
    const char *m=mid;
    char *p=post,c;
    
    while(*m){
        if(isDigit(*m)||*m=='.'){
            *p++=*m++;
            *p++=' ';
        }else{
            if(strchr("^*+-",*m)){
                while(cTop!=-1&&getPriority(cStack[cTop])>=getPriority(*m)){
                    *p++=cPop();
                }
                cPush(*m++);
            }else if(*m=='('){
                cPush(*m++);
            }else if(*m==')'){
                for (;;) {
                    c = cPop();
                    if(c=='(')
                        break;
                    
                    *p++=c;
                }
                m++;
            }else{
                m++;
            }
        }
    }
    while(cTop!=-1){
        *p++=cPop();
    }
    *p=0;

}

double calcPostFix(char* postfix){
    double result = 0;
    double left,right;
    const char *p = postfix;

    while(*p){
        if(isDigit(*p)){
            result = atof(p);
            dPush(result);
            for(;isDigit(*p)||*p=='.';p++){
                printf("%c\n",*p);
                printf("%lf",result);
            };
        }else{
            if(strchr("^*/+-",*p)){
                right = dPop();
                left = dPop();
                switch(*p){
                        case '+':
                        dPush(left+right);
                        break;
                        case '-':
                        dPush(left-right);
                        break;
                        case '*':
                        dPush(left*right);
                        break;
                        case '/':
                        if(right==0.0){
                            dPush(0.0);
                        }else
                            dPush(left/right);
                        break;
                        case '^':
                        dPush(pow(left,right));
                        break;
                }
            }
        }
        
        p++;
    }
    
    if(dTop != -1){
        result=dPop();
    } else {
        result=0.0;
    }
    
    return result;
}

double calcExp(const char *exp,int *bError){
    // 후위식으로 만들 배열
    char post[kMAX_LENGTH];
    const char *p;
    int count;
    
    // 괄호 개수 체크
    for(p=exp,count=0;*p;p++){
        if(*p=='(')count++;
        if(*p==')')count--;
    }
    *bError=(count!=0);
    
    makePostfix(post,exp);
    printf("%s\n",post);
    return calcPostFix(post);
}

int main(void){
    int i;
    
    char exp[256];
    int bError;
    double result;
    char *p = strchr("^*/+-", NULL);
    strcpy(exp,"2+3*4");
    printf("%s=%.2f\n",exp,calcExp(exp,&bError));
    
//    scanf("%s",infix);
//    for (i=0;i<strlen(infix);i++){
//        
//    }
    return 0;
}