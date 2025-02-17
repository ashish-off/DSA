#include <stdio.h>

int binary_search(int arr[], int size, int element)
{
  int low, high, mid;
  low = 0;
  high = size - 1;

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (arr[mid] == element)
    {
      return mid;
    }
    else if (arr[mid] < element)
    {
      low = mid + 1;
    }
    else 
    {
      high = mid -1;
    }
  }
  return -1;
}

int main()
{ // shorted array
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(arr) / sizeof(int);
  int element = 4;

  int result = binary_search(arr, size, element);

  if (result != -1)
  {
    printf("The index is %d\n", result);
  }
  else
  {
    printf("Element not found in the array.\n");
  }

  return 0;
}