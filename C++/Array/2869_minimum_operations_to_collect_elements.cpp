/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/minimum-operations-to-collect-elements/?envType=problem-list-v2&envId=array
 * Created at: 08/03/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach: Set
 * We use a set to keep track the elements when we iterate through the array in
 * reverse order. If the size of the set is equals to k, we can stop and return
 * the result
 */

int minOperations(vector<int>& nums, int k) {
    unordered_set<int> collection;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] <= k) {
            collection.insert(nums[i]);
        }
        if (collection.size() == k) {
            return nums.size() - i;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {3, 2, 5, 3, 1};
    int k = 3;
    int result = minOperations(nums, k);
    cout << "Result: " << result << endl;

    return 0;
}