#include <stdio.h>
#include <math.h>
// int max(int a, int b) { return (a > b) ? a : b; }
// int knapsack(int N, int wt[], int val[], int n)
// {
//   int i, w;
//   int K[n + 1][N + 1];

//   // Build table K[][] in bottom up manner
//   for (i = 0; i <= n; i++)
//   {
//     for (w = 0; w <= N; w++)
//     {
//       if (i == 0 || w == 0)
//         K[i][w] = 0;
//       else if (wt[i - 1] <= w)
//         K[i][w] = fmax(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
//       else
//         K[i][w] = K[i - 1][w];
//     }
//   }

//   return K[n][N];
// }

int knapsack(int wt[], int val[], int N, int n)
{
  int k[n + 1][N + 1];
  int i, w;
  for (i = 0; i <= n; i++)
  {
    for (w = 0; w <= N; w++)
    {
      if (i == 0 || w == 0)
      {
        k[i][w] = 0;
      }
      else if (wt[i - 1] <= w)
      {
        k[i][w] = fmax(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
      }
      else

        k[i][w] = k[i - 1][w];
    }
  }
  return k[n][N];
}

int main()
{
  int val[] = {3, 4, 5, 6};
  int wt[] = {2, 3, 4, 5};
  int N = 5;
  int n = sizeof(val) / sizeof(val[0]);
  printf("\nValue = %d", knapsack(wt, val, N, n));
  return 0;
}