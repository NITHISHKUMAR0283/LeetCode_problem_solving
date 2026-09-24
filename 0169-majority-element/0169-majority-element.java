class Solution {
    public int majorityElement(int[] nums) {
        int candidate = nums[0];
        int vote = 1;
        int n = nums.length;
        for(int i = 1 ; i <n; i++){
            if(nums[i]!=candidate){
                vote--;
                if(vote==0){
                    candidate= nums[i];
                    vote = 1;
                }
            }
            else{
                vote++;
            }
        }        
        return candidate;
    }
}