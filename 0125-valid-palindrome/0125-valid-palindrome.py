class Solution(object):
    def isPalindrome(self, s):
        
        buffer = []
        for c in s:
            if c.isalnum():
                buffer.append(c.lower())
        end = len(buffer)-1
        start = 0
        while start<end:
            if buffer[start]!=buffer[end]:
                return False
            start+=1
            end-=1
        return True
        