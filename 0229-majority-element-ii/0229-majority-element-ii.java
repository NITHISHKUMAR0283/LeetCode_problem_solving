class Solution {
    public List<Integer> majorityElement(int[] nums) {
        
        int n = nums.length;

        int cand1 = nums[0];
        int cand2 = Integer.MIN_VALUE;
        int count1  = 1;
        int count2 = 0;
        for(int i = 1;i<n;i++){
            if((cand2 ==Integer.MIN_VALUE || count2==0 ) && nums[i]!=cand1){
                cand2 = nums[i];
                count2 = 1;
            }
            else if ((cand1 == Integer.MIN_VALUE || count1 == 0) && nums[i]!=cand2){
                cand1 = nums[i];
                count1 = 1;
            }
            else if (nums[i]==cand1)count1++;
            else if (nums[i]==cand2)count2++;
            else{
                count1--;
                count2--;
                if(count1==0){
                }
            }
        }

        count1 = 0;
        count2 = 0;

        for(int ele : nums){
            if(ele==cand1)count1++;
            if(ele==cand2)count2++;
        }
        List <Integer> ans = new ArrayList <> ();

        if(Math.floorDiv(n,3)<count1)ans.add(cand1);
        if(Math.floorDiv(n,3)<count2)ans.add(cand2);

        return ans; 
    }
}