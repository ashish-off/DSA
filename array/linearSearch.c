#include <stdio.h>

int linear_search(int arr[], int size, int element)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == element)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {1, 233, 3, 44, 5, 6, 735, 8, 39, 10};
  int size = sizeof(arr) / sizeof(int);
  int element = 735;

  int result = linear_search(arr, size, element);

  printf("the index is %d\n the element is %d", result, element);

  return 0;
}