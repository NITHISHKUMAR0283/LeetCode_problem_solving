class Solution(object):
    def isNStraightHand(self, hand, groupSize):

        n = len(hand)
        if n%groupSize!=0:
            return False
        keys = set()
        freq = defaultdict(int)

        for ele in hand:
            keys.add(ele)
            freq[ele]+=1
        keys = list(keys)
        keys.sort()
        for k in keys:
            while k in freq and freq[k]>0:
                for j in range(groupSize):                    
                    if k+j not in freq :
                        return False
                    freq[k+j]-=1
                    if freq[k+j]==0:
                        del freq[k+j]
        return True