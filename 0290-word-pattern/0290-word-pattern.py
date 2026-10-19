class Solution(object):
    def wordPattern(self, pattern, s):
        mapped = defaultdict(int)
        gotted = defaultdict(int)
        start = 0
        n = len(s)
        words = []
        while start<n:
            word = ""
            while start<n and s[start]!=" ":
                word+=s[start]
                start+=1
            words.append(word)
            start+=1
        if len(pattern) != len(words):
            return False
        for i in range(len(words)):
            if pattern[i] in mapped and mapped[pattern[i]]!=words[i]:
                print("Here",i)
                return False
            elif words[i] in gotted and gotted[words[i]]!= pattern[i]:
                return False
            else:
                mapped[pattern[i]] = words[i]
                gotted[words[i]] = pattern[i]
        return True