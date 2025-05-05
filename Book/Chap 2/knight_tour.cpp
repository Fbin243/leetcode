#include <iostream>
using namespace std;

const int n = 5;
int a[n][n];
int step[8][2] = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
                  {1, -2},  {2, -1},  {2, 1},  {1, 2}};

void print_arr() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << "  ";
    }
    cout << endl;
  }
}

bool is_candidate(int r, int c) {
  if (0 <= r && r < n && 0 <= c && c < n && a[r][c] == 0) return true;
  return false;
}

// Find all solutions
/**
 * Approach: Backtracking
 * Time: (8^(n^2))
 * Space: o(n^2)
 */
void knight_tour(int k, int r, int c) {
  if (k == n * n + 1) {
    print_arr();
    cout << endl;
    return;
  }

  for (int i = 0; i < 8; i++) {
    int newR = r + step[i][0];
    int newC = c + step[i][1];
    if (is_candidate(newR, newC)) {
      a[newR][newC] = k;
      knight_tour(k + 1, newR, newC);
      a[newR][newC] = 0;
    }
  }
}

// Find one solution
bool knight_tour_one(int k, int r, int c) {
  if (k == n * n + 1) {
    print_arr();
    cout << endl;
    return true;
  }

  for (int i = 0; i < 8; i++) {
    int newR = r + step[i][0];
    int newC = c + step[i][1];
    if (is_candidate(newR, newC)) {
      a[newR][newC] = k;
      if (knight_tour_one(k + 1, newR, newC)) {
        return true;
      }
      a[newR][newC] = 0;
    }
  }

  return false;
}

int main() {
  // The start point choice can make a solution or not, for example:
  // n = 5 and the start point is (2, 1)
  a[0][0] = 1;
  knight_tour(2, 0, 0);
  // knight_tour_one(2, 0, 0);
  return 0;
}
