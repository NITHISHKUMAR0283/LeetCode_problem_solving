class Solution(object):
    def findIndices(self, nums, indexDifference, valueDifference):
        n = len(nums)
        i = 0
        mini = float("inf")
        maxi = float("-inf")
        minii  = 0
        maxii = 0
        left=(-1*indexDifference)
        while i<n:
            if left<0:
                left+=1
                i+=1
                continue
            if mini>nums[left]:
                mini = nums[left]
                minii = left
            if maxi<nums[left]:
                maxi = nums[left]
                maxii = left
            if abs(nums[i]-mini)>=valueDifference:
                return [minii,i]
            if abs(nums[i]-maxi)>=valueDifference:
                return [maxii,i]
            i+=1
            left+=1
        return [-1,-1]
            