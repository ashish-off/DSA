#include <stdio.h>
//
void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++) // acess arrary element
  {
    int swap = 0;
    for (int j = 0; j < n - 1 - i; j++) // to compare the adjacent elements (one less each time)
    {
      if (arr[j] > arr[j + 1])
      {
        // swap if the elements are not in ascending order
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swap = 1;
      }
    }
    if (swap == 0)
    {
      break;
    }
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int arr[] = {99, 67, 54, 2, 44, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: \n");
  printArray(arr, n);

  bubbleSort(arr, n);

  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}