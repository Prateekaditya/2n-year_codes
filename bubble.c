// OPTIMIZED BUBBLE SORT
#include <stdio.h>
#include <stdlib.h>

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
  int n;
  int *arr; // Declare arr as a pointer to an integer

  printf("Enter the size of the array:");
  scanf("%d", &n);

  arr = malloc(n * sizeof(int)); // Dynamically allocate memory for the array

  for (int i = 0; i < n; i++) {
    printf("Enter element %d:", i + 1);
    scanf("%d", arr + i); // Use the pointer syntax to access array elements
  }

  bubbleSort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  free(arr); // Deallocate the memory for the array

  return 0;
}
