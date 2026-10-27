class MyCircularQueue(object):

    def __init__(self, k):
        
        self.que = [-1]*k
        self.front = 0
        self.back = 0
        self.total = k

    def enQueue(self, value):

        
        
        if self.back-self.front>=self.total:
            return False
        
        self.que[(self.back)%self.total]= value
        
        self.back+=1
        
        return True
        

    def deQueue(self):

        if self.back-self.front==0:
            return False
        self.que[self.front%self.total]=-1
        self.front+=1
        return True

    def Front(self):

        if self.back-self.front==0:
            return -1
        f = self.que[self.front%self.total]
        return f

    def Rear(self):
        if self.back-self.front==0:
            return -1
        r = self.que[(self.back-1)%self.total]
        return r
    def isEmpty(self):
        
        if self.back-self.front==0:
            return True
        return False


    def isFull(self):

        if self.back-self.front==self.total:
            return True
        return False