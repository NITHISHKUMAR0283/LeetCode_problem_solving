class Solution(object):
    def maxArea(self, height):
        
        left = 0
        right = len(height)-1
        volume = 0

        while left<right:
            wall = min(height[left],height[right])
            volume = max(volume,wall*(right-left))
            if height[left]<height[right]:
                left+=1
            else:
                right-=1
        return volume    