class Solution(object):
    def isPalindrome(self, s):
        
        buffer = []
        for c in s:
            # string is immutable , so we store the chars for two pointer approach 
            if c.isalnum():
                buffer.append(c.lower())
        
        end = len(buffer)-1
        start = 0
        #inc and dec both end and check the char are same are not for palindriome
        while start<end:
            if buffer[start]!=buffer[end]:
                return False
            start+=1
            end-=1
        return True
        