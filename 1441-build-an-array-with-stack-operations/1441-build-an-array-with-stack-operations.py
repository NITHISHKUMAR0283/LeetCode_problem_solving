class Solution(object):
    def buildArray(self, target, n):
        operations = []
        start = 1
        left = 0
        while start<=n:
            if  target[left]==start:
                operations.append("Push")
                left+=1
                if left>=len(target):
                    break 
            else:
                operations.append("Push")
                operations.append("Pop")
            start+=1
        return operations
                