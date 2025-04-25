/**
 * Author: Fbin
 * Created at: 13/04/2025
 */
#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    int val = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > val) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = val;
  }
}

int main() {
  vector<int> arr = {-5, 3, 2, 1, -3, -8, 7, 2, 2};
  insertion_sort(arr);

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}