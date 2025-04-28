/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/valid-sudoku/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 27/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  /**
   * Breakdown:
   * (r / 3) and (c / 3) are used to get the sub-box indexes from the 9x9 box's
   * rows & columns. This means you'll get these values for the sub-boxes
   * (r/3,c/3):
   * 0,0 0,1 0,2
   * 1,0 1,1 1,2
   * 2,0 2,1 2,2
   *
   * Eg. r=2 c=2 -> 2/3 =0, 2/3=0
   * -> r=2 c=2 belongs to the first sub-box. r=4 c=0 -> 4/3=1, 0/3=0 -> r=4 c=0
   * belongs to the 4th sub-box (1,0). Now you just need to find a way to number
   * each of these sub-boxes as an int incrementally:
   * -- 0, 1, 2
   * -- 3, 4, 5
   * -- 6, 7, 8
	 * 
   * You can see that the int is incremented by 3 when going down, and
   * incremented by 1 when going to the right. So (r / 3) * 3 - is for going
   * down (c / 3) * 1 - is for going to the right. You'll get (r / 3 ) * 3 + (c
   * / 3) * 1 --> (r / 3) * 3 + (c / 3).
   *
   * Approach: Hash Table + set
   * Time complexity: O(81) → O(1)
   * rows(9)∗columns(9)=81
   *
   * Space complexity: O(243) → O(1)
   * rows(81)+columns(81)+boxes(81)=243
   */
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, set<char>> rowm;
    unordered_map<int, set<char>> colm;
    unordered_map<int, set<char>> boxm;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        int cell = board[i][j];
        if (!isalnum(cell)) continue;
        int boxIdx = (i / 3) * 3 + (j / 3);
        if (rowm[i].find(cell) != rowm[i].end() ||
            colm[j].find(cell) != colm[j].end() ||
            boxm[boxIdx].find(cell) != boxm[boxIdx].end()) {
          return false;
        }
        rowm[i].insert(board[i][j]);
        colm[j].insert(board[i][j]);
        boxm[boxIdx].insert(board[i][j]);
      }
    }

    return true;
  }
};
