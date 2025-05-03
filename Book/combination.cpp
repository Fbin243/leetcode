#include <bits/stdc++.h>
using namespace std;

int C_n_k(int n, int k) {
  if (k == n || k == 0) return 1;
  return C_n_k(n - 1, k) + C_n_k(n - 1, k - 1);
}

int C_n_k_memo(vector<vector<int>>& memo, int n, int k) {
  if (memo[n][k] > 0) return memo[n][k];
  if (k == n || k == 0)
    memo[n][k] = 1;
  else
    memo[n][k] = C_n_k_memo(memo, n - 1, k) + C_n_k_memo(memo, n - 1, k - 1);
  return memo[n][k];
}

int C_n_k_iter(int n, int k) {
  int ans = 1;
  for (int i = 1; i <= k; i++) {
    ans = ans * ((n - i + 1) * 1.0 / i);
  }

  return ans;
}

void print_pascal_triangle(int n) {
  for (int i = 0; i <= n; i++) {
    for (int k = 0; k <= i; k++) {
      cout << C_n_k(i, k) << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> memo(10, vector<int>(10, 0));
  cout << C_n_k(6, 4) << endl;
  cout << C_n_k_memo(memo, 6, 4) << endl;
  cout << C_n_k_iter(6, 4) << endl;
  print_pascal_triangle(5);
  return 0;
}
