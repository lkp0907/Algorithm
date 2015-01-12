//
//  postorder.c
//  Dovelet
//
//  Created by GiPyeong Lee on 2015. 1. 10..
//  Copyright (c) 2015년 com.devsfolder.Dovelet. All rights reserved.
//

#include <stdio.h>

#define kMAX_LENGTH 20
int tree[kMAX_LENGTH*2+1];

void preOrder(int node){
    int newNode;
    scanf("%d",&newNode);
    tree[node*2]=newNode;
    
    if(newNode!=-1){
        preOrder(node*2);
    }
    scanf("%d",&newNode);
    tree[node*2+1]=newNode;
    if(newNode!=-1){
        preOrder(node*2+1);
    }
}

void postOrder(int node){
    if(tree[node]==-1)
        return;
    
    postOrder(node*2);
    postOrder(node*2+1);
    printf("%d ",tree[node]);
    
}

int main(void){
    int root;
    scanf("%d",&root);
    tree[1]=root;
    preOrder(1);
    postOrder(1);
    return 0;
}
