class Solution(object):
    def minRemoveToMakeValid(self, s):
        
        n = len(s)
        valid = [False] * n
        stack = []

        for i in range(n):
            if s[i]=='(':
                stack.append(('(',i))
            elif s[i]==")":
                if len(stack)>0 and stack[-1][0]=='(':
                    valid[stack[-1][1]]=True
                    valid[i]=True
                    stack.pop()
                else:
                    stack.append((')',i))
            else:
                valid[i]=True
        result = ""
        for i in range(len(valid)):
            if valid[i]:
                result+=s[i]
        return result
            