class Solution {
    public int subarraySum(int[] nums, int k) {
        
        int sum = 0;
        int n = nums.length;
        int ans = 0;

        Map <Integer,Integer> prefix = new HashMap<>();

        prefix.put(0,1);

        for(int i = 0;i<n;i++){
            sum+=nums[i];
            int complement = sum-k;            

            if(prefix.containsKey(complement)){
                ans+=prefix.get(complement);
            }
            prefix.merge(sum,1,Integer::sum);
        }
        return ans;

    }
}