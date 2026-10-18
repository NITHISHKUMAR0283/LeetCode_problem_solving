class Solution(object):
    def isPrefixOfWord(self, sentence, searchWord):
        """
        :type sentence: str
        :type searchWord: str
        :rtype: int
        """
        n =len(sentence)
        i=0
        word = 1
        while i<n:
            if sentence[i]==searchWord[0]:
                current = 0
                start = i
                while i<n and  current<len(searchWord) and sentence[i]==searchWord[current] :
                    current+=1
                    i+=1
                if current>=len(searchWord):
                    return word
            while i<n and sentence[i]!=" ":
                i+=1
            i+=1
            word+=1
        return -1