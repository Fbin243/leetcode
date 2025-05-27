/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/subsets/description/
 * Created at: 27/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  vector<vector<int>> res;
  vector<int> v;

 public:
  void backtrack(vector<int>& nums, int k) {
    if (k == nums.size()) {
      res.push_back(v);
      return;
    }

    // Choose
    v.push_back(nums[k]);
    backtrack(nums, k + 1);
    v.pop_back();

    // Not choose
    backtrack(nums, k + 1);
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    backtrack(nums, 0);
    return res;
  }
};