class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words =""
        start = 0
        end = 0
        n = len(s)
        while end<n:
            w = ""
            while end<n and s[end]==" ":
                end+=1
            while end<n and  s[end]!=" ":
                w+=s[end]
                end+=1
        
            words+=w[::-1]
            if w!="":
                words+=" "
        words=words[:len(words)-1]
        return words[::-1]
