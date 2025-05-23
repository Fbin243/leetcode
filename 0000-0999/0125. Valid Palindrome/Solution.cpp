/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 27/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i <= j) {
      if (!isalnum(s[i])) {
        i++;
        continue;
      }
      if (!isalnum(s[j])) {
        j--;
        continue;
      }
      if (tolower(s[i]) == tolower(s[j])) {
        i++;
        j--;
      } else
        return false;
    }

    return true;
  }
};

// --- Solution at 23/05/2025
class Solution {
 public:
  bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      while (i < j && !isalnum(s[i])) i++;
      while (i < j && !isalnum(s[j])) j--;
      if (tolower(s[i]) != tolower(s[j])) return false;
      i++;
      j--;
    }

    return true;
  }
};