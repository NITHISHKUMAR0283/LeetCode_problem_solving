class Solution(object):
    def makeGood(self, s):
        stack = []
        for c in s:
            if len(stack)>0 and abs(ord(c)-ord(stack[-1]))==32:
                stack.pop()
            else:
                stack.append(c)
        result = ""
        for ele in stack:
            result+=ele
        return result