#include <stdio.h>
// minimun element comes frist then at the adjacent place and so on
void selectionSort(int arr[], int n) {
  for (int i = 0 ; i<n-1; i++){ // to determine number of step
    int minIndex = i;
    for (int j = i+1 ; j<n; j++){ // to find minimum index
      if(arr[j] < arr[minIndex])
        minIndex = j;
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
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
  int arr[] = {88,45,67,100,33,21,1,1,43};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("The array : \n");
  printArray(arr, size);

  selectionSort(arr, size);
  printf("The sorted array : \n");
  printArray(arr, size);
}