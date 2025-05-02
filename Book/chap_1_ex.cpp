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

int main() {
  cout << mystery(10) << endl;
  cout << pesky(10) << endl;
  cout << prestiferous(10) << endl;
  cout << conundrum(10) << endl;
}
