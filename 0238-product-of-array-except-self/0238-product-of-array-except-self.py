class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        left = []
        right = []
        
        n = len(nums)
        product = 1
        p2 =1
        for i in range(n):
            product*=nums[i]
            left.append(product)
            p2*=nums[n-i-1]
            right.append(p2)
        right.reverse()
        result = [right[1]]
        for i in range(1,n-1):
            result.append(left[i-1]*right[i+1])
        result.append(left[-2])
        return result