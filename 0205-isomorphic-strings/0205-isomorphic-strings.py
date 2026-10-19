class Solution(object):
    def isIsomorphic(self, s, t):
        mapped=  {}
        gotted  = {}
        n = len(s)

        for i in range(n):
            if  s[i] in mapped:
                if mapped[s[i]] != t[i]:
                    return False
            
            else:
                if t[i] in gotted and gotted[t[i]]!=s[i]:
                    return False
                mapped[s[i]] = t[i]
                gotted[t[i]] = s[i]
        return True