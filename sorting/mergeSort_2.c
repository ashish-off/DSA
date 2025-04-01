#include <stdio.h>

// Function to print an array
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


void merge(int arr[], int start , int mid , int end){
  int i = start;
  int j = mid +1;
  int k = start;
  int temp[100];

 while( i <= mid && j<= end )
  {
    if(arr[i] <= arr[j]) {
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }
  
  while( i<= mid ){
    temp[k] = arr[i];
    i++;
    k++;
  }
  while (j <= end) {
    temp[k] = arr[j];
    j++;
    k++;
}

  
  for (k = start; k <= end; k++) {
    arr[k] = temp[k];
}

}

// Function to implement merge sort
void mergeSort(int arr[], int start, int end)
{
  if (start < end)
  {
    int mid = start + (end - start) / 2;

    // Sort first and second halves
    mergeSort(arr, start, mid); // left half
    mergeSort(arr, mid + 1, end); // right half

    // Merge the sorted halves
    merge(arr, start, mid, end);
  }
}

int main()
{
  int arr[] = {34, 22, 1, 55, 6, 7, 3};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: \n");
  printArray(arr, size);

  mergeSort(arr, 0, size - 1);
  printf("Sorted array: \n");
  printArray(arr, size);

  return 0;
}