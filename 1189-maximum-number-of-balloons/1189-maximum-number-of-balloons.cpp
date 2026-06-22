class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int> freq;
        for(auto c : text){
            freq[c]++;
        }
        freq['l']=freq['l']/2;
        freq['o']=freq['o']/2;
        string word = "balon";
        int maxi = INT_MAX;
        
        for(auto c : word){
            maxi = min(maxi,freq[c]);
        }
        return maxi;

    }
};