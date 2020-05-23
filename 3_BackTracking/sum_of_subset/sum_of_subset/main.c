#include <stdio.h>
#include <malloc/malloc.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define N 7
int timer = 0;

int w[N] = { 0, 2, 10, 13, 17, 22, 42 };
int W = 52;

bool promising(int i, int weight, int total) {
    return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}

int estimate_sum_of_subset(int n, int weight, int total) {
    int i = 0, j = 0;
    int m = 1, mprod = 1, numnodes = 1;
    int prom_children[N + 1];
    
    while (m != 0 && i != n) {
        mprod = mprod * m;
        numnodes = numnodes + mprod * n;
        i++;
        m = 0;
        
        for (int z = 0; z <= n; z++)
            prom_children[z] = 0;
        
        weight += j;
        total -= w[i];
        
        if (promising(i, weight + w[i], total)) {
            m++;
            prom_children[1] = w[i];
        }
        if (promising(i, weight, total)) {
            m++;
            prom_children[2] = 0;
        }
        
        if (m != 0) {
            srand((unsigned int)time(NULL) + (timer++ * 1000));
            int flag = (rand() % 2) + 1;
            j = prom_children[flag];
        }
    }
    return numnodes;
}

int main(void) {
    int mon[20];
    int avg = 0;
    int total = 0;
    
    for (int i = 1; i <= N; i++) {
        total += w[i];
    }
    
    for (int i = 0; i < 20; i++) {
        printf("%d.\t  %d\n", i + 1, mon[i] = estimate_sum_of_subset(N, 0, total));
        avg += mon[i];
        sleep(1);
    }
    
    printf("평균값 : %d\n", avg / 20);
    
    return 0;
}
