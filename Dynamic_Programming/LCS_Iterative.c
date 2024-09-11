#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

char *LCS_iterative(char str1[], char str2[])
{
    int m = strlen(str1);
    int n = strlen(str2);

    int mattrix[m + 1][n + 1];
    int direction_mattrix[m + 1][n + 1];
    
    // initialize mattrix and direction_mattrix with 0
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            mattrix[i][j] = 0;
            direction_mattrix[i][j] = 0;
        }
    }

    // Fill the matrices based on the comparison of str1 and str2
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                mattrix[i][j] = 1 + mattrix[i - 1][j - 1];
                direction_mattrix[i][j] = 1; // 1 for diagonal
            }
            else
            {
                if (mattrix[i - 1][j] > mattrix[i][j - 1])
                {
                    mattrix[i][j] = mattrix[i - 1][j];
                    direction_mattrix[i][j] = 2; // 2 for up
                }
                else
                {
                    mattrix[i][j] = mattrix[i][j - 1];
                    direction_mattrix[i][j] = 3; // 3 for left
                }
            }
        }
    }

    // Allocate memory for the LCS string
    static char lcs_string[100];
    int index = mattrix[m][n]; // length of the LCS
    lcs_string[index] = '\0';  // Null-terminate the string

    // Find the LCS string by tracing back the direction matrix
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (direction_mattrix[i][j] == 1) // diagonal, characters matched
        {
            lcs_string[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (direction_mattrix[i][j] == 2) // up
        {
            i--;
        }
        else // left
        {
            j--;
        }
    }

    return lcs_string;
}

int main()
{
    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";

    char *lcs_string = LCS_iterative(str1, str2);
    printf("Longest common subsequence is %s\n", lcs_string);

    return 0;
}
