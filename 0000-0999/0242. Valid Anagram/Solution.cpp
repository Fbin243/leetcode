/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 30/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    int freq[26];
    for (int i = 0; i < s.length(); i++) {
      freq[s[i] - 'a']++;
      freq[t[i] - 'a']--;
    }

    for (int& f : freq) {
      if (f != 0) return false;
    }

    return true;
  }
};
