#include <vector>
using namespace std;

class CDate {
 private:
  int m_iDay, m_iMonth, m_iYear;

 public:
  CDate() {};
  CDate(int day, int month, int year)
      : m_iDay(day), m_iMonth(month), m_iYear(year) {};
  int getDay();
  int getMonth();
  int getYear();
};

int CDate::getDay() { m_iDay = 1; }

class Human {
 private:
  CDate& ref;
  CDate* ptr;
  const int MAX;
  vector<int> arr;

 public:
  Human(CDate& r, CDate* ptr) : ref(r), ptr(ptr), MAX(100), arr(MAX) {};
};

int main() {
  CDate date = CDate();
  CDate* date2 = new CDate();
  delete date2;
}