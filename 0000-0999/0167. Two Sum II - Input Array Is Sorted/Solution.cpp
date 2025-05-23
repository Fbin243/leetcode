/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 05/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // Solve with binary search
  vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int n = numbers.size();
    int r = n;
    while (l < r) {
      // Find the element that greater than or equal by lower_bound
      r = lower_bound(numbers.begin() + l + 1, numbers.begin() + r,
                      target - numbers[l]) -
          numbers.begin();
      if (r < n && numbers[l] + numbers[r] == target)
        return vector<int>{l + 1, r + 1};
      l++;
    }

    return vector<int>{-1, -1};
  }

  // Solve with pointers
  vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    while (l < r) {
      if (numbers[l] + numbers[r] == target)
        return vector<int>{l + 1, r + 1};
      else if (numbers[l] + numbers[r] < target)
        l++;
      else
        r--;
    }

    return vector<int>{-1, -1};
  }
};

// --- Solution at 23/05/2025
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
      int sum = numbers[i] + numbers[j];
      if (sum == target)
        return vector<int>{i + 1, j + 1};
      else if (sum > target)
        j--;
      else
        i++;
    }

    return vector<int>{0, 0};
  }
};