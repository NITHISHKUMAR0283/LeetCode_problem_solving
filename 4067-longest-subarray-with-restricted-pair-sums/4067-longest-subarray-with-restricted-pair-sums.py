class Solution(object):
    def isvalid(self,current,freq):
        for key , value in freq.items():
            if key+current in freq:
                return True
            if  current-key in freq :
                if current-key!=key or freq[key]>=2 :
                    return True
        return False
    def maxSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        current = 0
        freq = defaultdict(int)
        n = len(nums)
        length = 0
        for i in range(n):
            current = nums[i]
            
               

            while left<i and self.isvalid(current,freq):
                freq[nums[left]]-=1
                if freq[nums[left]]==0:
                    del freq[nums[left]]
                left+=1
            freq[nums[i]]+=1
            length  = max(length,i-left+1)

        return length
                
                

        