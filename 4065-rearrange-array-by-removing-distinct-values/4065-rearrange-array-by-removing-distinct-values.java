class Solution {
    public int[] rearrangeArray(int[] nums) {
        int []freq = new int [101];
        int n = nums.length;
        for(int i = 0;i<n;i++){
            freq[nums[i]]++;
        }
        int [] ans = new int [n];
        int left = 0;
        while(left<n){
            for(int i = 0 ; i<101 ; i++){
                if(freq[i]!=0){
                    ans[left]=i;
                    freq[i]--;
                    left++;
                }
            }
        }
        return ans;
        
    }
}