#include <iostream>
using namespace std;

struct PolyNode {
  int coeff;
  int pow;
  PolyNode* link;

  PolyNode(int coeff, int pow) : coeff(coeff), pow(pow), link(nullptr) {}
};

void InsertNode(PolyNode*& head, PolyNode*& tail, int coeff, int pow) {
  if (coeff == 0) return; // skip 0 terms
  PolyNode* newNode = new PolyNode(coeff, pow);
  if (!head) {
    head = tail = newNode;
  } else {
    tail->link = newNode;
    tail = newNode;
  }
}

void print(PolyNode* head) {
  if (!head) {
    cout << "0" << endl;
    return;
  }
  while (head) {
    cout << head->coeff << "x^" << head->pow;
    head = head->link;
    if (head) cout << " + ";
  }
  cout << endl;
}

void destroy(PolyNode*& head) {
  while (head) {
    PolyNode* temp = head;
    head = head->link;
    delete temp;
  }
}

PolyNode* PolySum(PolyNode* p1, PolyNode* p2) {
  PolyNode *result = nullptr, *tail = nullptr;
  while (p1 && p2) {
    if (p1->pow < p2->pow) {
      InsertNode(result, tail, p1->coeff, p1->pow);
      p1 = p1->link;
    } else if (p1->pow > p2->pow) {
      InsertNode(result, tail, p2->coeff, p2->pow);
      p2 = p2->link;
    } else {
      int sumCoeff = p1->coeff + p2->coeff;
      InsertNode(result, tail, sumCoeff, p1->pow);
      p1 = p1->link;
      p2 = p2->link;
    }
  }

  while (p1) {
    InsertNode(result, tail, p1->coeff, p1->pow);
    p1 = p1->link;
  }
  while (p2) {
    InsertNode(result, tail, p2->coeff, p2->pow);
    p2 = p2->link;
  }

  return result;
}

PolyNode* PolyMult(PolyNode* p1, PolyNode* p2) {
  PolyNode* result = nullptr;

  for (PolyNode* term1 = p1; term1; term1 = term1->link) {
    PolyNode *temp = nullptr, *tempTail = nullptr;
    for (PolyNode* term2 = p2; term2; term2 = term2->link) {
      InsertNode(temp, tempTail, term1->coeff * term2->coeff, term1->pow + term2->pow);
    }

    PolyNode* newResult = PolySum(result, temp);
    destroy(result);
    destroy(temp);
    result = newResult;
  }

  return result;
}

int main() {
  PolyNode *p1 = nullptr, *p1Tail = nullptr;
  PolyNode *p2 = nullptr, *p2Tail = nullptr;

  InsertNode(p1, p1Tail, 1, 0);
  InsertNode(p1, p1Tail, 2, 2);
  InsertNode(p1, p1Tail, 3, 3);

  InsertNode(p2, p2Tail, 6, 0);
  InsertNode(p2, p2Tail, 4, 1);
  InsertNode(p2, p2Tail, 5, 2);

  PolyNode* p3 = PolySum(p1, p2);
  PolyNode* p4 = PolyMult(p1, p2);

  cout << "P1: "; print(p1);
  cout << "P2: "; print(p2);
  cout << "P1 + P2: "; print(p3);
  cout << "P1 * P2: "; print(p4);

  destroy(p1);
  destroy(p2);
  destroy(p3);
  destroy(p4);

  return 0;
}
