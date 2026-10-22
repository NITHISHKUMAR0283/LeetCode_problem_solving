class Solution(object):
    def isValid(self, s):
        stack = []
        pair = {
            ')':'(',
            ']':'[',
            '}':'{'
        }

        for c in s:
            if c=='(':
                stack.append('(')
            elif c=='[':
                stack.append('[')
            elif c=='{':
                stack.append('{')
            else:
                if len(stack)<=0 or stack[-1]!=pair[c]:
                    return False
                else:
                    stack.pop()
        if len(stack)>0:
            return False
        return True