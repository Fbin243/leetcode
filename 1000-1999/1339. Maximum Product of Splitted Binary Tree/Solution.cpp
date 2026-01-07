/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-10
 * Created at: 07/01/2026
 */

#include <fbin/leetcode.h>

/**
 * Definition for a binary tree node.
The sum of first subtree is S
The sum of second subtree is TotalSum - S
=> Maximize the value of this expr: S * (TotalSum - S)
 */

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
  vector<long> allSums;

  long treeSum(TreeNode* root) {
    if (root == nullptr) return 0;
    long leftSum = treeSum(root->left);
    long rightSum = treeSum(root->right);
    long sum = root->val + leftSum + rightSum;
    allSums.push_back(sum);
    return sum;
  }

  int maxProduct(TreeNode* root) {
    long maxProd = 0;
    long totalSum = treeSum(root);
    for (long sum : allSums) {
      maxProd = max(maxProd, sum * (totalSum - sum));
    }

    return maxProd % static_cast<long>(pow(10, 9) + 7);
  }
};
