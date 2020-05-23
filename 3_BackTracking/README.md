> 인접한 지역이 다른 색이 되게 색칠하는 방법

```c
// Graph Coloring

#include <stdio.h>
#include <stdbool.h>

#define N 6         //node count
#define CN 3        //color count B G W

bool W[N+1][N+1] ={
    {0,},
    {0,0,1,0,1,0,0},
    {0,1,0,1,0,1,0},
    {0,0,1,0,0,0,1},
    {0,1,0,0,0,1,0},
    {0,0,1,0,1,0,1},
    {0,0,0,1,0,1,0}};        //weight
int vcolor[N+1];     //visit color
int n;

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
                printf("%d ",vcolor[j]);
            }
            printf("\n");
        }
        else
            for(color = 1; color<=CN; color++){
                vcolor[i+1] = color;
                m_coloring(i+1);
            }
    }
}
```

## Planar Graph

> 평면 상에서 이음선들이 서로 엇갈리지 않게 그릴 수 있는 그래프

- promising : 연결이 되어있는가 && 색깔이 같은가

## Hamiltonian Circuits

> 일주여행경로, 한 정점에서 출발하여 그래프 상의 각 정점을 한번씩 경유하여 시작점으로 돌아오는 경로

- 한붓그리기 느낌
- 시간복잡도가 지수를 넘어가지만 몬테칼로 기법으로 분석하면 쓸모있는 알고리즘

## 배낭채우기 문제

> 상태공간 트리로 해결

- promising : weight < W, 유망함은 더 팽챙해야 함을 의미한다.
- bound : 남은 가방 공간에 덩이를 잘라서 넣는다고 생각한다. (상한 : 꽉채우기)
- bound ≤ maxprofit 이면 유망하지 않다.
