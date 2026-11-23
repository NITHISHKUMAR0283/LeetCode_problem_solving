class Solution(object):
    def longestBeautifulSubstring(self, word):

        v = ['a','e','i','o','u']
        
        left = 0
        current = 0
        n = len(word)
        ans = 0
        while current<n:
            s = 0
            while s<5 and current<n-1 and   word[current]==v[s]:
                current+=1
                if word[current]!=v[s]:
                    s+=1
            if s==5 :
                ans = max(ans,current-left)
            if s==0:
                current+=1
            if (s==4 and current==n-1 and word[n-1]=="u"):
                ans = max(ans,current-left+1)
            left = current
        return ans