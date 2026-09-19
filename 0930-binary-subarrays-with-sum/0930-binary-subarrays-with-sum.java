class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int n = nums.length;
        Map<Integer,Integer> prefsum = new HashMap<>();
        prefsum.put(0,1);

        int sum = 0;
        int count = 0;
        for(int i = 0; i<n ; i++ ){
            sum+=nums[i];
            int compliment = sum-goal;
            
            
            if(compliment>=0){
            count+=prefsum.getOrDefault(compliment,0);}
            
            prefsum.put(sum,prefsum.getOrDefault(sum,0)+1);

        }
        return count;
    }
}