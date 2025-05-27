/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
 * Fbin's solution: Recursive DFS
 */
class Solution {
 private:
  int count = 0;
  int res;

 public:
  void dfs(TreeNode *root, int k) {
    if (!root) return;
    dfs(root->left, k);
    count++;
    if (count == k) {
      res = root->val;
    }
    dfs(root->right, k);
  }
  int kthSmallest(TreeNode *root, int k) {
    dfs(root, k);
    return res;
  }

  /**
   * Neetcode: Iterative DFS
   */
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> st;
    TreeNode *cur = root;
    int cnt = 0;

    while (cur || !st.empty()) {
      // Go to the left child
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }

      // Handle the node
      cur = st.top();
      st.pop();
      cnt++;
      if (cnt == k) return cur->val;

      // Go to the right child
      cur = cur->right;
    }

    return -1;
  }
};