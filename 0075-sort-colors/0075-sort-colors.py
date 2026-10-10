class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        zero = 0
        one = len(nums)-1
        i=0
        while i <=one:
            if nums[i]==0:
                nums[zero],nums[i]= nums[i],nums[zero]
                zero+=1
                i+=1
            elif nums[i] ==2:
                nums[i],nums[one] = nums[one],nums[i]
                one-=1
            else:
                i+=1
        

        