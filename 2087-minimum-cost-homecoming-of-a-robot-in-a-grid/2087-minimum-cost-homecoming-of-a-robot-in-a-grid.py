class Solution(object):
    def minCost(self, startPos, homePos, rowCosts, colCosts):
        sr,sc = startPos
        dr , dc = homePos

        cost = 0

        while sr!=dr:
            sr+= 1 if sr<dr else -1
            cost+=rowCosts[sr]
        while sc!=dc:
            sc+=1 if sc<dc else -1
            cost+=colCosts[sc]
        return cost