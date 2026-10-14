class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        freq = defaultdict(int)
        left = 0
        n = len(nums)
        for right in range(n):
            if nums[right] in freq:
                return True
            freq[nums[right]]+=1
            while right-left>=k:
                
                print(right,left,k)
                freq[nums[left]]-=1
                if freq[nums[left]]==0:
                    del freq[nums[left]]
                left+=1        
        return False
        