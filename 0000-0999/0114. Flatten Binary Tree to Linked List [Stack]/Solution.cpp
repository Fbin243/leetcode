/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/simplify-path/description/?envType=problem-list-v2&envId=stack
 * Created at: 12/03/2025
 */

#include <bits/stdc++.h>

using namespace std;

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

/*
class Solution {
   public:
   void traversePreOrder(TreeNode* root, stack<TreeNode*>& st) {
       if (!root) return;
       st.push(root);
       traversePreOrder(root->left, st);
       traversePreOrder(root->right, st);
   }

   void flatten(TreeNode* root) {
       stack<TreeNode*> st;
       traversePreOrder(root, st);
       root = nullptr;
       while (!st.empty()) {
           TreeNode* cur = st.top();
           cout << st.top()->val << endl;
           cur->right = root;
           cur->left = nullptr;
           root = cur;
           st.pop();
       }
   }
};
*/