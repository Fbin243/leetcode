#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

Node* Insert_Head(Node* head, int value) {
  Node* newNode = new Node();
  newNode->value = value;
  newNode->next = head;
  head = newNode;

  return head;
}

Node* Insert_Last(Node* head, int value) {
  Node* newNode = new Node();
  newNode->value = value;

  Node* cur = head;
  while (cur->next != nullptr) {
    cur = cur->next;
  }
  cur->next = newNode;

  return head;
}

Node* Insert_Middle(Node* pred, int value) {
  Node* newNode = new Node();
  newNode->value = value;
  newNode->next = pred->next;

  pred->next = newNode;

  return newNode;
}

Node* Delete_Head(Node* head) {
  Node* temp = head;
  head = head->next;

  delete temp;
  return head;
}

Node* Delete_Last(Node* head) {
  Node* cur = head;
  Node* prev = cur;

  while (cur->next != nullptr) {
    prev = cur;
    cur = cur->next;
  }

  prev->next = nullptr;
  delete cur;

  return head;
}

void Print_List(Node* head) {
  Node* cur = head;

  while (cur != nullptr) {
    cout << cur->value << " ";
    cur = cur->next;
  }
}

bool IsEmpty(Node* head) { return head->next == nullptr; }

Node* MakeNull(Node* head) {
  while (!IsEmpty(head)) {
    Delete_Head(head);
  }

  return head;
}

int main() {
  Node* head = nullptr;
  head = Insert_Head(head, 1);
  Node* pred = head;

  srand(time(nullptr));

  for (int i = 0; i < 10; i++) {
    int val = rand() % 20 + 1;
    if (rand() % 2) val = -val;
    pred = Insert_Middle(pred, val);
  }

  Node *P1, *P2, *N1, *N2;
  P1 = P2 = N1 = N2 = nullptr;
  while (head != nullptr) {
    if (head->value > 0) {
      if (!P1) {
        P1 = Insert_Head(P1, head->value);
        N1 = P1;
      } else
        P1 = Insert_Middle(P1, head->value);
    } else {
      if (!P2) {
        P2 = Insert_Head(P2, head->value);
        N2 = P2;
      } else
        P2 = Insert_Middle(P2, head->value);
    }
    head = head->next;
  }

  Print_List(N1);
  cout << endl;
  Print_List(N2);

  return 0;
}
