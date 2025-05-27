/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
 * Created at: 27/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
 private:
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;

 public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    pq = {nums.begin(), nums.end()};
    while (pq.size() > k) pq.pop();
  }

  int add(int val) {
    if (pq.size() < k) {
      pq.push(val);
    } else if (val > pq.top()) {
      pq.pop();
      pq.push(val);
    }

    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */