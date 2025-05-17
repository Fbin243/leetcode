#include <iostream>
#include <string>
using namespace std;

class Person {
 public:
  string name;

  Person(string n) : name(n) {
    cout << "Constructor called for " << name << endl;
  }

  Person(const Person& other) : name(other.name) {
    cout << "Copy constructor called for " << name << endl;
  }

  Person& operator=(const Person& other) {
    cout << "Assignment operator called for " << other.name << endl;
    if (this != &other) {
      name = other.name;
    }
    return *this;
  }
};

void doSomething(Person x) { cout << "In function with " << x.name << endl; }

Person getPerson() {
  Person p("Mickey");
  return p;
}

int main() {
  Person p("Donald");       // Constructor
  Person r(p);              // Copy constructor
  Person q = p;             // Copy constructor
  p = r;                    // Assignment operator
  doSomething(p);           // Copy constructor (tham số truyền theo giá trị)
  Person p2 = getPerson();  // Copy constructor (trả về đối tượng)
}
