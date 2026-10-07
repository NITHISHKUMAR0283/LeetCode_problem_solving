class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        Ele_ind = {} #primitive dict allowed in alpha 300

        for i in range(len(nums)): # making ele , index pair 
            Ele_ind[nums[i]]=i


        for i in range(len(nums)):
            if target-nums[i] in Ele_ind and i !=Ele_ind[target-nums[i]]:
                return [i,Ele_ind[target-nums[i]]]