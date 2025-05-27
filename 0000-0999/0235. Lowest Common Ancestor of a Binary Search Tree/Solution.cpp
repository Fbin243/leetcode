/**
Author: Fbin
 * Link:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 * Created at: 27/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  TreeNode* lca;

 public:
  /**
   * For general kind of tree
   * Time: O(n)
   * Space: O(n)
   */
  int find(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return 0;

    int found = 0;
    if ((root->val == p->val) || (root->val == q->val)) found++;
    found += find(root->left, p, q) + find(root->right, p, q);

    if (found == 2 && !lca) {
      lca = root;
    }

    return found;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    find(root, p, q);
    return lca;
  }

  /**
   * If the tree is BST we can do more easily like below
   * Time: O(h)
   * Space: O(h)
   */
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    if (p->val < root->val && q->val < root->val)
      return lowestCommonAncestor(root->left, p, q);

    if (p->val > root->val && q->val > root->val)
      return lowestCommonAncestor(root->right, p, q);

    return root;
  }
};