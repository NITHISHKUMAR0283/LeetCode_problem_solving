class Solution {
public:
    long long power (long long base , long long exp , long long MOD){
        long long res = 1;
        base %=MOD;
        while(exp>0){
            if(exp%2==1)res = (res*base)%MOD;
            base = (base*base)%MOD;
            exp/=2;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        int result = 0;
        int MOD  = 1e9 +7;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            long long width = nums[i]%10;
            long long depth = floor(nums[i]/10);
       
            string s = to_string(depth);
            long long x = stoll(s.substr(0,width));
            long long y = stoll(s.substr(width));
           
            result = (result + power(x,y,MOD))%MOD;
            
        }
        return result;
    }
};