#include <stdio.h>


void
 
swap(int *a, int *b)
 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void
 
insertionSort(int arr[], int n)
 
{
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      swap(&arr[j], &arr[j + 1]);
      j--;
    }

    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}