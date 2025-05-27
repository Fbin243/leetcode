/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/combination-sum/description/
 * Created at: 27/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  vector<int> v;
  vector<vector<int>> res;
  int curSum;

 public:
  void dfs(vector<int> candidates, int target, int k) {
    if (curSum == target) {
      res.push_back(v);
    }

    for (int i = k; i < candidates.size(); i++) {
      if (curSum + candidates[i] <= target) {
        v.push_back(candidates[i]);
        curSum += candidates[i];
        dfs(candidates, target, i);
        v.pop_back();
        curSum -= candidates[i];
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    dfs(candidates, target, 0);
    return res;
  }
};