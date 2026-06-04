class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> index;
        for(int i = 0;i<nums.size();i++){
            index[nums[i]]=i;
        }
        for(int i = 0;i<nums.size();i++){
            int ele = nums[i];
            int compliment = target-ele;
            auto it = index.find(compliment);
            if(it!=index.end() && it->second!=i){
                return {i,index[compliment]};
            }
        }
        return {};
    }
};