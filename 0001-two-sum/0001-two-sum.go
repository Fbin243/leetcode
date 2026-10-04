func twoSum(nums []int, target int) []int {
    for i := 0; i < len(nums) - 1; i++ {
        for j := i + 1; j < len(nums); j++ {
            if nums[j] == target - nums[i] {
                return []int{i, j};
            }
        }
    }

    return nil;
}