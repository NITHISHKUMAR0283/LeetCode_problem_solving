class Solution(object):
    def findAnagrams(self, s, p):
        freq = [0]*26
        pfreq = [0]*26
        anagram = []
        n = len(s)
        
        for i in range(len(p)):
            pfreq[ord(p[i])-97]+=1
        
        left = 0
        for right in range(len(s)):
            c = s[right]
            ascii = ord(c)-97
            freq[ascii]+=1
            while left<n and freq[ascii]>pfreq[ascii] :
                freq[ord(s[left])-97]-=1
                left+=1
            if left <n and freq==pfreq:
                anagram.append(left)
                freq[ord(s[left])-97]-=1
                left+=1


        return anagram

            



        