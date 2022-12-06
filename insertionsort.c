#include <stdio.h>

void insertion(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void main()
{
  int arr[] = {1, 5, 19, 18, 52, 7};
  int n = sizeof(arr) / sizeof(int);

  insertion(arr, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}