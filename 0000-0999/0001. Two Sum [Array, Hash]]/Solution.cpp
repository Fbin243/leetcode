/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=array
 * Created at: 08/03/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Brute Force
 * It's very simple. Just loop through each element x and find if there is
 * another value that equals to target - x.
 * In total, we have two nested loops.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */

/**
 * Approach 2: Hash table
 * We can reduce a loop of Brute Force way by using hash table.
 * Iterate through the array once, and for each element x, check if target - x
 * exists in the hashtable
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> seen;
  for (int i = 0; i < nums.size(); i++) {
    if (seen.find(target - nums[i]) != seen.end()) {
      return vector<int>{seen[target - nums[i]], i};
    }
    seen[nums[i]] = i;
  }

  return vector<int>{};
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = twoSum(nums, target);
  cout << "Result: " << result[0] << " " << result[1] << endl;

  return 0;
}
