#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int i = left, j = mid + 1;
  int n = right - left + 1;
  int* temp = new int[n];
  int k = 0;
  while (i <= mid && j <= right) {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  while (i <= mid) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];

  for (int l = left; l <= right; l++) {
    arr[l] = temp[l - left];
  }

  delete []temp;
}

void mergeSort(int arr[], int left, int right) {
  if (left >= right) return;
  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

int bin_search(int arr[], int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}

int Sum(int A[], int B[], int n, int k) {
  mergeSort(A, 0, n - 1);
  mergeSort(B, 0, n - 1);
  for (int i = 0; i < n; i++) {
    if (bin_search(B, 0, n - 1, k - A[i]) != -1) return 1;
  }

  return 0;
}

int main() {
  int A[] = {3, -4, 1, 2};
  int B[] = {1, 2, 3, 4};
  int k = 7;
  int n = 4;
  cout << "Are there two number a and b such that a + b = " << k
       << "? Answer: " << Sum(A, B, n, k);

  return 0;
}