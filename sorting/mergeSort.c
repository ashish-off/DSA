#include <stdio.h>
#include <stdlib.h>

// Function to print an array
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Function to merge two halves of an array

void merge(int arr[], int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // create temp arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[left + i];

  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  i = 0;
  j = 0;
  k = left;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if any
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if any
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

int main()
{
  int arr[] = {34, 22, 1, 55, 6, 7, 6, 3, 1, 12};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: \n");
  printArray(arr, size);

  mergeSort(arr, 0, size - 1);
  printf("Sorted array: \n");
  printArray(arr, size);

  return 0;
}