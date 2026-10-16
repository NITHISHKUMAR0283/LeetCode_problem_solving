class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        freq = {}
        for c in s:
            if c not in freq:
                freq[c]=0
            freq[c]+=1
        for c in t:
            
            if c not in freq:
                return c
            freq[c]-=1
            if freq[c]==0:
                del freq[c]
        