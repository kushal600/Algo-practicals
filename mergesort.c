

// #include <stdio.h>

// #define max 10

// void merging(int low, int mid, int high, int a[])
// {

//   int b[high + 1];
//   int i = low;
//   int j = mid + 1;
//   int k = low;

//   while (i <= mid && j <= high)
//   {
//     if (a[i] < a[j])
//     {
//       b[k] = a[i];
//       k = k + 1;
//       i = i + 1;
//     }
//     else
//     {
//       b[k] = a[j];
//       k = k + 1;
//       j = j + 1;
//     }
//   }

//   while (i <= mid)
//     b[k++] = a[i++];

//   while (j <= high)
//     b[k++] = a[j++];

//   for (i = low; i <= high; i++)
//     a[i] = b[i];
// }

// void sort(int l, int h, int a[])
// {
//   int mid;

//   if (l < h)
//   {
//     mid = (l + h) / 2;
//     sort(l, mid, a);
//     sort(mid + 1, h, a);
//     merging(l, mid, h, a);
//   }
//   else
//   {
//     return;
//   }
// }

// int main()
// {
//   int i;
//   int a[] = {19, 2, 9, 7, 1};
//   int N = sizeof(a) / sizeof(int);
//   int l = 0;
//   int h = N - 1;
//   sort(l, h, a);
//   for (i = 0; i < N; i++)
//     printf("%d ", a[i]);
// }

#include <stdio.h>
void combine(int arr[], int low, int mid, int high)
{
  int temp[high + 1];
  int i = low;
  int j = mid + 1;
  int k = low;

  while (i <= mid && j <= high)
  {
    if (arr[i] < arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
    }
  }
  while (i <= mid)
  {
    temp[k++] = arr[i++];
  }
  while (j <= high)
  {
    temp[k++] = arr[j++];
  }

  for (i = low; i <= high; i++)
  {
    arr[i] = temp[i];
  }
}

void mergesort(int arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    combine(arr, low, mid, high);
  }
  else
  {
    return;
  }
}

void main()
{
  // int arr[] = {10, 4, 7, 2, 9, 1, 79, 65};
  int n;

  printf("Enter value of n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter value of arrays");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  int low = 0;
  int high = n - 1;
  mergesort(arr, low, high);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}