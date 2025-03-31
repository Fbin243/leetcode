/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/sqrtx/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 30/03/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * Time: O(n)
   * Space: O(1)
   */
  vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    vector<int> ans(2, -1);
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) {
        ans[0] = m;
        ans[1] = m;
        while (ans[0] > 0 && nums[ans[0] - 1] == target) ans[0]--;
        while (ans[1] < n - 1 && nums[ans[1] + 1] == target) ans[1]++;
        return ans;
      }
      if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }

    return ans;
  }

  /**
   * Time: O(logn)
   * Space: O(1)
   */
  vector<int> searchRange2(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    vector<int> ans{-1, -1};
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] >= target) {
        if (nums[m] == target) ans[0] = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    l = 0;
    r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] <= target) {
        if (nums[m] == target) ans[1] = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return ans;
  }

  /**
   * Lower bound and upper bound
   * Time: O(logn)
   * Space: O(1)
   */
  vector<int> searchRange3(vector<int>& nums, int target) {
    int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (l <= r) return {l, r};
    return {-1, -1};
  }
};

int main() {
  Solution s;
  vector<int> nums{5, 7, 7, 8, 8, 10};
  int target = 8;
  vector<int> ans = s.searchRange2(nums, target);
  cout << ans[0] << " " << ans[1] << endl;

  return 0;
}