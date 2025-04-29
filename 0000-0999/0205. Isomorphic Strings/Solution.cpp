/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 29/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> cMap;
    unordered_map<char, char> cMap2;
    for (int i = 0; i < s.length(); i++) {
      if (cMap[s[i]] && cMap[s[i]] != t[i]) return false;
      if (cMap2[t[i]] && cMap2[t[i]] != s[i]) return false;
      cMap[s[i]] = t[i];
      cMap2[t[i]] = s[i];
    }

    return true;
  }
};
