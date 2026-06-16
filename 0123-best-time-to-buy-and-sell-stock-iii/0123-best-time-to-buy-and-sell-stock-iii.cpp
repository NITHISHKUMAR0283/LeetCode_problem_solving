class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp (2,vector<vector<int>>(n+1,vector<int>(3,0)));
        for(int i = n-1;i>=0;i--){
            for(int j = 1;j>-1;j--){
                dp[0][i][j] = max(dp[0][i+1][j],dp[1][i+1][j]-prices[i]);
                dp[1][i][j] = max(dp[1][i+1][j],dp[0][i+1][j+1]+prices[i]);
            }
        }
        return dp[0][0][0];
    }
};