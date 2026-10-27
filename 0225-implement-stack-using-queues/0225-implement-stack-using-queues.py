class MyStack(object):

    def __init__(self):
        self.que = deque()


    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        
        self.que.append(x)
        for i in range(len(self.que)-1):
            self.que.append(self.que.popleft())
    def pop(self):
        """
        :rtype: int
        """
        return self.que.popleft()
        

    def top(self):
        """
        :rtype: int
        """
        return self.que[0]
        

    def empty(self):
        """
        :rtype: bool
        """
        if len(self.que)==0:
            return True
        return False
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()