class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        current = len(s)-1
        while current>=0 and s[current]==" ":
            current-=1
        end = current
        while current>=0 and s[current]!=" ":
            current-=1
        return end-current
        