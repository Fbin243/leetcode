/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/count-complete-tree-nodes/description/?envType=problem-list-v2&envId=binary-search
 * Created at: 05/04/2025
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
  int countNodes(TreeNode *root) {
    if (!root) return 0;

    int leftHeight = 0;
    int rightHeight = 0;
    TreeNode *leftNode = root;
    TreeNode *rightNode = root;

    while (leftNode) {
      leftHeight++;
      leftNode = leftNode->left;
    }

    while (rightNode) {
      rightHeight++;
      rightNode = rightNode->right;
    }

    if (leftHeight == rightHeight) {
      return (1 << leftHeight) - 1;  // 2^h - 1
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};