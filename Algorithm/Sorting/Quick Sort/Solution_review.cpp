#include <iostream>
using namespace std;

int partition(int arr[], int l, int h) {
  int i = l, j = h + 1;
  int pivot = arr[l];

  while (i < j) {
    do {
      i++;
    } while (i < h && arr[i] < pivot);

    do {
      j--;
    } while (j > 0 && arr[j] > pivot);

    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[l], arr[j]);
  return j;
}

void quick_sort(int arr[], int l, int h) {
  if (l < h) {
    int pivot = partition(arr, l, h);
    quick_sort(arr, l, pivot);
    quick_sort(arr, pivot + 1, h);
  }
}

int main() {
  int A[] = {3, -4, 1, 2};
  int n = 4;

  quick_sort(A, 0, n - 1);

  for (int i = 0; i < n; i++) cout << A[i];

  return 0;
}