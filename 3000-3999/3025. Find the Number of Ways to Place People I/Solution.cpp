/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/?envType=daily-question&envId=2025-09-02
 * Created at: 02/09/2025
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfPairs(vector<vector<int>>& points) {
    int ans = 0;
    sort(points.begin(), points.end(), comp);
    for (int j = points.size() - 1; j >= 0; --j) {
      int x = points[j][0];
      int y = points[j][1];
      int mny = 1e9;
      for (int i = j - 1; i >= 0; --i) {
        int xx = points[i][0];
        int yy = points[i][1];
        if (yy >= mny || yy < y) continue;
        ++ans;
        mny = yy;
      }
    }
    return ans;
  }

 private:
  static bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
  }
};
