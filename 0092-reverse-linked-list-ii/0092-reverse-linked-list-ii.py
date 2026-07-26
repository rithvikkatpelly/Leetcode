# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseBetween(self, head: 'ListNode', left: int, right: int) -> 'ListNode':
        if not head or left == right:
            return head

        dummy = ListNode(0, head)

        # Step 1: move `prev` to the node just before position `left`
        prev = dummy
        for _ in range(left - 1):
            prev = prev.next

        # `curr` will start at position `left` and get pushed forward
        # by repeatedly moving the node after it to the front of the sublist
        curr = prev.next

        # Step 2: reverse the sublist from left to right using
        # the "insert front" technique
        for _ in range(right - left):
            nxt = curr.next
            curr.next = nxt.next
            nxt.next = prev.next
            prev.next = nxt

        return dummy.next    