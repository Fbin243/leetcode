/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/?envType=daily-question&envId=2025-09-05
 * Created at: 05/09/2025
 */

#include <fbin/leetcode.h>
using namespace std;

class Solution {
 public:
  int makeTheIntegerZero(int num1, int num2) {
    for (int i = 30; i >= 0; i--) {
			int divisor = pow(2, i) + num2
			if(num1 % divisor == 0) {
				return i;
			}
    }
  }
};
