/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/distribute-candies-among-children-ii/description/?envType=daily-question&envId=2025-06-01
 * Created at: 01/06/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach: Backtracking (TLE: 500/958 cases)
 * Time: O(n^3) - n and limit are in range [0, 10e6]
 * Space: O(1)
 */
class Solution {
 private:
  int res = 0;
  vector<int> v = {};
  /** Determine based on the size of set
   * 1 -> 1
   * 2 -> 3
   * 3 -> 6
   */
  vector<int> perm = {1, 3, 6};

 public:
  void print(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << ", ";
    cout << endl;
  }

  void dfs(int n, int limit, int k, int prev) {
    if (k == 3) {
      if (n <= limit) {
        v.push_back(n);
        unordered_set<int> st = {v.begin(), v.end()};
        // print(v);
        res += perm[st.size() - 1];
        v.pop_back();
      }

      return;
    }

    for (int i = prev; i <= min(limit, n); i++) {
      v.push_back(i);
      if (n - i >= i) {
        dfs(n - i, limit, k + 1, i);
      }
      v.pop_back();
    }
  }

  long long distributeCandies(int n, int limit) {
    dfs(n, limit, 1, 0);
    return res;
  }
};

/**
 * Approach: Combination Math: Inclusion-Exclusion Principle - Nguyên lý bù trừ :))
 * Time: O(n)
 * Space: O(1)
 */
class Solution {
 public:
  long long factorial(int n) {
    if (n <= 1) return 1;
    long long ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
  }

  long long combination(int k, int n) {
    if (n <= 0) return 0;
    long long temp = 1;
    for (int i = n; i >= (n - k + 1); i--) temp *= i;
    return temp / factorial(k);
  }

  long long distributeCandies(int n, int limit) {
    limit++;
    long long U = combination(2, n + 2);
    long long A1 = combination(2, n - limit + 2);
    long long A2 = combination(2, n - 2 * limit + 2);
    long long A3 = combination(2, n - 3 * limit + 2);
    return U - (3 * A1 - 3 * A2 + A3);
  }
};