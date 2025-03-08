/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/minimum-operations-to-collect-elements/?envType=problem-list-v2&envId=array
 * Created at: 08/03/2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Set
 * We use a set to keep track the elements when we iterate through the array in
 * reverse order. If the size of the set is equals to k, we can stop and return
 * the result
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int minOperations1(vector<int>& nums, int k) {
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

/**
 * Approach 2: Bit Manipulation
 * Instead of using a set or map, we use bit manipulation to track "seen"
 * numbers efficiently.
 *
 * - Use a variable (`cond`) where each bit represents a value in the range [1,
 * k].
 * - For every element in the array, set the corresponding bit of `num` to 1.
 * - Continue this process until `num & cond` equals `cond`, meaning `num`
 * contains all the required bits set.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

int minOperations2(vector<int>& nums, int k) {
    long long cond = 0;
    long long num = 0;
    long long count = 0;

    // Create the condition mask with k bits set to 1
    // for (int i = 0; i < k; i++) {
    //     cond = (cond << 1) | 1;
    // }
    //

    // Instead of for loop, we can
    cond = (1LL << k) - 1;

    // Process elements from the back of nums
    // while ((num & cond) != cond) {
    //     int last_ele = nums.back();
    //     nums.pop_back();

    //     num |= (1LL << (last_ele - 1));
    //     count++;
    // }

    // We can do better than while loop (don't need last_ele variable)
    for (int i = nums.size() - 1; i >= 0; i--) {
        num |= (1LL << (nums[i] - 1));
        count++;
        if ((num & cond) == cond) return count;
    }

    return -1;
}

int main() {
    vector<int> nums1 = {3, 2, 5, 3, 1};
    vector<int> nums2 = {3, 2, 5, 3, 1};
    int k = 3;
    cout << "Result 1: " << minOperations1(nums1, k) << endl;
    cout << "Result 2: " << minOperations2(nums2, k) << endl;

    return 0;
}