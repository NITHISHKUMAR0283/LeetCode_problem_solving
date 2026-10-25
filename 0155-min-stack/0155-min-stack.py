class MinStack(object):

    def __init__(self):

        self.stack = []
    def push(self, value):
        
        curr_mini = min(value , self.stack[-1][1]) if self.stack else value
        self.stack.append((value,curr_mini))
        
    def pop(self):

        top , min = self.stack.pop()
    
    def top(self):

        top , min = self.stack[-1]
        return top

    def getMin(self):
        
        top , min = self.stack[-1]
        return min
        
