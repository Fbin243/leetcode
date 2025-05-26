/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/time-based-key-value-store/description/
 * Created at: 26/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
 private:
  unordered_map<string, vector<pair<string, int>>> mp;

 public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mp[key].push_back({value, timestamp});
  }

  string get(string key, int timestamp) {
    int l = 0, r = mp[key].size() - 1;
    string res = "";
    int resIdx = 0;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (mp[key][m].second <= timestamp) {
        res = mp[key][m].first;
        l = m + 1;
      } else
        r = m - 1;
    }

    return res;
  }
};

// Shorter version (not use accumulative variable)
class TimeMap {
 private:
  unordered_map<string, vector<pair<string, int>>> mp;

 public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mp[key].push_back({value, timestamp});
  }

  string get(string key, int timestamp) {
    int l = 0, r = mp[key].size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;

      if (mp[key][m].second == timestamp) {
        return mp[key][m].first;
      }

      if (mp[key][m].second < timestamp) {
        l = m + 1;
      } else
        r = m - 1;
    }

    return r >= 0 ? mp[key][r].first : "";
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */