/**
 * Author: Fbin
 * Created at: 25/04/2025
 * Link:https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150
 * Goal: Zalopay Tech Freshers 2025
 */
function canCompleteCircuit(gas: number[], cost: number[]): number {
  let min_idx = 0;
  let min_val = 10e4;
  const n = gas.length;
  for (let i = 0; i < n; i++) {
    const cur_gas = i > 0 ? gas[i - 1] : 0;
    gas[i] = cur_gas + gas[i] - cost[i];
    if (gas[i] < min_val) {
      min_val = gas[i];
      min_idx = i;
    }
  }

  let start_idx = min_idx + 1;
  let sum = 0;
  while (start_idx % n != min_idx + 1) {
    sum += gas[start_idx % n];
    if (sum < 0) return -1;
  }

  return start_idx;
}

console.log(canCompleteCircuit([1, 2, 3, 4, 5], [3, 4, 5, 1, 2]));
