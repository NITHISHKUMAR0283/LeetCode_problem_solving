class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        dequeue = deque()
        result = []
        for i in range(len(nums)):
            
            if dequeue and dequeue[0]<i-k+1:
                dequeue.popleft()
            while dequeue and nums[dequeue[-1]]<nums[i]:
                dequeue.pop()
            dequeue.append(i)
            if i>=k-1:
                result.append(nums[dequeue[0]])
        return result
        