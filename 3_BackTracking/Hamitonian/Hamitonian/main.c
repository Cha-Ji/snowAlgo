//  Hamitonian

#include <stdio.h>
#include <stdbool.h>
#define N 12

bool W[N+1][N+1]={
    {0,},
    {0,0,1,0,0,1,0,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,1,1,0,0,0,0},
    {0,0,1,0,1,0,0,0,1,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,1,0,0,0},
    {0,1,0,0,0,0,1,0,0,0,1,0,0},
    {0,0,0,0,0,1,0,1,0,0,0,1,0},
    {0,0,1,0,0,0,1,0,1,0,0,0,0},
    {0,0,1,1,0,0,0,1,0,1,0,0,0},
    {0,0,0,0,1,0,0,0,1,0,0,0,1},
    {0,0,0,0,0,1,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,1,0,0,0,1,0,1},
    {0,0,0,0,0,0,0,0,0,1,0,1,0}
};
int vindex[N];

void hamitonian(int i);
bool promising(int i);

int main(void) {
    hamitonian(0);
    int asdf;
    scanf("%d",&asdf);
    return 0;
}

void hamitonian(int i){
    int j;
    
    if(promising(i)){
        if(i==N-1){
            for(int index=0;index<=N-1;index++)
                printf("%d ",vindex[index]);
            printf("\n");
        }
        else
            for(j=2;j<=N;j++){
                vindex[i+1]=j;
                hamitonian(i+1);
            }
    }
}

bool promising(int i){
    int j;
    bool switchi;
    
    if(i==N-1 && !W[vindex[N-1]][vindex[0]])    //첫 정점과 마지막 정점은 연결되어야 한다.
        switchi = false;
    else if(i>0 && !W[vindex[i-1]][vindex[i]])  //i번째와 i-1번째는 연결되어야 한다.
        switchi = false;
    else{
        switchi = true;
        j = 1;
        while (j<i && switchi){
            if(vindex[i] == vindex[j])          // 이미 선택된 정점인지
                switchi = false;
            j++;
        }
    }
    return switchi;
}
