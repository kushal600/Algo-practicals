void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapsort(int arr[], int N)
{
  for (int i = N / 2 - 1; i > 0; i--)
  {
    heapify(arr, N, i);
  }
  for (int i = N - 1; i > 0; i--)
  {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

void heapify(int arr[], int N, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (arr[left] > arr[largest] && left < N)
  {
    largest = left;
  }

  if (arr[right] > arr[largest] && right < N)
  {
    largest = right;
  }

  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, N, largest);
  }
}

void main()
{
  int arr[] = {10, 4, 2, 97, 3};
  int N = sizeof(arr) / sizeof(int);
  heapsort(arr, N);
  for (int i = 0; i < N; i++)
  {
    printf("%d ", arr[i]);
  }
}