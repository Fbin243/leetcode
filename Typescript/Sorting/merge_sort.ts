/**
 * Author: Fbin
 * Created at: 13/04/2025
 */
function merge(arr1: number[], arr2: number[]): number[] {
  let i = 0,
    j = 0;
  const mergeArr = [];
  while (i < arr1.length && j < arr2.length) {
    if (arr1[i] < arr2[j]) {
      mergeArr.push(arr1[i++]);
    } else {
      mergeArr.push(arr2[j++]);
    }
  }
  while (i < arr1.length) {
    mergeArr.push(arr1[i++]);
  }
  while (j < arr2.length) {
    mergeArr.push(arr2[j++]);
  }

  return mergeArr;
}

function merge_sort(arr: number[], left: number, right: number): number[] {
  if (left == right) return [arr[left]];
  const mid = Math.floor((left + right) / 2);
  const arr1 = merge_sort(arr, left, mid);
  const arr2 = merge_sort(arr, mid + 1, right);

  return merge(arr1, arr2);
}

(function () {
  const arr = [9, 8, 1, 2, 3, 7, 6, 5, 4, 10];
  const n = arr.length;

  console.log(merge_sort(arr, 0, n - 1));
})();
