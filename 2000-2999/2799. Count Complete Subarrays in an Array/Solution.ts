/**
 * Author: Fbin
 * Created at: 24/04/2025
 * Link:https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24
 * Goal: Zalo Tech Freshers 2025
 */

function countCompleteSubarrays(nums: number[]): number {
  let l = 0,
    r = 0,
    res = 0,
    n = nums.length;
  const set = new Set(nums);
  const map = new Map<number, number>();

  while (r < n) {
    map.set(nums[r], (map.get(nums[r]) || 0) + 1);

    let count = 0;
    while (l <= r && map.size == set.size) {
      const freq = map.get(nums[l])!;
      if (freq > 0) map.set(nums[l], freq - 1);
      if (freq == 1) map.delete(nums[l]);
      count++;
      l++;
    }

    res += count * (n - r);
    r++;
  }

  return res;
}

// Test case
console.log(countCompleteSubarrays([1, 3, 1, 2, 2])); // Output: 4
console.log(countCompleteSubarrays([5, 5, 5, 5])); // Output: 10
console.log(countCompleteSubarrays([1, 2, 3, 4])); // Output: 1
