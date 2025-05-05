#include <iostream>
using namespace std;

const int n = 5;
int a[n][n];
int magic_constant = n * (n * n + 1) / 2;
int sumRow = 0;
int sumCol = 0;
int sumMainDiag = 0;
int sumAuxDiag = 0;

bool is_candidate(int r, int c) {
  sumRow = 0;
  sumCol = 0;
  sumMainDiag = 0;
  sumAuxDiag = 0;
  for (int i = 0; i < n; i++) {
    sumRow += a[r][i];
    sumCol += a[i][c];
    sumMainDiag += a[i][i];
    sumAuxDiag += a[i][n - 1 - i];
    if (sumRow > magic_constant || sumCol > magic_constant ||
        sumMainDiag > magic_constant || sumAuxDiag > magic_constant)
      return false;
  }

  return true;
}

void print_arr() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << "  ";
    }
    cout << endl;
  }
}

bool magic_square(int k) {
  cout << k << endl;
  if (k == n * n + 1 && sumRow == magic_constant && sumCol == magic_constant &&
      sumMainDiag == magic_constant && sumAuxDiag == magic_constant) {
    print_arr();
    cout << endl;
    return true;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        a[i][j] = k;
        if (is_candidate(i, j)) {
          magic_square(k + 1);
        }
        a[i][j] = 0;
      }
    }
  }

  return false;
}

int main() {
  magic_square(1);
  return 0;
}
