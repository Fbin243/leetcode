/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/minimum-size-subarray-sum/?envType=problem-list-v2&envId=binary-search
 * Created at: 05/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * Time: O(n)
   * Space: O(n)
   * Approach: Prefix Sum + Sliding Window
   */
  int minSubArrayLen(int target, vector<int>& nums) {
    // Build prefix sum array
    vector<int> sums(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
      sums[i + 1] = sums[i] + nums[i];
    }

    // Apply sliding windows to find the valid subarrays
    int l = 0;
    int r = 1;
    int n = sums.size();
    int ans = n;
    while (l < n) {
      while (r < n - 1 && sums[r] - sums[l] < target) r++;
      if (sums[r] - sums[l] >= target) ans = min(ans, r - l);
      l++;
    }

    return ans == n ? 0 : ans;
  }

  /**
   * Time: O(n)
   * Space: O(1)
   * Approach: Prefix Sum + Sliding Window
   * Note: This is a more optimized version of the above approach
   */
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int ans = n + 1;

    while (r < n) {
      sum += nums[r];
      while (sum >= target) {
        ans = min(ans, r - l + 1);
        sum -= nums[l];
        l++;
      }
      r++;
    }

    return ans == n + 1 ? 0 : ans;
  }

  /**
   * Time: O(nlogn)
   * Space: O(n)
   * Approach: Binary Search
   * Note: This is a less efficient approach compared to the above
   * two approaches, but it is still a valid solution.
   */
  int minSubArrayLen(int target, vector<int>& nums) {
    // Build prefix sum array
    vector<int> sums(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
      sums[i + 1] = sums[i] + nums[i];
    }

    int l = 0;
    int n = sums.size();
    int ans = n;
    while (l < n) {
      int r = lower_bound(sums.begin() + l + 1, sums.end(), target + sums[l]) -
              sums.begin();
      if (r < n && sums[r] - sums[l] >= target) ans = min(ans, r - l);
      l++;
    }

    return ans == n ? 0 : ans;
  }

  /**
   * Binary Search
   * Time: O(nlogn)
   * Space: O(n)
   * Approach: Binary Search
   * Note: This is code from GPT-4o, the same with Fbin's code above
   */
  int minSubArrayLen(int target, vector<int>& nums) {
    // Build prefix sum array
    vector<int> sums(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
      sums[i + 1] = sums[i] + nums[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      int l = lower_bound(sums.begin(), sums.end(), target + sums[i]) -
              sums.begin();
      if (l != sums.size()) ans = min(ans, l - i);
    }

    return ans == INT_MAX ? 0 : ans;
  }
};

int main() {
  Solution* s = new Solution();
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  s->minSubArrayLen(7, nums);

  return 0;
}