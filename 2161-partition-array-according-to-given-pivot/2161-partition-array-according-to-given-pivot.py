class Solution(object):
    def pivotArray(self, nums, pivot):
        """
        :type nums: List[int]
        :type pivot: int
        :rtype: List[int]
        """
        less =[]
        great = []
        current = 0
        for i in range(len(nums)):
            if nums[i]<pivot:
                less.append(nums[i])
            elif nums[i]>pivot:
                great.append(nums[i])
            else:
                current+=1
        result = less
        for _ in range(current):
            result.append(pivot)
        result+=great
        return result
        