//
//  catalan.c
//  Step1
//
//  Created by GiPyeong Lee on 2015. 1. 8..
//  Copyright (c) 2015년 com.devsfolder.jsonToSQL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct StackNode{
    int data;
    struct StackNode *nextStackNode;
}StackNode;

typedef struct Stack{
    StackNode *list;
    StackNode *top;
}Stack;

// 스택 노드 생성
StackNode *createStackNode(int inputData){
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = inputData;
    node->nextStackNode = NULL;
    return node;
}

// 노드 삽입
void pushNode(Stack* stack,StackNode* node){
    if(stack->list==NULL){
        stack->list = node;
    }else{
        stack->top->nextStackNode = node;
    }
    stack->top = node;
}
// 노드 팝
StackNode* popNode(Stack* stack){
    StackNode *node = stack->top;
    if(stack->list==stack->top){
        stack->list=NULL;
        stack->top= NULL;
    }else{
        StackNode* oldTopNode = stack->list;
        while(oldTopNode->nextStackNode!=stack->top){
            oldTopNode = oldTopNode->nextStackNode;
        }
        stack->top = oldTopNode;
        oldTopNode->nextStackNode = NULL;
    }
    return node;
}

void createStack(Stack **stack){
    (*stack) = (Stack*)malloc(sizeof(Stack));
    (*stack)->list = NULL;
    (*stack)->list = NULL;
}
int main(void){
    Stack *stack;
    createStack(&stack);
    
    Stack *goalStack;
    createStack(&goalStack);
    
    fflush(stdin);
    int i,input;
    scanf("%d",&input);
    int size = input;
    int *intArray = (int *)malloc(sizeof(int)*input);
    for(i=0; i < size; i++){
        scanf("%d", &intArray[i]);
    }

    int index=size;
    while(index-->0){
        int data = intArray[index];
        if(data<size){
            pushNode(stack,createStackNode(data));
        }else{
            size = size-1;
            while(stack->top!=NULL&&size==stack->top->data){
                popNode(stack);
                size = size-1;
            }
        }
    }
    printf("%s",(size==0)?"YES":"NO");
  
    return 0;
}