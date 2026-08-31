class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum  = accumulate(nums.begin(),nums.end(),0);

        if(sum%2==1)return false;

        int target = sum/2;

        vector<vector<bool>> dp (n+1,vector<bool> (target+1,false));

        for( int item = 0 ; item <=n ; item ++){
            dp[item][0]=true;
        }

        for (int item = 1; item <= n ; item++ ){
            for( int sum = 1; sum <= target ; sum++ ){

                int need = sum - nums[item-1];
                bool possi = false;
                if(need >=0 && dp[item-1] [need]==true){
                    possi = true; 
                }
                dp[item] [ sum ] = dp[item-1][sum] || possi;
            }
        }
        for( int item = 0 ; item <= n ; item ++ ){
            for( int sum = 0 ; sum <= target ; sum ++ ){
                cout<< dp[item][sum]<< " ";
            }
        }
        return dp[n][target];
    }
};