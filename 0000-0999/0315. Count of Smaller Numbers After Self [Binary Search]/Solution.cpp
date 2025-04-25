/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 13/04/2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Time: O(n^2) (Because of the insert function will
   * take O(n) to shift the elements)
   * Space: O(n)
   * Idea: Use a sorted array to store the elements that
   * are already processed. For each element, we find
   * the position of the current element in the sorted
   * array using lower_bound. The position will be the
   * number of elements that are smaller than the current
   * element.
   */
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> sorted;
    vector<int> res;
    for (int i = nums.size() - 1; i >= 0; i--) {
      int pos =
          lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
      res.push_back(pos);
      sorted.insert(sorted.begin() + pos, nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};