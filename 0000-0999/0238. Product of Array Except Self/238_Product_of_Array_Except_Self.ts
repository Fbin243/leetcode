/**
 * Author: Fbin
 * Created at: 22/04/2025
 * Link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150
 */

function productExceptSelf(nums: number[]): number[] {
  const leftProd = [1];
  const rightProd = [1];
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    leftProd[i + 1] = leftProd[i] * nums[i];
  }
  for (let i = n - 1; i >= 0; i--) {
    rightProd[n - i] = rightProd[n - i - 1] * nums[i];
  }

  return nums.map(function (num: number, idx: number): number {
    return leftProd[idx] * rightProd[n - 1 - idx];
  });
}

// Test cases
console.log(productExceptSelf([1, 2, 3, 4])); // [24, 12, 8, 6]
console.log(productExceptSelf([-1, 1, 0, -3, 3])); // [0, 0, 9, 0, 0]
console.log(productExceptSelf([1])); // [1]
console.log(productExceptSelf([1, 2])); // [2, 1]
console.log(productExceptSelf([1, 2, 3])); // [6, 3, 2]
