/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/?envType=problem-list-v2&envId=array
 * Created at: 08/03/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach: Hash Map & Frequency Counting
 * 1. Use an unordered map to count the frequency of each number in the array.
 * 2. For each unique number:
 *    - If its frequency is 1, return -1 (since we can't remove it in groups of
 * 2 or 3).
 *    - Otherwise, minimize the number of operations needed:
 *      - Prefer removing elements in groups of 3.
 *      - If there are leftover elements (not divisible by 3), use one extra
 * operation to remove them in groups of 2.
 */

int minOperations(vector<int>& nums) {
    unordered_map<int, int> occurrence;
    for (int i = 0; i < nums.size(); i++) {
        occurrence[nums[i]]++;
    }

    int result = 0;
    for (auto it = occurrence.begin(); it != occurrence.end(); it++) {
        int occur = it->second;
        if (occur < 2) return -1;
        result += occur / 3;
        if (occur % 3 != 0) result += 1;
    }

    return result;
}

int main() {
    vector<int> nums = {2, 1, 2, 2, 3, 3};
    cout << "Result: " << minOperations(nums);

    return 0;
}