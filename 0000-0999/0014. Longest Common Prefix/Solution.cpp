/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 26/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int i = 0;
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];

    while (true) {
      for (int j = 1; j < strs.size(); j++) {
        if (i == strs[j].length() || strs[j][i] != strs[j - 1][i])
          return strs[0].substr(0, i);
      }
      i++;
    }

    return "";
  }
};
