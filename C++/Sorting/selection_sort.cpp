/**
 * Author: Fbin
 * Created at: 13/04/2025
 */
#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int> &nums) {
  for (int i = 0; i < nums.size() - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] < nums[min_idx]) {
        min_idx = j;
      }
    }
    swap(nums[i], nums[min_idx]);
  }
}

int main() {
  vector<int> arr = {-5, 3, 2, 1, -3, -3, 7, 2, 2};
  selection_sort(arr);

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}