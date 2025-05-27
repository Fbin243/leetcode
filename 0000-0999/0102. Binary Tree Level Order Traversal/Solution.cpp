/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
  vector<vector<int>> res;

 public:
  /**
   * Fbin's solution
   */
  void bfs(TreeNode *root) {
    if (!root) return;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int level = 0;
    vector<int> v;
    while (!q.empty()) {
      pair<TreeNode *, int> p = q.front();
      q.pop();

      if (p.first->left) q.push({p.first->left, p.second + 1});
      if (p.first->right) q.push({p.first->right, p.second + 1});

      if (p.second > level) {
        level = p.second;
        res.push_back(v);
        v = {};
      }

      v.push_back(p.first->val);
    }

    res.push_back(v);
  }

  vector<vector<int>> levelOrder(TreeNode *root) {
    bfs(root);
    return res;
  }

  /**
   * BFS standard version
   */
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int qLen = q.size();
      vector<int> v = {};

      while (qLen--) {
        TreeNode *t = q.front();
        q.pop();
        v.push_back(t->val);
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }

      res.push_back(v);
    }

    return res;
  }

  /**
   * Smart way with DFS approach
   */
  vector<vector<int>> levelOrder(TreeNode *root) {
    dfs(root, 0);
    return res;
  }

  void dfs(TreeNode *node, int depth) {
    if (!node) return;

    if (res.size() == depth) {
      res.push_back(vector<int>());
    }

    res[depth].push_back(node->val);
    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
  }
};