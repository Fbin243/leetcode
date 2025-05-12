/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 27/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int i = 0, j = 0;
    int n = haystack.length();
    int m = needle.length();
    while (i < n) {
      j = 0;
      int start = i;
      while (start < n && j < m && needle[j] == haystack[start]) {
        start++;
        j++;
      }

      if (j == m) return i;
      i++;
    }

    return -1;
  }
};
