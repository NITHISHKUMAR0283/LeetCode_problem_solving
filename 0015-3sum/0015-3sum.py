class Solution(object):
    def quicksort(self,nums,low,high):
        if low<high:
            pivot = nums[high]
            
            i = low-1
            for j in range(low,high):
                if nums[j]<=pivot:
                    i+=1
                    nums[i],nums[j] = nums[j],nums[i]
            nums[i+1],nums[high] = nums[high] , nums[i+1]
            pivot_ind = i+1
            self.quicksort(nums,low,pivot_ind-1)
            self.quicksort(nums,pivot_ind+1,high)
        

    def threeSum(self, nums):

        n = len(nums)
        self.quicksort(nums,0,n-1)

        triplets = []
        i = 0
        n = len(nums)


        while i<n:
            k = n-1
            j = i+1
            while j<k:
                sum = nums[j]+nums[k]                
                if sum==-nums[i]:
                    triplets.append([nums[i],nums[j],nums[k]])
                    j+=1
                    while j<n and nums[j]==nums[j-1]:
                        j+=1
                elif sum>-nums[i]:
                    k-=1
                else:
                    j+=1
            i+=1
            while i<n and nums[i]==nums[i-1]:
                i+=1

        return triplets
        

        