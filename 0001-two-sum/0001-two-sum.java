class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> visited = new HashMap<>();
        int n = nums.length;
        for(int i = 0 ; i<n;i++){     
            int compliment = target-nums[i];
            if(visited.containsKey(compliment)){
                return new int []{visited.get(compliment),i};
            }
            
            visited.put(nums[i],i);
        }
        return new int []{};
    }
}