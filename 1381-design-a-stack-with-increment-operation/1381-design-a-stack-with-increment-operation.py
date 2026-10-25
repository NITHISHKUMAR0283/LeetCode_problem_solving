class CustomStack(object):
    def __init__(self, maxSize):
        
        self.stack = [-1]*maxSize
        self.n = maxSize
        self.left = 0

    def push(self, x):

        if self.left==self.n:
            return
        self.stack[self.left] = x
        self.left+=1       

    def pop(self):
        
        if self.left==0:
            return -1
        val = self.stack[self.left-1]
        self.stack[self.left-1]=-1
        self.left-=1
        return val

    def increment(self, k, val):
        
        end = min(k,self.n)
        for i in range(end):
            self.stack[i]+=val
