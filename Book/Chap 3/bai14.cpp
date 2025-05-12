#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
};

Node* InsertNode(Node*& head, Node*& tail, int val) {
  Node* newNode = new Node{val, nullptr};
  if (!head)
    head = tail = newNode;
  else {
    tail->next = newNode;
    tail = newNode;
  }

  return newNode;
}

void Print(Node* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

void Destroy(Node*& head) {
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

void removeNode(Node* ptr) {
  Node* prev = nullptr;
  while (ptr != nullptr && ptr->next != nullptr) {
    ptr->val = ptr->next->val;
    prev = ptr;
    ptr = ptr->next;
  }
  if (prev) {
    prev->next = nullptr;
    delete ptr;
  }
}

int main() {
  Node *head = nullptr, *tail = nullptr, *ptr;
  for (int i = 0; i < 10; i++) {
    Node* temp = InsertNode(head, tail, i);
    if (i == 8) ptr = temp;
  }

  Print(head);

  removeNode(ptr);

  Print(head);

  Destroy(head);

  return 0;
}