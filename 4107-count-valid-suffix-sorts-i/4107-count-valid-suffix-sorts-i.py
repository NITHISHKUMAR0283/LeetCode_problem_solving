class Solution(object):
    def countSuffix(self, nums, target):
        """
        :type nums: List[int]
        :type target: List[int]
        :rtype: int
        """
        if Counter(nums) != Counter(target):
            return 0
        
        n = len(nums)
        
        p = 0
        while p < n and nums[p] == target[p]:
            p += 1
            
        q = n - 1
        while q > 0 and target[q - 1] >= target[q]:
            q -= 1
            
        upper = min(p, n - 1)
        return max(0, upper - q + 1)