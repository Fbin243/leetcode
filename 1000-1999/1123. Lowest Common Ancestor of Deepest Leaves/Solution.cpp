/**
* Author: Fbin
* Link:https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* res;
    int deepestNodeCount = 0;
    int maxDepth = 0;

    int calcMaxDepth(TreeNode* root) {
        if(root == nullptr) return -1;
        return 1 + max(calcMaxDepth(root->left), calcMaxDepth(root->right));
    }

    int DFS(TreeNode* root, int depth) {
        if(root == nullptr) return 0;
        int nodeCount = 0;
        if(depth == maxDepth) nodeCount = 1;
        nodeCount += DFS(root->left, depth + 1) + DFS(root->right, depth + 1);
        if(nodeCount > deepestNodeCount) {
            deepestNodeCount = nodeCount;
            res = root;
        }
        return nodeCount;
    }


    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        res = root;
        maxDepth = calcMaxDepth(root);
        DFS(root, 0);
        return res;
    }
};
