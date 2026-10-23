class Solution(object):
    def calPoints(self, operations):
        sums = []
        result = 0
        for ope in operations:
            if ope=='C' and len(sums)>0:
                sums.pop()
            elif ope=='D' and len(sums)>0:
                sums.append(sums[-1]*2)
            elif ope=='+' and len(sums)>1:
                sums.append(sums[-1]+sums[-2])
            else:
                sums.append(int(ope))
        return sum(sums)
