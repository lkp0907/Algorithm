//
//  BRACKETS2.c
//  Step1
//
//  Created by GiPyeong Lee on 2015. 1. 7..
//  Copyright (c) 2015년 com.devsfolder.jsonToSQL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct charNode{
    char letter;
    struct charNode* nextNode;
}charNode;

typedef struct charStack{
    charNode *list;
    charNode *top;
}charStack;

typedef struct Node{
    char *string;
    struct Node* nextNode;
}Node;

typedef struct Stack{
    Node *list;
    Node *top;
}Stack;

charNode* createNode(char let){
    charNode* node = (charNode *)malloc(sizeof(charNode));
    node->letter = let;
    node->nextNode = NULL;
    return node;
}

void createStack(charStack **stack){
    (*stack) = (charStack *)malloc(sizeof(charStack));
    (*stack)->list=NULL;
    (*stack)->top=NULL;
}
void appendNode(charStack *stack,charNode *node){
    if(stack->list==NULL){
        stack->list = node;
    }else{
        charNode *topNode = stack->top;
        topNode->nextNode = node;
    }
    
    stack->top = node;
}
void popNode(charStack *stack){
    if(stack->list==stack->top){
        stack->list=NULL;
        stack->top=NULL;
    }else{
        charNode *currentTop = stack->list;
        while(currentTop!=NULL&&currentTop->nextNode!=stack->top){
            currentTop = currentTop->nextNode;
        }
        stack->top = currentTop;
        free(currentTop->nextNode);
    }
}

const char* isRightSentence(char *string){
    int isRight=1;
    charStack *stack;
    createStack(&stack);
    int i=0;
    for (i=0; i<strlen(string); i++) {
        char temp = string[i];
        if(temp==40||temp==123||temp==91){
            charNode*newNode = createNode(string[i]);
            appendNode(stack, newNode);
        }else{
            if(stack->top==NULL){
                isRight=0;
                break;
            }
            if(temp==')'&&stack->top->letter!='('){
                isRight = 0;
                break;
            }
            else if(temp=='}'&&stack->top->letter!='{'){
                isRight = 0;
                break;
            }else if(temp==']'&&stack->top->letter!='['){
                isRight = 0;
                break;
            }
            else{
                popNode(stack);
            }
        }
    }
    if(stack->top!=NULL){
        isRight=0;
        while(stack->top!=NULL){
            popNode(stack);
        }
    }
    free(stack);
    return (isRight==1)?"YES":"NO";
}
void appendNode(Stack *stack,Node *node){
    if(stack->list==NULL){
        stack->list = node;
    }else{
        Node *topNode = stack->top;
        topNode->nextNode = node;
    }
    
    stack->top = node;
}
Node *createNode(char *string){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->string = (char *)malloc(sizeof(char)*strlen(string)+1);
    strcpy(newNode->string,string);
    newNode->nextNode = NULL;
    return newNode;
}
void createStackList(Stack **stack){
    
    (*stack) = (Stack*)malloc(sizeof(Stack));
    (*stack)->list=NULL;
    (*stack)->top= NULL;
}

int main(void){
    int capacity;
    scanf("%d",&capacity);
    Stack *stackList;
    createStackList(&stackList);
    
    for(int i=0;i<capacity;i++){
        char inputChar[10000];
        scanf("%s",inputChar);
        appendNode(stackList,createNode(inputChar));
    }
    
    Node* head = stackList->list;
    while(head!=NULL){
        printf("%s\n",isRightSentence(head->string));
        head = head->nextNode;
    }
    free(stackList);
    return 0;
}