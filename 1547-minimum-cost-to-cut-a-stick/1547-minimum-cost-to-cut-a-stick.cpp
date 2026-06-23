class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int  m=cuts.size();
        vector<vector<int>> dp (m+1,(vector<int>(m+1,-1)));
        return cost(0,cuts.size()-1,cuts,dp);
    }
    int cost ( int start , int end , vector<int>& cuts, vector<vector<int>>& dp){
        if(start+1==end)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        int mini = INT_MAX;
        for(int i =start+1;i<end;i++){
            int costi = cuts[end]-cuts[start]+  cost(start,i,cuts,dp)+ cost(i,end,cuts,dp)     ;
            mini = min(mini,costi);
        }
        dp[start][end]=mini;
        return mini;    


    }
};