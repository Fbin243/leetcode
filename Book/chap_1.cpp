#include <iostream>
#include <vector>
using namespace std;
/**
 * Time: O(n^3)
 */
int directAlgo(vector<int>& nums) {
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
int fasterAlgo(vector<int>& nums) {
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
int recursiveAlgo(vector<int>& nums, int l, int r) {
  if (l == r) return nums[l];
  int m = l + (r - l) / 2;
  int maxL = recursiveAlgo(nums, l, m);
  int maxR = recursiveAlgo(nums, m + 1, r);
  int maxM = maxEndAt(nums, l, m) + maxStartAt(nums, m + 1, r);
  return max(maxL, max(maxR, maxM));
}

/**
 * O(n)
 */
int dynamicProgrammingAlgo(vector<int>& nums) {
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
  cout << "Thuat toan truc tiep: " << directAlgo(nums) << endl;
  cout << "Thuat toan nhanh hon: " << fasterAlgo(nums) << endl;
  cout << "Thuat toan de quy: " << recursiveAlgo(nums, 0, nums.size() - 1)
       << endl;
  cout << "Thuat toan quy hoach dong: " << dynamicProgrammingAlgo(nums)
       << endl;

  return 0;
}
