class MyQueue(object):

    def __init__(self):
        self.input_stack = []
        self.output_stack = []



    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.input_stack.append(x)


    def pop(self):
        """
        :rtype: int
        """
        if len(self.output_stack)==0:
            self.reverse()
        return self.output_stack.pop()
        
    def reverse (self):
        while len(self.input_stack)>0:
                self.output_stack.append(self.input_stack.pop())
    def peek(self):
        """
        :rtype: int
        """
        if len(self.output_stack)==0:
            self.reverse()
        
        return self.output_stack[-1]
        

    def empty(self):
        """
        :rtype: bool
        """
        
        if len(self.output_stack)==0 and len(self.input_stack)==0:
            return True
        return False
# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()