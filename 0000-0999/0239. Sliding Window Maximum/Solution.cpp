/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/sliding-window-maximum/description/
 * Created at: 24/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Neetcode' solution
 * Approach: Dequeue (20ms ++)
 * Time: O(n)
 * Space: O(n)
 */
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;

    for (int i = 0; i < k; i++) {
      while (!dq.empty() && dq.back() < nums[i]) {
        dq.pop_back();
      }
      dq.push_back(nums[i]);
    }

    int r = k;
    vector<int> res;
    while (r < nums.size()) {
      res.push_back(dq.front());
      if (nums[r - k] == dq.front()) dq.pop_front();
      while (!dq.empty() && dq.back() < nums[r]) {
        dq.pop_back();
      }
      dq.push_back(nums[r]);
      r++;
    }

    res.push_back(dq.front());

    return res;
  }

  /**
   * Shorter version
   */
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;

    int r = 0;
    vector<int> res;
    while (r < nums.size()) {
      while (!dq.empty() && dq.back() < nums[r]) {
        dq.pop_back();
      }
      dq.push_back(nums[r]);

      if (r >= k - 1) {
        res.push_back(dq.front());
        if (nums[r - k + 1] == dq.front()) dq.pop_front();
      }

      r++;
    }

    return res;
  }
};

/**
 * Fbin's Solution (100ms ++)
 * Approach: Priority Queue + Hash Map
 * Time: O(nlogn)
 * Space: O(n)
 */
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<int> pq;
    unordered_map<int, int> freq;
    for (int i = 0; i < k; i++) {
      pq.push(nums[i]);
      freq[nums[i]]++;
    }

    int l = 0, r = k;
    vector<int> res;
    while (r <= nums.size()) {
      while (freq[pq.top()] <= 0) {
        pq.pop();
      }

      res.push_back(pq.top());
      freq[nums[l]]--;
      if (r < nums.size()) {
        pq.push(nums[r]);  // O(logn) to call sift up
        freq[nums[r]]++;
      }
      l++;
      r++;
    }

    return res;
  }

  /**
   * Shorter version
   */
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<int> pq;
    unordered_map<int, int> freq;

    int r = 0;
    vector<int> res;
    while (r < nums.size()) {
      pq.push(nums[r]);  // O(logn) to call sift up
      freq[nums[r]]++;

      if (r >= k - 1) {
        while (freq[pq.top()] <= 0) {
          pq.pop();
        }

        res.push_back(pq.top());
        freq[nums[r - k + 1]]--;
      }

      r++;
    }

    return res;
  }
};