class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int [] back = new int [n+1];
        int start = 1;
        for(int i = n-1 ; i>=0 ; i-- ){
            start*=nums[i];
            back[i]=start;
            if(start==0)start = 1;
        }
        int front = 1;
        int ans = -10;
        for(int i = 0;i<n;i++){
            front*=nums[i];
            ans =Math.max(ans, Math.max(front,back[i]));
            if(front==0)front = 1;
        }
        return ans;
    }
}