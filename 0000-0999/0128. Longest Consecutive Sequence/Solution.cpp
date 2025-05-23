/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/longest-consecutive-sequence/description/
 * Created at: 23/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++) {
      st.insert(nums[i]);
    }

    int res = 0;
    for (int k : st) {
      if (!st.count(k - 1)) {
        int l = k + 1;
        int curLen = 1;
        while (st.count(l)) {
          l++;
          curLen++;
        }
        res = max(res, curLen);
      }
    }

    return res;
  }
};