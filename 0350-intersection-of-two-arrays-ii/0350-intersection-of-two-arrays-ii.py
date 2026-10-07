class Solution(object):
    def intersect(self, nums1, nums2):
        freq1 = {}
        for ele in nums1:
            if ele not in freq1:
                freq1[ele]=0
            freq1[ele]+=1
        intersection = []
        for ele in nums2:
            if ele in freq1:
                intersection.append(ele)
                freq1[ele]-=1
                if freq1[ele]==0:
                    freq1.pop(ele)
        return intersection
        