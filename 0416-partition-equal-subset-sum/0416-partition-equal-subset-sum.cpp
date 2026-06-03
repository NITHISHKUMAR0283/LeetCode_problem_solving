#include <numeric>
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sums  = reduce(nums.begin(),nums.end());
        int h_sum =sums/2;
        if(sums%2==1)return false;
        vector<vector<bool>> dp ( n+1,vector<bool>(h_sum+1,false));
        for(int i = 0;i<n;i++){
            dp[i][0]=true;
        }
        for(int i = 1;i<=n ;i++){
            for(int j =1 ;j<=h_sum;j++){
                bool nottaken = dp[i-1][j];
                int taken = false;
                if(nums[i-1]<=j){
                    taken = dp[i-1][j-nums[i-1]];
                }
                dp[i][j] = nottaken || taken ;
            }
        }
        return dp[n][h_sum];
    }
};