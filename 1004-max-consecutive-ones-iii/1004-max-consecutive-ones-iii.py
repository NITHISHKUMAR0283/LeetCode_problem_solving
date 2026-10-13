class Solution(object):
    def longestOnes(self, nums, k):
        
        left = 0
        right = 0
        n = len(nums)
        maxi = 0
        while right<n:
            if nums[right]==0:
                if k>0:
                    k-=1
                else:
                    while left<n and  nums[left]!=0:
                        left+=1
                    left+=1
            maxi = max(maxi,right-left+1)
            right+=1
        return maxi