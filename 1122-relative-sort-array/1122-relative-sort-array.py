class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        freq = [0]*1001
        n = len(arr1)
        for ele in arr1:
            freq[ele]+=1
        result = [0]*n
        left = 0
        for ele in arr2:
            for j in range(freq[ele]):
                result[left] = ele
                left+=1
            freq[ele]=0

        for i in range(1001):
            for j in range(freq[i]):
                result[left] = i
                left+=1
        return result
            
        