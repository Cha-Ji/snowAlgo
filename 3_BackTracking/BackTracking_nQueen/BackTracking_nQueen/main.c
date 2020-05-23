// BackTracking
// n_queens Algorithm
#define N 8
#include <stdbool.h>
#include <stdio.h>

void printSolution(int board[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col){
    int i, j;
    
    // Check row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    
    // Check upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    
    // Check lower diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    
    return true;
}

bool solveNQUtil(int board[N][N], int col){
    if (col >= N)
        return true;
    
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {    //is safe?
            board[i][col] = 1;
            
            if (solveNQUtil(board, col + 1))
                return true;
            
            board[i][col] = 0; // BACKTRACK
            printf("%d,%d에서 backtrack \n",i+1,col+1);
        }
    }
    
    return false;   //cannot place this col
}

int main(){
    int board[N][N] = {0,};
    
    if (!solveNQUtil(board, 0)) {
        printf("해답이 없습니다.");
        return 0;
    }
    
    printSolution(board);
    return 0;
}
