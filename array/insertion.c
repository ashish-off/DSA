#include<stdio.h>

void insertAtindex (int arr[], int element, int index, int size, int capacity){
  if(index < 0 || index > size || size >= capacity) {
    printf("Invalid index\n");
  }else {
    for (int i = size -1; i >= index; i--){
      arr[i+1] = arr[i];
    }
    arr[index] = element;
  }
}


void displayArray(int arr[], int size){
  printf("\n");
  for(int i=0; i<size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main () {

  int arr[100] = {1, 2, 3, 4, 5,56,24,99};
  int size = 8;
  displayArray(arr, size);

  int capacity = sizeof(arr) / sizeof(arr[0]); // (4*100)/4 = 100
  int element = 232;
  int index = 2;

  insertAtindex(arr, element, index, size, capacity);
  displayArray(arr, size);
}