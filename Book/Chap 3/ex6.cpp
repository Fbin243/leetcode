#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int val, Node* next) : val(val), next(next) {}
};

void InsertNode(Node*& head, Node*& tail, int val) {
  Node* newNode = new Node(val, head);
  // Node* newNode2 = new Node{val, head};
  if (!head)
    head = tail = newNode;
  else {
    tail->next = newNode;
    tail = newNode;
  }
}

int Count(Node* ptr) {
  if (!ptr) return 0;
  int cnt = 1;
  Node* cur = ptr->next;
  while (cur != ptr) {
    cur = cur->next;
    cnt++;
  }

  return cnt;
}

void Print(Node* head, Node* tail) {
  while (head != tail) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << tail->val << endl;
}

void Destroy(Node*& head, Node*& tail) {
  while (head != tail) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  tail = nullptr;
}

int main() {
  Node *head = nullptr, *tail = nullptr;
  for (int i = 0; i < 10; i++) {
    InsertNode(head, tail, i * 100);
  }

  Print(head, tail);

  cout << "Number of nodes: " << Count(head);

  Destroy(head, tail);
  return 0;
}