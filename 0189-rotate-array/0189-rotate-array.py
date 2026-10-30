class Solution(object):
    def rotate(self, nums, k):
        
        left = 0
        right = len(nums)-1
        n = len(nums)
        k%=n
        while left<right:
            nums[left],nums[right] = nums[right] , nums[left]
            left+=1
            right-=1
        
        left = 0
        right = k-1
        while left<right:
            nums[left],nums[right] = nums[right] , nums[left]
            left+=1
            right-=1
        left = k
        right = n-1
        while left<right:
            nums[left],nums[right] = nums[right] , nums[left]
            left+=1
            right-=1