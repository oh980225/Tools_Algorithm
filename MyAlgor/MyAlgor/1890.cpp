#include <stdio.h>

using namespace std;

int n;
int maps[105][105];
int memo[105][105];

int main()
{
    scanf("%d", &n);
    int num;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &maps[i][j]);
        }
    }
    memo[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int curNum = maps[i][j];
            if (memo[i][j] == 0 || (i == n - 1 && j == n - 1))
            {
                continue;
            }
            int newX = i + curNum;
            int newY = j + curNum;
            if (newX < n)
            {
                memo[newX][j] += memo[i][j];
            }
            if (newY < n)
            {
                memo[i][newY] += memo[i][j];
            }
        }
    }

    printf("%d", memo[n - 1][n - 1]);

    return 0;
}