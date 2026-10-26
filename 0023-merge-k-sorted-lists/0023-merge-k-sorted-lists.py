# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        heap = []
        for l in lists:
            if l==None:
                continue
            heapq.heappush(heap,(l.val,l))
            
        head = ListNode()
        
        ans = head
        while heap:
            val,curr = heapq.heappop(heap)
            head.next = curr
            head = head.next
            if curr.next!=None:
                heapq.heappush(heap,(curr.next.val,curr.next))
        return ans.next