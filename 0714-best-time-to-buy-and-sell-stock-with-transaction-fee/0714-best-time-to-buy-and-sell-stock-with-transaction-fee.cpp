class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>dp(2,0);
        
        for(int i = n-1;i>=0;i--){
            int buy =max(dp[0],dp[1]-prices[i]);
            int sell =max(dp[1],dp[0]+prices[i]-fee);
            dp[0]=buy;
            dp[1]=sell;
        }
        return dp[0];
    }
};