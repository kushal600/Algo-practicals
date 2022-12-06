#include <stdio.h>
void minmax(int arr[], int low, int high, int min, int max)
{

  int n = high + 1;
  if (n == 1)
  {
    min = arr[low];
    max = arr[low];
  }
  else if (low == high - 1)
  {
    if (arr[low] > arr[high])
    {
      min = arr[high];
      max = arr[low];
    }
    else
    {
      min = arr[low];
      max = arr[high];
    }
  }
  else
  {
    int min1 = 9999;
    int max1 = -9999;
    int mid = (low + high) / 2;
    minmax(arr, low, mid, min, max);
    minmax(arr, mid + 1, high, min1, max1);
    if (min > min1)
    {
      min = min1;
    }
    if (max < max1)
    {
      max = max1;
    }
  }

  printf("%d is min and %d is max", min, max);
}

void main()
{
  int arr[] = {2, 5, 89, 2, 65, 1};
  int low = 0;
  int high = (sizeof(arr) / sizeof(int)) - 1;
  int min = 9999;
  int max = -9999;
  minmax(arr, low, high, min, max);
}