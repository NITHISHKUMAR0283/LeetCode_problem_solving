# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        slow = head
        fast = head
        # find middle by slow and fast pointer then reverse the next half and tranverse and check it is palindrom or not from the both end 
        if head.next==None:
            return True
        while fast!=None and fast.next!=None:
            slow = slow.next
            fast=fast.next.next
        
        
        head2 = slow
        next = None
        current = head2
        prev = None
        while head2!=None:
            next = head2.next
            head2.next = prev
            prev = head2
            head2 = next
        head1= head
        head2= prev
        while head1!=None and head2!=None:
            if head1.val !=head2.val:
                return False
            head1=head1.next
            head2=head2.next
        
        return True
        