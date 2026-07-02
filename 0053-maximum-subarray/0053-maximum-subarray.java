class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int maxi = Integer.MIN_VALUE;
        for(int ele : nums){
            sum+=ele;
            sum= Math.max(sum,ele);
            maxi = Math.max(sum,maxi);

        }
        return maxi ;
    }
}