#include <iostream>
using namespace std;

template <typename T>
struct Node {
  T value;
  Node* next;
};

template <typename T>
struct Stack {
  Node<T>* top;
};

template <typename T>
void destroy(Stack<T>* s) {
  while (s->top != nullptr) {
    Node<T>* temp = s->top;
    s->top = s->top->next;
    delete temp;
  }
}

template <typename T>
void push(Stack<T>* s, int value) {
  Node<T>* newNode = new Node<T>();
  newNode->value = value;
  newNode->next = s->top;
  s->top = newNode;
}

template <typename T>
bool is_stack_empty(Stack<T>* s) {
  return s->top == nullptr;
}

template <typename T>
T pop(Stack<T>* s) {
  if (is_stack_empty(s)) return -1;

  Node<T>* temp = s->top;
  s->top = s->top->next;
  int value = temp->value;
  delete temp;

  return value;
}

template <typename T>
T top(Stack<T>* s) {
  if (is_stack_empty(s)) return -1;
  return s->top->value;
}

template <typename T>
void print(Stack<T>* s) {
  Node<T>* cur = s->top;
  while (cur != nullptr) {
    cout << cur->value << " ";
    cur = cur->next;
  }
  cout << endl;
}

int eval(int or1, int or2, char op) {
  switch (op) {
    case '+':
      return or1 + or2;
    case '-':
      return or1 - or2;
    case '*':
      return or1 * or2;
    default:
      return or1 / or2;
  }
}

int evaluate_postfix(string s) {
  Stack<int>* st = new Stack<int>();
  for (char c : s) {
    if (isalnum(c)) {
      push(st, c - '0');
    } else {
      int or1 = pop(st);
      int or2 = pop(st);
      int ans = eval(or1, or2, c);
      push(st, ans);
    }
  }

  int ans = pop(st);
  destroy(st);
  return ans;
}

int priority(char op) {
  switch (op) {
    case '-':
    case '+':
      return 0;
    case '*':
    case '/':
      return 1;
    case '^':
      return 2;
    default:
      return -1;
  }
}

string convert_infix_to_postfix(string s) {
  string ans = "";
  Stack<char>* st = new Stack<char>();
  for (char c : s) {
    // print(st);
    if (isalnum(c)) {
      ans += c;
      continue;
    }

    if (is_stack_empty(st)) {
      push(st, c);
      continue;
    }

    if (c == ')') {
      while (top(st) != '(') {
        ans += pop(st);
      }
      pop(st);
      continue;
    }

    int p1 = priority(top(st));
    int p2 = priority(c);
    while (!is_stack_empty(st) &&
           ((p1 > p2 && c != '(') || (p1 == p2 && c != '^'))) {
      ans += pop(st);
      p1 = priority(top(st));
      p2 = priority(c);
    }

    push(st, c);
  }

  while (!is_stack_empty(st)) {
    ans += pop(st);
  }

  destroy(st);

  return ans;
}

int main() {
  cout << evaluate_postfix("598-71-*+7*") << endl;
  cout << convert_infix_to_postfix("1-2^3^3-(4+5*6)*7") << endl;

  return 0;
}
