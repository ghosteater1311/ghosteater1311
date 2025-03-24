#include <stdio.h>

int empty_cells[1000][1000];
int mark_rows[1000][1000] = {0};
int mark_cols[1000][1000] = {0};
int mark_subsquares[1000][1000][1000] = {0};
int board[9][9];
int n_empty = 0;
int count = 0;

int check(int k, int v)
{
    int r = empty_cells[k][0];
    int c = empty_cells[k][1];
    if (mark_rows[r][v] == 1 || mark_cols[c][v] == 1 || mark_subsquares[r/3][c/3][v] == 1)
    {
        return 0;
    }
    return 1;
}

void printSolution()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void input()
{
    int v;

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            scanf("%d", &v);
            board[r][c] = v;
            if (v == 0)
            {
                empty_cells[n_empty][0] = r;
                empty_cells[n_empty][1] = c;
                n_empty++;
            }
            else
            {
                mark_rows[r][v] = 1;
                mark_cols[c][v] = 1;
                mark_subsquares[r/3][c/3][v] = 1;
            }
        }
    }
}

void Try(int k)
{
    int r = empty_cells[k][0];
    int c = empty_cells[k][1];
    
    for (int v = 1; v <= 9; v++)
    {
        if (check(k, v))
        {
            //Assign
            board[r][c] = v;

            //Mark
            mark_rows[r][v] = 1;
            mark_cols[c][v] = 1;
            mark_subsquares[r/3][c/3][v] = 1;

            if (k == n_empty - 1)
            {
                printSolution();
                return;
            }
        }

        else 
        {
            Try(k + 1);
        }
        
        mark_rows[r][v] = 0;
        mark_cols[c][v] = 0;
        mark_subsquares[r/3][c/3][v] = 0;
    }
}

int main()
{
    input();
    Try(1);
    return 0;
}