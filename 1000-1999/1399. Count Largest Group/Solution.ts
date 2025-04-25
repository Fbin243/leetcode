/**
 * Author: Fbin
 * Created at: 23/04/2025
 * Link:https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23
 * Goal: Zalo Tech Freshers 2025
 */

function countLargestGroup(n: number): number {
  const map = new Map<number, number>();
  for (let i = 1; i <= n; i++) {
    const sum = getSum(i);
    if (map.has(sum)) {
      map.set(sum, map.get(sum)! + 1);
    } else {
      map.set(sum, 1);
    }
  }

  let max = 0;
  let count = 0;
  for (const value of map.values()) {
    if (value > max) {
      max = value;
      count = 1;
    } else if (value === max) {
      count++;
    }
  }
  return count;
}

function getSum(n: number): number {
  let sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = Math.floor(n / 10);
  }
  return sum;
}
