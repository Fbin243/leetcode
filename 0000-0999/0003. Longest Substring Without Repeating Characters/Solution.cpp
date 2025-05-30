/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 27/04/2025
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0, res = 0;
    set<char> st;
    while (r < s.length()) {
      if (st.find(s[r]) != st.end()) {
        while (s[l] != s[r]) {
          st.erase(s[l]);
          l++;
        }
        l++;
      } else {
        st.insert(s[r]);
      }

      res = max(res, r - l + 1);
      r++;
    }

    return res;
  }
};

// --- Solution at 23/05/2025
class Solution {
 public:
  /**
   * Two pointers (Sliding window)
   * Time: O(n)
   * Space: O(1)
   */
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int maxLen = 0, len = 0, l = 0, r = 0;
    while (r < s.length()) {
      while (seen.count(s[r])) {
        seen.erase(s[l++]);
        len--;
      }
      seen.insert(s[r++]);
      len++;
      maxLen = max(maxLen, len);
    }

    return maxLen;
  }
};