#include <iostream>
using namespace std;

class A {
  int b;    // 4 bytes
  char a;   // 1 byte
  char c1;  // 1 byte
  char c2;  // 1 byte
  char c3;  // 1 byte
  char c;   // 1 byte
};

int main() { cout << "sizeof(A) = " << sizeof(A) << endl; }
