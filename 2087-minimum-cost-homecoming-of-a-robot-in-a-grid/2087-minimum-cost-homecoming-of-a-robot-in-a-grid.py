class Solution(object):
    def minCost(self, startPos, homePos, rowCosts, colCosts):
        sr, sc = startPos
        dr, dc = homePos
        
        rs = sum(rowCosts[sr+1:dr+1]) if sr<dr else sum(rowCosts[dr:sr])
        cs = sum(colCosts[sc+1:dc+1]) if sc<dc else sum(colCosts[dc:sc])

        return rs+cs