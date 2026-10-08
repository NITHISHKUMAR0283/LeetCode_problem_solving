class Solution(object):
    def reverseOnlyLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        # take the letters from starting and start to replace letters from last
        letters = []
        string = []
        for c in s:
            string.append(c)
            if c.isalpha():
                letters.append(c)
        replace = len(letters)
        right = len(string)-1
        r = 0
        while replace>0:
            while right>=0 and  not string[right].isalpha():
                right-=1
            if replace>0:
                string[right]=letters[r]
                r+=1
                replace-=1
            right-=1
        ans = ""
        for c in string:
            ans+=c
        return ans
                

