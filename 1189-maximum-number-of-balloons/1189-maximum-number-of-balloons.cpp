class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int> freq;
        for(auto c : text){
            freq[c]++;
        }
        if(freq.contains('l')) freq['l']=freq['l']/2;
        if(freq.contains('o'))freq['o']=freq['o']/2;
        string word = "balon";
        int maxi = INT_MAX;
        
        for(auto c : word){
            if(!freq.count(c))return 0;
            maxi = min(maxi,freq[c]);
        }
        return maxi;

    }
};