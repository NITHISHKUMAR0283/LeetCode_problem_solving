class NumMatrix(object):

    def __init__(self, matrix):
        self.matrix = matrix
        row = len(matrix)
        col = len(matrix[0])
        self.dp = [[0]*(col+1) for _ in range(row+1)]

        for i in range(row):
            sum = 0
            for j in range(col):
                sum+=matrix[i][j]
                self.dp[i+1][j+1] = self.dp[i][j+1]+sum
        

        

    def sumRegion(self, row1, col1, row2, col2):
        sum = 0
        sum +=self.dp[row2+1][col2+1]-self.dp[row1][col2+1]-self.dp[row2+1][col1]+self.dp[row1][col1]
        return sum

        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)