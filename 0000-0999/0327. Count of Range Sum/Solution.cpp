/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 13/04/2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    multiset<long> prefixSet;
    prefixSet.insert(0);

    long sum = 0;
    int count = 0;

    for (int num : nums) {
      sum += num;

      // Đếm có bao nhiêu prefix trong đoạn [sum - upper, sum - lower]
      auto it1 = prefixSet.lower_bound(sum - upper);  // >=
      auto it2 = prefixSet.upper_bound(sum - lower);  // >

      count += distance(it1, it2);

      // Lưu prefix hiện tại để dùng sau
      prefixSet.insert(sum);
    }

    return count;
  }
};