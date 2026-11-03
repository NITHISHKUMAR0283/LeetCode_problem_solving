class Solution(object):
    def leastInterval(self, tasks, n):
        freq = {}
        maxi = 0
        count_maxi = 0 
        for t in tasks:
            if t not in freq:
                freq[t]=0
            freq[t]+=1
            if freq[t]>maxi:
                maxi = freq[t]
                count_maxi=1
            elif freq[t]==maxi:
                count_maxi+=1

        segments = maxi-1
        empty = segments*(n-(count_maxi-1))
        idle = max(0,empty-(len(tasks)-(maxi*count_maxi)))

        return idle+len(tasks)