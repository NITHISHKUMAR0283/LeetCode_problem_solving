class Solution(object):
    def pivotIndex(self, nums):
        accumulate = [0]
        sum = 0
        for ele in reversed(nums):
            sum+=ele            
            accumulate.append(sum)
        sum = 0
        accumulate.reverse()
        for i in range(len(nums)):
            if sum == accumulate[i+1]:
                return i
            sum+=nums[i]
        return -1
