class Solution(object):
        
    def platesBetweenCandles(self, s, queries):
        candles = []
        plates = 0
        prefix = {}
        for i in range(len(s)):
            if s[i]=="*":
                plates+=1
            else:
                prefix[i] = plates
                candles.append(i)
        result = []
        for s,e in queries:
            left , right =  bisect.bisect_left(candles,s),bisect.bisect_right(candles,e)-1
            if right<left:
                result.append(0)
                continue
            left , right = candles[left], candles[right]
            curr = prefix[right]-prefix[left]
            result.append(curr)
        return result