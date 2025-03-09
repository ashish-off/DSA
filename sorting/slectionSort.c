#include <stdio.h>

void slectionSort(int arr[], int n) {
  for (int i = 0 ; i<n-1; i++){ // to determine number of step
    int minIndex = i;
    for (int j = i ; j<n; j++){ // to find minimum index
      if(arr[j+1] < arr[i])
        minIndex = i+1;
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

printArray(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
}