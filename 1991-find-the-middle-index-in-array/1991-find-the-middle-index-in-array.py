class Solution(object):
    def findMiddleIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        accumulate = [0]
        sum = 0
        for ele in reversed(nums):
            sum+=ele
            accumulate.append(sum)
        accumulate.append(0)
        accumulate.reverse()
        sum=0
        for i in range(len(nums)):
            if sum==accumulate[i+2]:
                return i
            sum+=nums[i]
        return -1