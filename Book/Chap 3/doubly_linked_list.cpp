#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* prev;
  Node* next;
};

void insert_node(Node*& head, Node*& tail, Node* pred, int value) {
  Node* newNode = new Node();
  newNode->value = value;
  newNode->prev = nullptr;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
    return;
  }

  newNode->next = pred->next;
  newNode->prev = pred;
  pred->next = newNode;

  if (pred != tail) {
    newNode->next->prev = newNode;
  } else {
    tail = newNode;
  }
}

void remove_node(Node*& head, Node*& tail, Node* removeNode) {
  if (removeNode->prev != nullptr) {
    removeNode->prev->next = removeNode->next;
  }
  if (removeNode->next != nullptr) {
    removeNode->next->prev = removeNode->prev;
  }
  if (removeNode == head) head = removeNode->next;
  if (removeNode == tail) tail = removeNode->prev;
  delete removeNode;
}

void print_forward(Node* head) {
  Node* cur = head;
  while (cur != nullptr) {
    cout << cur->value << " ";
    cur = cur->next;
  }
  cout << endl;
}

void print_backward(Node* tail) {
  Node* cur = tail;
  while (cur != nullptr) {
    cout << cur->value << " ";
    cur = cur->prev;
  }
  cout << endl;
}

void make_null(Node* head) {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  Node *head, *tail;
  head = tail = nullptr;

  for (int i = 0; i < 10; i++) {
    insert_node(head, tail, tail, i);
  }

  print_forward(head);
  remove_node(head, tail, tail);
  print_backward(tail);
  make_null(head);
  return 0;
}
