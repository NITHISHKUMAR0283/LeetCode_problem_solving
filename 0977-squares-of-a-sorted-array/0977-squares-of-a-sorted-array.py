class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        left = 0
        n = len(nums)
        while left<n and nums[left]<0:
            left+=1
        for i in range(n):
            nums[i] = nums[i]*nums[i]
        result = [0]*n
        right = left
        left =left-1
        current = 0
        print(left,right)
        while left>=0 and right<n:
            if nums[left]<=nums[right]:
                result[current] = nums[left]
                left-=1
            else:
                result [current] = nums[right]
                right+=1
            current+=1
        while left>=0:
            result[current]=nums[left]
            left-=1
            current+=1
        while right<n:
            result[current] = nums[right]
            right+=1
            current+=1
        return result
            
        