class Solution {
    public void swap (int [] nums , int a , int b ){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    public void reverse (int [] nums , int start , int end){
        while(start<=end){
            swap(nums,start,end);
            start++;
            end--;
        }
    }
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int index = -1;
        for(int i = n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                index = i-1;
                break;
            }
        }
        if(index ==-1){
            reverse(nums,0,n-1);
            return ;
        }
        
        for(int j = n-1;j>index;j--){
            if(nums[j]>nums[index]){
                swap(nums,index,j);
                break;
            }
        }

        reverse(nums,index+1,n-1);                
    }
}