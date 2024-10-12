#include <stdio.h>
#include <stdlib.h>

typedef struct location{
    int row;
    int column;
}location;

location locate[81];
int sudoku[9][9], count=0, result=0;

int check(int i, int k){
    int startRow = 3 * (locate[k].row / 3);
    int startColumn = 3 * (locate[k].column / 3);
    for (int j = 0; j < 9; j++)
    {
        if (i == sudoku[j][locate[k].column]) return 0;
        if (i == sudoku[locate[k].row][j]) return 0;
        if (i == sudoku[startRow + (j / 3)][startColumn + (j % 3)]) return 0;
    }
    return 1;
}

void Try(int k)
{
    for (int i = 1;i <= 9; i++)
    {
        if (check(i, k)){
            sudoku[locate[k].row][locate[k].column] = i;
            if (k == count - 1) result++;
            else Try(k + 1);
            sudoku[locate[k].row][locate[k].column] = 0;
        }
    }
}

int main()
{
   for (int i = 0; i < 9; i++)
   {
    for (int j = 0; j < 9; j++)
    {
        scanf("%d", &sudoku[i][j]);
        if (sudoku[i][j] == 0)
        {
            locate[count].row = i;
            locate[count].column = j;
            count++;
        }
    }
   }
   Try(0);
   printf("%d", result);
}