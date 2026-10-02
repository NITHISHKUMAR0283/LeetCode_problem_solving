class Solution(object):
    def longestSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        longest = 0
        
        for i in range(n):
            sum = 0
            seen_mod = set()
            for j in range(i,n):
                sum+=nums[j]
                seen_mod.add((2*nums[j])%k)

                mod = sum%k
                if mod==0 or mod in seen_mod:
                    longest = max(longest,j-i+1)
        return longest
        