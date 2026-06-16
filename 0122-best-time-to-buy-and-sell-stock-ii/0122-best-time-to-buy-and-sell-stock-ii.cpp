class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp represent the max profit from day 0 to i 
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        dp[1][0]=0;
        dp[0][0]=0;
        for(int i =n-1;i>=0;i--){
            
                dp[0][i]=max(dp[0][i+1],dp[1][i+1]-prices[i]);
                dp[1][i]=max(dp[1][i+1],dp[0][i+1]+prices[i]);
            }
        
        return dp[0][0];
           
    }
};