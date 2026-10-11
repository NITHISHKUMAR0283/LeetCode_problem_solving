class Solution(object):
    def merge(self, nums1, m, nums2, n):
        
        right = len(nums1)-1
        left = m-1
        while left>-1:
            nums1[right]=nums1[left]
            left-=1
            right-=1
        
        left = right+1
        right = 0
        current = 0
        while left<len(nums1) and right <n:
            if nums1[left]<=nums2[right]:
                nums1[current]=nums1[left]
                left+=1
                current+=1
            else:
                nums1[current] = nums2[right]
                right+=1
                current+=1
        while left<len(nums1):
            nums1[current]=nums1[left]
            left+=1
            current+=1
        while right <n:
            nums1[current] = nums2[right]
            right+=1
            current+=1
