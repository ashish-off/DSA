#include <stdio.h>

void insertionSort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && key < arr[j])
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n ; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


int main()
{
  int arr[] = {9, 5, 1, 4, 3, 6, 7};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("\n Original array: ");
  printArray(arr, size);

  insertionSort(arr, size);
  printf("\n Sorted Array : ");
  printArray(arr, size);

}