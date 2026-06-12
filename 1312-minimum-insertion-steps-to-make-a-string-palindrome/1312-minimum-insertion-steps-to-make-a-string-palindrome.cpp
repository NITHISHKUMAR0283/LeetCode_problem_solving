class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        string rev = s;
        reverse(rev.begin(),rev.end());

        for(int i = n-1;i>=0;i--){
            int next_diagonal = 0;
            for(int j = n-1;j>=0;j--){
                int temp = dp[j];
                if(s[i]==rev[j]){
                    dp[j]=1+next_diagonal;
                }
                else{
                    dp[j]=max(dp[j+1],dp[j]);
                }
                next_diagonal = temp;
            }
        }
        int llcs = dp[0];

        return n-llcs;
    }
};