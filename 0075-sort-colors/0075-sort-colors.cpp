class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0;
        int n = nums.size();
        int t = n-1;
        int curr = 0;
        while(curr<=t){
            if(nums[curr]==0){
                swap(nums[curr],nums[z]);
                curr++;
                z++;
            }
            else if(nums[curr]==1){
                curr++;
            }
            else{
                swap(nums[curr],nums[t]);
                t--;
            }
        }
    }
};