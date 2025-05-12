#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int val) : val(val), next(nullptr) {}
};

void InsertNode(Node*& head, Node*& tail, int val) {
  Node* newNode = new Node(val);
  if (!head) {
    head = tail = newNode;
  }
  tail->next = newNode;
  tail = newNode;
}

void RemoveNode(Node*& head, Node*& tail, Node* removeNode) {
  if (!removeNode) return;
  Node *cur = head, *prev = nullptr;
  while (cur != removeNode) {
    prev = cur;
    cur = cur->next;
  }

  if (removeNode == head) head = head->next;
  if (removeNode == tail) tail = prev;
  if (prev) {
    prev->next = removeNode->next;
  }

  delete removeNode;
}

void Destroy(Node* head) {
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

void Print(Node* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Node *head = nullptr, *tail = nullptr, *cur = nullptr;
  for (int i = 0; i < 10; i++) InsertNode(head, tail, i);

  cur = head;
  for (int i = 0; i < 10; i++) {
    Node* temp = cur;
    // cur = cur ? cur->next : nullptr;
    cur = cur->next;
    if (i % 2) RemoveNode(head, tail, temp);
  }

  Print(head);
  Destroy(head);

  return 0;
}