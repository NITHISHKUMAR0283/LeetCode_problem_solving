class Solution {
    public int lengthOfLongestSubstring(String s) {
        int [] freq = new int [1000] ;
        int left = 0;
        int maxi = 0;

        for(int i = 0 ;i<s.length();i++){
            char C = s.charAt(i);
            int ind = C;
            while(left<s.length() && freq[ind]>=1){
                    freq[s.charAt(left)]--;
                    left++;
                
            }
            freq[ind]++;
            maxi = Math.max(maxi , i-left+1);
        }
        return maxi;
    }
}