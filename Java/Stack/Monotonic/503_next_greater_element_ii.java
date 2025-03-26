package Monotonic;
import java.util.Arrays;
import java.util.Stack;

/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/next-greater-element-ii/
 * Created at: 26/03/2025
 */

class Solution {
  public int[] nextGreaterElements(int[] nums) {
    int n = nums.length;
    int res[] = new int[n];
    Arrays.fill(res, -1);
    Stack<Integer> st = new Stack<>();
    for (int i = 0; i < n * 2; i++) {
      while (!st.empty() && nums[st.peek() % n] < nums[i % n]) {
        res[st.peek() % n] = nums[i % n];
        st.pop();
      }
      st.push(i % n);
    }
    return res;
  }
}

class Main {
  public static void main(String[] args) {
    Solution sol = new Solution();
    int[] nums = { 1, 2, 3, 4, 3 };
    int[] res = sol.nextGreaterElements(nums);
    for (int i : res) {
      System.out.print(i + " ");
    }
  }
}