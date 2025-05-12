#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
};

void InsertNode(Node*& head, Node*& tail, int val) {
  Node* newNode = new Node{val, nullptr};
  if (!head) head = tail = newNode;
  tail->next = newNode;
  tail = newNode;
}

void Destroy(Node*& head) {
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

void Shuffle(Node* head) {
  if (!head) return;
  Node *odd = nullptr, *oddHead = head;
  Node *even = nullptr, *evenHead = head->next;
  bool isOdd = true;
  while (head) {
    if (isOdd) {
      if (odd) {
        odd->next = head;
        odd = odd->next;
      } else
        odd = head;
    } else {
      if (even) {
        even->next = head;
        even = even->next;
      } else
        even = head;
    }

    head = head->next;
    isOdd = !isOdd;
  }

  even->next = oddHead;
  odd->next = nullptr;
  Print(evenHead);

  Destroy(evenHead);
}

int main() {
  Node *head = nullptr, *tail = nullptr;
  for (int i = 0; i < 10; i++) {
    InsertNode(head, tail, i);
  }

  Print(head);
  Shuffle(head);
  return 0;
}