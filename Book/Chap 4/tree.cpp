#include <iostream>
using namespace std;

struct TreeNode {
  char val;
  TreeNode* left;
  TreeNode* right;
};

void freeTree(TreeNode* t) {
  if (!t) return;
  freeTree(t->left);
  freeTree(t->right);
  delete t;
}

// Preorder = NLR
void printPreorder(TreeNode* t) {
  if (!t) return;
  cout << t->val << " ";
  printPreorder(t->left);
  printPreorder(t->right);
}

// Postorder = LRN
void printPostorder(TreeNode* t) {
  if (!t) return;
  printPostorder(t->left);
  printPostorder(t->right);
  cout << t->val << " ";
}

// Inorder = LNR
void printInorder(TreeNode* t) {
  if (!t) return;
  printInorder(t->left);
  cout << t->val << " ";
  printInorder(t->right);
}

int countNodes(TreeNode* t) {
  if (!t) return 0;
  return 1 + countNodes(t->left) + countNodes(t->right);
}

int depth(TreeNode* t) {
  if (!t) return -1;
  return 1 + max(depth(t->left), depth(t->right));
}

int main() {
  TreeNode* root = new TreeNode{
      'a',
      new TreeNode{'b',
                   new TreeNode{'d', new TreeNode{'h', nullptr, nullptr},
                                new TreeNode{'i', nullptr, nullptr}},
                   new TreeNode{'e', new TreeNode{'j', nullptr, nullptr},
                                new TreeNode{'k', nullptr, nullptr}}},
      new TreeNode{'c', new TreeNode{'f', nullptr, nullptr},
                   new TreeNode{'g', nullptr, nullptr}},
  };

  cout << "Preorder: ";
  printPreorder(root);
  cout << endl;

  cout << "Postorder: ";
  printPostorder(root);
  cout << endl;

  cout << "Inorder: ";
  printInorder(root);
  cout << endl;

  cout << "Number of nodes: " << countNodes(root) << endl;
  cout << "Depth of tree: " << depth(root) << endl;

  freeTree(root);

  return 0;
}