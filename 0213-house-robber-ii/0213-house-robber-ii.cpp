class Solution {
public:
    int solve(vector<int> & nums){
        int n = nums.size();
        vector<int> dp (n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return nums[0];
        if(n<=3)return nums[distance(nums.begin(),max_element(nums.begin(),nums.end()))];
        vector<int> ex_f (nums.begin()+1,nums.end());
        vector<int> ex_l (nums.begin(),nums.end()-1);
        return max(solve(ex_f),solve(ex_l));
    }
};