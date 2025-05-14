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

// Check if two trees are isometric
bool bai15_isometric(TreeNode* t1, TreeNode* t2) {
  if (!t1 && !t2) return true;
  if ((t1 && !t2) || (!t1 && t2)) return false;
  return bai15_isometric(t1->left, t2->left) &&
         bai15_isometric(t1->right, t2->right);
}

// Calculate sum of odd nodes
int bai16_oddSum(TreeNode* t) {
  if (!t) return 0;
  return (t->val % 2 ? t->val : 0) + bai16_oddSum(t->left) +
         bai16_oddSum(t->right);
}

// Mirror tree
TreeNode* bai17_mirror(TreeNode* t) {
  if (!t) return t;
  swap(t->left, t->right);
  bai17_mirror(t->left);
  bai17_mirror(t->right);
  return t;
}

// Calculate sum of tree
int bai18_sum(TreeNode* t) {
  if (!t) return 0;
  return t->val + bai18_sum(t->left) + bai18_sum(t->right);
}

// Find maximum even number in Binary Search Tree
int bai19_evenMax(TreeNode* t) {
  if (!t) return -1;
  return max(((t->val % 2) ? -1 : t->val),
             max(bai19_evenMax(t->left), bai19_evenMax(t->right)));
}

// Check if the tree is balanced
int checkBalanced(TreeNode* t, bool& balanced) {
  if (!t) return 0;
  int leftHeight = checkBalanced(t->left, balanced);
  int rightHeight = checkBalanced(t->right, balanced);
  if (abs(leftHeight - rightHeight) > 1) balanced = false;
  return 1 + max(leftHeight, rightHeight);
}

bool bai20_isBBT(TreeNode* t) {
  bool balanced = true;
  checkBalanced(t, balanced);
  return balanced;
}

// Find the diameter of tree
int find_diam_edges(TreeNode* t, int& diam) {
  if (!t) return -1;
  int leftHeight = find_diam_edges(t->left, diam);
  int rightHeight = find_diam_edges(t->right, diam);
  diam = max(diam, 2 + leftHeight + rightHeight);
  return 1 + max(leftHeight, rightHeight);
}

// If you define the path length is number of nodes
int find_diam_nodes(TreeNode* t, int& diam) {
  if (!t) return 0;
  int leftHeight = find_diam_nodes(t->left, diam);
  int rightHeight = find_diam_nodes(t->right, diam);
  diam = max(diam, 1 + leftHeight + rightHeight);
  return 1 + max(leftHeight, rightHeight);
}

int bai21_BT_Diam(TreeNode* t) {
  int diam = 0;
  find_diam_edges(t, diam);
  return diam;
}

// All keys in tree is smaller than key
bool bai22_isLeft(TreeNode* t, int key) {
  if (!t) return true;
  if (t->val >= key) return false;
  return bai22_isLeft(t->left, key) && bai22_isLeft(t->right, key);
}

// Count number of even leaf nodes
int bai24_evenLeaf(TreeNode* t) {
  if (!t) return 0;
  return (!t->left && !t->right && (t->val % 2 == 0)) +
         bai24_evenLeaf(t->left) + bai24_evenLeaf(t->right);
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
       << "8. Postfix notion \"" << postfixStr
       << "\" has value: " << bai8_eval_postfix(postfixStr);

  freeTree(root);

  // --- Bai 13 & 14 & 16
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
  int key = 9;
  cout << endl
       << "13. Number of nodes greater than " << k
       << " is: " << bai13_countNodes(root, k);
  cout << endl << "14. Number of leaf nodes is: " << bai14_countLeafs(root);
  cout << endl << "16. Odd sum: " << bai16_oddSum(root);
  cout << endl << "18. Sum of tree: " << bai18_sum(root);
  cout << endl << "19. Maximum even number: " << bai19_evenMax(root);
  cout << endl << "21. Diameter of tree: " << bai21_BT_Diam(root);
  cout << endl
       << "22. All keys smaller than " << key
       << " is: " << bai22_isLeft(root, key);
  cout << endl << "24. Number of even leaf nodes: " << bai24_evenLeaf(root);

  freeTree(root);

  // --- Bai 15
  root = new TreeNode{
      'a',
      new TreeNode{
          'b',
          new TreeNode{
              'd',
              nullptr,
              new TreeNode{'f', nullptr, nullptr},
          },
      },
      new TreeNode{
          'c',
          new TreeNode{
              'e',
              nullptr,
              new TreeNode{'g', nullptr, nullptr},
          },
      },
  };

  TreeNode* root2 = new TreeNode{
      'a',
      new TreeNode{
          'b',
          new TreeNode{
              'd',
              nullptr,
              new TreeNode{'f', nullptr, nullptr},
          },
      },
      new TreeNode{
          'c',
          new TreeNode{
              'e',
              new TreeNode{'g', nullptr, nullptr},
              nullptr,
          },
      },
  };

  cout << endl << "15. Isometric: " << bai15_isometric(root, root2);
  cout << endl << "17. Mirror tree: ";
  cout << endl << "--- Before: " << getPostOrderStr(root);
  bai17_mirror(root);
  cout << endl << "--- After: " << getPostOrderStr(root);
  cout << endl << "20. Is Balanced Tree: " << bai20_isBBT(root);

  freeTree(root);
  freeTree(root2);

  return 0;
}
