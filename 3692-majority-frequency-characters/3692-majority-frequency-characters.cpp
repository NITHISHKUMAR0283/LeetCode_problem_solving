class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<char,int> freq;
        for(auto& c: s){
            freq[c]++;
        }        
        unordered_map<int,vector<char>> bucket ;
        vector<char> ans = {s[0]};
        int max_len = 0;
        for(auto& [c,f] : freq){
            bucket[f].push_back(c);
            
            if (max_len<bucket[f].size() || (max_len==bucket[f].size() && freq[ans[0]]<freq[bucket[f][0]])){
                ans = bucket[f];
                max_len = bucket[f].size();
            }


        }
        string res (ans.begin(),ans.end());
        return res;
    }
};