// C program to find minimum
// number of denominations
#include <stdio.h>
// #define N 9
// #define MAX 20

// // All denominations of Indian Currency
// int coins[N] = {1, 2, 5, 10, 20,
//                 50, 100, 200, 2000};

// void findMin(int cost)
// {
//   int List[MAX] = {0};
//   int i, k = 0;

//   for (i = N - 1; i >= 0; i--)
//   {
//     while (cost >= coins[i])
//     {
//       cost -= coins[i];
//       // Add coin in the list
//       List[k++] = coins[i];
//     }
//   }

//   for (i = 0; i < k; i++)
//   {
//     // Print
//     printf("%d ", List[i]);
//   }
//   return;
// }

// int main(void)
// {
//   // input value
//   int cost = 82;

//   printf("Following is minimal number"
//          "of change for %d: ",
//          cost);
//   findMin(cost);
//   return 0;
// }
// Code by Munish Bhardwaj

void findMin(int coins[], int cost, int N)
{
  int k = 0;
  int list[20] = {0};
  for (int i = N - 1; i > 0; i--)
  {
    while (cost >= coins[i])
    {
      cost -= coins[i];
      list[k] = coins[i];
      k++;
    }
  }

  for (int i = 0; i < k; i++)
  {
    printf("%d ", list[i]);
  }
}

void main()
{
  int coins[] = {1, 2, 5, 10, 20, 50, 100};
  int N = sizeof(coins) / sizeof(int);

  int cost = 69;
  findMin(coins, cost, N);
}