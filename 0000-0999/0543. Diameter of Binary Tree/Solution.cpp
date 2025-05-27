/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/diameter-of-binary-tree/description/
 * Created at: 26/05/2025
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
 public:
  /**
   * Time: O(n) - Visit each node once
   * Space: O(h) = O(logn) - If the tree is balanced / O(n) - If the tree is not
   * balanced.
   */
  int find_diam_edges(TreeNode *t, int &diam) {
    if (!t) return -1;
    int leftHeight = find_diam_edges(t->left, diam);
    int rightHeight = find_diam_edges(t->right, diam);
    diam = max(diam, 2 + leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
  }

  int diameterOfBinaryTree(TreeNode *root) {
    int diam = 0;
    find_diam_edges(root, diam);
    return diam;
  }
};