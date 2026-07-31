# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1
        
        if list1.val > list2.val:
            return self.mergeTwoLists(list2, list1)
        
        c1 = list1
        c2 = list2
        prev = ListNode(0, None)
        while c1 and c2:
            if c1.val <= c2.val:
                prev = c1
                c1 = c1.next
            else:
                next2 = c2.next

                prev.next = c2
                c2.next = c1

                prev = c2
                c2 = next2
        if c2:
            prev.next = c2
        return list1