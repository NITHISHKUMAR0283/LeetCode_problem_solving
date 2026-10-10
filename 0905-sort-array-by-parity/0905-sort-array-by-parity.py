class Solution(object):
    def sortArrayByParity(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        even = 0
        odds = []
        next = 0
        for i in range(len(nums)):
            if nums[i]%2==0:
                nums[next] = nums[i]
                next+=1
            else:
                odds.append(nums[i])
        l = 0
        while next<len(nums):
            nums[next]=odds[l]
            l+=1
            next+=1
        return nums
