class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freq;
        for(auto& c: s){
            freq[c]++;
        }        
        unordered_map<int,vector<char>> bucket ;
        vector<char> ans = {s[0]};
        int max_len = 0;
        int ans_f = 0;
        for(auto& [c,f] : freq){
            bucket[f].push_back(c);
            int cc = bucket[f].size();
            if (max_len<cc || (max_len==cc && ans_f<f)){
                
                max_len = cc;
                ans_f = f;
            }


        }
        vector<char>& ress = bucket[ans_f];
        string res (ress.begin(),ress.end());
        return res;
    }
};