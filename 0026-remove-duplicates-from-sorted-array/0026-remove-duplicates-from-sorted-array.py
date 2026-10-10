class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        j = 0
        n = len(nums)
        while j<n:
            while j<n and  nums[j]==nums[i]:
                j+=1
            if j>=n:
                break
            
            i+=1
            if i>=n:
                break
            nums[i],nums[j]= nums[j],nums[i]
            j+=1
        return i+1
            