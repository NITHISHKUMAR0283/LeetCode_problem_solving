class Solution(object):
    def findClosestElements(self, arr, k, x):

        lbound = bisect.bisect_left(arr,x)
        result = deque()
        left = lbound-1
        right = lbound
        while k and left>=0 and right<len(arr):
            ldist = abs(arr[left]-x) 
            rdist = abs(arr[right]-x)

            if left>=0 and  ldist<=rdist and arr[left]<arr[right] :
                result.appendleft(arr[left])
                left-=1
            else:
                result.append(arr[right])
                right+=1
            
            k-=1
        
        if left<0:
            while k:
                result.append(arr[right])
                right+=1
                k-=1
        elif right>=len(arr):
            while k :
                result.appendleft(arr[left])
                left-=1
                k-=1
        return list(result)