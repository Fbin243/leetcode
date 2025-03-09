/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/partition-list/?envType=problem-list-v2&envId=linked-list
 * Created at: 09/03/2025
 */

#include <bits/stdc++.h>

#include "linked_list.h"

using namespace std;

/**
 * Approach: Use two pointers and dummy node
 * Idea: We will use two linked list, the first one will keep track the elements
 * greater than or equal to the x and the second one will keep track the
 * elements less than the x.
 *
 * We iterate over the linked list and try to remove all greater elements from
 * it and push them to the greater linked list. Afterwards, we will combine two
 * linked lists and return the final result.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

ListNode* partition(ListNode* head, int x) {
    ListNode* dummyGreater = new ListNode(0);
    ListNode* dummyRes = new ListNode(0);
    ListNode* prev = dummyRes;
    ListNode* greater = dummyGreater;
    prev->next = head;

    while (head) {
        if (head->val >= x) {
            greater->next = head;
            greater = greater->next;
            prev->next = head->next;
        } else
            prev = head;
        head = head->next;
    }

    greater->next = nullptr;
    prev->next = dummyGreater->next;

    return dummyRes->next;
}

int main() {
    ListNode* head = CreateList({1, 4, 3, 2, 5, 2});
    int x = 3;
    PrintList(partition(head, x));

    return 0;
}