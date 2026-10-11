class Solution(object):
    def quicksort(self,intervals,l,right):
        if right<=l:
            return 
        pivot = right

        left = l
        for i in range(left,right+1):
            if intervals[i][0]<intervals[pivot][0]:
                intervals[left] ,intervals[i] = intervals[i],intervals[left]
                left+=1
            if intervals[i][0]==intervals[pivot][0]:
                if intervals[i][1]<intervals[pivot][1]:
                    intervals[left] ,intervals[i] = intervals[i],intervals[left]
                    left+=1
        
        intervals[left] ,intervals[right] = intervals[right],intervals[left]
        self.quicksort(intervals,left+1,right)
        self.quicksort(intervals,l,left-1)
            

    def merge(self, intervals):

        n = len(intervals)
        self.quicksort(intervals,0,n-1)

        start = intervals[0][0]
        end = intervals[0][1]
        merged = []
        for cstart , cend in intervals:
            if end <cstart:
                merged.append([start,end])
                start = cstart
                end = cend
            else:
                end = max(cend,end)
        merged.append([start,end])
        return merged
                


