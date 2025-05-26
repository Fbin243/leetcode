/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/reorder-list/description/
 * Created at: 26/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Approach: Stack
 * Time: O(n)
 * Space: O(n)
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    stack<ListNode*> st;
    ListNode* cur = head;
    int n = 0;
    while (cur) {
      n++;
      cur = cur->next;
    }

    cur = head;
    for (int i = 0; i < n; i++) {
      if (i >= (n + 1) / 2) st.push(cur);
      cur = cur->next;
    }

    cur = head;
    for (int i = 0; i < n / 2; i++) {
      ListNode* prev = cur;
      cur = cur->next;
      ListNode* temp = nullptr;
      if (!st.empty()) {
        temp = st.top();
        st.pop();
      }
      prev->next = temp;
      if (temp && temp != cur) temp->next = cur;
    }

    if (cur) cur->next = nullptr;
  }

  /**
   * Approach: Reverse And Merge
   * Time: O(n)
   * Space: O(1)
   */
  void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* second = slow->next;
    ListNode* prev = slow->next = nullptr;
    while (second != nullptr) {
      ListNode* tmp = second->next;
      second->next = prev;
      prev = second;
      second = tmp;
    }

    ListNode* first = head;
    second = prev;
    while (second != nullptr) {
      ListNode* tmp1 = first->next;
      ListNode* tmp2 = second->next;
      first->next = second;
      second->next = tmp1;
      first = tmp1;
      second = tmp2;
    }
  }
};