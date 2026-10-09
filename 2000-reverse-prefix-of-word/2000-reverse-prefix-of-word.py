class Solution(object):
    def reversePrefix(self, word, ch):
        
        string = []
        for c in word:
            string.append(c)
        start = 0
        while  start<len(word) and word[start]!=ch:
            start+=1
        end = start
        start = 0
        if end==len(word):
            return word
        while start<end:
            string[start],string[end]=string[end],string[start]
            start+=1
            end-=1
        ans = ""
        for c in string:
            ans+=c
        return ans
        