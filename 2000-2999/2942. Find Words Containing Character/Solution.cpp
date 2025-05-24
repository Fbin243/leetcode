/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-words-containing-character/description/?envType=daily-question&envId=2025-05-24
 * Created at: 24/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> res;
    for (int i = 0; i < words.size(); i++) {
      if (words[i].find(x) != string::npos) {
        res.push_back(i);
      }
    }

		return res;
  }
};