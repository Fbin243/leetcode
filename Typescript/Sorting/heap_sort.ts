/**
 * Author: Fbin
 * Created at: 13/04/2025
 */
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

(function () {
  const arr = [9, 8, 1, 2, 3, 7, 6, 5, 4, 10];
  const n = arr.length;

  // Build max heap
  for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  // Extract elements from heap
  for (let i = n - 1; i > 0; i--) {
    [arr[0], arr[i]] = [arr[i], arr[0]];
    heapify(arr, i, 0);
  }

  console.log("Sorted:", arr);
})();
