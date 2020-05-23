// Graph Coloring

#include <stdio.h>
#include <stdbool.h>

#define N 6         //node count
#define CN 3        //color count R G W

bool W[N+1][N+1] ={
    {0,},
    {0,0,1,0,1,0,0},
    {0,1,0,1,0,1,0},
    {0,0,1,0,0,0,1},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,1},
    {0,0,0,1,0,1,0}};        //weight
char vcolor[N+1];     //visit color
int n;
char RGW[4] = {0,'R','G','W'};

bool promising(int i);
void m_coloring(int i);

int main(int argc, const char * argv[]) {
    vcolor[1] = 1;
    m_coloring(0);
    return 0;
}

bool promising(int i){
    int j = 0;
    bool switchi = true;
    
    while(j<i && switchi){
        if(W[i][j] && vcolor[i] == vcolor[j])
            switchi = false;
        j++;
    }
    
    return switchi;
}

void m_coloring(int i){
    int color;
    
    if(promising(i)){
        if(i==N){
            for(int j=1;j<=N;j++){
                printf("%c ",vcolor[j]);
            }
            printf("\n");
        }
        else
            for(color = 1; color<=CN; color++){
                vcolor[i+1] = RGW[color];
                m_coloring(i+1);
            }
    }
}
