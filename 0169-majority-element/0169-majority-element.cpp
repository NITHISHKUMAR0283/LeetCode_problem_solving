class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand= nums[0];
        int vote = 1;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i]!=cand){
                vote--;
                if(vote==0){
                    cand = nums[i];
                    vote = 1;
                }
            }
            else{
                vote++;
            }
        }
        return cand;
    }
};