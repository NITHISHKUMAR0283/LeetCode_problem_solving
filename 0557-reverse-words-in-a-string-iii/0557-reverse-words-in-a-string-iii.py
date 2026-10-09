class Solution(object):
    def reverseWords(self, s):
        string = []
        for c in s:
            string.append(c)
        start = 0
        end = 0
        n = len(s)
        while end<n:
            while end <n and string[end]!=" ":
                end+=1
            end-=1
            e = end
            while start<end:
                string[end],string[start]=string[start],string[end]
                start+=1
                end-=1
            start=e+2
            end = start
        
        while start<n:            
            string[end],string[start]=string[start],string[end]
            start+=1
            end-=1
        ans = ""
        for c in string:
            ans+=c
        return ans
