class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
            for(int j = 0;j<n;j++){
                if(j>0 && nums[j]==nums[j-1])continue;
                int low = j+1;
                int high = n-1;
                while(low<high){
                    if(low >j && nums[low]==nums[low-1])continue;
                    int sum = nums[low]+nums[high]+nums[j];
                    if(sum>0)high--;
                    else if(sum==0){
                        solution.push_back({nums[j],nums[low],nums[high]});
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        while (low < high && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                        }
                    else low++;                    
                }
            

        }
        return solution;
    }
};