//  travel
#include <stdio.h>

#define N 5
#define INF 1234567
int W[N+1][N+1];
typedef struct pq{
    int level;
    int path[N+1];
    int bound;
}pq;

int length(pq u){
    int totLength=0;
    for(int i=1;i<N;i++){
        totLength += W[u.path[i]][u.path[i+1]];
    }
    totLength+=W[u.path[N]][1];
    
    return totLength;
}
int bound(pq u){
    int result=0;
    int min[N+1]={INF,};
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)continue;
            else
                if(min[i]>W[i][j])
                    min[i]=W[i][j];
        }
        result+=min[i];
    }
    
    return result;
}

int main(int argc, const char * argv[]) {

    return 0;
}
