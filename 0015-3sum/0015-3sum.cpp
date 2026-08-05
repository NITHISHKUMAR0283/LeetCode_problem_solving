class Solution {
public:
    
    vector<vector<int>> twoSum(vector<int>& nums, int target,int start) {
        vector<pair<int,int>> numInd;       
        vector<vector<int>> sol; 
        int n = nums.size();
        for(int i = start;i<n;i++){
            numInd.push_back({nums[i],i});
        }
        sort(numInd.begin(),numInd.end());
        int i = 0,j=numInd.size()-1;
        while(i<j){
            int sum = numInd[i].first+numInd[j].first;
            if(sum==target){
                sol.push_back({numInd[i].first,numInd[j].first});
                j--;
            }
            if(sum>target){
                j--;
            }
            else if(sum<target){
                i++;
            }
            
        }
        return sol;

    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        set<vector<int>> s;
        for(int i = 0;i<n-1;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int sum = nums[i];
            auto rems = twoSum(nums,-sum,i+1);
            for(const auto& rem :rems){
            int j = rem[0];
            int k = rem[1];
                s.insert({nums[i],j,k});
            }
        }

        vector<vector<int>> sol(s.begin(),s.end());
        return sol;
    }
};