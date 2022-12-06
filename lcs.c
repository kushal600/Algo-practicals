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

// int i, j, m, n, LCS_table[20][20];
// char S1[20] = "ACADB", S2[20] = "CBDA", b[20][20];

// void lcsAlgo()
// {
//   m = strlen(S1);
//   n = strlen(S2);

//   // Filling 0's in the matrix
//   for (i = 0; i <= m; i++)
//     LCS_table[i][0] = 0;
//   for (i = 0; i <= n; i++)
//     LCS_table[0][i] = 0;

//   // Building the mtrix in bottom-up way
//   for (i = 1; i <= m; i++)
//     for (j = 1; j <= n; j++)
//     {
//       if (S1[i - 1] == S2[j - 1])
//       {
//         LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
//       }
//       else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
//       {
//         LCS_table[i][j] = LCS_table[i - 1][j];
//       }
//       else
//       {
//         LCS_table[i][j] = LCS_table[i][j - 1];
//       }
//     }

//   int index = LCS_table[m][n];
//   char lcsAlgo[index + 1];
//   lcsAlgo[index] = '\0';

//   int i = m, j = n;
//   while (i > 0 && j > 0)
//   {
//     if (S1[i - 1] == S2[j - 1])
//     {
//       lcsAlgo[index - 1] = S1[i - 1];
//       i--;
//       j--;
//       index--;
//     }

//     else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
//       i--;
//     else
//       j--;
//   }

//   // Printing the sub sequences
//   printf("S1 : %s \nS2 : %s \n", S1, S2);
//   printf("LCS: %s", lcsAlgo);
// }

char S1[20] = "ABBABABA";
char S2[20] = "BABAABAAB";
int table[20][20], i, j, m, n;

void lcsAlgo()
{
  m = strlen(S1);
  n = strlen(S2);
  for (i = 0; i <= m; i++)
  {
    table[i][0] = 0;
  }
  for (j = 0; j <= n; j++)
  {
    table[0][j] = 0;
  }

  for (i = 1; i <= m; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (S1[i - 1] == S2[j - 1])
      {
        table[i][j] = 1 + table[i - 1][j - 1];
      }
      else if (table[i - 1][j] >= table[i][j - 1])
      {
        table[i][j] = table[i - 1][j];
      }
      else
      {
        table[i][j] = table[i][j - 1];
      }
    }
  }

  int index = table[m][n];
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

    else if (table[i - 1][j] >= table[i][j - 1])
      i--;
    else
      j--;
  }

  // Printing the sub sequences
  printf("S1 : %s \nS2 : %s \n", S1, S2);
  printf("LCS: %s", lcsAlgo);
}

int main()
{
  lcsAlgo();
  printf("\n");
}
