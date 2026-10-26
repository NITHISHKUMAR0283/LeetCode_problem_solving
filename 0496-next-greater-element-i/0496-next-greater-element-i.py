class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        val_ind = {}
        result = []
        for i in range(len(nums2)):
            val_ind[nums2[i]]=i
        for i in range(len(nums1)):
            great = -1
            start = val_ind[nums1[i]]
            j = start+1
            while j<len(nums2):
                if nums2[j]>nums2[start]:
                    great=nums2[j]
                    break
                j+=1
            result.append(great)
        return result