class Solution(object):
    

    def myPow(self, x, n):
        
        result = 1
        is_neg = False
        if n<0:
            is_neg=True
            n*=-1
        while n>0:
            if n%2==0:
                x*=x
                n/=2
            else:
                result*=x
                n-=1
        if is_neg:
            return 1/result
        return result