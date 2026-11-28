class Solution(object):
    def letterCombinations(self, digits):
        
        num_alp = {2:"abc",
                    3:"def",4:"ghi",5:"jkl",6:"mno",7:"pqrs",8:"tuv",9:"wxyz"}

        rev = 0

        n = len(digits)

        result = []
        for w in num_alp[int(digits[0])]:
            result.append(w)

        for i in range(1,n):
            d = int(digits[i])
            
            set2 = num_alp[d]
            curr = []
            for w in result:
                for w2 in set2:
                    curr.append(w+w2)
            result = curr
        return result 