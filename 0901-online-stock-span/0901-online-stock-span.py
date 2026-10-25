class StockSpanner(object):

    def __init__(self):
        self.stack = []
    def next(self, price):
        streak = 1
        start = len(self.stack)-1
        while start>=0 and self.stack[start][0]<=price:
            streak+=self.stack[start][1]
            start-=self.stack[start][1]
        self.stack.append((price,streak))
        return streak



# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)