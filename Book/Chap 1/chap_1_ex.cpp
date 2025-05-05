#include <bits/stdc++.h>
using namespace std;

int mystery(int n) {
  int r = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = 1; k <= j; k++) r = r + 1;
  return r;
}

int pesky(int n) {
  int r = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      for (int k = j; k <= i + j; k++) r = r + 1;
  return r;
}

int prestiferous(int n) {
  int r = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      for (int k = j; k <= i + j; k++)
        for (int l = 1; l <= i + j - k; l++) r = r + 1;
  return r;
}

int conundrum(int n) {
  int r = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = i + j - 1; k <= n; k++) r = r + 1;
  return r;
}

int ex_14(int n) {
  int count = 0;
  for (int i = 1; i <= n / 2; i++)
    for (int j = i; j <= n - i; j++)
      for (int k = 1; k <= j; k++) {
        printf("Hello");
        count++;
      }
  return count;
}

vector<vector<int>> multiply_matrix(vector<vector<int>>& A,
                                    vector<vector<int>>& B) {
  int x = A.size();
  int y = A[0].size();
  int z = B[0].size();
  vector<vector<int>> C(x, vector<int>(z, 0));
  for (int i = 0; i < x; i++) {
    for (int k = 0; k < z; k++) {
      for (int j = 0; j < y; j++) {
        C[i][k] += A[i][j] * B[j][k];
      }
      cout << C[i][k] << " ";
    }
    cout << endl;
  }

  return C;
}

int main() {
  cout << mystery(10) << endl;
  cout << pesky(10) << endl;
  cout << prestiferous(10) << endl;
  cout << conundrum(4) << endl;
  cout << ex_14(10) << endl;

  vector<vector<int>> A = {{1, 0, 1}, {2, 1, 0}};
  vector<vector<int>> B = {{1, 3}, {5, 1}, {1, 0}};
  multiply_matrix(A, B);
}
