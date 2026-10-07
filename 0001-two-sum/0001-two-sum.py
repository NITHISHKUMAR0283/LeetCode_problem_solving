class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        Ele_ind = {} #primitive dict allowed in alpha 300



        for i in range(len(nums)): # finding complement , if found return its index
            complement = target-nums[i]

            if target-nums[i] in Ele_ind :
                return [Ele_ind[complement],i]
            Ele_ind[nums[i]]=i