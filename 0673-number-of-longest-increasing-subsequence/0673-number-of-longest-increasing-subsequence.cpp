class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1,1);
        vector<int> counts(n+1,1);
        int max_len = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<i ;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=1+dp[j];
                        counts[i]=counts[j];
                    }
                    else if (dp[j]+1==dp[i]){
                        counts[i]+=counts[j];
                    }
                }
            }
            max_len = max(max_len,dp[i]);
                    }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(dp[i]==max_len){
                ans += counts[i];
            }
        }
        return ans;
    }
};