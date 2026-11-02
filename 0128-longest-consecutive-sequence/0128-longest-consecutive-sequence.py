class Solution(object):
    def longestConsecutive(self, nums):
        seen = set(nums)
        longest = 0

        for ele in seen:
            count =1
            if ele-1 not in seen:
                while ele+1 in seen:
                    ele+=1
                    count+=1
            longest = max(longest,count)
        return longest

        