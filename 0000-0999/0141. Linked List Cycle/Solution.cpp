/**
 * Author: Fbin
 * Link:
 * Created at: 26/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  /**
   * Hash set
   * Time: O(n)
   * Space: O(1)
   */
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> st;
    while (head) {
      if (st.count(head)) return true;
      st.insert(head);
      head = head->next;
    }

    return false;
  }

  /**
   * Floyd's Tortoise and Hare
   * Time: O(n)
   * Space: O(1)
   */
  bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow) return true;
    }

    return false;
  }
};