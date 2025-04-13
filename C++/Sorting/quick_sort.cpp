/**
 * Author: Fbin
 * Created at: 13/04/2025
 */
#include <bits/stdc++.h>

using namespace std;

void quick_sort(vector<int> &nums, int left, int right) {
  int l = left;
  int r = right;
  int pivot = nums[left + (right - left) / 2];
  while (l <= r) {
    while (nums[l] < pivot) l++;
    while (nums[r] > pivot) r--;
    if (l <= r) {
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
  }
  if (left < r) quick_sort(nums, left, r);
  if (l < right) quick_sort(nums, l, right);
}

void quick_sort_iterative(vector<int> &nums) {
  stack<pair<int, int>> st;
  st.push({0, (int)nums.size() - 1});

  while (!st.empty()) {
    auto [left, right] = st.top();
    st.pop();
    if (left >= right) continue;

    int l = left, r = right;
    int pivot = nums[left + (right - left) / 2];

    while (l <= r) {
      while (nums[l] < pivot) l++;
      while (nums[r] > pivot) r--;
      if (l <= r) {
        swap(nums[l], nums[r]);
        l++;
        r--;
      }
    }

    if (left < r) st.push({left, r});
    if (l < right) st.push({l, right});
  }
}

void quick_sort_randomized(vector<int> &nums, int left, int right) {
  if (left >= right) return;

  int pivot_index = left + rand() % (right - left + 1);
  swap(nums[left], nums[pivot_index]);
  int pivot = nums[left];

  int l = left + 1;
  int r = right;

  while (l <= r) {
    while (l <= right && nums[l] < pivot) l++;
    while (r >= left && nums[r] > pivot) r--;
    if (l <= r) {
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
  }

  swap(nums[left], nums[r]);

  quick_sort_randomized(nums, left, r - 1);
  quick_sort_randomized(nums, r + 1, right);
}

int main() {
  vector<int> arr = {10, 9, 8, 7, 6, 5};
  quick_sort(arr, 0, arr.size() - 1);

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}