#include <stdio.h>
#include <malloc/malloc.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int promising(int i, int col[]);

int estimate_n_queens(int n, int col[]){
    int i,j,z;
    int m ,mprod, numnodes;
    
    int prom_children[n+1];
    
    int index = 0;
    int flag=0;
    
    i=0; numnodes=1; m=1; mprod=1;
    
    while(m!=0 && i!=n){
        mprod = mprod*m;
        numnodes = numnodes + mprod*n;
        i++;
        m=0;
        
        for(z=1;z<=n;z++)
            prom_children[z]=0;
        
        for(j=1; j<=n; j++){
            col[i] = j;
            if(promising(i,col)){
                m++;
                for(z=1; z<=n; z++){
                    if(prom_children[z]==0){
                        prom_children[z]=j;
                        break;
                    }
                }
            }
        }
        if(m!=0){
            for(z=1;z<=n;z++){
                if(prom_children[z]!=0) index++;
            }
            
            srand((unsigned)time(NULL));
            flag = (rand()%index)+1;
            
            j = prom_children[flag];
            
            col[i] = j;
            index=0;
        }
    }
    return numnodes;
}

int promising(int i, int col[]){
    int k;
    int bSwitch;
    
    k=1;
    bSwitch=1;
    
    while(k<i && bSwitch){
        if(col[i] == col[k] || abs(col[i]-col[k])==i-k)
            bSwitch=0;
        k++;
    }
    return bSwitch;
    
}

int main(void){
    int i,n,*col;
    
    int mon[20];
    int avg=0;
    
    printf("N = ?\n");
    scanf("%d",&n);
    getchar();
    
    col = (int *)malloc(sizeof(int)*n);
    for(i = 0;i<20;i++){
        printf("%d : %d\n",i+1,mon[i]=estimate_n_queens(n, col));
        avg+=mon[i];
        sleep(1);
    }
    
    printf("평균값 : %d\n",avg/20);
    
    free(col);
    
    return 0;
}
