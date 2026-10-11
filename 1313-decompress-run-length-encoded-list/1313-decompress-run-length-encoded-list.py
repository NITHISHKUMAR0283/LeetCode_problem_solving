class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = []
        for i in range(0,len(nums),2):
            freq = nums[i]
            ele = nums[i+1]
            for _ in range(freq):
                result.append(ele)
        return result