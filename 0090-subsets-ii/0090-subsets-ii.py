class Solution(object):
    def subsetsWithDup(self, nums):

        n = len(nums)
        nums.sort()
        result = []
        seen = set()
        for i in range(2**n):
            binary = bin(i)[2:].zfill(n)
            curr = []
            for j in range(n):
                if binary[j]=="1":
                    curr.append(nums[j])
            if curr not in result:
                result.append(curr)
        return result
