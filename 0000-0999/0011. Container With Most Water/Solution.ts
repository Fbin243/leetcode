function maxArea(height: number[]): number {
	let i = 0, j = height.length - 1;
	let res = 0;
	while(i < j) {
		res = Math.max(res, Math.min(height[i], height[j]) * (j - i));
		if(height[i] < height[j]) i++;
		else j--;
	}

	return res;
};