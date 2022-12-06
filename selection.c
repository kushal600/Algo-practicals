#include <stdio.h>

void main()
{
  int arrr[] = {10, 6, 9, 18, 3, 4, 1};
  int i, j;
  int n = sizeof(arrr) / sizeof(int);
  for (i = 0; i < n - 1; i++)
  {
    int min = i;
    for (j = i + 1; j < n; j++)
    {
      if (arrr[j] < arrr[min])
      {
        min = j;
      }
    }

    if (min != i)
    {
      int temp;
      temp = arrr[i];
      arrr[i] = arrr[min];
      arrr[min] = temp;
    }
  }
  for (i = 0; i < n; i++)
  {
    printf("%d ", arrr[i]);
  }
}