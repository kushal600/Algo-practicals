#include <stdio.h>

void main()
{
  int a[] = {2, 9, 7, 4, 1, 8, 4};
  int n = 7;
  int b[n];
  int k = -9999;
  for (int i = 0; i < n; i++)
  {
    if (k < a[i])
    {
      k = a[i];
    }
  }
  int c[k + 1];
  for (int i = 0; i <= k; i++)
  {
    c[i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    c[a[i]] = c[a[i]] + 1;
  }

  for (int i = 1; i <= k; i++)
  {
    c[i] = c[i] + c[i - 1];
  }

  for (int i = n - 1; i >= 0; i--)
  {
    b[c[a[i]]] = a[i];
    c[a[i]] -= 1;
  }

  for (int i = 1; i <= n; i++)
  {
    printf("%d ", b[i]);
  }
}