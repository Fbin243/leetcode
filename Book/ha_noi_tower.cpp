#include <bits/stdc++.h>
using namespace std;

int step = 0;

void move(int n, string A, string B, string C) {
  if (n == 1) {
    cout << "Move disk from " + A + " to " + C << endl;
    step++;
    return;
  }

  // Move n - 1 disks from A to B using C as the auxiliary rod
  move(n - 1, A, C, B);

  // Move the biggest disk from A to C (1 step)
  move(1, A, B, C);

  // Move n - 1 disk from B to C using A as the auxiliary rod
  move(n - 1, B, A, C);
}

int main() {
  move(15, "A", "B", "C");
  cout << "Total step: " << step << endl;
  return 0;
}
