/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * Created at: 23/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Two pointers (Sliding window)
   * Time: O(n)
   * Space: O(1)
   */
  int maxProfit(vector<int>& prices) {
    int i = 0, j = 1, maxProfit = 0;
    while (j < prices.size()) {
      if (prices[i] < prices[j]) {
        maxProfit = max(maxProfit, prices[j] - prices[i]);
      } else {
        i = j;
      }
      j++;
    }

    return maxProfit;
  }
};