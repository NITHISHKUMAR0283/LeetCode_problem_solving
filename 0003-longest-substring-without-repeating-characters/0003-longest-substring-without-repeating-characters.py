class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        seen = set()
        left = 0
        length =0
        n = len(s)
        for right in range(n):
            while left<n and  s[right] in seen:
                seen.discard(s[left])
                left+=1        
            seen.add(s[right])
            length = max(length , right-left+1)
        return length