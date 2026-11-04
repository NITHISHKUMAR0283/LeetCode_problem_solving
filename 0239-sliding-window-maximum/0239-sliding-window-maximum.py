class Solution(object):
    def maxSlidingWindow(self, nums, k):
        heap = []
        result = []

        for i in range(k):
            heapq.heappush(heap,(-nums[i],i))
        result.append(-heap[0][0])
        for i in range(k,len(nums)):
            heapq.heappush(heap,(-nums[i],i))

            left = i-k+1

            while heap[0][1]<left:
                heapq.heappop(heap)
            result.append(-heap[0][0])

        return result