class Solution {
public:
    using ll = long long ;
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll dp0 = 0  , dpm = 0 , dp2=0,dpc=0,res = -1e9;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            ll e = nums[i];
            
            dp2= max({dpm+e,dp2+e,dpc+e});   
            dpm=max({dpm+e*k,dp0+e*k,e*k});
            dpc=max({e/k,dp0+e/k,dpc+e/k});
            dp0=max({e,dp0+e});
            res=max({res,dp2,dpm,dpc,dp0});
        }
        return res;
    }
};