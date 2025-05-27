/**
* Author: Fbin
* Link:https://leetcode.com/problems/kth-largest-element-in-an-array/description/
* Created at: 27/05/2025
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while(--k) {
            pq.pop();
        }

        return pq.top();
    }
};