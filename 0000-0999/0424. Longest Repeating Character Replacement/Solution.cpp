/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/longest-repeating-character-replacement/description/
 * Created at: 23/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Time: O(26n)
 * Space: O(26)
 */
class Solution {
 public:
  int getMaxFreq(int freq[26]) {
    int maxF = freq[0];
    for (int i = 1; i < 26; i++) {
      maxF = max(maxF, freq[i]);
    }

    return maxF;
  }
  int characterReplacement(string s, int k) {
    int freq[26] = {};
    int i = 0, j = 0, res = 0;
    while (j < s.length()) {
      freq[s[j] - 'A']++;
      while (j - i + 1 - getMaxFreq(freq) > k) {
        freq[s[i] - 'A']--;
        i++;
      }
      res = max(res, j - i + 1);
      j++;
    }

    return res;
  }
};

/**
 * Fbin's solution - Using 2 while
 */
class Solution {
 public:
  int characterReplacement(string s, int k) {
    int l, r, res = 0, orgK = k;
    for (int i = 0; i < 26; i++) {
      l = 0, r = 0, k = orgK;
      while (r < s.length()) {
        while (k == 0 && s[r] != 'A' + i) {
          if (s[l] != 'A' + i) k++;
          l++;
        }
        if (s[r] != 'A' + i) k--;
        res = max(res, r - l + 1);
        r++;
      }
    }

    return res;
  }
};

/**
 * Fbin's solution - Using if/else
 */
class Solution {
 public:
  int characterReplacement(string s, int k) {
    int l = 0, r = 0, res = 0, orgK = k;
    for (int i = 0; i < 26; i++) {
      l = 0, r = 0, k = orgK;
      while (r < s.length()) {
        if (k == 0 && s[r] != 'A' + i) {
          if (s[l] != 'A' + i) k++;
          l++;
        } else {
          if (s[r] != 'A' + i) k--;
          res = max(res, r - l + 1);
          r++;
        }
      }
    }

    return res;
  }
};

// --- Other problem when we just can map A -> B for all operations
class Solution {
 public:
  int getMinValue(unordered_map<char, int>& mp) {
    int minVal = INT_MAX;
    for (auto& [k, v] : mp) {
      minVal = min(minVal, v);
    }

    return minVal;
  }

  int characterReplacement(string s, int k) {
    unordered_map<char, int> mp;
    int l = 0, r = 0, res = 0;
    while (r < s.length()) {
      mp[s[r]]++;
      while (mp.size() > 2 || (mp.size() == 2 && getMinValue(mp) > k)) {
        mp[s[l]]--;
        if (mp[s[l]] == 0) {
          mp.erase(s[l]);
        }
        l++;
      }
      cout << l << " " << r << endl;
      res = max(res, r - l + 1);
      r++;
    }

    return res;
  }
};
