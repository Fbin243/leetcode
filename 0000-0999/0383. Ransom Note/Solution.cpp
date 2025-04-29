/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 29/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int freq[26];
    for (char& c : magazine) {
      freq[c - 'a']++;
    }

    for (char& c : ransomNote) {
      freq[c - 'a']--;
      if (freq[c - 'a'] < 0) return false;
    }

    return true;
  }
};
