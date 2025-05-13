#include <iostream>
#include <stack>
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

string getPostOrderStr(TreeNode* t) {
  if (!t) return "";
  return getPostOrderStr(t->left) + getPostOrderStr(t->right) + t->val;
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

void bai7(TreeNode* t) {
  if (!t) return;
  cout << t->val;
  bai7(t->left);
  bai7(t->right);
  cout << t->val;
}

int bai8_eval_exp(int or1, int or2, char op) {
  switch (op) {
    case '+':
      return or1 + or2;
    case '-':
      return or1 - or2;
    case '*':
      return or1 * or2;
    default:
      return or1 / or2;
  }
}

int bai8_eval_postfix(string s) {
  stack<int> st;
  for (char c : s) {
    if (isalnum(c)) {
      st.push(c - '0');
    } else {
      int or2 = st.top();
      st.pop();
      int or1 = st.top();
      st.pop();
      st.push(bai8_eval_exp(or1, or2, c));
    }
  }

  return st.top();
}

// Count number of node greater than k
int bai13_countNodes(TreeNode* t, int k) {
  if (!t) return 0;
  return ((t->val > k) ? 1 : 0) + bai13_countNodes(t->left, k) +
         bai13_countNodes(t->right, k);
}

// Count number of leaf node
int bai14_countLeafs(TreeNode* t) {
  if (!t) return 0;
  return ((!t->left && !t->right) ? 1 : 0) + bai14_countLeafs(t->left) +
         bai14_countLeafs(t->right);
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

  // --- Bai 7
  root = new TreeNode{
      'a',
      new TreeNode{
          'b',
          new TreeNode{'c', nullptr, nullptr},
          new TreeNode{'a', nullptr, nullptr},
      },
      new TreeNode{
          'e',
          new TreeNode{'f', nullptr, nullptr},
          new TreeNode{'g', nullptr, nullptr},
      },
  };

  bai7(root);

  freeTree(root);

  // --- Bai 8
  root = new TreeNode{
      '/',
      new TreeNode{'+',
                   new TreeNode{
                       '/',
                       new TreeNode{'9', nullptr, nullptr},
                       new TreeNode{'3', nullptr, nullptr},
                   },
                   new TreeNode{'9', nullptr, nullptr}},
      new TreeNode{
          '/',
          new TreeNode{'8', nullptr, nullptr},
          new TreeNode{
              '*',
              new TreeNode{'2', nullptr, nullptr},
              new TreeNode{
                  '-',
                  new TreeNode{'4', nullptr, nullptr},
                  new TreeNode{'2', nullptr, nullptr},
              },
          },
      },
  };

  string postfixStr = getPostOrderStr(root);
  cout << endl
       << "Postfix notion \"" << postfixStr
       << "\" has value: " << bai8_eval_postfix(postfixStr);

  freeTree(root);

  // --- Bai 13 & 14
  root = new TreeNode{
      1,
      new TreeNode{
          2,
          new TreeNode{3, nullptr, nullptr},
          new TreeNode{
              4,
              new TreeNode{5, nullptr, nullptr},
              new TreeNode{6, nullptr, nullptr},
          },
      },
      new TreeNode{
          5,
          new TreeNode{6, nullptr, nullptr},
          new TreeNode{
              7,
              nullptr,
              new TreeNode{8, nullptr, nullptr},
          },
      },
  };

  int k = 5;
  cout << endl
       << "Number of nodes greater than " << k
       << " is: " << bai13_countNodes(root, k);

  cout << endl << "Number of leaf nodes is: " << bai14_countLeafs(root);

  freeTree(root);

  return 0;
}
