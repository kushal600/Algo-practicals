// C program for coin change problem.
#include <stdio.h>

// int count(int coins[], int n, int N)
// {
//   int i, j, x, y;

//   // We need sum+1 rows as the table is constructed
//   // in bottom up manner using the base case 0
//   // value case (sum = 0)
//   int table[N + 1][n];

//   // Fill the entries for 0 value case (n = 0)
//   for (i = 0; i < n; i++)
//     table[0][i] = 1;

//   // Fill rest of the table entries in bottom
//   // up manner
//   for (i = 1; i < N + 1; i++)
//   {
//     for (j = 0; j < n; j++)
//     {
//       // Count of solutions including S[j]
//       x = (i - coins[j] >= 0) ? table[i - coins[j]][j]
//                               : 0;

//       // Count of solutions excluding S[j]
//       y = (j >= 1) ? table[i][j - 1] : 0;

//       // total count
//       table[i][j] = x + y;
//     }
//   }

//   return table[N][n - 1];
// }

int NoOfSol(int coins[], int n, int N)
{
  int i, j, x, y;
  int table[N + 1][n];

  for (i = 0; i < n; i++)
  {
    table[0][i] = 1;
  }

  for (i = 1; i < N + 1; i++)
  {
    for (j = 0; j < n; j++)
    {
      x = (i - coins[j] >= 0) ? table[i - coins[j]][j] : 0;
      y = (j >= 1) ? table[i][j - 1] : 0;
      table[i][j] = x + y;
    }
  }
  return table[N][n - 1];
}

// Driver program to test above function
int main()
{
  int coins[] = {1, 2, 4, 5};
  int n = sizeof(coins) / sizeof(coins[0]);
  int N = 7;
  printf(" %d ", NoOfSol(coins, n, N));
  return 0;
}

// void main()
// {
//   int d[] = {1, 2, 3};
//   int N = 4;
//   int n = sizeof(d) / sizeof(int);
//   int c[n][N];
//   // for (int i = 0; i < n; i++)
//   //   c[i][0] = 0;
//   for (int i = 1; i <= n; i++)
//   {
//     for (int j = 0; j <= N; j++)
//     {
//       if (i == 1)
//       {
//         c[i][j] = 1 + c[1][j - d[i]];
//       }
//       else if (j < d[i])
//       {
//         c[i][j] = c[i - 1][j];
//       }
//       else
//       {
//         c[i][j] = fmin(c[i - 1][j], 1 + c[i][j - d[i]]);
//       }
//     }
//   }
//   printf("%d ", c[n - 1][N - 1]);
// }

// #include <stdio.h>
// #include <conio.h>

// int making_change(int[], int, int);
// int min(int, int);
// void main()
// {
//   int l;
//   int amount;
//   printf("Enter number of coins:");
//   scanf("%d", &l);
//   int d[l];
//   for (int i = 0; i < l; i++)
//   {
//     scanf("%d", &d[i]);
//   }
//   printf("Enter amount:");
//   scanf("%d", &amount);
//   printf("Minimum number of coins required to make %d :", amount, making_change(d, l, amount));
// }

// int min(int a, int b)
// {
//   return (a < b ? a : b);
// }
// int making_change(int d[], int l, int a)
// {
//   int dp[l + 1][a + 1];
//   for (int j = 0; j <= a; j++)
//   {
//     dp[0][j] = 0;
//   }
//   for (int i = 1; i <= l; i++)
//   {
//     for (int j = 0; j <= a; j++)
//     {
//       if (i == 1)
//       {
//         dp[i][j] = 1 + dp[1][j - d[i - 1]];
//       }
//       if (j < d[i - 1])
//       {
//         dp[i][j] = dp[i - 1][j];
//       }
//       else
//       {
//         dp[i][j] = min(dp[i - 1][j], dp[i][j - d[i - 1] + 1]);
//       }
//     }
//   }
//   return dp[l][a];
// }