class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int,int> presum;
        presum[0]=1;
        for(int ele:nums){
            sum+=ele;
            int comp = (sum%k+k)%k;
            if(presum.find(comp)!=presum.end()){
                count+=presum[comp];
            }
            presum[comp]++;
        }
        return count;
    }
};