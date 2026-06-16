class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        for(int i = 0;i<prices.size();i++){
            
            int today_p = prices[i]-mini;
            if(today_p>profit){
                profit = today_p;
            }
            if(mini>prices[i]){
                mini = prices[i];
            }
        }
        return profit;
    }
};