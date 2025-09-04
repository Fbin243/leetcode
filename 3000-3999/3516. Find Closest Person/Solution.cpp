/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-closest-person/description/?envType=daily-question
 * Created at: 04/09/2025
 */

#include <cmath>
using namespace std;

class Solution {
public:
  int findClosest(int x, int y, int z) {
    int distanceXZ = abs(x - z);
    int distanceYZ = abs(y - z);
    if (distanceXZ < distanceYZ)
      return 1;
    if (distanceXZ > distanceYZ)
      return 2;
    return 0;
  }
};
