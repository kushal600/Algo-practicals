#include <stdio.h>

void main()
{
  int arr[] = {2, 6, 8, 4, 4, 10, 12, 1};
  int i, j;
  int n = sizeof(arr) / sizeof(int);
  printf("%d", n);

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}