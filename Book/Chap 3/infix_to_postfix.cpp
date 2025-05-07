#include <cctype>
#include <iostream>
#include <stack>
#include <string>

int precedence(char op) {
  if (op == '^') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return 0;
}

bool isRightAssociative(char op) { return op == '^'; }

std::string convert_infix_to_postfix(const std::string& s) {
  std::string ans;
  std::stack<char> st;

  for (char c : s) {
    if (std::isalnum(c)) {
      ans += c;
    } else if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      if (!st.empty()) st.pop();  // Loại bỏ '('
    } else {                      // Là toán tử
      while (
          !st.empty() && st.top() != '(' &&
          (precedence(st.top()) > precedence(c) ||
           (precedence(st.top()) == precedence(c) && !isRightAssociative(c)))) {
        ans += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  return ans;
}
