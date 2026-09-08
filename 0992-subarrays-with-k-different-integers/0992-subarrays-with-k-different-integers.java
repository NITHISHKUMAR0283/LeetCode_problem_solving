class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return atmost_k(nums,k)-atmost_k(nums,k-1);
    }
    private int atmost_k(int [] nums , int k ){
        int n = nums.length;
        int left = 0;
        Map<Integer,Integer> freq = new HashMap<>();
        int res = 0;
        for(int i = 0;i<n;i++){
            if(freq.getOrDefault(nums[i],0)==0){
                k--;
            }
            freq.put(nums[i], freq.getOrDefault(nums[i],0)+1);
            
            while(k<0){
                freq.put(nums[left],freq.get(nums[left])-1);
                if(freq.get(nums[left])==0){
                    k++;
                }
                left++;
            }
            res += i-left+1;

        }
        return res;
    }
}