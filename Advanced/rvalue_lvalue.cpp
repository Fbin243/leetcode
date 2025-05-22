#include <algorithm>
#include <cstring>

class string {
  char* data;

 public:
  string(const char* p) {
    size_t size = std::strlen(p) + 1;
    data = new char[size];
    std::memcpy(data, p, size);
  }

  ~string() { delete[] data; }

  string(const string& that) {
    size_t size = std::strlen(that.data) + 1;
    data = new char[size];
    std::memcpy(data, that.data, size);
  }
};

int main() {
  string x("abc");
  string a(x);
  // string b(x + y);                               // Line 2
  // string c(some_function_returning_a_string());  // Line 3
}