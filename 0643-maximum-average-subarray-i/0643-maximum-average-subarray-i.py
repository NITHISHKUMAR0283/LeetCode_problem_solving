class Solution(object):
    def findMaxAverage(self, nums, k):
        sum = 0
        left = 0
        right = 0
        n = len(nums)
        ans = float("-inf")
        while right<n:            
            sum+=nums[right]
            if right-left+1<k:
                right+=1
                continue
            ans=  max(ans,float(sum)/k)
            sum-=nums[left]
            left+=1
            right+=1
        return ans
