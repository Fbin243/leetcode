/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/maximum-average-pass-ratio/?envType=daily-question
 * Created at: 01/09/2025
 */

#include <iostream>
#include <queue>
using namespace std;

double calcRatio(const vector<int> &a) { return (1.0 * a[0]) / a[1]; }

double calcIncRatio(const vector<int> &a) {
  return (1.0 * (a[0] + 1) / (a[1] + 1)) - (1.0 * a[0] / a[1]);
}

struct CompareRatio {
  bool operator()(const vector<int> &a, const vector<int> &b) {
    double incRatioA = calcIncRatio(a);
    double incRatioB = calcIncRatio(b);
    return incRatioA < incRatioB;
  }
};

class Solution {
public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    priority_queue<vector<int>, vector<vector<int>>, CompareRatio> pq(
        classes.begin(), classes.end());
    while (extraStudents > 0) {
      vector<int> v = pq.top();
      pq.pop();
      v[0]++;
      v[1]++;
      pq.push(v);
      extraStudents--;
    }

    double sumRatio = 0;
    while (!pq.empty()) {
      vector<int> v = pq.top();
      sumRatio += calcRatio(v);
      pq.pop();
    }

    return sumRatio / classes.size();
  }

  /**
   * Optimize version
   * */
  double maxAverageRatio2(vector<vector<int>> &classes, int extraStudents) {
    using Class = pair<int, int>; // {pass, total}

    auto gain = [](const Class &c) {
      // Gain when adding one student
      return (1.0 * (c.first + 1) / (c.second + 1)) -
             (1.0 * c.first / c.second);
    };

    auto cmp = [&](const Class &a, const Class &b) {
      return gain(a) < gain(b); // max-heap by gain
    };

    priority_queue<Class, vector<Class>, decltype(cmp)> pq(cmp);

    for (auto &c : classes)
      pq.emplace(c[0], c[1]);

    while (extraStudents--) {
      auto [pass, total] = pq.top();
      pq.pop();
      pq.emplace(pass + 1, total + 1);
    }

    double sum = 0;
    while (!pq.empty()) {
      auto [pass, total] = pq.top();
      pq.pop();
      sum += double(pass) / total;
    }
    return sum / classes.size();
  }
};

int main() { return 0; }
