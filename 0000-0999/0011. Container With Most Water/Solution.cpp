/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 27/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Good explanation. This observation is the most important part:

                After that, we want to move one of the pointers. How can we
   judge it? It's simple. We want to keep taller height between left and right
   because there is a possibility that we will get max area with the taller
   height.

                Perhaps this statement can be made stronger. Other than there is
   a "possibility" that we will get a bigger area with the taller height, it is
   important to assert that there cannot be a bigger area in between the two
   points that contains the lower pointer's point. This fact is what allows us
   to "ignore" any other combination with the lower point and shift the lower
   pointer closer to the middle.

                Approach: Two pointers
                Time: O(n)
                Space: O(1)
   */
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1, res = 0;
    while (l < r) {
      res = max(res, min(height[l], height[r]) * (r - l));
      if (height[l] <= height[r])
        l++;
      else
        r--;
    }

    return res;
  }
};

// --- Solution at 23/05/2025
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int res = 0;
    while (i < j) {
      res = max(res, min(height[i], height[j]) * (j - i));
      if (height[i] > height[j])
        j--;
      else
        i++;
    }

    return res;
  }
};