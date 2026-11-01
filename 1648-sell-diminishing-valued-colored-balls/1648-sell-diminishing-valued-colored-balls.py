class Solution(object):
    def sumn(self,n):
        return n*(n+1)/2
    def maxProfit(self, inventory, orders):
        """
        :type inventory: List[int]
        :type orders: int
        :rtype: int
        """
        MOD = 10**9+7
        inventory.append(0)
        inventory.sort(reverse=True)
        sum = 0

        n = len(inventory)
        profits = 0
        for i in range(1,n):
            blocks = inventory[i-1]-inventory[i]
            if blocks*(i) >orders:
                count = i
                k = orders//count
                remainder = orders%count

                top = inventory[i-1]
                bottom = top-k

                profits += (count*(top+bottom+1)*(top-bottom)//2)%MOD

                profits+=(remainder*bottom)%MOD
                break
            else:
                profits += ((self.sumn(inventory[i-1])-self.sumn(inventory[i]))*(i))%MOD
                orders-=blocks*i
        return profits%MOD
        