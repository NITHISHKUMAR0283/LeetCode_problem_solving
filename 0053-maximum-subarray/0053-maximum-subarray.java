class Solution {
    public int maxSubArray(int[] nums) {
        
        int sum = nums[0];
        int maxi = sum;
        int n = nums.length;
        for(int i = 1;i<n;i++){
            if(sum<0){
                sum=0;
            }
            sum+=nums[i];
            
            if (maxi<sum){
                maxi = sum;

            }
            
        }
        return maxi;
    }
}