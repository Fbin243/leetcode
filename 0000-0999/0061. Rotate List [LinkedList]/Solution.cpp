/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=linked-list
 * Created at: 09/03/2025
 */

#include <bits/stdc++.h>

#include "linked_list.h"

using namespace std;

/**
 * Approach: Use a pointer to keep track the tail node.
 * - 1. Handle edge cases: If the list is empty or contains only one element,
 * return the head immediately.
 * - 2. Find the tail node and determine the length of the list by traversing
 * through it.
 * - 3. Optimize the number of rotations by computing k % n to eliminate
 * redundant rotations. If k is a multiple of n, the list remains unchanged.
 * - 4. Instead of performing k right rotations, rotate the list left (n - k)
 * times to achieve the same result.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

ListNode* rotateRight(ListNode* head, int k) {
  if (!head || !head->next) return head;
  ListNode* tail = head;
  int n = 1;
  while (tail->next) {
    tail = tail->next;
    n++;
  }
  int i = 0;
  k = k % n;
  while (i++ < n - k) {
    tail->next = head;
    head = head->next;
    tail = tail->next;
    tail->next = nullptr;
  }

  return head;
}