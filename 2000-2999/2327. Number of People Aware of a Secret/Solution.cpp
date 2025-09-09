/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/?envType=daily-question&envId=2025-09-09
 * Created at: 09/09/2025
 */

#include <fbin/leetcode.h>
using namespace std;

class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    long long share = 0, MOD = 1000000007;
    for (int t = 2; t <= n; t++) {
      if (t - delay > 0)
        share = (share + dp[t - delay] + MOD) % MOD;
      if (t - forget > 0)
        share = (share - dp[t - forget] + MOD) % MOD;
      dp[t] = share;
    }
    long long know = 0;
    for (int i = n - forget + 1; i <= n; i++)
      know = (know + dp[i]) % MOD;
    return (int)know;
  }
};
