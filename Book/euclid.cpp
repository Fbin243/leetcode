#include <bits/stdc++.h>
using namespace std;

int naive_gcd(int a, int b) {
  for (int i = min(a, b); i >= 1; i--) {
    if (a % i == 0 && b % i == 0) return i;
  }
  return -1;
}

int rec_euclid_gcd(int a, int b) {
  if (a == 0 || b == 0) return a + b;
  if (a < b) swap(a, b);
  return rec_euclid_gcd(a % b, b);
}

int iter_euclid_gcd(int a, int b) {
  while (a != 0 && b != 0) {
    if (a < b) swap(a, b);
    a = a % b;
  }

  return a + b;
}

int main() {
  int a = 1022;
  int b = 1022;
  cout << naive_gcd(a, b) << endl;
  cout << rec_euclid_gcd(a, b) << endl;
  cout << iter_euclid_gcd(a, b) << endl;
  return 0;
}
