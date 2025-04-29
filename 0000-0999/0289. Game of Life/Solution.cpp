/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 29/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach: To generate the next state in-place, we need to keep the old and
new state simultaneously by using encoding like below:
[2nd bit, 1st bit] = [next state, current state]

- 00  dead (next) <- dead (current)
- 01  dead (next) <- live (current)
- 10  live (next) <- dead (current)
- 11  live (next) <- live (current)

 * Time: O(m*n)
 * Space: O(1)
 */

class Solution {
 public:
  int countLiveNeighbors(vector<vector<int>>& board, int y, int x) {
    int count = 0;
    int m = board.size();
    int n = board[0].size();
    for (int i = max(0, y - 1); i <= min(m - 1, y + 1); i++) {
      for (int j = max(0, x - 1); j <= min(n - 1, x + 1); j++) {
        if (i != y || j != x) count += board[i][j] & 1;
      }
    }

    return count;
  }

  void gameOfLife(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        int liveNeighbors = countLiveNeighbors(board, i, j);
        if ((board[i][j] && (liveNeighbors == 2 || liveNeighbors == 3)) ||
            (!board[i][j] && liveNeighbors == 3)) {
          board[i][j] += 2;
        }
      }
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        board[i][j] = board[i][j] >> 1;
      }
    }
  }
};
