#include <stdio.h>
#include <stdlib.h>

// strecture for array of size (total_size) and used size (used_size)
struct myArray
{
  int total_size;
  int used_size;
  int *ptr; // pointer to the array
};

void createArray(struct myArray *arr, int tSize, int uSize)
{
  arr->total_size = tSize;
  arr->used_size = uSize;
  arr->ptr = (int *)malloc(tSize * sizeof(int));

  if (arr->ptr == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1); // Exit if memory allocation fails
  };
}

void setVal(struct myArray *array)
{
  int n;
  for (int i = 0; i < array->used_size; i++)
  {
    printf("Enter value for index %d: ", i);
    scanf("%d", &n);
    (array->ptr)[i] = n;
  }
}
void display(struct myArray *array)
{
  for (int i = 0; i < array->used_size; i++)
  {
    printf("%d \n", (array->ptr)[i]);
  }
}

int main()
{
  struct myArray marks;
  createArray(&marks, 10, 4);
  setVal(&marks);
  display(&marks);

  free(marks.ptr);
  return 0;
};