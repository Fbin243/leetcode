/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 26/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    string res = "";
    vector<string> words;
    string word = "";
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != ' ') {
        word += s[i];
        if (i == s.length() - 1 || s[i + 1] == ' ') {
          words.push_back(word);
          word = "";
        }
      }
    }

    reverse(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++) {
      res += words[i];
      if (i != words.size() - 1) res += ' ';
    }

    return res;
  }
};
