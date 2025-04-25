/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/subarray-sum-equals-k/
 * Created at: 25/04/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int prefix = 0;
    int res = 0;
    unordered_map<int, int> map;
    map[k] = 1;
    for (int i = 0; i < nums.size(); i++) {
      prefix += nums[i];
      res += map[prefix];
      map[k + prefix]++;
    }

    return res;
  }
};
