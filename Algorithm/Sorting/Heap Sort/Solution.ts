/**
 * Author: Fbin
 * Created at: 13/04/2025
 */

// Sift down used for heapify to build heap
// Time complexity: O(n)
// Space complexity: O(logn)
// It can be used to sort, delete
function heapify(arr: number[], n: number, i: number): void {
  const left = 2 * i + 1;
  const right = 2 * i + 2;
  let largest = i;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest !== i) {
    [arr[i], arr[largest]] = [arr[largest], arr[i]];
    heapify(arr, n, largest);
  }
}

// Siftup used for heapify to build heap
// Time complexity: O(nlogn)
// Space complexity: O(logn)
// It can be used to insert
function heapify_siftup(arr: number[], n: number, i: number): void {
  const left = 2 * i + 1;
  const right = 2 * i + 2;
  let largest = i;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest !== i) {
    [arr[i], arr[largest]] = [arr[largest], arr[i]];
    if (i != 0) {
      heapify_siftup(arr, n, Math.floor((i - 1) / 2));
    }
  }
}

(function () {
  const arr = [9, 8, 1, 2, 3, 7, 6, 5, 4, 10];
  const n = arr.length;

  // ------------------ Sift down to build heap
  for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  // Extract elements from heap
  for (let i = n - 1; i > 0; i--) {
    [arr[0], arr[i]] = [arr[i], arr[0]];
    heapify(arr, i, 0);
  }

  // ----------------- Sift up to build heap
  for (let i = 0; i <= Math.floor(n / 2) - 1; i++) {
    heapify_siftup(arr, n, i);
  }

  // Extract elements from heap
  for (let i = n - 1; i > 0; i--) {
    [arr[0], arr[i]] = [arr[i], arr[0]];
    heapify(arr, i, 0);
  }

  console.log("Sorted:", arr);
})();
