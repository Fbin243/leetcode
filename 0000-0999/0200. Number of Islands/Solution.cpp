/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/number-of-islands/description/
 * Created at: 27/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  unordered_set<int> visited;

 public:
  void bfs(vector<vector<char>>& grid, int r, int c) {
    int row = grid.size();
    int col = grid[0].size();

    queue<pair<int, int>> q;
    q.push({r, c});
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      for (auto& [dr, dc] : directions) {
        int newR = p.first + dr;
        int newC = p.second + dc;
        if (0 <= newR && newR < row && 0 <= newC && newC < col &&
            !visited.count(newR * col + newC) && grid[newR][newC] == '1') {
          q.push({newR, newC});
          visited.insert(newR * col + newC);
        }
      }
    }
  }

  void dfs_iterative(vector<vector<char>>& grid, int r, int c) {
    int row = grid.size();
    int col = grid[0].size();

    deque<pair<int, int>> q;
    q.push_back({r, c});
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    while (!q.empty()) {
      auto p = q.back();
      q.pop_back();
      for (auto& [dr, dc] : directions) {
        int newR = p.first + dr;
        int newC = p.second + dc;
        if (0 <= newR && newR < row && 0 <= newC && newC < col &&
            !visited.count(newR * col + newC) && grid[newR][newC] == '1') {
          q.push_back({newR, newC});
          visited.insert(newR * col + newC);
        }
      }
    }
  }

  int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) return 0;

    int islands = 0;
    int row = grid.size();
    int col = grid[0].size();
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (!visited.count(r * col + c) && grid[r][c] == '1') {
          bfs(grid, r, c);
          islands++;
        }
      }
    }

    return islands;
  }
};