/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 30/04/2025
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (string& str : strs) {
      string tmp = str;
      sort(tmp.begin(), tmp.end());
      map[tmp].push_back(str);
    }

    vector<vector<string>> ans;
    for (const auto& [key, strs] : map) {
      ans.push_back(strs);
    }

    return ans;
  }
};
