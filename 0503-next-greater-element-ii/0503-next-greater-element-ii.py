class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        val_ind = {}
        result = []
        for i in range(len(nums)):
            j = i +1
            greatest = -1
            while j-i<len(nums):
                rot = j%len(nums)
                if nums[rot]>nums[i]:
                    greatest = nums[rot]
                    break
                j+=1
            result.append(greatest)

        return result
        