/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=linked-list
 * Created at: 09/03/2025
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Approach: Use two pointers
 * We need to find out the node before the to-delete node. Since we can not
 * traverse backward in the singly linked list, we use two pointers to
 * efficiently locate the node to be deleted.
 *
 * Make a dummy node, move the head n steps to make a distance n between head
 * and dummy. Then move both head and dummy node until the head become nullptr.
 * At this time, the dummy node is right before the node to be deleted.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  ListNode* res = dummy;

  while (n--) {
    head = head->next;
  }

  while (head) {
    head = head->next;
    dummy = dummy->next;
  }

  ListNode* removeNode = dummy->next;
  dummy->next = removeNode->next;
  delete removeNode;

  return res->next;
}

// -- Solution at 26/05/2025
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode *fast = dummy, *slow = dummy;
    while (n--) {
      fast = fast->next;
    }
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode* temp = slow->next;
    slow->next = temp->next;
    delete temp;
    temp = nullptr;

    return dummy->next;
  }
};