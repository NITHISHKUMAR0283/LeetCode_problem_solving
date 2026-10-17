class Solution(object):
    def toLowerCase(self, s):
        """
        :type s: str
        :rtype: str
        """
        word = []
        for c in s:
            word.append(c.lower())
        ans = ""
        for c in word:
            ans+=c
        return ans