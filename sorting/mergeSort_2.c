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

// function to merging and sorting

void merge(int arr[], int start , int mid , int end){
  int i = start;
  int j = mid +1;
  int k = start;
  int temp[100];

  // Merge two subarrays into temp[]
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
  
   // Copy remaining elements of left subarray (greater values)
  while( i<= mid ){
    temp[k] = arr[i];
    i++;
    k++;
  }

   // Copy remaining elements of right subarray (greater values)
  while (j <= end) {
    temp[k] = arr[j];
    j++;
    k++;
}

   // Copy merged elements back to original array
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
  int arr[] = {45,6,67,34,7,8,2,4,56,5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: \n");
  printArray(arr, size);

  mergeSort(arr, 0, size - 1);
  printf("Sorted array: \n");
  printArray(arr, size);

  return 0;
}

// Best Case	O(n log n) 
// Average Case	O(n log n)
// Worst Case	O(n log n)