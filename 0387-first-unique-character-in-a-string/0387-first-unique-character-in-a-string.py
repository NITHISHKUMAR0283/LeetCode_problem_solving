class Solution(object):
    def firstUniqChar(self, s):
        freq = {}
        n = len(s)

        for i in range(n):
            if s[i] not in freq:
                freq[s[i]]=0
            freq[s[i]]+=1
        for i in range(n):
            if freq[s[i]]==1:
                return i
        return -1
        