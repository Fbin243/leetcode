/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/permutations/description/
 * Created at: 27/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  vector<vector<int>> res;
  unordered_set<int> seen;
  vector<int> v;

 public:
  void dfs(vector<int>& nums) {
    if (v.size() == nums.size()) {
      res.push_back(v);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (!seen.count(nums[i])) {
        v.push_back(nums[i]);
        seen.insert(nums[i]);
        dfs(nums);
        v.pop_back();
        seen.erase(nums[i]);
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    dfs(nums);
    return res;
  }
};