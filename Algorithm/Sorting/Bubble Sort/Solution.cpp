/**
 * Author: Fbin
 * Created at: 13/04/2025
 */
#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int> &nums) {
  for (int i = nums.size() - 1; i >= 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (nums[j] < nums[j - 1]) {
        swap(nums[j], nums[j - 1]);
      }
    }
  }
}

int main() {
  vector<int> arr = {-5, 3, 2, 1, -3, -3, 7, 2, 2};
  bubble_sort(arr);

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}