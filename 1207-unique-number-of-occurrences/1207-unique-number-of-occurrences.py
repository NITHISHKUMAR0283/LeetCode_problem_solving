class Solution(object):
    def uniqueOccurrences(self, arr):
        
        freq = {}
        for ele in arr:
            if ele not in freq:
                freq[ele]=0
            freq[ele]+=1
        seen = set()        
        for ele , f in freq.items():
            if f in seen:
                return False
            seen.add(f)
        return True
