
#include <stdio.h>

int main() {
  int n = 100; // Define the array size explicitly
  int a[n]; // Declare the array with the specified size
  int i, j, flag, temp;

  printf("Enter the size of the array:");
  scanf("%d", &n); // Read the array size (but unused since n is already defined)

  printf("Enter the array elements:");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]); // Read input into the array
  }

  for (i = 0; i < n - 1; i++) {
    flag = 0;

    for (j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        flag = 1;
      }
    }

    if (flag == 0) {
      break;
    }
  }

  printf("Sorted array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  return 0;
}