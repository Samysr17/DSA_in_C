#include <stdio.h>
void insertion_sort(int a[], int n);
void display(int a[], int n);
int main() {
  int a[] = {3, 5, 1, 2, 4};
  int n = 5;
  printf("Unsorted Array\n");
  display(a, n);
  insertion_sort(a, n);
  printf("Sorted Array\n");
  display(a, n);
  return 0;
}
void insertion_sort(int a[], int n) {
  int i, j, key;
  for (int i = 1; i < n; i++) {
    key = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
}
void display(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", a[i]);
  }
}