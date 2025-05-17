#include <iostream>
using namespace std;

struct Beverage {
  // Beverage() { cout << "Make new beverage" << endl; }
  // Beverage(const Beverage& b) { cout << "Copy beverage." << endl; }
};

struct Coffee : public Beverage {
  Coffee() { cout << "Make new Coffee" << endl; }
  Coffee(const Coffee& b) { cout << "Copy Coffee." << endl; }
};

struct Cappuchino : public Coffee {
  Cappuchino() { cout << "Make new Cappuchino" << endl; }
  // Cappuchino(const Cappuchino& b) { cout << "Copy Cappuchino."; }
};

int main() {
  Cappuchino c1;
  cout << endl;
  Cappuchino c2(c1);
}