class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int n = nums.length;
        int [] prefsum = new int [n+1];

        int sum = 0;
        int count = 0;
        prefsum[0]=1;
        for(int i = 0; i<n ; i++ ){
            sum+=nums[i];
            int compliment = sum-goal;
            
            
            if(compliment>=0){
            count+=prefsum[compliment];}
            
            prefsum[sum]++;

        }
        return count;
    }
}