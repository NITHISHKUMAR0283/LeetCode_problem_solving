class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1,0);
        dp[0]=1;
        for(int i = 0;i<coins.size();i++){
            unsigned long long coin = coins[i];
            for(int j = 0;j<=amount;j++){
                int prev = j-coin;
                if(prev<0)continue;
                dp[j]+=dp[prev];
            }
        }
        return dp[amount];
    }
};