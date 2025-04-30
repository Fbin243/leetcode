/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 30/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Approach: Use two hash maps to store the mapping between characters and
   * words.
   * Split by using stringstream and store the words in a vector.
   */
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> cMap;
    unordered_map<string, char> wMap;
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, ' ')) {
      tokens.push_back(token);
    }

    if (tokens.size() != pattern.length()) return false;

    for (int i = 0; i < pattern.length(); i++) {
      if (cMap.find(pattern[i]) != cMap.end() && cMap[pattern[i]] != tokens[i])
        return false;
      if (wMap.find(tokens[i]) != wMap.end() && wMap[tokens[i]] != pattern[i])
        return false;
      cMap[pattern[i]] = tokens[i];
      wMap[tokens[i]] = pattern[i];
    }

    return true;
  }

  /**
   * Approach: Use two hash maps to store the mapping between characters and
   * words.
   * Split by using find and substr to store the words in a vector.
   */
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> cMap;
    unordered_map<string, char> wMap;
    vector<string> tokens;
    int start = 0;
    int end = 0;

    while ((end = s.find(' ', start)) != string::npos) {
      tokens.push_back(s.substr(start, end - start));
      start = end + 1;
    }
    tokens.push_back(s.substr(start));

    if (tokens.size() != pattern.length()) return false;

    for (int i = 0; i < pattern.length(); i++) {
      if (cMap.find(pattern[i]) != cMap.end() && cMap[pattern[i]] != tokens[i])
        return false;
      if (wMap.find(tokens[i]) != wMap.end() && wMap[tokens[i]] != pattern[i])
        return false;
      cMap[pattern[i]] = tokens[i];
      wMap[tokens[i]] = pattern[i];
    }

    return true;
  }
};
