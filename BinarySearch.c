#include <stdio.h>

int linearSearch(int arr[], int N, int k)
{
  for (int i = 0; i < N; i++)
  {
    if (k == arr[i])
    {
      return i;
    }
  }
  return -1;
}

int binarySearch(int arr[], int k, int l, int h)
{

  int m = (l + h) / 2;
  // printf("%d", m);
  if (k == arr[m])
  {
    return m;
  }
  else if (k < arr[m] && m > 0)
  {
    binarySearch(arr, k, l, m);
  }
  else if (k > arr[m] && m > 0)
  {
    binarySearch(arr, k, m + 1, h);
  }
  else
  {
    return -1;
  }
}
void main()
{
  int arr[] = {-7, 4, 5, 7, 9};
  int N = sizeof(arr) / sizeof(int);
  int k = -7;
  int l = 0;
  int h = N - 1;
  // int pos = linearSearch(arr, N, k);
  // printf("%d is the pos\n", pos);

  int pos2 = binarySearch(arr, k, l, h);
  printf("%d is binary pos", pos2);
}