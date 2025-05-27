/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/validate-binary-search-tree/description/
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

/**
 * Fbin's solution
 * Time: O(n)
 * Space: O(h)
 */
class Solution {
 private:
  long curVal = -2147483649;

 public:
  bool isValidBST(TreeNode *root) {
    if (!root) return true;

    bool isValid = isValidBST(root->left);
    if (root->val > curVal) {
      curVal = root->val;
    } else
      isValid = false;
    isValid = isValid && isValidBST(root->right);
    return isValid;
  }
};

/**
 * Neetcode's solution - DFS
 * Time: O(n)
 * Space: O(h)
 */
class Solution {
 public:
  bool isValidBST(TreeNode *root) { return valid(root, LONG_MIN, LONG_MAX); }

  bool valid(TreeNode *node, long left, long right) {
    if (!node) {
      return true;
    }
    if (!(left < node->val && node->val < right)) {
      return false;
    }
    return valid(node->left, left, node->val) &&
           valid(node->right, node->val, right);
  }
};