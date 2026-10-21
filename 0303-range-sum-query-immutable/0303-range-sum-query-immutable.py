class NumArray(object):
    nums = None
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums
        

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        sum = 0
        for i in range(left,right+1):
            sum+=self.nums[i]
        return sum
        
