/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 06/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * Time: O(n)
   * Space: O(1)
   * Approach: Math
   * 1. The sum of the first n natural numbers is n * (n + 1) / 2.
   * 2. The missing number is the difference between the sum of the first n
   * natural numbers and the sum of the given array.
   */
  int missingNumber(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      sum += nums[i];
    }

    return n * (n + 1) / 2 - sum;
  }

  /**
   * Time: O(n)
   * Space: O(1)
   * Arpproach: Utilize the index
   */
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = n;
    for (int i = 0; i < n; i++) {
      sum += i - nums[i];
    }

    return sum;
  }

  /**
   * Time: O(n)
   * Space: O(1)
   * Approach: XOR
   * 1. The XOR of a number with itself is 0.
   * 2. The XOR of a number with 0 is the number itself.
   * 3. The missing number is the XOR of all the numbers from 0 to n and the
   * XOR of all the numbers in the array.
   */
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = n;
    for (int i = 0; i < n; i++) {
      ans ^= i ^ nums[i];
    }

    return ans;
  }

  /**
   * Time: O(n * log(n)) + O(n)
   * Space: O(1)
   * Approach: Linear Search
   * 1. The array is not sorted -> sort the array first.
   * 2. The missing number is the first number that is not equal to its index.
   */
  int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i) return i;
    }

    return nums.size();
  }

  /**
   * Time: O(n * log(n))
   * Space: O(1)
   * Approach: Binary Search
   * 1. The array is sorted.
   * 2. The missing number is the first number that is not equal to its index.
   */
  int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == mid)
        l = mid + 1;
      else
        r = mid - 1;
    }

    return l;
  }
};
