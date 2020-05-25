//  01KnapSack_BackTrack
#include <stdio.h>
#include <stdbool.h>

#define W 9
#define N 5

int maxprofit,numbest,bestset[N+1],include[N+1];
int p[N+1] = {0,20,30,35,12,3};
int w[N+1] = {0,2,5,7,3,1};

void knapsack(int i, int profit, int weight);
bool promising(int i, int profit, int weight);

int main(int argc, const char * argv[]) {
    numbest=0;
    maxprofit=0;
    knapsack(0, 0, 0);
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
    if(weight <= W && profit > maxprofit){
        maxprofit = profit;
        numbest = i;
        for(int j=1;j<=N;j++){
            bestset[j]=include[j];
        }
    }
    if(promising(i,profit,weight)){
        include[i+1] = true;    //include tree
        knapsack(i+1, profit+p[i+1], weight+w[i+1]);
        include[i+1] = false;   //not include tree
        knapsack(i+1, profit, weight);
    }
}

bool promising(int i, int profit, int weight){
    int totweight;
    float bound;
    
    if(weight >= W)
        return false;
    else{
        int j = i+1;
        bound = profit;
        totweight = weight;
        while(j<= N && totweight + w[j] <= W){
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }
        int k = j;
        if(k<=N)
            bound += (W-totweight)*p[k]/w[k];
        return bound>maxprofit;
    }
    
}
