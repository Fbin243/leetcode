/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 26/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) return s;
    vector<string> strs(numRows, "");
    int k = (numRows - 1) * 2;
    for (int i = 0; i < s.length(); i++) {
      strs[i % k < numRows ? i % k : k - i % k] += s[i];
    }

    string res = "";
    for (int i = 0; i < numRows; i++) {
      res += strs[i];
    }

    return res;
  }
};
