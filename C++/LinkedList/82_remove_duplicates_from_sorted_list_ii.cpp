/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=linked-list
 * Created at: 09/03/2025
 */

#include <bits/stdc++.h>

#include "linked_list.h"

using namespace std;

/**
 * Approach: Use two pointers and dummy node
 * We make a dummy node keep the head of the result and ez to delete the head
 * node if needed.
 *
 * Afterwards, we iterate through the linked list we check if the current node’s
 * value differs from both the previous and next node’s values. If so, we add it
 * to the result list. This ensures that only distinct elements remain.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 */

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = new ListNode(-101);
    ListNode* dummy = res;
    ListNode* prev = res;
    while (head) {
        int nextVal = head->next ? head->next->val : -101;
        if (head->val != prev->val && head->val != nextVal) {
            res->next = head;
            res = res->next;
        }
        prev = head;
        head = head->next;
    }
    res->next = nullptr;
    return dummy->next;
}

int main() {
    ListNode* head = CreateList({1, 2, 3, 3, 4, 4, 5});
    int n = 2;
    PrintList(deleteDuplicates(head));

    return 0;
}