/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/permutation-in-string/description/
 * Created at: 24/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Neetcode's solution
 * Time: O(n) - n is the length of s2
 * Space: O(26)
 */
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2) return false;
    int l = 0, r = n1, matches = 26;
    int freq1[26] = {}, freq2[26] = {};
    for (int i = 0; i < n1; i++) {
      freq1[s1[i] - 'a']++;
      freq2[s2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      if (freq1[i] != freq2[i]) matches--;
    }

    while (r < n2) {
      if (matches == 26) return true;
      if (s2[l] != s2[r]) {
        freq2[s2[l] - 'a']--;
        freq2[s2[r] - 'a']++;
        if (freq2[s2[l] - 'a'] + 1 == freq1[s2[l] - 'a']) matches--;
        if (freq2[s2[r] - 'a'] == freq1[s2[r] - 'a'] + 1) matches--;
        if (freq2[s2[l] - 'a'] == freq1[s2[l] - 'a']) matches++;
        if (freq2[s2[r] - 'a'] == freq1[s2[r] - 'a']) matches++;
      }
      l++;
      r++;
    }

    return matches == 26;
  }
};

/**
 * Fbin's solution
 * Time: O(26n) - n is the length of s2
 * Space: O(26)
 */
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2) return false;
    int l = 0, r = n1 - 1;
    int freq1[26] = {}, freq2[26] = {};
    for (int i = 0; i < n1; i++) {
      freq1[s1[i] - 'a']++;
      freq2[s2[i] - 'a']++;
    }

    while (r < n2) {
      bool isIncluded = true;
      for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
          isIncluded = false;
          break;
        }
      }

      if (isIncluded) return true;
      freq2[s2[l] - 'a']--;
      if (r + 1 < n2) freq2[s2[r + 1] - 'a']++;
      l++;
      r++;
    }

    return false;
  }
};