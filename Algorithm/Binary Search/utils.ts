// Find the first postion such that the value of it is greater than or equal to the target
function lower_bound(nums: number[], target: number): number {
	let l = 0,
		r = nums.length;

	while (l < r) {
		let m = l + Math.floor((r - l) / 2);
		if (nums[m] < target) {
			l = m + 1;
		} else {
			r = m;
		}
	}

	return l;
}

export { lower_bound };
