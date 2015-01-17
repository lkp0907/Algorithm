#include <stdio.h>
#define kMAX_LENGTH 50
int N;
int P[kMAX_LENGTH+1][kMAX_LENGTH+1];

int main(void){
    
    scanf("%d",&N);
    
    for (int i=1; i<=N; i++) {
        P[i][i]=1;
        P[i][0]+=P[i][i];
        for (int j=1; j<=i/2; j++) {
            for(int k=j;k<=i-j;k++){
                P[i][j] =P[i][j]+P[i-j][k];
            }
            P[i][0] = P[i][0]+P[i][j];
        }
    }
    
    printf("%d",P[N][0]);
    return 0;
}