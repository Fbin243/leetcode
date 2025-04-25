'''
/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=problem-list-v2&envId=binary-search
 * Created at: 31/03/2025
 */
'''

class Solution:
    def search(self, nums: list[int], target: int) -> int:
      left = 0
      right = len(nums) - 1
      while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
          return mid
        if nums[left] <= nums[mid]:
          if nums[left] <= target < nums[mid]:
              right = mid - 1
          else:
              left = mid + 1
        else:
          if nums[mid] < target <= nums[right]:
             left = mid + 1
          else:
             right = mid - 1
      return -1  
    
# Example usage
def main():
    nums = [4,5,6,7,0,1,2]
    target = 0
    solution = Solution()
    result = solution.search(nums, target)
    print(result)  # Output: 4

if __name__ == "__main__":
    main()