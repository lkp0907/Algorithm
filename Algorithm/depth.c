//
//  postorder.c
//  Dovelet
//
//  Created by GiPyeong Lee on 2015. 1. 10..
//  Copyright (c) 2015년 com.devsfolder.Dovelet. All rights reserved.
//

#include <stdio.h>

#define kMAX_DEPTH 1024

int tree[kMAX_DEPTH*2+1];
int Depth=0;
int degree=0;

void preOrder(int node,int depth){
	int input;
	int isDegree=-1;
	depth+=1;
	if(Depth<depth)
		Depth=depth;

	scanf("%d",&input);

	if(input!=-1){
		isDegree+=1;
		preOrder(node*2,depth);
	}

	scanf("%d",&input);
	
	if(input!=-1){
		isDegree+=1;
		preOrder(node*2+1,depth);
		
	}
	if(isDegree==1)
		degree++;
}

int main(void){
	int input;
	scanf("%d",&input);
	tree[1]=input;
	preOrder(1,Depth);
	printf("%d\n%d",degree,Depth);
	return 0;
}
