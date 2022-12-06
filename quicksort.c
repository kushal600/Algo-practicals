#include <stdio.h>
// void quicksort(int arr[], int l, int h)
// {
//   int i, j, pivot, temp;
//   if (l < h)
//   {
//     pivot = l;
//     i = l;
//     j = h;
//     while (i < j)
//     {
//       while (arr[i] <= arr[pivot] && i < h)
//         i++;
//       while (arr[j] > arr[pivot])
//         j--;
//       if (i < j)
//       {
//         temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//       }
//     }
//     temp = arr[pivot];
//     arr[pivot] = arr[j];
//     arr[j] = temp;
//     quicksort(arr, l, j);
//     quicksort(arr, j + 1, h);
//   }
// }

int partition(int arr[], int low, int high)
{
  int i, j, pivot, temp;
  if (low < high)
  {
    i = low;
    pivot = low;
    j = high;

    while (i < j)
    {
      while (arr[i] <= arr[pivot] && i < high)
      {
        i++;
      }
      while (arr[j] > arr[pivot])
      {
        j--;
      }
      if (i < j)
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    return j;
    // quicksort(arr, low, j);
    // quicksort(arr, j + 1, high);
  }
}

void qs(int arr[], int low, int high)
{
  if (low < high)
  {
    int m = partition(arr, low, high);
    qs(arr, low, m);
    qs(arr, m + 1, high);
  }
}

int main()
{
  int arr[] = {9, 6, 2, 1, 56, 34};
  int N = sizeof(arr) / sizeof(int);
  int l = 0;
  int h = N - 1;
  qs(arr, l, h);
  printf("Order of Sorted elements: ");
  for (int i = 0; i < N; i++)
    printf(" %d", arr[i]);
  return 0;
}