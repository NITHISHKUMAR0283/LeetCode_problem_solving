class Solution(object):
    def moveZeroes(self, nums):
        
        current=  0
        n = len(nums)
        while current<n:
            if nums[current]==0:
                nonzero = current+1
                while nonzero<n and nums[nonzero]==0:
                    nonzero+=1
                if nonzero>=n :
                    break
                nums[current],nums[nonzero] = nums[nonzero],nums[current]
            current+=1