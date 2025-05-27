/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/binary-tree-right-side-view/description/
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
 * Fbin's solution with BFS
 */
class Solution {
 public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int qLen = q.size();
      res.push_back(q.back()->val);
      while (qLen--) {
        TreeNode *t = q.front();
        q.pop();
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
    }

    return res;
  }
};

/**
 * Smart way with DFS
 */
class Solution {
 public:
  vector<int> res;

  vector<int> rightSideView(TreeNode *root) {
    dfs(root, 0);
    return res;
  }

  void dfs(TreeNode *node, int depth) {
    if (!node) return;

    if (res.size() == depth) {
      res.push_back(node->val);
    }

    dfs(node->right, depth + 1);
    dfs(node->left, depth + 1);
  }
};