class Solution(object):
    def totalFruit(self, fruits):
        basket = {}
        left = 0
        maxi = 0
        for i in range(len(fruits)):
            f= fruits[i]
            if f not in basket:
                basket[f]=0
            basket[f]+=1
            while len(basket)>2 and left<len(fruits):
                basket[fruits[left]]-=1
                if basket[fruits[left]]==0:
                    del basket[fruits[left]]
                left+=1
            maxi = max(maxi , i-left+1)
        return maxi