#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// find longest common subsequence using memoization method
int LCS(char str1[], char str2[], int m, int n)
{

    //create mattrix and initialize with -1
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
    //if value is already calculated then return it
    if (mattrix[m][n] != -1)//is [m][n] have some value?
    {
        return mattrix[m][n];
    }
    //if last character of the substring is same?  then add 1 and call LCS for m-1 and n-1
    if (str1[m] == str2[n])
    {
        return mattrix[m][n] = 1 + LCS(str1, str2, m - 1, n - 1);
    }
    //if last character of the substring is not same? then get max of LCS for m-1 and & LCS for m and n-1
    else
    {
        return mattrix[m][n] = max(LCS(str1, str2, m - 1, n), LCS(str1, str2, m, n - 1));
    }
}

int main()
{
    //declare two strings with default values
    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";

    //take input from user
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    //get length of the strings
    int m = strlen(str1);
    int n = strlen(str2);

    //call LCS function
    int lcsLength = LCS(str1, str2, m, n);

    //print the length of the longest common subsequence
    printf("Length of Longest Common Subsequence: %d\n", lcsLength);


    return 0;
}