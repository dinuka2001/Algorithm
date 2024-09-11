#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// find longest common subsequence using memoization method
int LCS(char str1[], char str2[], int m, int n)
{

    //create mattrix
    int mattrix[m + 1][n + 1];
    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            mattrix[i][j] = -1;
        }
    }
    //basecase
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (mattrix[m][n] != -1)
    {
        return mattrix[m][n];
    }
    if (str1[m] == str2[n])
    {
        return mattrix[m][n] = 1 + LCS(str1, str2, m - 1, n - 1);
    }
    else
    {
        return mattrix[m][n] = max(LCS(str1, str2, m - 1, n), LCS(str1, str2, m, n - 1));
    }
}

int main()
{

    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";

    int m = strlen(str1);
    int n = strlen(str2);

    int lcsLength = LCS(str1, str2, m, n);

    printf("Length of Longest Common Subsequence: %d\n", lcsLength);


    return 0;
}