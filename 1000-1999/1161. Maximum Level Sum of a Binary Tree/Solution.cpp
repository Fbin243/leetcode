/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06
 * Created at: 06/01/2026
 */

#include <fbin/leetcode.h>

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
  int maxLevelSum(TreeNode* root) {
    int maxSum = INT_MIN;
    int sum = 0;
    int maxLevel = 1;
    int level = 1;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      sum = 0;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode* t = q.front();
        q.pop();
        if (t->left != nullptr) {
          q.push(t->left);
        }
        if (t->right != nullptr) {
          q.push(t->right);
        }
        sum += t->val;
      }
      if (maxSum < sum) {
        maxSum = sum;
        maxLevel = level;
      }
      level++;
    }
    return maxLevel;
  }
};
