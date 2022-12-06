/* A naive recursive implementation that simply
follows the above optimal substructure property */
#include <limits.h>
#include <stdio.h>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
// int MatrixChainOrder(int p[], int i, int j)
// {
//   if (i == j)
//     return 0;
//   int k;
//   int min = INT_MAX;
//   int count;

//   // place parenthesis at different places between first
//   // and last matrix, recursively calculate count of
//   // multiplications for each parenthesis placement and
//   // return the minimum count
//   for (k = i; k < j; k++)
//   {
//     count = MatrixChainOrder(p, i, k) +
//             MatrixChainOrder(p, k + 1, j) +
//             p[i - 1] * p[k] * p[j];

//     if (count < min)
//       min = count;
//   }

//   // Return minimum count
//   return min;
// }

// // Driver program to test above function
// int main()
// {
//   int arr[] = {1, 2, 3, 4, 3};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   printf("Minimum number of multiplications is %d ",
//          MatrixChainOrder(arr, 1, n - 1));

//   getchar();
//   return 0;
// }
int chainedmatrix(int arr[], int i, int j)
{
  int k;
  int min = INT_MAX;
  int count;
  // printf("%d", arr[0]);
  if (i == j)
  {
    // printf("0");
    return 0;
  }
  for (k = i; k < j; k++)
  {
    count = chainedmatrix(arr, i, k) + chainedmatrix(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
    if (count < min)
    {
      min = count;
    }
  }
  return min;
  // printf("%d is min", count);
}
void main()
{
  int arr[] = {10, 20, 30};
  int n = sizeof(arr) / sizeof(int);

  printf("%d",
         chainedmatrix(arr, 1, n - 1));
}