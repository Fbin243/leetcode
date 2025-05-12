#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void InsertNode(int val) {
  Node* newNode = new Node{val, nullptr};
  if (!head)
    head = tail = newNode;
  else {
    tail->next = newNode;
    tail = newNode;
  }
}

void Destroy() {
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

void Print() {
  Node* cur = head;
  while (cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

void Reverse() {
  Node* prev = nullptr;
  Node* cur = head;
  while (cur) {
    Node* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  tail = head;
  head = prev;
}

int main() {
  for (int i = 0; i < 10; i++) {
    InsertNode(i);
  }

  Print();
  Reverse();
  Print();

  Destroy();

  return 0;
}