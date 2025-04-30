func twoSum(nums []int, target int) []int {
	seen := map[int]int{}
	for idx, num := range nums {
		value, exist := seen[target-num]
		if exist {
			return []int{idx, value}
		}
		seen[num] = idx
	}

	return []int{-1, -1}
}
