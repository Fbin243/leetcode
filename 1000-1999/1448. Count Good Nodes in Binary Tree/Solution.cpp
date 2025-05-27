/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
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
 * Fbin's solution with DFS
 * Time: O(1)
 * Space: O(h) - h is the height of the tree
 */
class Solution {
 private:
  int count = 0;

 public:
  void dfs(TreeNode *root, int maxVal) {
    if (!root) return;
    if (root->val >= maxVal) {
      count++;
      maxVal = root->val;
    }

    dfs(root->left, maxVal);
    dfs(root->right, maxVal);
  }

  int goodNodes(TreeNode *root) {
    dfs(root, -10e4 - 1);
    return count;
  }
};

/**
 * Fbin's another one with BFS approach :)
 */
class Solution {
 public:
  int goodNodes(TreeNode *root) {
    int count = 0;
    if (!root) return count;
    queue<pair<TreeNode *, int>> q;
    q.push({root, -10e4 - 1});

    while (!q.empty()) {
      int qLen = q.size();
      while (qLen--) {
        pair<TreeNode *, int> p = q.front();
        q.pop();
        if (p.first->val >= p.second) count++;
        int maxVal = max(p.first->val, p.second);
        if (p.first->left) q.push({p.first->left, maxVal});
        if (p.first->right) q.push({p.first->right, maxVal});
      }
    }

    return count;
  }
};