//
//  catch_cow.c
//  Step1
//
//  Created by GiPyeong Lee on 2015. 1. 8..
//  Copyright (c) 2015년 com.devsfolder.jsonToSQL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int intTable[200000];
static int count=0;
typedef struct Node{
    struct Node *next;
    int depth;
    int data;
}Node;
typedef struct Stack{
    struct Node *list;
    struct Node *top;
}Stack;

void createStack(Stack** stack){
    (*stack) = (Stack*)malloc(sizeof(Stack));
    (*stack)->list = NULL;
    (*stack)->top = NULL;
}

int isExist(int data){
    int i=0;
    for (i=0;i<count;i++) {
        if(data==intTable[i]){
            return 1;
        }
    }
    intTable[count] = data;;
    count++;
    return 0;
}

Node *createNode(int data,int depth){
    if(isExist(data))
        return NULL;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->depth = depth+1;
    newNode->next = NULL;
    
    return newNode;
}
void pushNode(Stack* stack,Node *node){
    if(node==NULL)
        return;
    
    if(stack->list==NULL){
        stack->list= node;
    }
    else{
        Node *top = stack->top;
        top->next = node;
    }
    while(node->next!=NULL){
        node = node->next;
    }
    stack->top = node;
}

int main(void){

    Stack *stack;
    createStack(&stack);
    int n,k;
    int count=0;
    scanf("%d %d",&n,&k);
    
    pushNode(stack, createNode(n,-1));

    Node *searchPoint = stack->list;
    while(n!=k){
        if(k<n){
            n--;
            count++;
        }
        else if(k-n>0){
            // *2 , +1 , -1
            while(searchPoint!=NULL){
                if(searchPoint->data==k){
                    count = searchPoint->depth;
                    n=k;
                    break;
                }
                if(searchPoint->data*2<=k+1&&searchPoint->data*2<=131072){
                    pushNode(stack,createNode(searchPoint->data*2, searchPoint->depth));
                }
                if(searchPoint->data-1>=0&&searchPoint->data-1<=131072)
                    pushNode(stack,createNode(searchPoint->data-1, searchPoint->depth));

                if(searchPoint->data+1<=131072)
                    pushNode(stack,createNode(searchPoint->data+1, searchPoint->depth));

                searchPoint = searchPoint->next;
                
                
            }
        }
        
        if(k==n)
            break;
    }
    //1000 8888
    printf("%d",count);
    return 0;
}