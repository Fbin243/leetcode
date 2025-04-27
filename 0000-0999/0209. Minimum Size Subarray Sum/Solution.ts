import { lower_bound } from "../../Algorithm/Binary Search/utils";

function minSubArrayLen(target: number, nums: number[]): number {
	nums = [0, ...nums];
	for (let i = 1; i < nums.length; i++) {
		nums[i] += nums[i - 1];
	}

	let res = nums.length;
	for (let [idx, num] of nums.entries()) {
		let pos = lower_bound(nums, target + num);
		if (pos < nums.length) {
			res = Math.min(res, pos - idx);
		}
	}

	return res == nums.length ? 0 : res;
}

minSubArrayLen(7, [2, 3, 1, 2, 4, 3]);
