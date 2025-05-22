/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/top-k-frequent-elements/description/
 * Created at: 20/05/2025
 */

#include <bits/stdc++.h>
using namespace std;
struct Compare {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
  }
};

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++) {
      freq[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    for (pair<int, int> f : freq) {
      pq.push(f);
    }

    vector<int> res;
    while (!pq.empty() && k > 0) {
      pair<int, int> p = pq.top();
      pq.pop();
      res.push_back(p.first);
      k--;
    }

    return res;
  }
};

// --- Solution 2 (Use lambda function)
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counter;
    for (int n : nums) {
      counter[n]++;
    }

    auto comp = [](pair<int, int>& a, pair<int, int>& b) {
      return a.second < b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(
        comp);

    for (auto& entry : counter) {
      heap.push({entry.first, entry.second});
    }

    vector<int> res;
    while (k-- > 0) {
      res.push_back(heap.top().first);
      heap.pop();
    }

    return res;
  }
};