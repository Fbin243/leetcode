/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=linked-list
 * Created at: 09/03/2025
 */

#include <bits/stdc++.h>

#include "linked_list.h"

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

int main() {
    ListNode* head = CreateList({1, 2, 3, 4, 5});
    int n = 2;
    PrintList(removeNthFromEnd(head, n));

    return 0;
}