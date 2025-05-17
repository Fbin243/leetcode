#include <iostream>
using namespace std;

class Rectangle {
 private:
  int width, height;

 public:
  Rectangle(int w = 1, int h = 1) {
    width = w;
    height = h;
  }

  void Show() { cout << "Width: " << width << ", Height: " << height << endl; }
};

int main() {
  Rectangle r1;         // dùng giá trị mặc định: 1,1
  Rectangle r2(5);      // height = 1
  Rectangle r3(5, 10);  // full

  r1.Show();
  r2.Show();
  r3.Show();
}
