class Solution(object):
    def detectCycle(self, head):
        slow = head
        fast = head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast ==slow:
                break
        if fast==None or fast.next==None:
            return None
        fast = head
        while fast != slow:
            fast = fast.next
            slow = slow.next
        return fast