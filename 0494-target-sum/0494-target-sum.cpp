
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto ele : nums){
            sum+=abs(ele);
        }
        vector<vector<int>> dp(n+1,vector<int> (2*(abs(sum)+1),-1)) ;
        explore(nums,0,target,0,dp,sum );
        return *max_element(dp[0].begin(),dp[0].end());

    }
    int explore(vector<int> & nums , int sum ,int target,int i ,vector<vector<int>> & dp,int sums ){
        if(i == nums.size()){
            if(sum == target)return 1;
            else return 0;}
        if(sum+sums>=(2*(sums+1)) || sum+sums<0)return 0;
        if(dp[i][sum+sums]!=-1)return  dp[i][sum+sums];

        
        //positive
        int pos = explore(nums,sum+nums[i],target,i+1,dp,sums );
        //negative 
        int neg = explore(nums, sum-nums[i],target , i+1,dp,sums);

        return dp[i][sum+sums]=pos+neg;
    }
};