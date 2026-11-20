class Solution(object):
    def longestNiceSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        current = 0
        n = len(nums)
        longest = 0
        i=0

        while i<n:
            
            while current&nums[i]!=0:
                    current^=nums[left]
                    left+=1
                
            current |= nums[i]
            longest = max(longest,i-left+1)
            i+=1

        
        return longest

        