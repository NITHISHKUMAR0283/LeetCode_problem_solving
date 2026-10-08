class Solution(object):
    def isPalindrome(self, x):
        rev= 0
        copy = x
        num = []
        if copy<0:
            return False
        while copy!=0:
            num.append(copy%10)
            copy/=10
        copy = x
        right = len(num)-1
        while right>=0:
            if copy%10!=num[right]:
                return False
            copy/=10
            right-=1
        return True
        