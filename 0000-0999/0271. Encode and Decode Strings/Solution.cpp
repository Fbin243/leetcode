/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/encode-and-decode-strings/description/
 * Neetcode:https://neetcode.io/problems/string-encode-and-decode
 * Created at: 22/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string encode(vector<string>& strs) {
    string res = "";
    for (string str : strs) {
      res += to_string(str.length()) + "#" + str;
    }

    return res;
  }

  vector<string> decode(string s) {
    vector<string> res;
    int numChar = 0;
    bool foundDelimeter = false;
    string str = "";
    for (char c : s) {
      if (!foundDelimeter && isdigit(c)) {
        numChar = numChar * 10 + (c - '0');
      } else if (!foundDelimeter && c == '#') {
        if (numChar > 0) {
          foundDelimeter = true;
        } else {
          res.push_back(str);
        }
      } else {
        str += c;
        numChar--;
        if (numChar == 0) {
          res.push_back(str);
          foundDelimeter = false;
          str = "";
        }
      }
    }

    return res;
  }
};
