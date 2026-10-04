class Solution(object):
    def minRotations(self, s):
        """
        :type s: str
        :rtype: int
        """
        dails = []
        for _ in range(3):
            for i in range(10):
                dails.append(i)
        start = 10
        cost = 0
        current = 0
        for i in range(len(s)):
            next = int(s[i])
            left= start+current
            right = left
            c=0
            while dails[left]!=next and dails[right]!=next:
                left-=1
                right+=1
                c+=1
            cost+=c            
            current = next
        return cost

        