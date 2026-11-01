from typing import Optional

# LeetCode's provided node definition
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k == 1:
            return head
            
        dummy = ListNode(0, head)
        prev_group_end = dummy  # Tracks the node before the current chunk
        
        while True:
            # 1️⃣ Check if at least k nodes remain
            kth_node = prev_group_end
            for _ in range(k):
                kth_node = kth_node.next
                if not kth_node:  # Not enough nodes for a full group
                    return dummy.next
                    
            # 2️⃣ Identify chunk boundaries
            next_group_start = kth_node.next  # First node of the next chunk
            first = prev_group_end.next       # First node of the current chunk
            
            # 3️⃣ Reverse the k nodes in-place
            prev, curr = kth_node.next, prev_group_end.next
            while curr != next_group_start:
                nxt = curr.next
                curr.next = prev
                prev = curr
                curr = nxt
                
            # 4️⃣ Reconnect the reversed chunk to the main list
            prev_group_end.next = kth_node    # Link previous chunk -> new head of reversed chunk
            first.next = next_group_start     # Link tail of reversed chunk -> next chunk
            prev_group_end = first            # Advance pointer to the tail of the reversed chunk
            
        return dummy.next
