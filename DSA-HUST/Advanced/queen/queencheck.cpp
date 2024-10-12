//C 
#include <stdio.h>

int isAttacked(int **board, int N) 
{
    for (int i = 0; i < N; i++) 
    {
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < N; j++) 
        {
            row_sum += board[i][j];
            col_sum += board[j][i];
        }
        if (row_sum > 1 || col_sum > 1)
            return 1;
    }
    for (int k = 0; k < 2 * N - 1; k++) 
    {
        int diag_sum1 = 0;
        int diag_sum2 = 0;
        for (int i = 0; i < N; i++) 
        {
            int j = k - i;
            if (j >= 0 && j < N) 
            {
                diag_sum1 += board[i][j];
            }
            j = (N - 1) - (k - i);
            if (j >= 0 && j < N) 
            {
                diag_sum2 += board[i][j];
            }
        }
        if (diag_sum1 > 1 || diag_sum2 > 1)
            return 1;
    }
    return 0;
}

int main() 
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int **board;
        board = new int*[N];
        for (int i = 0; i < N; i++) 
        {
            board[i] = new int[N];
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &board[i][j]);
            }
        }
        int result = isAttacked(board, N);
        printf("%d\n", !result);
        for (int i = 0; i < N; i++) 
        {
            delete[] board[i];
        }
        delete[] board;
    }
    return 0;
}
