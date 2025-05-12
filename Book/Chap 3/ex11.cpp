#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* prev;
  Node* next;
};

Node* gHead;
Node* gTail;

void InsertNode(int val) {
  Node* newNode = new Node{val, gTail, nullptr};
  if (!gHead) {
    gHead = gTail = newNode;
  } else {
    gTail->next = newNode;
    gTail = newNode;
  }
}

void PrintForward(Node* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

void PrintBackward(Node* tail) {
  while (tail) {
    cout << tail->val << " ";
    tail = tail->prev;
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

void Remove(Node* head, int key) {
  while (head) {
    Node* temp = nullptr;

    if (head->val == key) {
      if (head->next) {
        head->next->prev = head->prev;
      }
      if (head->prev) {
        head->prev->next = head->next;
      }
      temp = head;
    }

    head = head->next;

    if (temp) {
      if (temp == gHead) gHead = gHead->next;
      if (temp == gTail) gTail = gTail->prev;
      delete temp;
    }
  }

  cout << "After remove " << key << ": ";
  PrintForward(gHead);
}

int main() {
  gHead = nullptr;
  gTail = nullptr;
  InsertNode(3);
  InsertNode(2);
  InsertNode(3);
  InsertNode(4);
  InsertNode(3);
  InsertNode(5);
  InsertNode(6);
  InsertNode(2);
  PrintForward(gHead);
  PrintBackward(gTail);

  Remove(gHead, 3);
  Remove(gHead, 2);

  Destroy(gHead);
  return 0;
}