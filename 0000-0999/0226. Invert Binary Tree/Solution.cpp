/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/invert-binary-tree/
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
  TreeNode *invertTree(TreeNode *root) {
    if (!root) return nullptr;
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);

    return root;
  }
};