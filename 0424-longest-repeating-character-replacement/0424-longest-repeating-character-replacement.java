class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int left  = 0;
        int [] freq = new int [26];
        int unique = 0;
        int longest = 0;
        int greatest = 0;
        int strike = 0;
        for(int i = 0;i<n;i++){
            int ind = s.charAt(i)-65;
            freq[ind]++;
            if(freq[ind]>freq[strike])strike=ind;
            while(i-left+1-freq[strike]>k && left<s.length()){
                freq[s.charAt(left)-65]--;
                left++;
                int maxi = 0;
                for(int j = 0;j<26;j++){
                    if(freq[j]>freq[maxi])maxi=j;
                }
                if(freq[strike]<freq[maxi])strike = maxi;
            }
            longest = Math.max(longest,i-left+1);
        }
        return longest;
    }
}