/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/trapping-rain-water/description/
 * Created at: 23/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

// -- Fbin's solution :) About 700ms
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    int i = 0, j = 0, water = 0;
    while (i < n - 1) {
      j = i + 1;
      int nonWater = 0;
      int maxHeight = height[j];
      while (j < n && height[j] < height[i]) {
        maxHeight = max(maxHeight, height[j]);
        nonWater += height[j++];
      }
      if (j < n) {
        water += height[i] * (j - i - 1) - nonWater;
        i = j;
      } else {
        height[i] = maxHeight;
      }
    }

    return water;
  }
};

// --- Neetcode's solution (0ms)
class Solution {
 public:
  /**
   * Time: O(n)
   * Space: O(n)
   */
  int trap(vector<int>& height) {
    int n = height.size();
    int i = 0, j = 0, water = 0;
    vector<int> maxLeft;
    vector<int> maxRight;
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
      maxLeft.push_back(left);
      left = max(left, height[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
      maxRight.push_back(right);
      right = max(right, height[i]);
    }

    reverse(maxRight.begin(), maxRight.end());

    for (int i = 0; i < n; i++) {
      water += max(0, min(maxLeft[i], maxRight[i]) - height[i]);
    }

    return water;
  }

  /**
   * Time: O(n)
   * Space: O(1)
   */
  int trap(vector<int>& height) {
    int n = height.size();
    int i = 0, j = n - 1, water = 0, maxLeft = 0, maxRight = 0;
    while (i <= j) {
      if (height[i] < height[j]) {
        water += max(0, maxLeft - height[i]);
        maxLeft = max(maxLeft, height[i]);
        i++;
      } else {
        water += max(0, maxRight - height[j]);
        maxRight = max(maxRight, height[j]);
        j--;
      }
    }

    return water;
  }
};