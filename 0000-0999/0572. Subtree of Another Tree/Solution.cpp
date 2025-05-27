/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/subtree-of-another-tree/description/
 * Created at: 27/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2 || t1->val != t2->val) return false;
    return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
  }

  /**
   * Time: O(m * n) - m is the number of nodes of root, n is the number of nodes
   * of subRoot
   * Space: O(m + n)
   */
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot) return true;
    if (!root) return false;
    if (isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};