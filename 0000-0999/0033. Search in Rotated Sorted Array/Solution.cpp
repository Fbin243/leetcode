/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=problem-list-v2&envId=binary-search
 * Created at: 31/03/2025
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] < target) {
        if (nums[mid] < nums[l] && nums[l] <= target) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (target < nums[l] && nums[l] <= nums[mid]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }

    return -1;
  }
};

// -- Solution at 26/05/2025
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) return m;

      // Left sorted portion
      if (nums[m] >= nums[l]) {
        if (nums[m] < target || target < nums[l]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
        // Right sorted portion
      } else {
        if (nums[m] > target || target > nums[r]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  cout << s.search(nums, target) << endl;  // Output: 4
  return 0;
}