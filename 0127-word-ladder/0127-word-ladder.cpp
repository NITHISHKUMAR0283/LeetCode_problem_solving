class Solution {
public:
    
    bool nei (string word1 , string word2){
        int n = word1.size();
        int change = 0;
        int i = 0;
        while(i<n){
            if(word1[i]!=word2[i]){
                change++;
                if(change>1)return false;
            }
            i++;
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();
        if(!ranges::contains(wordList,endWord))return 0;
        unordered_set<string>left,right,next;
        
        unordered_set<string>visited;
        left.insert(beginWord);
        right.insert(endWord);
        int count = 2;

        while(!left.empty() && !right.empty()){
            if(right.size()<left.size()){
                left.swap(right);
            }
            next.clear();
            for(const auto& sold:left){                
                for(const auto& tran:wordList){
                    if(sold==tran)continue;
                    if(visited.contains(tran))continue;
                    if(nei(sold,tran)){
                        if(right.contains(tran)){
                            print("right contains {} ",tran);
                            return count;}
                        next.insert(tran);
                    }
                    
                }
                
                visited.insert(sold);
            }
            left.swap(next);
            count++;
        }
        return 0;
    }
};