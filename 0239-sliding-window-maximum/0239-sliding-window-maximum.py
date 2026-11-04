class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        dequeue = deque()
        result = []
        for i in range(k):
            while len(dequeue)>0 and nums[dequeue[-1]]<nums[i]:
                dequeue.pop()
            dequeue.append(i)
        result.append(nums[dequeue[0]])

        for i in range(k,len(nums)):
            
            if dequeue[0]<i-k+1:
                dequeue.popleft()
            while len(dequeue)>0 and nums[dequeue[-1]]<nums[i]:
                dequeue.pop()
            dequeue.append(i)
            result.append(nums[dequeue[0]])
        return result
        