class Solution(object):
    def reverseStr(self, s, k):
        start= 0
        n = len(s)
        string  = []
        for c in s:
            string.append(c)
        while start<n:
            end = start+k-1
            if end>=n:
                break
            st = start 
            en = end
            while st<en:
                string[st],string[en] = string[en],string[st]
                st+=1
                en-=1
            start = start+2*k
        if start<n:
            end = n-1
            while start<end:
                string[start],string[end] = string[end],string[start]
                start+=1
                end-=1
        ans = ""
        for c in string:
            ans+=c
        return ans
        