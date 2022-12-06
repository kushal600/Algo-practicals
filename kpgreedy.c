#include <stdio.h>

// void knapsack(int n, float weight[], float profit[], float capacity)
// {
//   float x[20], tp = 0;
//   int i, j, u;
//   u = capacity;

//   for (i = 0; i < n; i++)
//     x[i] = 0.0;

//   for (i = 0; i < n; i++)
//   {
//     if (weight[i] > u)
//       break;
//     else
//     {
//       printf("fwffff");
//       x[i] = 1.0;
//       tp = tp + profit[i];
//       u = u - weight[i];
//     }
//   }

//   if (i < n)
//     x[i] = u / weight[i];

//   tp = tp + (x[i] * profit[i]);

//   printf("\nThe result vector is:- ");
//   for (i = 0; i < n; i++)
//     printf("%f\t", x[i]);

//   printf("\nMaximum profit is:- %f", tp);
// }

// int main()
// {
//   float weight[20], profit[20], capacity;
//   int num, i, j;
//   float ratio[20], temp;

//   printf("\nEnter the no. of objects:- ");
//   scanf("%d", &num);

//   printf("\nEnter the wts and profits of each object:- ");
//   for (i = 0; i < num; i++)
//   {
//     scanf("%f %f", &weight[i], &profit[i]);
//   }

//   printf("\nEnter the capacityacity of knapsack:- ");
//   scanf("%f", &capacity);

//   for (i = 0; i < num; i++)
//   {
//     ratio[i] = profit[i] / weight[i];
//   }

//   for (i = 0; i < num - 1; i++)
//   {
//     for (j = 0; j < num - i - 1; j++)
//     {
//       if (ratio[j] < ratio[j + 1])
//       {
//         temp = ratio[j];
//         ratio[j] = ratio[j + 1];
//         ratio[j + 1] = temp;

//         temp = weight[j];
//         weight[j] = weight[j + 1];
//         weight[j + 1] = temp;

//         temp = profit[j];
//         profit[j] = profit[j + 1];
//         profit[j + 1] = temp;
//       }
//     }
//   }

//   knapsack(num, weight, profit, capacity);
//   return (0);
// }

void knapsack(int n, float weight[], float profit[], float capacity)
{
  int u = capacity;
  float x[20];
  int i, j;
  float tp = 0;

  for (i = 0; i < n; i++)
  {
    x[i] = 0.0;
  }

  for (i = 0; i < n; i++)
  {
    if (u < weight[i])
    {
      break;
    }
    else
    {
      x[i] = 1.0;
      u = u - weight[i];
      tp = tp + profit[i];
    }
  }

  if (i < n)
  {
    x[i] = u / weight[i];
  }
  tp = tp + (x[i] * profit[i]);
  printf("Total profit: %f", tp);
}

int main()
{
  float weight[20], profit[20], ratio[20], capacity, temp;
  int n, i, j;

  printf("Enter number of elements");
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    printf("Enter weight and profit");
    scanf("%f %f", &weight[i], &profit[i]);
  }
  printf("Enter capacity");
  scanf("%f", &capacity);

  // for (i = 0; i < n; i++)
  // {
  //   printf("%f %f \n", weight[i], profit[i]);
  // }

  for (i = 0; i < n; i++)
  {
    ratio[i] = profit[i] / weight[i];
  }

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (ratio[j] < ratio[j + 1])
      {
        temp = ratio[j];
        ratio[j] = ratio[j + 1];
        ratio[j + 1] = temp;

        temp = weight[j];
        weight[j] = weight[j + 1];
        weight[j + 1] = temp;

        temp = profit[j];
        profit[j] = profit[j + 1];
        profit[j + 1] = temp;
      }
    }
  }
  // for (i = 0; i < n; i++)
  // {
  //   printf("%f %f %f\n", weight[i], profit[i], ratio[i]);
  // }
  knapsack(n, weight, profit, capacity);
  return (0);
}