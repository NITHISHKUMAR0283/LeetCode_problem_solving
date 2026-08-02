class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSum;
        int sum = 0;
        int n = nums.size();
        int count  = 0;
        prefixSum[0]=1;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            int comp = sum-k;
            if(prefixSum.contains(comp)){
                count+=prefixSum[comp];
            }
            if(prefixSum.find(sum)!=prefixSum.end()){
                
                prefixSum[sum]++;
            }
            else{
                prefixSum[sum]=1;
            }
        }
        return count;
    }
};