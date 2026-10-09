class Solution(object):
    def reverseVowels(self, s):
        vowels =[]
        string =[]
        for c in s:
            string.append(c)
            if c.lower() in "aeiou":
                vowels.append(c)
        ans = ""
        right = len(string)-1
        end = 0
        while right>-1:
            if string[right].lower() in "aeiou":
                string[right]=vowels[end]
                end+=1
            right-=1
        for c in string:
            ans+=c
        return ans 
        