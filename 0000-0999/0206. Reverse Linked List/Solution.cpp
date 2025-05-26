/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/reverse-linked-list/description/
 * Created at: 26/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  /**
   * Iterative version
   * Time: O(n)
   * Space: O(1)
   */
  ListNode *reverseList(ListNode *head) {
    ListNode *cur = nullptr, *prev = nullptr;
    while (head) {
      cur = head;
      head = head->next;
      cur->next = prev;
      prev = cur;
    }

    return prev;
  }

  /**
   * Recursive version
   * Time: O(n)
   * Space: O(n) // call stack
   */
  ListNode *reverseList(ListNode *head) {
    if (!head) {
      return nullptr;
    }

    ListNode *after = head;
    if (head->next) {
      after = reverseList(head->next);
      head->next->next = head;
    }
    head->next = nullptr;

    return after;
  }
};
