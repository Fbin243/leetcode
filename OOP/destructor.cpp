#include <iostream>
using namespace std;

class Base {
 public:
  virtual ~Base() { cout << "Base destructor"; }
};

class Derived : public Base {
 public:
  ~Derived() { cout << "Derived destrutor"; }
};

int main() {
  Base* ptr = new Derived();
  delete ptr;
}