#include<stdio.h>
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selectionSort(int arr[], int n) 
{for(int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(&arr[i], &arr[minIndex]);
  }
}
int main()
{
  int arr[] = {64,34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}