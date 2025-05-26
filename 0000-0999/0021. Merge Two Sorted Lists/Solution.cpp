/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/merge-two-sorted-lists/description/
 * Created at: 26/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();
    ListNode *cur = dummy, *temp = nullptr;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        temp = list1;
        list1 = list1->next;
      } else {
        temp = list2;
        list2 = list2->next;
      }

      temp->next = nullptr;
      cur->next = temp;
      cur = cur->next;
    }

    if (list1) {
      cur->next = list1;
    }

    if (list2) {
      cur->next = list2;
    }

    return dummy->next;
  }
};
