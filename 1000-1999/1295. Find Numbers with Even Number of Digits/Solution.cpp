/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/?envType=daily-question&envId=2025-04-30
 * Created at: 30/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findNumbers(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      int count = 0;
      while (nums[i] > 0) {
        nums[i] = nums[i] / 10;
        count++;
      }
      ans += 1 - count % 2;
    }
    return ans;
  }
};
