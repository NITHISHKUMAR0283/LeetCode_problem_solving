class Solution {
public:
    bool diff (string w1,string w2){
        int n = w1.size();
        int m = w2.size();
        if(abs(n-m)>2)return false;
        int i = 0,j=0;
        int change = 0;
        while(i<n && j<m &&change <2){
            if(w1[i]==w2[j]){
                i++;
                j++;
            }
            else{
                j++;
                change++;
            }
        }
        change+= abs(i-j);
        if(change >2)return false;
        return true;
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<int,vector<string>> dp;
        int n = words.size();
        int min_ind = INT_MAX;
        int max_ind = INT_MIN;

        for(auto str : words){
            int len = str.length();
            if(len < min_ind)min_ind = len;
            if(len> max_ind)max_ind = len;
            dp[len].push_back(str);
        }
        
        vector<int> chain(n+1,1);
        int start = min_ind+1;
        int maxi = 1;
        while(start<=max_ind){
            int pars = dp[start].size();
            int chis = dp[start-1].size();
            
            vector<int>last(pars,1);
            for(int par = 0;par<pars;par++){
                for(int chi = 0;chi<chis;chi++){

                    if(diff(dp[start-1][chi],dp[start][par])){
                        if(last[par]<chain[chi]+1){
                            last[par]=chain[chi]+1;
                            maxi = max(last[par],maxi);
                            
                        }
                    }
                }
            }
            chain=last;
            start++;
        }
        return maxi;
    }
};