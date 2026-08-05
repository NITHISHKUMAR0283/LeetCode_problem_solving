class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> numInd;        
        int n = nums.size();
        for(int i = 0;i<n;i++){
            numInd.push_back({nums[i],i});
        }
        sort(numInd.begin(),numInd.end());
        int i = 0,j=n-1;
        while(i<j){
            int sum = numInd[i].first+numInd[j].first;
            if(sum==target){
                return {numInd[i].second,numInd[j].second};
            }
            if(sum>target){
                j--;
            }
            else if(sum<target){
                i++;
            }
            
        }
        return {0,0};

    }
};