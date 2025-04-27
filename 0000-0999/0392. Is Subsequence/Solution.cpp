/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 27/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    if (s.length() == 0) return true;
    while (j < t.length()) {
      if (t[j] == s[i]) {
        i++;
        if (i == s.length()) return true;
      }
      j++;
    }

    return false;
  }
};
