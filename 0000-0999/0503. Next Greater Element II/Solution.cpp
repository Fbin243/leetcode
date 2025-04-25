/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/next-greater-element-ii/
 * Created at: 26/03/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n * 2; i++) {
      while (!st.empty() && nums[st.top()] < nums[i % n]) {
        res[st.top()] = nums[i % n];
        st.pop();
      }
      st.push(i % n);
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 3};
  vector<int> res = sol.nextGreaterElements(nums);
  for (int i : res) {
    cout << i << " ";
  }
  return 0;
}