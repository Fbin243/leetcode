#include <iostream>
#include <vector>
using namespace std;
/**
 * Time: O(n^3)
 */
int thuat_toan_truc_tiep(vector<int>& nums) {
  int n = nums.size();
  int maxSum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) sum += nums[k];
      maxSum = max(maxSum, sum);
    }
  }

  return maxSum;
}

/**
 * Time: O(n^2)
 */
int thuat_toan_nhanh_hon(vector<int>& nums) {
  int n = nums.size();
  int maxSum = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += nums[j];
      maxSum = max(sum, maxSum);
    }
  }

  return maxSum;
}

int maxEndAt(vector<int>& nums, int i, int j) {
  int maxSum = 0;
  int sum = 0;
  for (int k = j; k >= i; k--) {
    sum += nums[k];
    maxSum = max(sum, maxSum);
  }

  return maxSum;
}

int maxStartAt(vector<int>& nums, int i, int j) {
  int maxSum = 0;
  int sum = 0;
  for (int k = i; k <= j; k++) {
    sum += nums[k];
    maxSum = max(sum, maxSum);
  }

  return maxSum;
}

/**
 * Time: O(nlogn)
 */
int thuat_toan_de_quy(vector<int>& nums, int l, int r) {
  if (l == r) return nums[l];
  int m = l + (r - l) / 2;
  int maxL = thuat_toan_de_quy(nums, l, m);
  int maxR = thuat_toan_de_quy(nums, m + 1, r);
  int maxM = maxEndAt(nums, l, m) + maxStartAt(nums, m + 1, r);
  return max(maxL, max(maxR, maxM));
}

/**
 * O(n)
 */
int thuat_toan_quy_hoach_dong(vector<int>& nums) {
  int maxS = nums[0];
  int maxE = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    maxE = max(nums[i], nums[i] + maxE);
    maxS = max(maxS, maxE);
  }

  return maxS;
}	

int main() {
  vector<int> nums = {-2, 11, -4, 13, -5, 2};
  cout << "Thuat toan truc tiep: " << thuat_toan_truc_tiep(nums) << endl;
  cout << "Thuat toan nhanh hon: " << thuat_toan_nhanh_hon(nums) << endl;
  cout << "Thuat toan de quy: " << thuat_toan_de_quy(nums, 0, nums.size() - 1)
       << endl;
  cout << "Thuat toan quy hoach dong: " << thuat_toan_quy_hoach_dong(nums)
       << endl;

  return 0;
}
