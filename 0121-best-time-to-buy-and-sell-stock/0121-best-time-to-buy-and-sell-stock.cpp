class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int maxi = INT_MIN;
        for(int i = n-1;i>-1;i--){
            if(maxi<prices[i]){
                maxi = prices[i];
            }
            ans = max(ans,maxi-prices[i]);
        }
        return ans;

    }
};