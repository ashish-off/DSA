#include<stdio.h>

void deletionAtInd (int arr[], int index, int size){

  if(index < 0 || index > size) {
    printf("Invalid index\n");
  }else {
    for (int i = index; i < size; i++){
      arr[i] = arr[i+1];
    }
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

  deletionAtInd(arr, index, size);
  size--;
  displayArray(arr, size);
  deletionAtInd(arr, index, size);
  size--;
  displayArray(arr, size);
  deletionAtInd(arr, index, size);
  size--;
  displayArray(arr, size);
}