function findNumbers(nums: number[]): number {
	let ans = 0;
	for (let i = 0; i < nums.length; i++) {
		let count = 0;
		while (nums[i] > 0) {
			nums[i] = Math.floor(nums[i] / 10);
			count++;
		}
		if(count % 2 == 0) ans++;
	}

	return ans;
}
