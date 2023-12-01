//OPTIMZED BUBBLE SORT
#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubbleSort(int arr[], int n) {
  int isSwapped;

  for (int i = 0; i < n - 1; i++) {
    isSwapped = 0;

    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        isSwapped = 1;
      }
    }

    if (!isSwapped) {
      break;
    }
  }
}
int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}