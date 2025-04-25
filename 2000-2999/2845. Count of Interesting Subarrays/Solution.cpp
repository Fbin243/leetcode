/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/count-of-interesting-subarrays/description/?envType=daily-question&envId=2025-04-25
 * Created at: 25/04/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * Brute force
   * Time Complexity: O(n^2)
   * Space Complexity: O(1)
   */
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      int count = 0;
      for (int j = i; j < nums.size(); j++) {
        if (nums[j] % modulo == k) count++;
        if (count % modulo == k) res++;
      }
    }

    return res;
  }

  /**
   * Prefix sum + Hash table
   * Time Complexity: O(n)
   * Space Complexity: O(n)
   *
   * Transform nums into a binary array where arr[i] = 1 if nums[i] % modulo ==
   * k and 0 otherwise, reducing the problem to counting subarrays with a given
   * sum.
   *
   * Maintain a running prefix sum `prefix` as the total of arr[0..i],
   * representing how many qualifying elements you’ve seen so far.
   *
   * Use an unordered_map keyed by `prefix % modulo` to store how often each
   * remainder has occurred, enabling O(1) lookups for prior prefixes.
   *
   * At each index `i`, add `map[(prefix - k + modulo) % modulo]` to your
   * result, which counts all subarrays ending at `i` whose element-count modulo
   * equals `k`.
   *
   * Initialize `map[0] = 1` to account for the “empty” prefix (i.e., subarrays
   * starting at index 0) whenever `prefix % modulo == k`.
   */
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    long long res = 0;
    long long prefix = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
      prefix += nums[i] % modulo == k;
      res += map[(prefix - k) % modulo];
      map[prefix % modulo]++;
    }

    return res;
  }
};
