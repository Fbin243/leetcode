/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/balanced-binary-tree/description/
 * Created at: 27/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  bool isBal;

 public:
  /**
   * Mutate global variable
   */
  int height(TreeNode *root) {
    if (!root) return -1;
    int hLeft = height(root->left);
    int hRight = height(root->right);
    isBal = isBal && (abs(hLeft - hRight) <= 1);
    return 1 + max(hLeft, hRight);
  }

  bool isBalanced(TreeNode *root) {
    isBal = true;
    height(root);
    return isBal;
  }

  /**
   * Use pair or array to store both height and balance factor of each node
   */
  vector<int> dfs(TreeNode *root) {
    if (!root) return {1, -1};

    vector<int> left = dfs(root->left);
    vector<int> right = dfs(root->right);

    int height = max(left[1], right[1]) + 1;
    if (left[0] && right[0] && abs(left[1] - right[1]) <= 1) return {1, height};
    return {0, height};
  }
  bool isBalanced(TreeNode *root) { return dfs(root)[0]; }
};