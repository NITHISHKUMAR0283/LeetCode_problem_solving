class Solution(object):
    def longestCommonPrefix(self, strs):
        common = []
        
        ans = ""
        for c in strs[0]:
            common.append(c)
        for i in range(len(strs)):
            j = 0
            current = []
            for c in strs[i]:
                if j>=len(common):
                    break
                if c!=common[j]:
                    break
                j+=1
                current.append(c)
            common  = current
            if len(common)==0:
                return ans
        for c in common:
            ans+=c
        return ans
