class Solution(object):
    def maxEqualAdjacentPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        seen = defaultdict(int)
        default = 0
        for i in range(len(nums)-1):
            if(nums[i]==nums[i+1]):default+=1
            else:
                seen[nums[i],nums[i+1]]+=1
                seen[nums[i+1],nums[i]]+=1
        maxi = 0
        for value in seen.values():
            maxi = max(maxi,value)

        return maxi+default
