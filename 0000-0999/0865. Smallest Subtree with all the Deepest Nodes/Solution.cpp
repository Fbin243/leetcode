/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-13
 * Created at: 14/01/2026
 */

#include <fbin/leetcode.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// Approach 1: Fbin's DFS
class Solution {
 public:
  TreeNode* res;
  int deepestNodeCount = 0;
  int maxDepth = 0;

  int calcMaxDepth(TreeNode* root) {
    if (root == nullptr) return -1;
    return 1 + max(calcMaxDepth(root->left), calcMaxDepth(root->right));
  }

  int DFS(TreeNode* root, int depth) {
    if (root == nullptr) return 0;
    int nodeCount = 0;
    if (depth == maxDepth) nodeCount = 1;
    nodeCount += DFS(root->left, depth + 1) + DFS(root->right, depth + 1);
    if (nodeCount > deepestNodeCount) {
      deepestNodeCount = nodeCount;
      res = root;
    }
    return nodeCount;
  }

  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    res = root;
    maxDepth = calcMaxDepth(root);
    DFS(root, 0);
    return res;
  }
};
