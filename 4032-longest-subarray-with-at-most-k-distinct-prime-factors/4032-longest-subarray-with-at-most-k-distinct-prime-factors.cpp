class Solution {
public:
    vector<int> getPrime (int n ){
        vector<int> factors;
        if(n%2==0){
            factors.push_back(2);
            while(n%2==0)n/=2;
            
        }
        for(int i = 3;i*i<=n;i+=2){
            if(n%i==0){
                factors.push_back(i);
            while(n%i==0){
                n/=i;
            }}
        }
        if(n>1){
            factors.push_back(n);
        }
        return factors;
    }
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        int left = 0;
        vector<vector<int>> factors(n);
        int result = 0;
        for(int i = 0;i<n;i++){
            factors[i]= getPrime(nums[i]);
            
            for(auto fa : factors[i]){
                freq[fa]++;
            }
            while(freq.size()>k){
                for(auto f: factors[left]){
                    freq[f]--;
                    if(freq[f]==0){
                        freq.erase(f);
                    }
                }
                left++;
            }
            result = max(result ,i-left+1);
        }
        return result;
    }
};