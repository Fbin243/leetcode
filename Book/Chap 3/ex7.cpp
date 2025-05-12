#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
};

void InsertNode(Node*& head, Node*& tail, int val) {
  Node* newNode = new Node{val, nullptr};
  if (!head)
    head = tail = newNode;
  else {
    tail->next = newNode;
    tail = newNode;
  }
}

void Print(Node* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

void Destroy(Node*& head, Node*& tail) {
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  tail = nullptr;
}

Node* removeDupes(Node* head) {
  Node* cur = head->next;
  Node* prev = head;
  while (cur) {
    if (cur->val == prev->val) {
      Node* temp = cur;
      prev->next = cur->next;
      cur = cur->next;
      delete temp;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }

  return head;
}

int main() {
  Node *head = nullptr, *tail = nullptr;
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < rand() % 10; j++) {
      InsertNode(head, tail, i);
    }
  }

  cout << "Before remove duplicates: ";
  Print(head);

  head = removeDupes(head);

  cout << "After remove duplicates: ";
  Print(head);
  Destroy(head, tail);

  return 0;
}