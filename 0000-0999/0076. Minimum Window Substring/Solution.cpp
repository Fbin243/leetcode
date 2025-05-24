/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/minimum-window-substring/description/
 * Created at: 24/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * TLE if checking with isIncluded
   */
  bool isIncluded(unordered_map<char, int> m1, unordered_map<char, int> m2) {
    for (pair<char, int> p : m1) {
      if (p.second > m2[p.first]) return false;
    }
    return true;
  }

  /**
   * Time: O(n) - n is the length of s
   * Space: O(1)
   */
  string minWindow(string s, string t) {
    if (s.length() < t.length()) return "";
    unordered_map<char, int> freqT, freqS;
    for (int i = 0; i < t.length(); i++) {
      freqT[t[i]]++;
    }

    int l = 0, r = 0, minLen = INT_MAX, mL = 0, mR = 0, matches = 0,
        matchSize = freqT.size();
    while (r < s.length()) {
      freqS[s[r]]++;
      if (freqS[s[r]] == freqT[s[r]]) matches++;
      while (matches == matchSize) {
        if (r - l + 1 < minLen) {
          mL = l;
          mR = r;
          minLen = r - l + 1;
        }
        freqS[s[l]]--;
        if (freqS[s[l]] + 1 == freqT[s[l]]) matches--;
        l++;
      }

      r++;
    }

    return minLen == INT_MAX ? "" : s.substr(mL, minLen);
  }
};