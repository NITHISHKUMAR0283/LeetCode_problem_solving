class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int maxi = 0;
        Map<Character , Integer> freq = new HashMap<>();

        for(int i = 0 ;i<s.length();i++){
            char C = s.charAt(i);
            while(left<s.length() && freq.containsKey(C) &&  freq.get(C)>=1){
                    freq.put(s.charAt(left),freq.get(s.charAt(left))-1);
                    left++;
                
            }
            freq.put(C,freq.getOrDefault(C,0)+1);
            maxi = Math.max(maxi , i-left+1);
        }
        return maxi;
    }
}