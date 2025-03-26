/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/next-greater-element-ii/
 * Created at: 26/03/2025
 */

function nextGreaterElements(nums: number[]) : number[] {
  const n = nums.length;
  const res = new Array(n).fill(-1);
  const stack = [];
  for (let i = 0; i < n * 2; i++) {
    while (stack.length && nums[stack[stack.length - 1]] < nums[i % n]) {
      res[stack.pop()!] = nums[i % n];
    }
    stack.push(i % n);
  }
  return res;
}

function main() {
  const nums = [ 1, 2, 3, 4, 3 ];
  const res = nextGreaterElements(nums);
  console.log(res);
}

main();
