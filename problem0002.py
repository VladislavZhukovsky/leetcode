
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def _createFromArray(self, arr):
        node = self
        for i in range(len(arr)):
            node.val = arr[i]
            if (i != len(arr) - 1):
                node.next = ListNode()
            node = node.next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l2.val += l1.val
        if l2.val > 9:
            l2.val -= 10
            if l2.next == None:
                l2.next = ListNode(1)
            else:
                l2.next.val += 1

        if l1.next == None and l2.next == None:
            return l2
        if l1.next == None:
            self.addTwoNumbers(ListNode(0), l2.next)
            return l2
        if l2.next == None:
            l2.next = ListNode()
        self.addTwoNumbers(l1.next, l2.next)

    def addTwoNumbers1(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        node1 = l1
        node2 = l2
        node3 = ListNode()

        result = ListNode()
        result.next = node3

        while node1 != None or node2 != None or node3 != None:
            x = 0
            if (node1 == None): x = 0
            else: x = node1.val

            y = 0
            if (node2 == None): y = 0
            else: y = node2.val

            node3.val += x + y
            if node3.val > 9:
                node3.val -= 10
                if node3.next == None:
                    node3.next = ListNode(0)
                node3.next.val += 1
        
            if node1 != None:
                node1 = node1.next
            if node2 != None:
                node2 = node2.next
            if (node1 != None or node2 != None) and node3.next == None:
                node3.next = ListNode()
            node3 = node3.next

        return result.next           

a = [2,4,3]
l1 = ListNode()
l1._createFromArray([2,4,9])
l2 = ListNode()
l2._createFromArray([5,6,4,9])

s = Solution()
result = s.addTwoNumbers1(l1, l2)
print(result)