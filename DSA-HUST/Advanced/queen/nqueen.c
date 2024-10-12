#include <stdio.h>
#include <stdbool.h>

#define N_MAX 20

int count = 0;

bool isSafe(int board[N_MAX][N_MAX], int row, int col, int n) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int board[N_MAX][N_MAX], int col, int n) {
    if (col >= n) {
        count++;
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQueensUtil(board, col + 1, n) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

int solveNQueens(int n, int K, int queens[K][2]) {
    int count = 0; 
    int board[N_MAX][N_MAX];
    
    for (int i = 0; i < N_MAX; i++)
        for (int j = 0; j < N_MAX; j++)
            board[i][j] = 0;

    for (int i = 0; i < K; i++) {
        int row = queens[i][0] - 1;
        int col = queens[i][1] - 1;
        board[row][col] = 1;
    }

    solveNQueensUtil(board, 0, n);

    return count;
}

int main() {
    int n, K;
    scanf("%d", &n);
    scanf("%d", &K);

    int queens[K][2];
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &queens[i][0], &queens[i][1]);
    }

    printf("%d\n", solveNQueens(n, K, queens));

    return 0;
}
