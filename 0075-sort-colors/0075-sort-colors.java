class Solution {
    public void sortColors(int[] nums) {
        int z = 0;
        
        int n = nums.length;
        int t = n-1;
        int curr = 0;
        while(curr<=t){
            if(nums[curr]==1){
                curr++;
                continue;
            }
            else if(nums[curr]==0){
                nums[curr]=nums[z];
                nums[z]=0;
                z++;
                curr++;
            }
            else if (nums[curr]==2){
                nums[curr]=nums[t];
                nums[t]=2;
                t--;
            }
        }
    }
}