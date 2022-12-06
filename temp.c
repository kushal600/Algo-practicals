
// void knapsack(int n, float weight[], float profit[], float capacity)
// {
//     float x[20], tp = 0;
//     int i, j, u;
//     u = capacity;

//     for (i = 0; i < n; i++)
//         x[i] = 0.0;

//     for (i = 0; i < n; i++)
//     {
//         if (weight[i] > u)
//             break;
//         else
//         {
//             printf("fwffff");
//             x[i] = 1.0;
//             tp = tp + profit[i];
//             u = u - weight[i];
//         }
//     }

//     if (i < n)
//         x[i] = u / weight[i];

//     tp = tp + (x[i] * profit[i]);

//     printf("\nThe result vector is:- ");
//     for (i = 0; i < n; i++)
//         printf("%f\t", x[i]);

//     printf("\nMaximum profit is:- %f", tp);
// }
// int main()
// {
//     float weight[20], profit[20], capacity;
//     int num, i, j;
//     float ratio[20], temp;

//     printf("\nEnter the no. of objects:- ");
//     scanf("%d", &num);

//     printf("\nEnter the wts and profits of each object:- ");
//     for (i = 0; i < num; i++)
//     {
//         scanf("%f %f", &weight[i], &profit[i]);
//     }

//     printf("\nEnter the capacityacity of knapsack:- ");
//     scanf("%f", &capacity);

//     for (i = 0; i < num; i++)
//     {
//         ratio[i] = profit[i] / weight[i];
//     }

//     for (i = 0; i < num - 1; i++)
//     {
//         for (j = 0; j < num - i - 1; j++)
//         {
//             if (ratio[j] < ratio[j + 1])
//             {
//                 temp = ratio[j];
//                 ratio[j] = ratio[j + 1];
//                 ratio[j + 1] = temp;

//                 temp = weight[j];
//                 weight[j] = weight[j + 1];
//                 weight[j + 1] = temp;

//                 temp = profit[j];
//                 profit[j] = profit[j + 1];
//                 profit[j + 1] = temp;
//             }
//         }
//     }

//     knapsack(num, weight, profit, capacity);
//     return (0);
// }

// /* A Naive recursive implementation of LCS problem */
// #include <stdio.h>
// #include <string.h>
// int max(int a, int b);

// /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
// int lcs(char *X, char *Y, int m, int n)
// {
//   if (m == 0 || n == 0)
//     return 0;
//   if (X[m - 1] == Y[n - 1])
//     return 1 + lcs(X, Y, m - 1, n - 1);
//   else
//     return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
// }

// /* Utility function to get max of 2 integers */
// int max(int a, int b)
// {
//   return (a > b) ? a : b;
// }

// /* Driver program to test above function */
// int main()
// {
//   char X[] = "AGGTAB";
//   char Y[] = "GXTXAYB";

//   int m = strlen(X);
//   int n = strlen(Y);

//   printf("Length of LCS is %d", lcs(X, Y, m, n));

//   return 0;
// }

// The longest common subsequence in C

#include <stdio.h>
#include <string.h>

int i, j, m, n, LCS_table[20][20];
char S1[20] = "ACADB", S2[20] = "CBDA", b[20][20];

void lcsAlgo()
{
    m = strlen(S1);
    n = strlen(S2);

    // Filling 0's in the matrix
    for (i = 0; i <= m; i++)
        LCS_table[i][0] = 0;
    for (i = 0; i <= n; i++)
        LCS_table[0][i] = 0;

    // Building the mtrix in bottom-up way
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            }
            else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
            {
                LCS_table[i][j] = LCS_table[i - 1][j];
            }
            else
            {
                LCS_table[i][j] = LCS_table[i][j - 1];
            }
        }

    int index = LCS_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }

    // Printing the sub sequences
    printf("S1 : %s \nS2 : %s \n", S1, S2);
    printf("LCS: %s", lcsAlgo);
}