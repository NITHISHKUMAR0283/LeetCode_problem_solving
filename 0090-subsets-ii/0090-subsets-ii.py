class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        n = len(nums)
        nums.sort()
        subset = []
        for i in range (2**(n)):
            binary = bin(i)[2:].zfill(n)
            curr = []
            for j in range(len(binary)):
                if binary[j]=='1':
                    curr.append(nums[j])
            if curr not in subset:
                subset.append(curr)
        return subset
                

        