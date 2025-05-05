#include <iostream>
#include <vector>
using namespace std;

int count = 0;
bool IsCandidate(vector<int>& a, int r, int c) {
  for (int i = 0; i < r; i++) {
    if ((a[i] == c) || (r - i == abs(c - a[i]))) {
      return false;
    }
  }

  return true;
}

void Queen(vector<int>& a, int i, int n) {
  if (i == n) {
    count++;
    for (int i = 0; i < a.size(); i++) {
      cout << a[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int j = 0; j < n; j++) {
    if (IsCandidate(a, i, j)) {
      a.push_back(j);
      Queen(a, i + 1, n);
      a.pop_back();
    }
  }
}

int main() {
  int n = 10;
  vector<int> a;
  Queen(a, 0, n);
  cout << "Total ways: " << count;

  return 0;
}
