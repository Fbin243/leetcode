#include <cstring>
#include <iostream>
using namespace std;

class MyString {
 public:
  char* buffer;
  MyString(const char str[]) {
    buffer = new char[strlen(str) + 1];
    strcpy(buffer, str);
  }

  MyString(const MyString& src) {
    if (src.buffer) {
      buffer = new char[strlen(src.buffer) + 1];
      strcpy(buffer, src.buffer);
    } else {
      buffer = nullptr;
    }
  }

  ~MyString() {
    delete[] buffer;
    buffer = nullptr;
  }

  void Mutate() { buffer[0] = 'B'; }

  void Print() { cout << buffer << endl; }
};

int main() {
  MyString* myStr = new MyString("Ahihi");
  MyString m1 = MyString(*myStr);
  myStr->Mutate();
  myStr->Print();
  m1.Print();
}