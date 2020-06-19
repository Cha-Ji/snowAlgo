//  01KnapSack_BackTrack
#include <stdio.h>
#include <stdbool.h>
    
#define W 9     //아이템의 총 무게 합
#define N 5     //아이템의 총 개수

int maxprofit,numbest,bestset[N+1],include[N+1];
int p[N+1] = {0,20,30,35,12,3}; //각 아이템의 가치
int w[N+1] = {0,2,5,7,3,1};     //각 아이템의 무게

void knapsack(int i, int profit, int weight);
bool promising(int i, int profit, int weight);

int main() {
    //초기화
    numbest=0;
    maxprofit=0;
    knapsack(0, 0, 0);  //i번째 아이템, 현재 가지의 이익과 무게
    
    //출력
    for(int i=1;i<=N;i++){
        printf("%d : ",i);
        if(bestset[i]==1)
            printf("포함\n");
        else
            printf("미포함\n");
    }
    return 0;
}

void knapsack(int i,int profit, int weight){
    
    /* 총 무게를 넘지않고, 이익이 maxprofit을 넘는다면
     최적의 조합(bestset)을 지금의 가지로 갱신한다.*/
    if(weight <= W && profit > maxprofit){
        maxprofit = profit;
        numbest = i;
        for(int j=1;j<=N;j++){
            bestset[j]=include[j];
        }
    }
    
    /* 가지가 유망하다면 자식가지를 포함시키고,
        유망하지 않다면 가지치기하고 진행한다.*/
    if(promising(i,profit,weight)){
        include[i+1] = true;    //include tree
        knapsack(i+1, profit+p[i+1], weight+w[i+1]);
        include[i+1] = false;   //not include tree
        knapsack(i+1, profit, weight);
    }
}

bool promising(int i, int profit, int weight){
    int totweight;  //가치가 상한일 때의 무게
    float bound;    //상한
    
    //무게가 수용할 수 있는 무게보다 크다면 유망하지 않다.
    if(weight >= W)
        return false;
    else{
        int j = i+1;
        bound = profit;
        totweight = weight;
        
        //무게가 최대가 될 때까지의 상한을 계산한다.
        while(j<= N && totweight + w[j] <= W){
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }
        int k = j;
        
        /*무게가 꽉 찼을 때 ,나머지 공간을
        배낭 가득채우기처럼 계산하고 상한을 계산한다.*/
        if(k<=N)
            bound += (W-totweight)*p[k]/w[k];
        
        return bound>maxprofit; //상한이 maxprofit을 넘지 못하면 유망하지 않다.
    }
    
}
