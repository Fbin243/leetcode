/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 30/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
      if (seen.find(nums[i]) != seen.end() && i - seen[nums[i]] <= k)
        return true;
      seen[nums[i]] = i;
    }

    return false;
  }
};
