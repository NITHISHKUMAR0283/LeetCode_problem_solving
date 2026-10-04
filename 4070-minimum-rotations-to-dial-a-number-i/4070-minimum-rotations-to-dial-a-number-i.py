class Solution(object):
    def minRotations(self, s):
        """
        :type s: str
        :rtype: int
        """
        cost = 0
        current = 0
        for i in range(len(s)):
            next =int(s[i])
            cost += min( abs(next-current) , min( current+abs(10-next), abs(10-current)+next))            
            current = int(s[i])
        return cost

        