class Solution {
    public void moveZeroes(int[] nums) {
        int insertPos = 0;
        int n = nums.length;
        for(int i  = 0; i<n;i++ ){
            if(nums[i]!=0){
                nums[insertPos]=nums[i];
                insertPos++;
            }
        }
        while(insertPos<n){
            nums[insertPos]=0;
            insertPos++;
        }        
    }
}