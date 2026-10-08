class Solution(object):
    def validPalindrome(self, s):
        change = 1
        n = len(s)
        left = 0
        right = n-1
        while left<=right:
            
            if s[left]!=s[right]: 
                skipl = left+1
                sright = right
                canl = True
                while skipl<=sright:
                    if s[skipl]!=s[sright]:
                        canl=False
                        break
                    else:
                        skipl+=1
                        sright-=1
                if canl:
                    return True
                right -=1
                while left<=right:
                    if s[left]!=s[right]:
                        return False
                    left+=1
                    right-=1
            else:
                left+=1
                right-=1
        return True
        