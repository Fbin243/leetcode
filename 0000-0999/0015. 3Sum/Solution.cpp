/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 27/04/2025
 */

#include <bits/stdc++.h>

#include <format>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    set<string> st;
    for (int i = 0; i < nums.size(); i++) {
      int sum = 0 - nums[i];
      unordered_map<int, int> m;
      for (int j = i + 1; j < nums.size(); j++) {
        if (m[sum - nums[j]]) {
          vector<int> ans = {nums[i], nums[j], nums[m[sum - nums[j]]]};
          sort(ans.begin(), ans.end());
          string key = "";
          for (auto& c : ans) key += to_string(c);
          if (st.find(key) == st.end()) res.push_back(ans);
        }
        m[nums[j]] = j;
      }
    }

    return res;
  }
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0;
    vector<vector<int>> res;
    while (i < nums.size()) {
      int l = i + 1;
      int r = nums.size() - 1;

      while (l < r) {
        if (nums[i] + nums[l] + nums[r] == 0) {
          res.push_back(vector<int>{nums[i], nums[l], nums[r]});
          l++;
          r--;
          while (l < r && nums[l] == nums[l - 1]) l++;
          while (l < r && nums[r] == nums[r + 1]) r--;
        } else if (nums[i] + nums[l] + nums[r] < 0) {
          l++;
        } else {
          r--;
        }
      }

      do {
        i++;
      } while (i < nums.size() && nums[i] == nums[i - 1]);
    }

    return res;
  }
};
