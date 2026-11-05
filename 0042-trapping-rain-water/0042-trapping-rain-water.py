class Solution(object):
    def trap(self, height):
        
        stack = []
        stack.append(0)

        water = 0
        for i in range(len(height)):
            curr = height[i]
            while stack and height[stack[-1]]<=curr:
                mid = stack.pop()

                if not stack:
                    break
                left = stack[-1]
                heights = min(height[i],height[left])-height[mid]
                width = i-left-1
                water += heights*width
            stack.append(i)
        return water
