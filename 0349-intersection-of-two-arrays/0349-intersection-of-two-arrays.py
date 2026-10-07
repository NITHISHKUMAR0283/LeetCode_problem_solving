class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        seen = set()
        for ele in nums1:
            seen.add(ele)
        intersection = []
        for ele in nums2:
            if ele in seen:
                intersection.append(ele)
                seen.discard(ele)
        return intersection
        