class Solution(object):
    def maxEqualAdjacentPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        seen = defaultdict(int)
        visited = set()
        visited.add(nums[-1])
        default = 0
        for i in range(len(nums)-1):
            visited.add(nums[i])
            if(nums[i]==nums[i+1]):default+=1
            seen[nums[i],nums[i+1]]+=1
        maxi = default
        for [f,s],value in seen.items():
            if f==s:continue
            maxi = max(maxi , seen[f,s]+seen[s,f]+default)

        return maxi
