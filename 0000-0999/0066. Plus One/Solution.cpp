/**
* Author: Fbin
* Link:https://leetcode.com/problems/plus-one/description/\?envType\=daily-question\&envId\=2026-01-01
* Created at: 01/01/2026
*/

#include <fbin/leetcode.h>

class Solution {
	public:
			vector<int> plusOne(vector<int>& digits) {
					vector<int> result;
					int remainder = 1;
					for(int i = digits.size() - 1; i >= 0; i--) {
							result.push_back((digits[i] + remainder) % 10);
							remainder = (digits[i] + remainder) / 10;
					}
					if (remainder > 0) {
							result.push_back(remainder);
					}

					reverse(result.begin(), result.end());
					return result;
			}
	};
