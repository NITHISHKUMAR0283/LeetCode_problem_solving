class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> visited;
        unordered_set<int>punished;
        int n = nums.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            if(i>0 && visited.find(nums[i])!=visited.end() && nums[i]!=nums[i-1] && punished.find(nums[i])==punished.end()){
                punished.insert(nums[i]);
                count--;
            }
            if(visited.find(nums[i])==visited.end()){
                count++;
                visited.insert(nums[i]);
            }
        }
        return count;
    }
};