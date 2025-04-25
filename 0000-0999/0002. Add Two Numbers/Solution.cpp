/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/add-two-numbers/description/?envType=problem-list-v2&envId=linked-list
 * Created at: 08/03/2025
 */

#include <bits/stdc++.h>

#include "linked_list.h"

using namespace std;

/**
 * Approach: Dummy node
 * To add two numbers represented as linked lists, we use a dummy node to
 * simplify list creation. We traverse both lists, summing their values along
 * with any carry-over, and store the result in a new linked list.
 *
 * Edge cases:
 * - Two linked lists can have different lengths, so if a linked list is over,
 * we still keep working on the remaining linked list
 * - A carry remains after processing all digits, requiring an extra node (1 at
 * the end).
 *
 * Time complexity: O(max(N, M)) -> O(n)
 * Space complexity: O(max(N, M)) -> O(n)
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* res = new ListNode(0);
  ListNode* dummy = res;
  int carry = 0;

  while (l1 || l2 || carry) {
    int val1 = l1 ? l1->val : 0;
    int val2 = l2 ? l2->val : 0;

    int sum = val1 + val2 + carry;
    res->next = new ListNode(sum % 10);
    carry = sum / 10;

    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
    res = res->next;
  }

  ListNode* result = dummy->next;
  delete dummy;
  return result;
}

int main() {
  ListNode* l1 = CreateList({9, 9, 9, 9, 9, 9, 9});
  ListNode* l2 = CreateList({9, 9, 9, 9});
  ListNode* result = addTwoNumbers(l1, l2);

  PrintList(result);

  return 0;
}