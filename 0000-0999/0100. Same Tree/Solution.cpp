/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/same-tree/description/
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
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if ((!p && q) || (p && !q)) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

  /**
   * Iterative DFS
   */
  bool isSameTree(TreeNode *p, TreeNode *q) {
    stack<pair<TreeNode *, TreeNode *>> stk;
    stk.push({p, q});

    while (!stk.empty()) {
      auto [node1, node2] = stk.top();
      stk.pop();

      if (!node1 && !node2) continue;
      if (!node1 || !node2 || node1->val != node2->val) return false;

      stk.push({node1->right, node2->right});
      stk.push({node1->left, node2->left});
    }

    return true;
  }
};