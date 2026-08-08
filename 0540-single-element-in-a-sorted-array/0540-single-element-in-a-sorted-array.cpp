class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(mid%2==1){
                if(nums[mid-1]!=nums[mid]){
                    high = mid;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid+1]!=nums[mid]){
                    high = mid;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return nums[high];
    }
};