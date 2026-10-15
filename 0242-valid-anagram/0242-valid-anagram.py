class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        freq = [0]*26
        for i in range(len(s)):
            ind = ord(s[i])-97
            freq[ind]+=1
        for j in range(len(t)):
            ind = ord(t[j])-97
            freq[ind]-=1
        for i in range(26):
            if freq[i]!=0:
                return False
        return True