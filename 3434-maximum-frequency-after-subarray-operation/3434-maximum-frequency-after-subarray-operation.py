class Solution(object):
    def maxFrequency(self, nums, k):
        countk = 0
        for x in nums:
            if x==k:
                countk+=1
        max_gain = 0
        for cand in range(1,51):
            if cand == k:
                continue
            count = 0
            
            max_sub_freq = 0
            for ele in nums:
                if ele == cand:
                    count+=1
                elif ele==k:
                    count-=1
                count = max(count,0)
                max_sub_freq = max(max_sub_freq,count)
            max_gain = max(max_gain,max_sub_freq)

        return max_gain+countk


        