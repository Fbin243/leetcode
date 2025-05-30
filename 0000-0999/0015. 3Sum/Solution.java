class Solution {
	public List<List<Integer>> threeSum(int[] nums) {
		int n = nums.length;
		Arrays.sort(nums);
		List<List<Integer>> res = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			int target = -nums[i];
			int l = i + 1;
			int r = n - 1;
			while (l < r) {
				if (nums[l] + nums[r] == target) {
					res.add(new ArrayList<Integer>(Arrays.asList(nums[i], nums[l], nums[r])));
					l++;
					r--;
					while (l < r && nums[l] == nums[l - 1])
						l++;
					while (l < r && nums[r] == nums[r + 1])
						r--;
				} else if (nums[l] + nums[r] < target)
					l++;
				else
					r--;
			}
		}

		return res;
	}
}