#include<stdio.h>

#define INF 123456
int R[5][5];

void print_root(int i, int j){
    int cur_root = R[i][j];
    if(i<=cur_root-1)
        print_root(i, cur_root-1);
    if(cur_root+1<=j)
        print_root(cur_root+1, j);
    
    printf("(%d, %d)의 루트 : %d\n", i, j, cur_root);
}

int main(){
    int n = 4;
    double p[4] = {0.2, 0.3, 0.1, 0.4};
    
    double A[8][8];
    double w[8][8];
    
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j = i+l-1;
            A[i][j] = INF;
            w[i][j] = w[i][j-1]+p[j];
            for(int r=i;r<=j;r++){
                double t = A[i][r-1]+A[r+1][j]+w[i][j];
                if(t<A[i][j]){
                    A[i][j] = t;
                    R[i][j] = r;
                }
                
            }
        }
    }
    print_root(1, n);
    
}


