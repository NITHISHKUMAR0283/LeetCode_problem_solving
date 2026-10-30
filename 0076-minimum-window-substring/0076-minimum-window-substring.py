class Solution(object):
    def minWindow(self, s, t):
        freq = [0]*100
        patt = [0]*100
        
        left = 0
        right  = 0
        n = len(s)
        mini  = float("inf")
        start = -1
        end = -1
        for i in range(len(t)):
            ind = ord(t[i])-65
            patt[ind]+=1
        while right<n:
            ind = ord(s[right])-65            
            freq[ind]+=1
            right+=1
            found = True
            for i in range(100):
                if freq[i]<patt[i]:
                    found = False
                    break
            if found :
                ind_l = ord(s[left])-65
                while left<n and patt[ind_l]<freq[ind_l] :
                    freq[ind_l]-=1
                    left+=1   
                    if left>=n:
                        break                 
                    ind_l = ord(s[left])-65
                if right-left+1<mini:
                    mini = right-left+1
                    start = left
                    end = right                
                    
        result = ""
        for i in range(start,end):
            result+=s[i]
        return result

