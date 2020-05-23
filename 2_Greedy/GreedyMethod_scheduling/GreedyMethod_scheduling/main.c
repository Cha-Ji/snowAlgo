//Ex19_ 4.3.1 scheduling [brute force]
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n[4]={7,3,10,5};
    int min=9999;
    int total=0;
    for(int i=0; i<4;i++){
        for(int j=0;j<4;j++){
            if(j==i)continue;
            for(int k=0;k<4;k++){
                if(k==i || k==j)continue;
                for(int m=0;m<4;m++){
                    if(m==i||m==j||m==k)continue;
                    total =3*n[i]+2*n[j]+1*n[k]+n[m];
                    if(total<min)min=total;
                    
                    printf("[%d %d %d %d]\t",i+1,j+1,k+1,m+1);
                    printf("총 소요시간 : %d\n",total);
                }
            }
        }
    }
    printf("최소시간 : %d\n",min);
    
    return 0;
}
